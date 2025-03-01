#include <assert.h>
#include "../include/disass.h"


static __u32 modrm_rm_set(instr_dat_t *ret, __u8 sz) {
	return reg_3bits_by_size(MODRM_RM(ret->modrm), sz, ret->rex.b);
}

static __u32 just_get_reg(__u8 bits, __u8 sz, __u8 rexWRBX) {
	return reg_3bits_by_size(bits, sz, rexWRBX);
}

static __u8 set_oper_disp_sz(__u8 *ptr, instr_dat_t *ret, operand *oper) {
	switch (MODRM_MOD(ret->modrm)) {
		case 0b01:
			oper->disp_sz = 8;
			oper->disp[0] = ptr[0];			break;
		case 0b10:
			oper->disp_sz = 32;
			memcpy(&oper->disp, ptr, 4);	break;
		default:
			DIE("");
	}
	oper->is_ptr=1;
	return oper->disp_sz/8;
}

// #define pow(a, b) ({__u64 x=1; for (int i=0;i<b;i++) x*=a; (__u8)x;})
#define SIB_SCALE_REAL(sib) ({			\
		__u8 s = (((__u8)sib)&0xc0)>>6;	\
		__u64 ret=1;					\
		for (int i=0;i<s;i++) ret*=2;	\
		(__u8)ret;						\
})
#define S_SIB		0x900
// #define S			0x010
// #define I			0x020
// #define B			0x040
#define S_DISP8		0x001
#define S_DISP32 	0x004

#define S_SIB_GET_DISP(x) (x &0xf)
#define S_CHECK_FLAG(x) ((x & 0xf00) == S_SIB)
#define is_S(x) !!((x &0xf0) & S)
#define is_I(x) !!((x &0xf0) & I)
#define is_B(x) !!((x &0xf0) & B)

static int fix_sib(__u8 *ptr, __u16 f, operand *op, instr_dat_t *ret) {
	if (!(S_CHECK_FLAG(f))) return -1;

	op->sib.on = 1;
	op->is_ptr = 1;

	if (is_S(f)) op->sib.s		= SIB_SCALE_REAL(ret->sib);
	if (is_I(f)) op->sib.i_reg  = SIB_INDEX(ret->sib) + (!!ret->rex.x<<3) + REG_ON_4BIT;
	if (is_B(f)) op->sib.b_reg  = SIB_BASE(ret->sib)  + (!!ret->rex.b<<3) + REG_ON_4BIT;

	switch (S_SIB_GET_DISP(f)) {
		case S_DISP8:
			op->disp_sz = 8;
			op->disp[0] = ptr[0];			break;
		case S_DISP32:
			op->disp_sz = 32;
			memcpy(&op->disp, ptr, 4);	break;
		default:
			return 0;
	}
	return op->disp_sz/8;
}

static int sib_fix_instr(__u8 *ptr, instr_dat_t *ret, operand *oper) {
	__u16 flags = S_SIB;
	assert(ret->sib_on && ret->modrm_on);
	switch (MODRM_MOD(ret->modrm)) {
		case 0b00:
		{
			switch (SIB_INDEX(ret->sib)) {
				case 0b100:
					flags |= (SIB_BASE(ret->sib) == 0b101) ? S_DISP32 : B;
					break;
				default:
					flags |= (SIB_BASE(ret->sib)==0b101) ? (S|I | S_DISP32) : (S|I|B);
					break;
			}
		}
		break;
		case 0b10:
		case 0b01:
			__u8 disp_sz = (MODRM_MOD(ret->modrm)==0b10) ? S_DISP32 : S_DISP8;
			flags |= (SIB_INDEX(ret->sib) == 0b100) ? (S|B | disp_sz) : (S|I|B | disp_sz);
			break;
	}
	return fix_sib(ptr, flags, oper, ret);
}

int get_modrm_operands(__u8 *ptr, instr_dat_t *ret, operand *oper) {
	// DBGF("+%x\t\t%u\t\t+", *ptr, oper->sz, get_addr_size(ret));
	if (!ret->modrm_on) return -1;
	__u8 addr_sz =  get_addr_size(ret);
	
	switch (MODRM_MOD(ret->modrm)) {
		case 0b00:
		{
			switch (MODRM_RM(ret->modrm)) {
				case 0b100:
					return sib_fix_instr(ptr, ret, oper);
				case 0b101:
				{	// RIP fuckery
					oper->rip = addr_sz;
					oper->is_ptr=1;
					oper->disp_sz = 32;
					memcpy(&oper->disp, ptr, 4);
					return 4;
				}
				default:
					oper->is_ptr=1;
					oper->reg = modrm_rm_set(ret, addr_sz);
					return 0;
			}
		}
		break;
		case 0b01:
		case 0b10:
		{
			switch (MODRM_RM(ret->modrm)) {
				case 0b100:
					return sib_fix_instr(ptr, ret, oper);

				default:
					oper->reg = modrm_rm_set(ret, addr_sz);
			}
			return set_oper_disp_sz(ptr, ret, oper);
		}
		case 0b11:
			oper->reg = modrm_rm_set(ret, oper->sz);
			return 0;
	}
	return -1;
}

