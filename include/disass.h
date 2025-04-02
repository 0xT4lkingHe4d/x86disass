#include <linux/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./def.h"
#include "./utils.h"
#include "./x_tuple.h"

#ifndef DISASS_X86_H
#define DISASS_X86_H
#define X86_64	1
#define X86		2
#ifndef REGS_H
#include "./regs.h"
#endif



#define INSTR_TABLE(t)	(((t) == X86) ? x86_tabl : x86_64_tabl)

#define DO_DEBUG

#ifdef DO_DEBUG
	#define DBG(...) {												\
			if (sizeof((void*[]){__VA_ARGS__})==sizeof(void*)) {	\
				printf("%s\n", __VA_ARGS__);						\
			} else {												\
				printf(__VA_ARGS__);								\
				puts("");											\
			}														\
	}
	#define DBGF(s, ...) { printf(s, __VA_ARGS__); }

#else
	#define DBG(...) {}
	#define DBGF(...) {}
#endif


#define DIE(str) ({												\
		puts("");												\
		fprintf(stderr, "[---] ERROR %s - @%s line %lu    %s\n",\
				__FILE__, __FUNCTION__, __LINE__, str);			\
		exit(-1);												\
})


// #ifndef DISASS_H_STRUCT
	#define __get_tabl_ndx(t, ptr) (((void*)ptr - (void*)(INSTR_TABLE((t)))) / sizeof(instr))
	#define MAX_TABLE_NDX(t) ((t==X86) ? (sizeof(x86_tabl)/sizeof(instr)-1) : (sizeof(x86_64_tabl)/sizeof(instr)-1))

	#define for_each_instr(t, l) \
			for (l = &INSTR_TABLE(t)[0]; l <= &INSTR_TABLE(t)[MAX_TABLE_NDX(t)]; l++)

	// binary search
	#define for_each_op(t, l, _0f, op, pfx_list)									\
				for_each_instr(t, l)												\
				if (((_0f==0x0F && l->two_byte) || (_0f!=0x0F && !l->two_byte))	\
					&& ((!!l->prefix) ? (list_contains(pfx_list, sizeof(pfx_list), l->prefix)) : 1)	\
					&& ((!l->prefix && (!op) ? 1 : !!l->opcode1) && l->opcode1==op))
					// opcode2
	#define foreach_operand(p, in)										\
		for(operand *p = &(in)->oper[0]; p <= &(in)->oper[3]; p++)	\
			if (!p->is_empty)

// #endif

#define MODRM_MOD(a)	(__u8)(( a & 0b11000000 ) >> 6 )
#define MODRM_REG(a)	(__u8)(( a & 0b00111000 ) >> 3 )
#define MODRM_RM(a)		(__u8) ( a & 0b00000111 )

#define MODRM_CMP_REG(a, b) (((a=='0')?0:a)==MODRM_REG(b))

// #define SET_REG_OP(ret, x) (ret->reg_op=(x & 0b00000111) | 0x10)
#define SIB_SCALE(a) (__u8)(( a & 0b11000000 ) >> 6 )
#define SIB_INDEX(a) (__u8)(( a & 0b00111000 ) >> 3 )
#define SIB_BASE(a)	 (__u8) ( a & 0b00000111 )


#define S	0x010
#define I	0x020
#define B	0x040


#define SET_MODRM(b, ret) {	\
	ret->modrm = b;			\
	ret->modrm_on = 1;		\
}
#define SET_SIB(b, ret) {	\
		ret->sib = b;		\
		ret->sib_on = 1;	\
}


#define IS_VALID_REX(a) !!((a&0xf0)==0x40)

#define REX_B_BIT(rex) ((rex & 1) >> 0)
#define REX_X_BIT(rex) ((rex & 2) >> 1)
#define REX_R_BIT(rex) ((rex & 4) >> 2)
#define REX_W_BIT(rex) ((rex & 8) >> 3)

#define REX_SET_EMPTY(rex_ptr) *(__u8*)rex_ptr = 0xff



#define UNSET_PTR 0x10
#define _BYTE_  8
#define _WORD_  16
#define _DWORD_ 32
#define _QWORD_ 64
#define _TBYTE_ 80
#define _DQWORD_ 128
#define _FWORD_ 48
#define _MMXWORD_ 64
#define _XMMWORD_ 128
#define _YMMWORD_ 0xff
#define _SGDT_ 0xde

#define _SG_PREC_ 0x1		// float
#define _DBL_PREC_ 0x2		// double

#define _SIGN_EXT_TO_DEST_SIZE_ 0x93

