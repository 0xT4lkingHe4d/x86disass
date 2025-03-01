#include <endian.h>
#include "../include/disass.h"

void print_instr(instr *e) {
	if (!e) {
		prf("NULL arg\n");
		return;
	}
	prf("Prefix[%02x]\t%s %02x %02x",
			e->prefix, (e->two_byte) ? "0f" : "",
			e->opcode1, e->opcode2);

	if (!!e->ops_count) {
		for (int i=0; i<e->ops_count; i++)
			prf("\t[%i] '%s';%s", i, e->ops[i].mnemonic, (i == e->ops_count-1) ? "\n" : "\t");

	} else {
		prf("\t'%s'", e->mnemonic);
	}
	if (e->reg_op) prf("\tregop[%02x]", e->reg_op);
	pr("");
}

char *word_sz_to_str(__u8 sz) {
	switch (sz) {
		case _BYTE_: 	return "BYTE";
		case _WORD_: 	return "WORD";
		case _DWORD_: 	return "DWORD";
		case _QWORD_: 	return "QWORD";
		case _XMMWORD_: return "XMM";
		case _TBYTE_: 	return "TBYTE";
		case _FWORD_: 	return "FWORD";
		default: 		return "N/A";
	}
}

char *seg_reg_str(__u8 v) {
	switch (v) {
		case SEG_CS: return "cs";
		case SEG_SS: return "ss";
		case SEG_DS: return "ds";
		case SEG_ES: return "es";
		case SEG_FS: return "fs";
		case SEG_GS: return "gs";
	}
	return "[no segreg]";
}

__u64 _pow(__u8 a, __u8 b) {
	__u64 x=1;
	for (__u64 i=0;i<b;i++) x*=a;
	return x-1;
}

// "+0xcafe"
static __u64 get_imm_le(__u8 addr[8], __u8 sz) {
	__u64 v = *(__u64*)addr & N_BITS_MAX(sz);

	switch (sz) {
		case 8:		v = v;			break;
		case 16:	v = le16toh(v);	break;
		case 32:	v = le32toh(v);	break;
		case 64:	v = le64toh(v);	break;
		default:
			DIE("FUCK");
	}

	return N_BITS_MAX(sz) & _signed(v, sz);
}

__u8 get_signed_char(__u64 v, __u64 sz) {
	return (v > (__u64)N_BITS_MAX(sz)/2) ? '-' : '+';
}

__u8 *get_rip_str(__u8 sz) {
	if (sz == 64) return "RIP";
	if (sz == 32) return "EIP";
	return "?";
}

void pr_in_str(instr_dat_t *in) {
	__u8 sc[15] = {0};
	if (!in || !in->insn) {
		pr("NULL instr");
		return;
	}

	assemble(in, sc);
	
	foreach(i, in->in_sz)		prf("%02x ", sc[i]);
	foreach(i, 10 - in->in_sz)	prf("   ");

	const __u8 *name = get_instr_name(in);
	__u8 addr_sz = get_addr_size(in);

	prf("%-8s", name);
	foreach_operand(p, in) {
		if (p != &in->oper[0]) prf(", ");

		if (p->seg_reg) prf("%s:", seg_reg_str(p->seg_reg));
		if (p->is_imm) {
			if (!!p->rip) {
				__u64 v = get_imm_le(p->imm, p->sz);
				prf("[%s", get_rip_str(p->rip));
				prf("%c0x%llx", get_signed_char(*(__u64*)p->imm, p->sz), v);
				prf("]");
			} else {		// is IMM
				prf("0x%x", N_BITS_MAX(p->sz) & *(__u64*)p->imm);
			}
		} else if (p->reg && !p->disp_sz) {
			__u32 reg = p->reg;

			if (IS_ANY_REGS(reg)) {
				// prf("/%s/", gen_reg_scale_by_val(reg, get_oper_size(in)));
			} else {
				__u8 *nm = get_reg_name(reg);
				if (p->is_ptr) {
					prf("%s ptr [%s]", word_sz_to_str(p->sz), nm);
				} else {
					prf("%s", nm);
				}
			}
		} else if (p->is_ptr) {
			if (!p->sz) TRAP();
			__u64 v = get_imm_le(p->disp, p->disp_sz);

			prf("%s ptr ", word_sz_to_str(p->sz));
			if (p->sib.on) {
				prf("[%s + %s*%i ",
					reg_4bits_name(p->sib.b_reg, addr_sz),
					(!p->sib.i_reg) ? "[NO]" : reg_4bits_name(p->sib.i_reg, addr_sz),
					p->sib.s);

				if (p->disp_sz) prf("%c0x%llx", get_signed_char((__u64*)p->disp, p->disp_sz), v);
				prf("]");
			} else if (in->modrm_on && !!p->disp_sz) {
				prf("[");
				prf("%s", (!!p->rip) ? get_rip_str(p->rip) : get_reg_name(p->reg));
				prf("%c0x%llx", get_signed_char(*(__u64*)p->disp, p->disp_sz), v);
				prf("]");
			}
		}
	}
	pr("");
}


