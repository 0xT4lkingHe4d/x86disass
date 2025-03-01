#include "../include/disass.h"
// had to stick it somewhere


static int x_tup_do_reg(instr_dat_t *ret, operand *p, regs_tuple_t *tup);
static int x_tup_do_seg(instr_dat_t *ret, operand *p, regs_tuple_t *tup);
static int x_tup_do_modrm(__u8 *ptr, instr_dat_t *ret, operand *p, regs_tuple_t *tup);


static __u8 modrm_enum_get_f(enum modrm_enum f, __u8 modrm) {
	switch(f) {
	// case mod: return ;
	case reg_f:	return MODRM_REG(modrm);
	case rm_f:	return MODRM_RM(modrm);
	default:	return -1;
	}
}

int handle_x_tup(__u8 *ptr, instr_dat_t *ret, operand *p, regs_tuple_t *tup) {
	memmove(&p->x_origin, tup, sizeof(regs_tuple_t));
	switch (tup->t) {
	case X_DEFAULT:	break;
	case X_REG:		return x_tup_do_reg(ret, p, tup);
	case X_SEG:		return x_tup_do_seg(ret, p, tup);
	case X_MODRM:	return x_tup_do_modrm(ptr, ret, p, tup);
	default:
		// TRAP();
		return 0;
	}
}

static int x_tup_do_reg(instr_dat_t *ret, operand *p, regs_tuple_t *tup) {
	typeof(ret->rex) *rex = &ret->rex;
	if (!ret->modrm_on)	return -1;
	__u8 bits = modrm_enum_get_f(tup->f, ret->modrm);
	if (bits==-1) 		return -1;
	// if (!p->is_ptr) {
		p->reg = reg_3bits_by_type(bits, tup->rgt, (tup->f==reg_f)?rex->b:(tup->f==rm_f)?rex->r:0);
	// }
	return 0;
}

static int x_tup_do_seg(instr_dat_t *ret, operand *p, regs_tuple_t *tup) {
	p->reg = gen_reg_change_scale(tup->reg, get_addr_size(ret));
	p->seg_reg = tup->seg;
	// cannot be overriden
	if (!tup->r) set_seg_reg(ret, p);
	if (tup->al) {
		// DBG("WELl");
		// TRAP();
	}
	return 0;
}


// 1 = ANY GP REGS
static int x_tup_do_modrm(__u8 *ptr, instr_dat_t *ret, operand *p, regs_tuple_t *tup) {
	int off = 0;
	if (!ret->modrm_on){
		ret->modrm_on=1;
		ret->modrm=*ptr;
		off++;
	}
	off += get_modrm_operands(ptr, ret, p);
	if (off <= -1) return -1;
	if (!p->is_ptr && p->reg && tup->m !=1 ) {	// ! any regs
		p->reg = reg_by_type(p->reg, tup->m);
	}
	return off;
}