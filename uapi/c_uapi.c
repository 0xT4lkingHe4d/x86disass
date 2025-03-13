#include <linux/types.h>
#include "../include/uapi.h"
#include <stdlib.h>

// Linker errors
#define __extern(fn) typeof((fn)) (*c_##fn) = (void*)(fn);
__extern(reg_by_name);
__extern(get_reg_name);
__extern(reg_by_val);
__extern(init_instr);
__extern(get_oper_sz);
__extern(get_instr_name);
__extern(get_rip_oper);
__extern(pr_in_str);

__u64 c_ptr_val(instr_dat_t *in, __u64 off) {
	__u64 v = 0;
	return !(get_rip_ptr_addr(in, (void*)off, &v)) ? v : -1;
}

__u64 c_operptr(instr_dat_t *in, operand *op) {
	__u64 v=0;
	__u8 plmin = get_operand_ptr(in, op, &v);
	
	if (plmin == -1) return -1;
	return ((plmin == u'-') ? (__s64)( -( ~v+1 ) ) : v);
}