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
	foreach_operand(p, this) if (p->is_ptr) return 1;
	return 0;
}

bool insn_t::IsShortJump() {
	if (!IsJump()) return 0;

	foreach_operand(p, this)
		if (p->is_ptr && (p->disp_sz==8 || p->sz==8))
			return 1;
	
	return 0;
}


__u8 insn_t::size() { return in_sz; }
__u8 insn_t::Sib()	{ return !!sib_on ? sib : 0; }
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


void linkOper(Operand& op, instr_dat_t *in) { op.link(in); }
