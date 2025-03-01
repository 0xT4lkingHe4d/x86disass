#ifndef REGS_H
#include "./regs.h"
#endif

#ifndef X_TUP_H
#define X_TUP_H
enum modrm_enum {
	// mod_f=1,
	reg_f=2,
	rm_f=3,
};

#define X_DEFAULT	1
#define X_SEG		2
#define X_REG		3
#define X_MODRM		5
#define X_IMM		6
#define X_REG_OP	7
#define X_MODRM_FXD	8

typedef struct {
	int t;
	union {
		// reg tuple
		struct {
			enum modrm_enum f;
			enum regs_t_enum rgt;
		};
		// seg-reg
		struct {
			__u8 seg;	// SEG_DS
			__u8 *reg;	// change to 3bit - bin
			__u8 al;	// - always [rBX + AL]
			__u8 r;		// cannot be overriden
		};
		// MODRM
		__u32 m;
	};
} regs_tuple_t;
#endif