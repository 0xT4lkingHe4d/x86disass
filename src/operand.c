#include "../include/disass.h"

void _memcpy_op_int(operand dst[4], struct op_int_st src[4]) {
	int i = 0;
	foreach(i, 4) {
		memcpy(&dst[i], &src[i].op, sizeof(operand));
	}
}

void memmove_ptr_add(void *dst, __u8 **ptr, size_t sz) {
	memmove(dst, *ptr, sz);
	*ptr += sz;
}

__u8 inst_has_pfx(instr_dat_t *in, __u8 pfx) {
	return list_contains(in->pfx, INST_MAX_PFX, pfx);
}


// #define pfx_list_sz 6
static __u8 get_seg_override(instr_dat_t *in) {
	__u8 pfx_list[6] = {0x2e,0x36,0x3e,0x26,0x64,0x65};

	for (int i=0; i < sizeof(pfx_list); i++)
		if (inst_has_pfx(in, pfx_list[i]))
			return pfx_list[i];

	return 0;
}


void set_seg_reg(instr_dat_t *in, operand *op) {
	__u8 pfx = get_seg_override(in);
	if (!!pfx) op->seg_reg = pfx;
}



__u8 inst_op_pfx_rexw(instr_dat_t *in) {
	return !in->rex.w && list_contains(in->pfx, INST_MAX_PFX, 0x66);
}

__u8 get_oper_size(instr_dat_t *in) {
	if (in->rex.w) return _QWORD_;
	return inst_has_pfx(in, 0x66) ? _WORD_ : _DWORD_;
}

__u8 get_addr_size(instr_dat_t *in) {
	if (inst_has_pfx(in, 0x67)) return _DWORD_;
	return _QWORD_;
}