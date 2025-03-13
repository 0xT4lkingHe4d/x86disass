#include "./disass.h"

#ifndef DISASS_UAPI_H
#define DISASS_UAPI_H


typedef unsigned char 		BYTE;
typedef unsigned short 		WORD;
typedef unsigned int 		DWORD;
typedef unsigned long long 	QWORD;
// #define RIP		(WORD) 0x0100
// #define PTR		(WORD) 0x1000

// #define IMM		(WORD) 0x0010
// #define REG		(WORD) 0x0008
// #define SIB		(WORD) 0x0004
// #define MODRM	(WORD) 0x0002
// #define DISP 	(WORD) 0x0001

#define MAX_INSTR_SZ	15

#define IS_(a, x) 	(!!(x&a))

// UAPI
__u8 in_cmp_mnemo(instr_dat_t *ret, __u8 *s);
__u32 get_inst_type(instr_dat_t *ret, operand *op);

#define foreach_instr(t, in, ptr, limit)			\
		for (instr_dat_t in = {0}; ptr < limit && init_instr((t), (&in), (ptr)) != -1 ; ptr += in.in_sz)

#define foreach_instr_off(t, in, i, ptr, len)						\
		for (instr_dat_t in = {0}; i < len ; i += in.in_sz)			\
			if (init_instr((t), (&in), (ptr + i)) != -1 || (i++ && 0))

typedef struct {
	__u64 v;
	__s8 ok;
} ok_t;
#define _OK(t, val) (ok_t) {.ok=t, .v=(val)}


typedef struct {
	__s8	ok;
	__u64	v;
} err_t;
#define NEW_ERROR(_ok, _v) ((err_t){.ok = _ok, .v = _v })

__u8 assemble(instr_dat_t *inst, __u8 ops[15]);

__u8 change_imm(instr_dat_t *ret, operand *p, __u64 imm);
__s8 change_disp(instr_dat_t *ret, operand *p, __u32 v);
void change_regop(instr_dat_t *ret, operand *p, __u8 reg);
__s8 change_modrm(instr_dat_t *ret, operand *p, __u8 reg);
__s8 chng_sib(instr_dat_t *ret, __u8 v, __u16 x);

__u8 i_jmp_byte_rel(__u8 b[15], __u8 v);
__u8 i_jmp_rel(__u8 b[15], __u32 v, __u8 sz);
__u8 get_oper_sz(instr_dat_t *in, operand *p);
__u8 get_operand_ptr(instr_dat_t *in, operand *p, __u64 *v);
__s8 get_rip_oper(instr_dat_t *in);

#define CHNG_REL 1
#define CHNG_FXD 2
__u32 change_ptr(instr_dat_t *in, __u64 diff, __u8 f);
err_t get_dst_ptr(instr_dat_t *in);

__u8 get_rip_val(instr_dat_t *in, __u64 *v);
__s8 get_rip_ptr_addr(instr_dat_t *in, void *off, __u64 *v);

ok_t get_imm(instr_dat_t *in);
__u8 _build_instr(instr *in, __u8 sc[15]);
#endif