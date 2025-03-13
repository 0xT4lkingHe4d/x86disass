#include <assert.h>
#include <string.h>

#define DISSAS_H
#include "../include/disass.h"
#undef DISSAS_H

#include "../include/operands.h"

static __u8 decode_opcode_pf(__u8 *ptr, instr_dat_t *ret) {
	__u8 c = 0;

	if (ptr[c]==0x66 || ptr[c]==0xf2 || ptr[c]==0xf3)	// Mandatory prefix
		ret->man_pfx = ptr[c++];

	if (IS_VALID_REX(ptr[c])) {		// REX pf
		ret->rex = (typeof(ret->rex)){
			.w = REX_W_BIT(ptr[c]),
			.r = REX_R_BIT(ptr[c]),
			.x = REX_X_BIT(ptr[c]),
			.b = REX_B_BIT(ptr[c++]),
		};
		ret->rex_on=1;
	}

	if (ptr[c] == 0x0F) {			// 0F / two byte
		ret->op[ret->op_len++] = 0x0F;
		c++;
	}

	return c;
}

static int init_instr_pfx(__u8 *cpy, instr_dat_t *ret) {
	__u8 *base = cpy;
	int pfx_off = decode_prefix(cpy, ret);
	if (pfx_off < 0) return -1;
	cpy += pfx_off;
	cpy += decode_opcode_pf(cpy, ret);
	return cpy - base;
}

// returns 2 if SIB is on
static __u8 set_modrm(__u8 *ptr, instr_dat_t *ret) {
	SET_MODRM(*ptr, ret);

	if (MODRM_MOD(*ptr)!=0b11 && MODRM_RM(*ptr)==0b100) {
		SET_SIB(*(ptr+1), ret);
		return 2;
	}
	return 1;
}


static void zero_ret_instr(instr_dat_t *ret) {
	if (ret->op[0]==0x0f) {
		memset(&ret->op[1], 0, 2);
		ret->op_len=1;
	} else {
		memset(ret->op, 0, 3);
		ret->op_len=0;
	}
	ret->reg_op = 0;
	ret->insn	= NULL;
}

static __u8 decode_opcode(__u8 *ptr, instr_dat_t *ret, const instr *min) {
	if (!!min) zero_ret_instr(ret);
	assert(ret->op_len < 2);

	__u8 ndx = ret->op_len++, modrm_off=0, off=0;
	instr *pick = find_instr(ptr, ret, *ptr, min);

	// might be a +r instr - fixed last 3bits
	if (pick == NULL) {	// +r
		ret->op[ndx] = (*ptr & 0b11111000);
		ret->reg_op	 = (*ptr & 7);
		pick = find_instr(ptr, ret, (ret->op[ndx]), min);
		if (!pick) {
			ret->pfx[strlen(ret->pfx)] = ret->op[ndx];
			ret->op[ndx] = ptr[1];
			pick = find_instr(ptr, ret, (ret->op[ndx]), min);
		}
	} else {
		ret->op[ndx] = *ptr;
	}
	if (pick == NULL) return -1;	// The heck happend

	ret->insn = pick;
	off = (pick->opcode2==0) ? 1 : 2;

	if (!!pick->reg_op) {		// init modrm
		off += set_modrm(ptr + ((!pick->opcode2) ? 1 : 2), ret);
	}

	return off;
}

#define instr_ident_same(a,b) (		\
	((	a->prefix == b->prefix	&&	\
		a->opcode1== b->opcode1 &&	\
		a->opcode2== b->opcode2 &&	\
		a->reg_op == b->reg_op) ? 1:0))

__u64 get_low(__u8 t, __u8 _0f, __u8 op) {
	__u64 low	= (_0f == 0x0F) ? 464 : 0;
	__u64 high	= (_0f == 0x0F) ? MAX_TABLE_NDX(t) : 464;
	while((__s64)(high-low) > 1) {
		__u64 mid = low + (high-low) / 2;
		const instr *i = &INSTR_TABLE(t)[mid];
		__u8 v = (i->prefix && !i->opcode1) ? i->prefix : i->opcode1;

		if (v >= op) high = mid;
		else low = mid;
	}
	return low;
}

