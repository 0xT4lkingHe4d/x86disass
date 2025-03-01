#define DISASS_H_PFX
#include "../include/disass.h"
#undef DISASS_H_PFX

#include <string.h>

#define MAX_PF_COUNT 4


__s8 list_contains(__u8 *list, size_t limit, __u8 a) {
	for (int i = 0; i < limit; i++)
		if (a == list[i]) return 1;
	return 0;
}

static int set_pfx(__u8 *ptr, __u16 pf) {
	if (!!pf && pf != -1) {*ptr = pf; return 0;};
	return -1;
}


// check if fits, is repeated, pfx group is repeated
__u16 pfx_lst_fits(__u8 b, __u8 *pflist, size_t list_len, int c, __u8 *pfx) {
	for (int i = 0; i < list_len; i++) {
		__u8 pf = pflist[i];

		if (b == pf) {
			for (__u8 l=0; l<c; l++) {
				if ((pfx[l] == pf) || list_contains(pflist, list_len, pfx[l]))
					return -1;
			}
			set_pfx(&pfx[c], pf);
		}
	}
	return 0;
}


__u16 pfx_fits(__u8 b, __u8 pf, int c, __u8 *pfx) {
	if (b == pf) {
		for (__u8 l=0; l<c; l++) {
			if (pfx[l] == pf)
				return -1;
		}
		set_pfx(&pfx[c], pf);
	}
	return 0;
}


int decode_prefix(__u8 *ptr, instr_dat_t *ret) {
	__u8 *pfx = (__u8*)&ret->pfx;
	__u8 len = 0;

	memset(pfx, 0, MAX_PF_COUNT);	// shall be memset to 0
	for (__u8 c = 0; c < MAX_PF_COUNT; c++, len++) {
		if (c > 0 && pfx[c-1]==0) {		// previous not set
			goto ret;
		}
		/* LOCK / REP / REPZ / REPNE */
		if (pfx_lst_fits(ptr[c], pf1_list, PF1_LIST_LEN, c, pfx))
			return -1;
		/* Segment overrides & branch taken / branch not taken */
		if (pfx_lst_fits(ptr[c], pf2_list, PF2_LIST_LEN, c, pfx))
			return -1;
		/* Operand size override */
		if (pfx_fits(ptr[c], 0x66, c, pfx))
			return -1;
		/* Address size override */
		if (pfx_fits(ptr[c], 0x67, c, pfx))
			return -1;

		// got here.
		if (!pfx[c])
			break;

		if (ptr[c] == ptr[c+1]) {
			ptr++;
			len++;
		}
	}

	ret:
		return len;
}