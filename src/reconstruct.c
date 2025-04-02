#include <assert.h>
#include "../include/uapi.h"

#define GET_REX_BYTE(rex)	(0x40 | (!!rex.w<<3 | !!rex.r<<2 | !!rex.x<<1 | !!rex.b))

__u8 assemble(instr_dat_t *in, __u8 ops[15]) {
	if (!in) return 0;
	const instr *e = in->insn;
	__u8 i = 0;

	// Prefixes
	for_range(i, INST_MAX_PFX) {
		if (!in->pfx[i]) break;
		ops[i]=in->pfx[i];
	}
	// REX
	if (!!in->rex_on) ops[i++]=GET_REX_BYTE(in->rex);

	// Add mandatory prefix if not already there
	if (e->prefix && !inst_has_pfx(in, e->prefix)) {
		ops[i++]=e->prefix;
	}
	// instr opcodes
	if (e->two_byte) ops[i++]=0x0f;
	ops[i] = e->opcode1;
	ops[i++] += (!!e->flds && !!e->flds ? in->reg_op : 0);

	if (e->opcode2) ops[i++]=e->opcode2;
	
	// Modrm + SIB
	if (in->modrm_on) {
		ops[i++]=in->modrm;
		if (in->sib_on) ops[i++]=in->sib;
	}
	// insert imm/disp
	foreach_operand(p, in) {
		// operand *p = &in->oper[l];
		// if (!!p->is_empty) break; // continue

		if (!!p->disp_sz) {
			__u8 sz = p->disp_sz/8;
			memcpy(&ops[i], p->disp, sz);
			i += sz;
		} else if (!!p->is_imm) {
			__u8 sz = p->sz/8;
			memcpy(&ops[i], p->imm, sz);
			i += sz;
		}
	}

	// _assertf(in->in_sz == i && i < 0x10, "in_sz: %lx i: %lx", in->in_sz, i);
	return i;
}

__u8 _build_instr(instr *in, __u8 *sc) {
	__u64 i = 0;
	if (in->prefix)		sc[i++] = in->prefix;
	if (in->two_byte)	sc[i++] = 0x0f;

	sc[i++] = in->opcode1;
	if (in->opcode2) sc[i++] = in->opcode2;

	if (in->reg_op && in->reg_op != F_MODRM) {
		sc[i-1] = (__u8)( ((in->reg_op == '0') ? 0 : in->reg_op) << 3);
	}
	return i;
}


__u8 change_imm(instr_dat_t *ret, operand *p, __u64 imm) {
	__u8 sz = p->sz/8;
	if (p->x_origin.t != X_IMM)
		return -1;

	memmove(p->imm, (__u8*)&imm, sz);
	return sz;
}

__s8 change_disp(instr_dat_t *ret, operand *p, __u32 v) {
	switch (p->disp_sz) {
	case 8:
		*p->disp = v & 0xff;	break;
	case 32:
		*(__u32*)p->disp = v;	break;
	default:
		return -1;
	}
	return 0;
}

#define CHANGE_MODRM_REG(x, v)	(((__u8)x &~0x38) | ((v&7) << 3))
#define CHANGE_MODRM_RM(x, v) 	(((__u8)x&~7) | (v&7))

#define CHANGE_SIB_S(x, v) 	(((__u8)x&~0xc0) | ((v&3)<<6))
#define CHANGE_SIB_I(x, v)	CHANGE_MODRM_REG(x, v);
#define CHANGE_SIB_B(x, v)	CHANGE_MODRM_RM(x, v);

void change_regop(instr_dat_t *ret, operand *p, __u8 reg) {
	if (p->x_origin.t != X_REG_OP) DIE("not regop");
	ret->reg_op = reg&7;
}

__s8 chng_sib(instr_dat_t *ret, __u8 v, __u16 x) {
	if (!ret->sib_on) return -1;
	switch (x) {
		case S:	ret->sib = CHANGE_SIB_S(ret->sib, v); break;
		case I:	ret->sib = CHANGE_SIB_I(ret->sib, v); break;
		case B:	ret->sib = CHANGE_SIB_B(ret->sib, v); break;
		default: return -1;
	}
	return 0;
}

__s8 change_modrm(instr_dat_t *ret, operand *p, __u8 reg) {
	const regs_tuple_t *tup = &p->x_origin;
	switch (tup->t) {
	case X_MODRM:
		{
			if (ret->sib_on || !!p->rip) return -1;
			ret->modrm = CHANGE_MODRM_RM(ret->modrm, reg);
		}
		break;
	case X_MODRM_FXD:
	case X_REG:
		{
			if (!ret->modrm_on) DIE("fuck");
			if (tup->f != reg_f && tup->f != rm_f) DIE(";....");

			ret->modrm =
				(tup->f==reg_f) ? CHANGE_MODRM_REG(ret->modrm, reg)
								: CHANGE_MODRM_RM(ret->modrm, reg);
		}
		break;
		default: return -1;
	}
	return 0;
}