// __u64 get_right(__u8 _0f, __u8 op) {
// 	__u64 low	= (_0f == 0x0F) ? 464 : 0;
// 	__u64 high	= (_0f == 0x0F) ? MAX_TABLE_NDX : 464;
// 	while((__s64)(high-low) > 1) {
// 		__u64 mid = low + (high-low) / 2;
// 		const instr *i = &tabl[mid];
// 		// If is prefix - use prefix
// 		__u8 v = (i->prefix && !i->opcode1) ? i->prefix : i->opcode1;
		
// 		if (v <= op) low = mid;
// 		else high = mid;
// 	}
// 	return high;
// }

static instr *find_instr(__u8 *ptr, instr_dat_t *ret, __u8 op, const instr *min) {
	const instr *iter = NULL, *pick = NULL;
	int keep = 0;
	__u8 l3bits = ret->reg_op;
	__u64 l = get_low(ret->type, ret->op[0], op);
	// __u64 r = get_right(ret->op[0], op);
	if (!(iter = &INSTR_TABLE(ret->type)[l])) return NULL;
	if (iter->opcode1 != op && (++iter)->opcode1 != op)
		return NULL;

	while (iter->opcode1 == op && iter != INSTR_TABLE(ret->type)) iter--;
	while ((++iter)->opcode1 == op) {
		if (iter->prefix)
			if (!list_contains(ret->pfx, sizeof(ret->pfx), iter->prefix))
				continue;

		if (!!min && (void*)iter <= (void*)min) continue;

		// +r 	-	6 cases
		if (!!( iter->flds )) {
			pick = ((iter+1)->opcode1 != op || !!l3bits) ? iter : iter+1;
			break;
		}
		// sec op 	- 	opcode2 fits, reg_op fits
		if (!!iter->opcode2 && iter->opcode2 == *(ptr+1)) {
			if (MODRM_CMP_REG(iter->reg_op, *(ptr+2))) {
				pick = iter;
				break;
			}
			if (keep < 3) {
				pick = iter; keep=3;
				continue;
			}
		} else if (iter->reg_op && MODRM_CMP_REG(iter->reg_op, *(ptr+1))) {
			pick = iter;
			break;
		}
		// keep=2, no opcode 2, reg_op fits
		if (keep < 2 && (( !iter->reg_op && !(*(ptr+1)&7) )
			|| list_contains(ret->pfx, INST_MAX_PFX, iter->prefix)))
		{
			pick = iter;	keep=2;
			continue;
		}

		// default
		if ((!iter->reg_op || iter->reg_op==F_MODRM) && !keep ) {
			pick = iter;	keep=1;
			continue;
		}
	}
	instr *a=pick, *b=(pick+1);
	if (a && b && (a->m || b->m)) {
		if (instr_ident_same(a, b)) {
			pick = (a->m==MODOP_E) ? a : b;
		}
	}
	return pick;	// (null)
}