typedef struct {
		__u8 is_empty;
		// __u8 ptr_sz;	// word, dword, qword
		__u8 is_ptr;
		__u8 disp_sz;
		__u8 disp[4];

		__u8 imm[8];
		__u8 is_imm;

		#pragma pack(1)
		struct {
			__u8 on;
			__u8 s;
			__u8 i_reg;
			__u8 b_reg;
		} sib;
		#pragma pack()
		__u8 	v;

		__u32 reg;	// register
		enum regs_t_enum reg_t;

		__u8 seg_reg;

		__u8 sz;	// _WORD_, _QWORD_, 

		/* If it is sign-extended (-1) then ---+ */
		__u8 sign_ext;
		struct {
			__u8 precision;
			__u8 scalar_on;	// using half of what it should be
		} xmm;				// xmm (128) - use (64) If double, single=32


		__u8 rflags;

		__u8 rip;	// 32 / 64 for EIP / RIP

		regs_tuple_t x_origin;
} operand;


#define INST_MAX_PFX 4+1

typedef struct {
	__u8	type;
	__u8 	pfx[INST_MAX_PFX];

	#pragma pack(1)
		struct {
			__u8 w;
			__u8 r;
			__u8 x;
			__u8 b;
		} rex;
		__s8 rex_on;
	#pragma pack()

	__u8 	reg_op;	// +r / 0xb0, 1..7

	__u8 	man_pfx;
	__u8 	op[3];
	__u8 	op_len;

	struct {
		__u8	modrm;
		__s8	modrm_on;
		__u8	sib;
		__s8	sib_on;
	};

	operand oper[4];

	const instr *insn;
	__u8 op_ndx;
	__u8 in_sz;
} instr_dat_t;
#pragma pack()

#define SEG_CS	0x2e
#define SEG_SS	0x36
#define SEG_DS	0x3e
#define SEG_ES	0x26
#define SEG_FS	0x64
#define SEG_GS	0x65

#ifdef DISASS_H_PFX
	// #define PF_LIST_SZ 28
	#define PF1_LIST_LEN 3
	#define PF2_LIST_LEN 6
	__u8 pf1_list[PF1_LIST_LEN] = {0xf0/*LOCK*/, 0xf2/*REPNZ*/, 0xf3/*REP OR REPZ*/};
	__u8 pf2_list[PF2_LIST_LEN] = {
	    0x2e,	// CS segment override	Also		Branch not taken
	    0x36,	// SS segment override
	    0x3e,	// DS segment override	Also		Branch taken 
	    0x26,	// ES segment override
	    0x64,	// FS segment override
	    0x65,	// GS segment override
	};
	#define OPER_SZ_OVERRIDE_PF 0x66;
	#define ADDR_SZ_OVERRIDE_PF 0x67;


#endif

#define REG_ON_4BIT 0x10

void pr_in_str(instr_dat_t *ret);
__u64 _pow(__u8 a, __u8 b);

#define OPER_NULL	0
#define OPER_FLAGS	0x1
#define OPER_REGS	0x2
#define OPER_VALUE	0x3
#define OPER_INVALID	0xff
#define OPER_THE_NO_CASE 0x11

void do_disass(__u8 *, __u32);
int decode_prefix(__u8 *, instr_dat_t *);
int init_instr(__u8, instr_dat_t *, void *);
static instr *find_instr(__u8 *, instr_dat_t *, __u8, const instr *min);
__s8 list_contains(__u8 *, size_t, __u8);
void pr_disass_instr(__u8 sc[15]);

#define TRAP() ({printf("%s:%i\n",__FILE__, __LINE__);asm("int3");})

#define PR_INSTR(e) (print_instr(e))
void print_instr(instr *);
char *word_sz_to_str(__u8 sz);
char *seg_reg_str(__u8 v);
__u8 *get_rip_str(__u8 sz);
__u8 get_signed_char(__u64 v, __u64 sz);
const __u8 *get_instr_name(instr_dat_t *in);
char *word_sz_to_str(__u8);


#define for_range(i, b)	for (i=0; i<b; i++)
#define foreach(i, b)	for (int i = 0; i<b; i++)



#define OPER_FITS 				1
#define OPER_FITS_XCLUSIVELY 	2
#define OPER_FITS_X 			2 	// alias
#define OPER_BAD_FIT 			4

struct op_int_st {
	operand op;
	int ret;
};


__u8 inst_has_pfx(instr_dat_t *, __u8);
__u8 get_oper_size(instr_dat_t *);
__u8 get_addr_size(instr_dat_t *);
__u8 inst_op_pfx_rexw(instr_dat_t *);
void set_seg_reg(instr_dat_t *, operand *);
void _memcpy_op_int(operand dst[4], struct op_int_st src[4]);
void memmove_ptr_add(void *dst, __u8 **ptr, size_t sz);

int handle_x_tup(__u8 *, instr_dat_t *, operand *, regs_tuple_t *);
int get_modrm_operands(__u8 *ptr, instr_dat_t *ret, operand *oper);


#define _signed_limit(n)	 	(N_MAX_BITS(n)/2)
#define _is_signed(v, len)		(((__u64)v > (__u64)_pow(2, len)/2))
#define _signed(v, len)			(((__u64)v > (__u64)_pow(2, len)/2) ? (~v)+1 : v)
#endif