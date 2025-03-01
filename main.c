#include <stdio.h>
#include <sys/mman.h>
#include "./disass.h"

void main() {
	do_disass((void*)mmap, 0xd9);

	puts("==================================");

	instr_dat_t in;
	__u8 *sc = "\x48\x8d\x05\x9d\x3b\x00\x00";
	puts(" + Source instr");

	if (init_instr(X86_64, &in, sc) == -1) DIE("failed");
	pr_in_str(&in);

	__u64 v = 0;
	if (!get_rip_ptr_addr(&in, 0x1000, &v))
		printf("%s @ 0x1000 points to 0x%lx\n\n", get_instr_name(&in), v);

	puts(" + Modified");
	change_ptr(&in, 0x1337, CHNG_REL);
	pr_in_str(&in);

	__u8 ret[0x10] = {0};
	assemble(&in, ret);
}