static int set_f_oper(instr_dat_t *in, operand *ret, oper_st *op) {
	switch(GET_F_OPER(op->f)) {
		case F_OPER_B:
			{	// Byte, regardless.
				ret->sz = _BYTE_;
				return OPER_FITS;
			}
		case F_OPER_WS:
		case F_OPER_W:
			{	// Word, regardless.
				ret->sz = _WORD_;
				return OPER_FITS;
			}
		case F_OPER_D:
			{	// Doubleword, regardless.
				ret->sz = _DWORD_;
				return OPER_FITS;
			}
		case F_OPER_Q:
		case F_OPER_QS:
			{	// Quadword, regardless.
				ret->sz = _QWORD_;
				return OPER_FITS;
			}
		case F_OPER_DQ:
			{	// Double-quadword, regardless.
				ret->sz = _DQWORD_;
				return OPER_FITS;
			}
		case F_OPER_QP:
			{	// Quadword, promoted by REX.W
				if (in->rex.w) {
					ret->sz = _QWORD_;
					return OPER_FITS_XCLUSIVELY;
				}
				return OPER_BAD_FIT;	// return BAD FIT
			}
		// UNTESTED
		case F_OPER_DQP:
			{	// Doubleword or Quadword-promoted by REX.W
				ret->sz = (in->rex.w) ? _QWORD_ : _DWORD_;
				return OPER_FITS;
			}
		case F_OPER_VQ:
			{	// Quadword (default) or word if operand-size prefix is used
				ret->sz = inst_op_pfx_rexw(in) ?  _WORD_ : _QWORD_;
				return OPER_FITS;
			}
		case F_OPER_VQP:
			{
				ret->sz = get_oper_size(in);
				return OPER_FITS;
			}
		case F_OPER_VDS:	// not tested
			{
				__u8 size = get_oper_size(in);
				ret->sz 		= (size==_QWORD_) ? _DWORD_ : size;
				ret->sign_ext	= size;
				return OPER_FITS;
			};
		case F_OPER_V:
			{
				// return OPER_BAD_FIT;
				ret->sz = inst_op_pfx_rexw(in) ? _WORD_ : _DWORD_;
				return OPER_FITS;
			}
		case F_OPER_WI:// X87 FPU
		case F_OPER_WO:
			{	// if it's Word sized
				if (get_oper_size(in) == _WORD_) {
					ret->sz = _WORD_;
					return OPER_FITS_XCLUSIVELY;
				}
				return OPER_BAD_FIT;
			}
		case F_OPER_SR:// Single-real
		case F_OPER_DI:// X87 FPU
		case F_OPER_DO:
			{	// if it's Doubleword
				if (get_oper_size(in) == _DWORD_) {
					ret->sz = _DWORD_;
					return OPER_FITS_XCLUSIVELY;
				}
				return OPER_BAD_FIT;
			}
		case F_OPER_DR:// Double-real
		case F_OPER_QI:// X87 FPU
			{
				if (get_oper_size(in) == _DWORD_) {
					ret->sz = _QWORD_;
					return OPER_FITS_XCLUSIVELY;
				}
				return OPER_BAD_FIT;
			}
		case F_OPER_ER:	// Extented-real - 2cases only neither matters
		case F_OPER_BCD: // Packed-BCD
			{
				ret->sz = _TBYTE_;
				return OPER_FITS_XCLUSIVELY;
			};
		//// untested
		case F_OPER_E:	// x87 FPU environment
		case F_OPER_ST:	// x87 FPU state
		case F_OPER_STX:	// x87 FPU and SIMD state
			{	// x87 FPU environment (for example, FSTENV)
				ret->sz = get_oper_size(in);
				return OPER_FITS;
			}
		case F_OPER_PS:	// 128-bit packed single-precision floating-point data.
		case F_OPER_PD:	// 128-bit packed double-precision floating-point data.
			{
				ret->sz = _XMMWORD_;
				ret->xmm.precision = (GET_F_OPER(op->f)==F_OPER_PS)?_SG_PREC_:_DBL_PREC_;
				return OPER_FITS;
			}
		case F_OPER_PSQ:
			{
				ret->sz = _QWORD_;
				ret->xmm.precision = _SG_PREC_;
				return OPER_FITS;
			}
		case F_OPER_SD:	// Scalar element of a 128-bit packed double-precision floating data.
		case F_OPER_SS:	// Scalar element of a 128-bit packed single-precision floating data.
			{
				ret->sz = _XMMWORD_;
				ret->xmm.scalar_on = 1;
				ret->xmm.precision = (GET_F_OPER(op->f)==F_OPER_SS)?_SG_PREC_:_DBL_PREC_;
				return OPER_FITS;
			}
		case F_OPER_PTP:	// 32-bit or 48-bit pointer, depending on operand-size attribute
			{
				ret->sz = (inst_op_pfx_rexw(in)) ? _DWORD_ : _FWORD_;
				return OPER_FITS;
			}
		case F_OPER_PI:	// Qword MMX
			{
				ret->reg_t = MMX;
				ret->sz = _QWORD_;
				return OPER_FITS;
			}
		case F_OPER_BS:	// byte sign-extended to size of dest
			{
				ret->sz = _BYTE_;
				ret->sign_ext = _SIGN_EXT_TO_DEST_SIZE_;
				return OPER_FITS;
			}
		case F_OPER_S:	// SGDT
			{
				ret->sz = _SGDT_;
				return OPER_FITS;
			}
		case F_OPER_BSS:
			{
				ret->sz = _BYTE_;
				ret->sign_ext = _QWORD_;
				return OPER_FITS;
			}
		case F_OPER_VS:
			{
				ret->sz = (inst_op_pfx_rexw(in)) ? _WORD_ : _DWORD_;
				ret->sign_ext = _QWORD_;
				return OPER_FITS;
			}
		default:
			ret->sz = 0xcc;
	}
	return OPER_BAD_FIT;
}

