#define REGS_H
#include <linux/types.h>

enum regs_t_enum {
	GP_8=0, GP_16=1, GP_32=2, GP_64=3,
	FPU_X86=4, MMX=5, XMM=6, YMM=7,
	SEG16=8, CTL32=9, DBG32=10,
};

#define F_REG 	 0x88000U
#define ANY_REGS 0x100000U
#define F_ANY_REGS_FPU_X86 (ANY_REGS | F_REG|(FPU_X86<<8))
#define IS_ANY_REGS(x) ((x >> 5*4) == 1)

typedef struct {
	char 				*name;
	enum regs_t_enum 	t;
	unsigned int		v;
} reg_st;


#define GET_REG_SZ(v) ({				\
	size_t ret = 8;						\
	for (int i = 1; i <= v; i++) ret*=2;\
	ret;								\
})


extern reg_st reg_tabl[168];

#define REG_TABL_MAX (sizeof(reg_tabl)/sizeof(reg_st))-1

#define for_each_regs(iter) \
			for (iter = &reg_tabl[0]; iter <= &reg_tabl[REG_TABL_MAX]; iter++)

#define IS_GENREG(t) (t==GP_8||t==GP_16||t==GP_32||t==GP_64)


__u32 anyreg_by_name(__u8 *str);
static __u32 gen_reg_scale(reg_st *reg, __u32 sz);
__u32 gen_reg_change_scale(__u8 *name, __u32 sz);
__u32 reg_3bits_by_size(__u8 b, __u32 sz, __u8 rex_b);
__u32 reg_3bits_by_type(__u8 b, enum regs_t_enum type, __u8 rex_bit);
const __u8 *reg_4bits_name(__u8 bits, __u32 sz);
const reg_st *reg_by_val(__u32 v);
const __u8 *get_reg_name(__u32 v);
const reg_st *reg_by_name(__u8 *s);
__u32 reg_by_type(__u32 v, enum regs_t_enum type);
// reg_st *gen_reg_scale_by_val(reg_st *reg, __u32 sz);
__u8 *gen_reg_scale_by_val(__u32 v, __u32 sz);
__s16 get_gp_reg_size(__u8 *name);