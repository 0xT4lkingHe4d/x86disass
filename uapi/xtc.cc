// #include "../include/uapi.h"
#include "./cpp_uapi.hpp"
#include "./xtc.hpp"

static std::map<__u8 *, std::list<struct xtc_st>> xtc_map;

void x_t_c::insert(instr *in) {
    for (__u8 l = 0; l < 0b111; l++) {
        __u8 pfx_i = 0;
        struct xtc_st x = {0};
        if (l&1) { x.pfx.rex    = (x.sc[pfx_i++] = 0x48); }
        if (l&2) { x.pfx.addr   = (x.sc[pfx_i++] = 0x67); }
        if (l&4) { x.pfx.oper   = (x.sc[pfx_i++] = 0x66); }
        x.sc_len = pfx_i + _build_instr(in, &x.sc[pfx_i]);
        x.in = in;

        insn_t instr(x.sc);
        if (instr.insn != in) continue;

        for (__u8 i = 0; i < instr.OperCount(); i++) {
            x.op[i].t    = instr[i]->Type();
            x.op[i].size = instr[i]->size();
            x.op_count++;
        }

        if (!in->ops_count) {
            xtc_map[in->mnemonic].push_back(x);
        } else {
            for (__u8 i = 0; i < in->ops_count; i++) {
                xtc_map[in->ops[i].mnemonic].push_back(x);
            }
        }
    }
}

x_t_c::x_t_c() {
    if (xtc_map.size() > 0) return;
    instr *in = NULL;
    for_each_instr(X86_64, in) {
        if ((!in || !in->mnemonic || in->opcode1 == 0x0F
            || (in->prefix && !in->opcode1)))
            continue;
        insert(in);
    }
}

__s8 x_t_c::get(__u8 *sc, insn_t& in, __u64 op[4]) {
    try {
        for (auto& x : xtc_map.at((__u8*)in.Mnemo())) {
            for (__u8 i = 0; i < in.OperCount(); i++) {
                if (!op[i]) {
                    if (in[i]->Type() != x.op[i].t)     break;
                    if (in[i]->size() != x.op[i].size)  break;
                } else {
                    if (x.op[i].size != op[i]) break;
                }

                if (!(i+1 < in.OperCount())) {
                    memcpy(sc, x.sc, x.sc_len);
                    return x.sc_len;
                }
            }
        }
    } catch (...) {
        return -1;
    }
    return -1;
}