/// REX.W + 66 = data16


__u8 oper_st_type(oper_st *op) {
	if (op->f)		return OPER_FLAGS;
	if (op->reg)	return OPER_REGS;
	if (op->v)		return OPER_VALUE;
	return OPER_NULL;
}


static void parse_oper_flags(instr_dat_t *in, oper_st src[4], struct op_int_st dst[4]) {
	oper_st *op_iter = NULL;
	int i=0;

	foreach_oper_st(op_iter, src, i) {
		// if (*(__u8*)op_iter == 0) TRAP();
		switch (oper_st_type(op_iter)) {
			case OPER_FLAGS:
			{		// F_ADDR_M | F_OPER_VDS
				if (!GET_F_OPER(op_iter->f)) {
					dst[i].op.sz	= get_oper_size(in);
					dst[i].ret		= OPER_FITS;
					return;
				}
				dst[i].ret = set_f_oper(in, &dst[i].op, op_iter);
				break;
			}
			case OPER_REGS:
			{
				__u8 *reg = op_iter->reg;
				__s16 reg_sz = get_gp_reg_size(reg);

				if (!strncmp(reg, "X86_GDTR", strlen(reg))) break;
				if (!strncmp(reg, "X86_IDTR", strlen(reg))) break;
				if (!strncmp(reg, "X86_LDTR", strlen(reg))) break;

				if (!strncmp(reg, "MSR", strlen(reg)))  break;
				if (!strncmp(reg, "MSW", strlen(reg)))  break;
				if (!strncmp(reg, "PMC", strlen(reg)))  break;
				if (!strncmp(reg, "TR", strlen(reg)))   break;

				if (!strncmp(reg, "ST", 3)) {
					dst[i].ret		= OPER_FITS;
					dst[i].op.reg	= F_ANY_REGS_FPU_X86;
					break;
				}
				dst[i].ret		= OPER_FITS;
				if (reg_sz > 0) {
					if (get_oper_size(in) == (__u8)reg_sz) {
						dst[i].ret	= OPER_FITS_XCLUSIVELY;
					}
				}
				dst[i].op.reg	= anyreg_by_name(reg);
				assert(!!dst[i].op.reg); /*"You fucked with the table"*/
				break;
			}
			case OPER_VALUE:
			{
				__u64 v = op_iter->v;
				// .v=1, .v=3
				if (v < 10) {
					dst[i].op.v = v;
					dst[i].ret	= OPER_FITS;
					break;
				}
				// switch (v) {
				if (v==X86_FPU_ANY) {
					if(!in->modrm_on) DIE("-");
					if (MODRM_MOD(in->modrm)!=0b11) {
						dst[i].ret 	= OPER_BAD_FIT;
						break;
					}
					dst[i].op.reg	= reg_3bits_by_type(MODRM_RM(in->modrm), FPU_X86, 0);
					dst[i].ret		= OPER_FITS;
					break;
				}
				// if (v==NO) {	// global desc table instructions
				dst[i].ret=OPER_BAD_FIT;
			}
			break;
		}
	}
}

static int parse_feech(instr *inst, instr_dat_t *ret, __u8 start) {
	x86_in_ops *iter = NULL;
	__u8 ndx = 0;
	int real = -1, i = 0;

	for_each_ops(iter, inst, ndx) {
		if (ndx < start) { continue; }

		struct op_int_st out[4] = {0};
		int x=0, bad=0, fit=0;
		parse_oper_flags(ret, iter->op, out);

		for(int i=0;i<4;i++) {
			switch(out[i].ret) {
				case OPER_FITS:		fit++;	break;
				case OPER_BAD_FIT:	bad++;	goto next;
				case OPER_FITS_X:	x++;	break;
				default:
					out[i].op.is_empty=1;
			}
		}
		// DBG("- %x FIT%X, X%x\n", ndx, fit, x);
		if (x || fit) {
			_memcpy_op_int(ret->oper, out);
			if (x) 	 return ndx;
			if (fit) real = ndx;
		}

		next:
		continue;
	}

	return real;
}


