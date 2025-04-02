#include "../include/uapi.h"
#include "./cpp_uapi.hpp"

const char *insn_t::Mnemo() {
    return (const char *)c_get_instr_name(this);
}

__u8 insn_t::OperCount() {
    for (int i=0; i < MAX_OPS_COUNT; i++)
        if (op[i].IsType(OperType::NONE))
            return i;

    return MAX_OPS_COUNT;
}

bool insn_t::IsPtr() {
    for (__u8 i = 0; i < OperCount(); i++) {
        if ((*this)[i]->Type() == OperType::PTR)
            return true;
    }
    return false;
}

bool insn_t::IsShortJump() {
    if (!IsJump()) return 0;

    foreach_operand(p, this)
        if (p->is_ptr && (p->disp_sz==8 || p->sz==8))
            return 1;
    
    return 0;
}


__u8 insn_t::size() { return in_sz; }
__u8 insn_t::Sib()  { return !!sib_on ? sib : 0; }
__u8 insn_t::ModRM() { return !!modrm_on ? modrm : 0; }
bool insn_t::IsRip() {
    return c_get_rip_oper(this) != -1;
}

bool insn_t::IsNull() { return !insn; }
void insn_t::Print() { c_pr_in_str(this); }
void *insn_t::Addr() { return addr; }
bool insn_t::IsRet() {
    return (!strncmp((char*)Mnemo(), "RET", 3));
}

bool insn_t::IsShortBranch() {
    if (!IsBranch()) return false;
    for (__u8 i = 0; i < OperCount(); i++)
        if ((*this)[i]->Type() == OperType::PTR)
            return ((*this)[i]->size() == 8);

    return false;
}
bool insn_t::IsBranch() {
    return INSN_GROUP(this, BRANCH);
}
bool insn_t::IsDatamov() {
    return INSN_GROUP(this, DATAMOV);
}
bool insn_t::IsJump() {
    return !IsNull() && INSN_GROUP(this, BRANCH) && !strncmp(Mnemo(), "J", 1);
}

bool insn_t::IsCall() {
    return !IsNull() && INSN_GROUP(this, BRANCH_STACK) && !strncmp(Mnemo(), "CALL", 4);
}

Operand *insn_t::operator[](__u8 i) {
    return (3 < i) ? nullptr : &op[i];
}

__u8 insn_t::dump(__u8 *out) {
    return c_assemble(this, out);
}

void insn_t::stick_ptr(__u64 diff, ReAsmT f) {
    c_change_ptr(this, diff, static_cast<__u8>(f));
}
__u8 insn_t::stick_in(void *out, __u64 rip_imm, __u64 virt, ReAsmT t) {
    return c_stick_in_instr(this, (__u8*)out, rip_imm, virt, static_cast<__u8>(t));
}

void linkOper(Operand& op, instr_dat_t *in) { op.link(in); }

// #define snf(dst, sz, fmt, ...)   snprintf((char*)(dst), (__u64)(sz), fmt, __VA_ARGS__)
#define snf snprintf

char *Operand::Str() {
    auto p = dynamic_cast<operand*>(this);
    if (!name) name = new char[0x30];

    char *out = name;
    if (p->seg_reg)
        out += ((__u64)name + snf(name, 0x30, "%s: ", c_seg_reg_str(p->seg_reg)));
    __u64 sz = 0x30 - (out - name);
    __u8 addr_sz = c_get_addr_size(instr);

    if (!!p->is_imm) {
        if (!!p->rip) {
            snf(out, sz, "[ %s %c 0x%lx]",
                c_get_rip_str(p->rip),
                c_get_signed_char(*(__u64*)p->imm, p->sz), v);
        } else {
            snf(out, sz, "0x%lx", p->imm);
        }
    } else if (p->reg && !p->disp_sz) {
        if (p->is_ptr) snf(out, sz, "%s [ %s ]", c_word_sz_to_str(p->sz), c_get_reg_name(p->reg));
        else snf(out, sz, "%s", c_get_reg_name(p->reg));
    } else if (p->is_ptr) {
        if (instr->sib_on) {
            if (!p->sib.i_reg)
                snf(out, sz, "%s [ %s + %s*%i ",
                    c_word_sz_to_str(p->sz),
                    c_reg_4bits_name(p->sib.b_reg, addr_sz),
                    c_reg_4bits_name(p->sib.i_reg, addr_sz), p->sib.s);
            else
                snf(out, sz, "%s [ %s ",
                    c_word_sz_to_str(p->sz),
                    c_reg_4bits_name(p->sib.b_reg, addr_sz));
            if (p->disp_sz) snf(out, sz, "%c 0x%lx", c_get_signed_char(*(__u64*)p->disp, p->disp_sz), v);
            snf(out, sz, " ]");
        } else if (instr->modrm_on && p->disp_sz) {
            snf(out, sz, "%s [ %s %c0x%llx ]",
                c_word_sz_to_str(p->sz),
                (!!p->rip) ? c_get_rip_str(p->rip) : c_get_reg_name(p->reg),
                c_get_signed_char(*(__u64*)p->disp, p->disp_sz), v);
        }
    }
    return name;
}