static int parse_seech(instr *inst, instr_dat_t *ret) {
	struct op_int_st out[4] = {0};
	parse_oper_flags(ret, inst->op, out);

	foreach(i, 4) {
		if (out[i].ret == OPER_BAD_FIT) {
			return -1;
		}
		if (!out[i].ret) {
			out[i].op.is_empty=1;
		}
	}
	foreach(i, 4) {
		memcpy(&ret->oper[i], &out[i].op, sizeof(operand));
	}

	return 0;
}

static int parse_operands(instr_dat_t *ret, __u8 start) {
	assert(ret->insn!=NULL);
	instr *inst = ret->insn;

	return (!!inst->ops_count) ?
			parse_feech(inst, ret, start) : parse_seech(inst, ret);
}





typedef regs_tuple_t x;

#define unlikely(x)		__builtin_expect(!!x, 0)

#define GET_OPER_BY_NDX(in, ndx) (oper_st*)(!in->ops_count ? &in->op : &in->ops[ndx].op)
static int parse_addressing(__u8 *ptr, instr_dat_t *ret) {
	__u16 ndx = ret->op_ndx;

	void *base = ptr;
	if (ret->insn == NULL || BAD_OPS_INDEX(ndx)) {
		return -1;
	}
	oper_st *ops = (oper_st*)GET_OPER_BY_NDX(ret->insn, ndx);
	typeof(&ret->rex) rex = &ret->rex;

	oper_st *iter = NULL;
	int i=0;
	/* * FUCK - make clear - instr-DEFINITION & return instr_dat
	*/
	foreach_oper_st(iter, ops, i) {
		if (!iter->f) { continue; }
		// printf("%lx -\n", iter->f);
		// PR_INSTR(ret->insn);

		operand *p = &ret->oper[i];	// operand [i]
		regs_tuple_t tup = {0};

		__u8 sz = p->sz;
		switch (GET_F_ADDR(iter->f)) {
			case F_ADDR_G:
			{
				// if (!ret->modrm_on) ret->modrm=*ptr; 0f 1e fa
				if (!ret->modrm_on) return -1;
				p->reg = reg_3bits_by_size(MODRM_REG(ret->modrm), sz, rex->r);
				tup = (x){ .t=X_MODRM_FXD, .f=reg_f };
				break;
			}
			case F_ADDR_R:	// mod - only gp register
			case F_ADDR_H:
			{
				// if (!ret->modrm_on) ret->modrm=*ptr; 0f 1e fa
				if (!ret->modrm_on) return -1;
				p->reg = reg_3bits_by_size(MODRM_RM(ret->modrm), sz, rex->b);
				tup = (x){ .t=X_MODRM_FXD, .f=rm_f };
				break;
			}
			case F_ADDR_Z:	/* No MODRM - 3 low bits - gp reg */
				p->reg = reg_3bits_by_size(ret->reg_op, sz, rex->b);
				tup = (x){ .t=X_REG_OP };
				break;
			/**
			 * MOD/REG/RM - selects different register type
			 */
			case F_ADDR_V:	tup = (x){ .t=X_REG, .rgt=XMM,  .f=reg_f }; break;
			case F_ADDR_U:	tup = (x){ .t=X_REG, .rgt=XMM,  .f=rm_f  };	break;
			case F_ADDR_N:	tup = (x){ .t=X_REG, .rgt=MMX,  .f=rm_f  };	break;
			case F_ADDR_D:	tup = (x){ .t=X_REG, .rgt=DBG32,.f=reg_f };	break;
			case F_ADDR_P:	tup = (x){ .t=X_REG, .rgt=MMX,  .f=reg_f };	break;
			case F_ADDR_S:	tup = (x){ .t=X_REG, .rgt=SEG16,.f=reg_f };	break;
			case F_ADDR_C:	tup = (x){ .t=X_REG, .rgt=CTL32,.f=reg_f };	break;
			/**
			 * MODRM - register || memory address */
			case F_ADDR_M:	/* mod != 0b11 */
				if (MODRM_MOD(ret->modrm)==0b11) return -1;
				// .m=1 = any gp regs
			case F_ADDR_E:	tup = (x){ .t=X_MODRM, .m=1 };			break;
			case F_ADDR_ES:	tup = (x){ .t=X_MODRM, .m=FPU_X86 };	break;
			case F_ADDR_Q:	tup = (x){ .t=X_MODRM, .m=MMX };		break;
			case F_ADDR_W:	tup = (x){ .t=X_MODRM, .m=XMM };		break;
			/**
			 * Addressed by Seg Regs : gp reg
			 */
			case F_ADDR_X:	tup = (x){.t=X_SEG, .seg=SEG_DS, .reg="RSI"}; 		break;
			case F_ADDR_Y:	tup = (x){.t=X_SEG, .seg=SEG_ES, .reg="RDI", .r=1};	break;
			case F_ADDR_BA:	tup = (x){.t=X_SEG, .seg=SEG_DS, .reg="RAX"};		break;
			case F_ADDR_BB:	tup = (x){.t=X_SEG, .seg=SEG_DS, .reg="RBX", .al=1};break;
			case F_ADDR_BD:	tup = (x){.t=X_SEG, .seg=SEG_DS, .reg="RDI"}; 		break;

			case F_ADDR_J:	p->rip = _QWORD_;	// 64bit 	p->is_ptr=1;
			case F_ADDR_I:
			{
				__u8 len = (sz/8);
				if(len > 8) {DBG("Its fucked"); return -1;}
				memmove_ptr_add(&p->imm, &ptr, len);
				p->is_imm=1;
				tup = (x){ .t=X_IMM };
				break;
			}
			case F_ADDR_O:	p->is_ptr=1;
			{
				// if (!inst_has_pfx(ret, 0x67)) return -1;
				memmove_ptr_add(&p->imm, &ptr, 4);
				tup = (x){ .t=X_IMM };
				p->is_imm=1;
				break;
			}
			case F_ADDR_F:
				p->rflags=1;	break;
			default:
				tup = (x){.t=X_DEFAULT};
				// TRAP();
		}
		
		int off = handle_x_tup(ptr, ret, p, &tup);
		if (off == -1) return -1;
		ptr += off;

		// segment overrides
		if (p->is_ptr && !p->seg_reg)
			set_seg_reg(ret, p);
		
		// assert((ret->modrm_on && ret->sib_on) ? (!p->reg) : 1);

	}
	// DBG("++=");

	return (int)((void*)ptr-base);
}




static int init_op_flags(__u8 *cpy, const __u8 *b, instr_dat_t *ret) {
	__u8 *saved = cpy;
	__u8 c=0;
	int r=parse_addressing(saved, ret);
	
	while (r==-1 && c < ret->insn->ops_count) {
		saved = cpy;
		c++;
		// pr("...");
		memset(ret->oper, 0, sizeof(operand[4]));
		ret->op_ndx = parse_operands(ret, c);
		r=parse_addressing(saved, ret);
	}

	// printf("cpy = %lx ; base = %lx (cpy-base = %lx) ; r = %lx from disass\n", cpy, b, cpy-b, r);
	ret->in_sz = cpy+r-b;
	return (r==-1) ? -1 : 0;
}

int init_instr(__u8 t, instr_dat_t *ret, void *base) {
	*ret = (instr_dat_t){.type = t, 0};
	__u8 *cpy = base;
	__s8 off = init_instr_pfx(cpy, ret);
	if (off == -1) return -1;
	cpy += off;

	// saved if this fails
	const __u8 *saved_cpy = cpy;
	instr_dat_t saved_ret = *ret;

	instr_dat_t *min = NULL;	// to move forward from bad fits
	foreach(i, 30) {
		cpy = saved_cpy;
		memcpy(ret, &saved_ret, sizeof(instr_dat_t));
		// check if fits
		__u8 dec_op_off = decode_opcode(cpy, ret, min);
		if ((__s8)dec_op_off == -1) return -1;

		cpy += dec_op_off;
		min = ret->insn;
		ret->op_ndx = parse_operands(ret, 0);

		// break, all good;
		if (!BAD_OPS_INDEX(ret->op_ndx)) {
			if (init_op_flags(cpy, base, ret) == -1) continue;
			break;
		}
	}
	return 0;
}


void do_disass(__u8 *ptr, uint b) {
	void *base = ptr;

	__u32 l = 0;

	while (l < b) {
		instr_dat_t in = {0};
		if (!!init_instr(X86_64, &in, ptr)) return;
		prf("0x%06x:   ", l);
		pr_in_str(&in);

		ptr += in.in_sz;
		l += in.in_sz;
	}
}
