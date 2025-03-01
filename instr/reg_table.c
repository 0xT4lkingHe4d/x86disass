#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/regs.h"


__u32 anyreg_by_name(__u8 *str) {
	int rANY=0;

	__u8 cpy[strlen(str)];
	memmove(cpy, str, sizeof(cpy));
	cpy[sizeof(cpy)]='\0';

	if (islower(cpy[0]))
		rANY = cpy[0] = toupper(cpy[0]);	// a to A
	const reg_st * reg = reg_by_name(cpy);
	return (rANY) ? ANY_REGS | reg->v : reg->v;
}


#define MAGIC_FORMULA(v, type) (F_REG | v | ((type-1)<<8))

#define GP_R11_START 0x8
#define X_MAGIC  0x4


/** This is a product of Bad reg_tabl design
 * !~!~! DO NOT ATTEMPT TO TOUCH IT
 * 			- not even the creator knows what it does
 */
static __u32 fear_and_loathing(__u32 v, __u32 srctype, __u32 dsttype) {
	// 0x1 2 3
	//   | | |
	//   | | +---- Y
	//   | +------ X adage
	//   +-------- X
	__u32 base = v & 0xfff;
	__u8 Y = (base & 0xf);

	/* Not yet R11, but it is already one of the AH, DH, CL, BH */
	if (Y < GP_R11_START && Y>=X_MAGIC) {
		if (!(base&~0xf) && srctype==GP_8) {
			return MAGIC_FORMULA(base-X_MAGIC, dsttype);
		}
		else if (dsttype==GP_8) 		base+=0x10;
		else if ((base&~0xf)==0x10) 	base-=0x10;
	}
	return MAGIC_FORMULA(base & ~0xf00, dsttype);
}


__u8 GP_REG_BITS(size_t a) {
	size_t i = 8, l=1;
	while(i < (size_t)a) i*=2, l++;
	return (i == a) ? l : 0;
}



static __u32 gen_reg_scale(reg_st *reg, __u32 sz) {
	if (reg == NULL || !IS_GENREG(reg->t)) {
		return 0;
	}
	return fear_and_loathing(reg->v, reg->t, GP_REG_BITS(sz));
}

__u32 gen_reg_change_scale(__u8 *name, __u32 sz) {
	return gen_reg_scale((reg_st*)reg_by_name(name), sz);
}

static reg_st *gen_reg_scale_by_reg(reg_st *reg, __u32 sz) {
	if (reg == NULL || !IS_GENREG(reg->t)) {
		return NULL;
	}
	__u32 v = fear_and_loathing(reg->v, reg->t, GP_REG_BITS(sz));
	return (reg_st*)reg_by_val(v);
}

__u8 *gen_reg_scale_by_val(__u32 v, __u32 sz) {
	if (IS_ANY_REGS(v))
		v ^= ANY_REGS;
	const reg_st *reg = reg_by_val(v);
	if (reg==NULL)
		return "N/A";

	reg_st *scaled_reg = gen_reg_scale_by_reg((reg_st*)reg, sz);
	if (scaled_reg==NULL)
		return "N/A";
	return scaled_reg->name;

}

const reg_st *reg_by_val(__u32 v) {
	reg_st *iter=NULL;
	int ok=0;
	for_each_regs(iter) {
		if (iter->v==v) {ok=1;break;}
	}
	return (const reg_st *)((!!ok) ? iter : NULL);
}

__u32 reg_3bits_by_size(__u8 b, __u32 sz, __u8 rex_bit) {
	reg_st *iter=NULL;
	for_each_regs(iter) {
		if ((7 & iter->v) == (7 & b)) {
			return gen_reg_scale(iter, sz)+((rex_bit)?0x8:0);
		}
	}
	return 0;
}
#define IS_BAD_SEG(v) ({__u8 y=v&0xf; (y==6||y==7||y==14||y==15); })

__u32 reg_3bits_by_type(__u8 b, enum regs_t_enum type, __u8 rex_bit) {
	reg_st *iter=NULL;
	for_each_regs(iter) {
		if ((7 & iter->v) == (7 & b)) {
			__u32 v = (iter->v & ~0xff0)+((__u32)type<<8);
			if (type==SEG16 && IS_BAD_SEG(v)) return 0;
			if (type!=FPU_X86) v+=(rex_bit?8:0);
			return v;
		}
	}
	return 0;
}


#define DBG(s, ...) {printf(s, __VA_ARGS__);}

__u32 reg_by_type(__u32 v, enum regs_t_enum type) {
	reg_st *iter = NULL;
	__u8 ok=0;
	if (type==SEG16 && IS_BAD_SEG(v)) return 0;
	v = (type==FPU_X86) ? ((v&~0xf) | ((v&0xf) % 7)) : v;
	v &= ~0xff0;

	for_each_regs(iter) {
		if (iter->v == v) ok=1;
	}
	return (!!ok) ? (v)+((__u32)type<<8) : 0;
}



// 0x10 & REX bit & 3bits
const __u8 *reg_4bits_name(__u8 bits, __u32 sz) {
	if (!bits) return "N/A";
	__u8 reg = bits ^ 0x10;
	__u32 v = reg_3bits_by_size(bits&7, sz, bits&8);
	return get_reg_name(v);
}



const __u8 *get_reg_name(__u32 v) {
	if (!v) return "N/A";
	return (reg_by_val(v))->name;
}

const reg_st *reg_by_name(__u8 *s) {
	unsigned long len = strlen(s);
	reg_st *iter=NULL;
	__u8 ok = 0;
	for_each_regs(iter) {
		if (!strncmp(s, iter->name, len)){ok=1; break;}
	}
	return (const reg_st *)((!!ok) ? iter: NULL);
}

__s16 get_gp_reg_size(__u8 *name) {
	const reg_st *reg = reg_by_name(name);
	if (reg==NULL) return -1;
	
	return (IS_GENREG(reg->t)) ? GET_REG_SZ(reg->t) : 0;
}

reg_st reg_tabl[168] = (reg_st[168]){
	{ .name ="AL", .t=GP_8, .v=F_REG 	|	0x000 },	/*                            "@>                                  */
	{ .name ="AX", .t=GP_16, .v=F_REG 	|	0x100 },	/*                             M@M                                 */
	{ .name ="EAX", .t=GP_32, .v=F_REG 	|	0x200 },	/*                             @@@J                                */
	{ .name ="RAX", .t=GP_64, .v=F_REG 	|	0x300 },	/*                          |@ @@@O"@>                             */
	{ .name ="ST0", .t=FPU_X86, .v=F_REG	|	0x400 },	/*                          |@"J@@ @@                              */
	{ .name ="MMX0", .t=MMX, .v=F_REG 	|	0x500 },	/*                       O> M@">@c @@                              */
	{ .name ="XMM0", .t=XMM, .v=F_REG 	|	0x600 },	/*                        @@M@@O@-I@@                              */
	{ .name ="YMM0", .t=YMM, .v=F_REG 	|	0x700 },	/*                       "@MI@@@@@@@M                              */
	{ .name ="ES", .t=SEG16, .v=F_REG 	|	0x800 },	/*                       @@| d@@@@@|-M"                            */
	{ .name ="CR0", .t=CTL32, .v=F_REG 	|	0x900 },	/*                      -@@I -@@@  d@"                             */
	{ .name ="DR0", .t=DBG32, .v=F_REG 	|	0xa00 },	/*                      I@@@O@@@  |@M                              */
	{ .name ="CL", .t=GP_8, .v=F_REG 	|	0x001 },	/*                     " a@@@@@a"M@@                               */
	{ .name ="CX", .t=GP_16, .v=F_REG 	|	0x101 },	/*                     {M-@@@@@@@@@                                */
	{ .name ="ECX", .t=GP_32, .v=F_REG 	|	0x201 },	/*                     I@@@@@@@@M"                                 */
	{ .name ="RCX", .t=GP_64, .v=F_REG 	|	0x301 },	/*                      @@@@@-Ic                                   */
	{ .name ="ST1", .t=FPU_X86, .v=F_REG	|	0x401 },	/*                     {@@@@M-                                     */
	{ .name ="MMX1", .t=MMX, .v=F_REG 	|	0x501 },	/*                    MM@@@@I"                                     */
	{ .name ="XMM1", .t=XMM, .v=F_REG 	|	0x601 },	/*                    >@@@@@@d                                     */
	{ .name ="YMM1", .t=YMM, .v=F_REG 	|	0x701 },	/*                     M@@@@@  {                                   */
	{ .name ="CS", .t=SEG16, .v=F_REG 	|	0x801 },	/*                    Ma@@@@@@@@                                   */
	{ .name ="CR1", .t=CTL32, .v=F_REG 	|	0x901 },	/*                     j@@@@@@@-                                   */
	{ .name ="DR1", .t=DBG32, .v=F_REG 	|	0xa01 },	/*                       @@@@@@@@                                  */
	{ .name ="DL", .t=GP_8, .v=F_REG 	|	0x002 },	/*                       O@@@@@@@@d                                */
	{ .name ="DX", .t=GP_16, .v=F_REG 	|	0x102 },	/*                      "ccJ@@@@@@@@>                              */
	{ .name ="EDX", .t=GP_32, .v=F_REG 	|	0x202 },	/*                          "@@@@@@@@d                             */
	{ .name ="RDX", .t=GP_64, .v=F_REG 	|	0x302 },	/*                        "M@@@@@@@@@@M                            */
	{ .name ="ST2", .t=FPU_X86, .v=F_REG	|	0x402 },	/*                             {@@@@@@@O                           */
	{ .name ="MMX2", .t=MMX, .v=F_REG 	|	0x502 },	/*                              {@@@@@@@                           */
	{ .name ="XMM2", .t=XMM, .v=F_REG 	|	0x602 },	/*                           OOj@@@@@@@@{                          */
	{ .name ="YMM2", .t=YMM, .v=F_REG 	|	0x702 },	/*                            -@@@@@@@@@|                          */
	{ .name ="SS", .t=SEG16, .v=F_REG 	|	0x802 },	/*                              -@@@@@@@"                          */
	{ .name ="CR2", .t=CTL32, .v=F_REG 	|	0x902 },	/*                         @d  O@@@@@@@M                           */
	{ .name ="DR2", .t=DBG32, .v=F_REG 	|	0xa02 },	/*                     I   M@@@@@@@@@@@                            */
	{ .name ="BL", .t=GP_8, .v=F_REG 	|	0x003 },	/*                    aM  -@@@@@@@@@@M"                            */
	{ .name ="BX", .t=GP_16, .v=F_REG 	|	0x103 },	/*                    M@@@@@@@@@@@@@-                              */
	{ .name ="EBX", .t=GP_32, .v=F_REG 	|	0x203 },	/*               J    @@@@@@@@@@@@-                                */
	{ .name ="RBX", .t=GP_64, .v=F_REG 	|	0x303 },	/*               @@cd@@@@@@@@@@M                                   */
	{ .name ="ST3", .t=FPU_X86, .v=F_REG	|	0x403 },	/*               "@@@@@@@@@@@{          ">                         */
	{ .name ="MMX3", .t=MMX, .v=F_REG 	|	0x503 },	/*                M@@@@@@@@I             -M                        */
	{ .name ="XMM3", .t=XMM, .v=F_REG 	|	0x603 },	/*            |  >@@@@@@@M         "c-M@@@- I                      */
	{ .name ="YMM3", .t=YMM, .v=F_REG 	|	0x703 },	/*            -@@@@@@@@@@     @  "@@@a@@@j"cM                      */
	{ .name ="DS", .t=SEG16, .v=F_REG 	|	0x803 },	/*              "a@@@@@@@    I@d@@M@" "@|{JI                       */
	{ .name ="CR3", .t=CTL32, .v=F_REG 	|	0x903 },	/*               -@@@@@@@J        @|   j@OIa                       */
	{ .name ="DR3", .t=DBG32, .v=F_REG 	|	0xa03 },	/*            >"{@@@@@@@@@M      j@      "                         */
	{ .name ="SPL1", .t=GP_8, .v=F_REG 	|	0x014 },	/*             "d@@@@@@@@@@@M    @@@@@@@@c                         */
	{ .name ="AH", .t=GP_8, .v=F_REG 	|	0x004 },	/*                 "@@@@@@@@@@@|"d  j@@@@@d                        */
	{ .name ="SP", .t=GP_16, .v=F_REG 	|	0x104 },	/*                 c@@@@@@@@@@@@@M"  @@@@@M                        */
	{ .name ="ESP", .t=GP_32, .v=F_REG 	|	0x204 },	/*                IJO> J@@@@@@@@@@@@M@@@@@>                        */
	{ .name ="RSP", .t=GP_64, .v=F_REG 	|	0x304 },	/*                      a@@@@@@@@@@@@@@@@"                         */
	{ .name ="ST4", .t=FPU_X86, .v=F_REG	|	0x404 },	/*                    O@@@> O@@@@@@@@@@                            */
	{ .name ="MMX4", .t=MMX, .v=F_REG 	|	0x504 },	/*                           J@@@@@@@@@@                           */
	{ .name ="XMM4", .t=XMM, .v=F_REG 	|	0x604 },	/*                         a@@@a@@@@@@@@|                          */
	{ .name ="YMM4", .t=YMM, .v=F_REG 	|	0x704 },	/*                              "@@@@@@@a                          */
	{ .name ="FS", .t=SEG16, .v=F_REG 	|	0x804 },	/*                              "@@@@@@@a                          */
	{ .name ="CR4", .t=CTL32, .v=F_REG 	|	0x904 },	/*                         I"   d@@@@@@@c                          */
	{ .name ="DR4", .t=DBG32, .v=F_REG 	|	0xa04 },	/*                         @@" M@@@@@@@@                           */
	{ .name ="BPL1", .t=GP_8, .v=F_REG 	|	0x015 },	/*                     j   d@@@@@@@@@@@-                           */
	{ .name ="CH", .t=GP_8, .v=F_REG 	|	0x005 },	/*                    M@" J@@@@@@@@@@@I                            */
	{ .name ="BP", .t=GP_16, .v=F_REG 	|	0x105 },	/*                    a@@@@@@@@@@@@@@M                             */
	{ .name ="EBP", .t=GP_32, .v=F_REG 	|	0x205 },	/*               cI  I@@@@@@@@@@@@@@@M   I                         */
	{ .name ="RBP", .t=GP_64, .v=F_REG 	|	0x305 },	/*               a@@@@@@@@@@@@@@@@@@@@@M@@                         */
	{ .name ="ST5", .t=FPU_X86, .v=F_REG	|	0x405 },	/*                M@@@@@@@@@@M"  "a@@a> j@                         */
	{ .name ="MMX5", .t=MMX, .v=F_REG 	|	0x505 },	/*                @@@@@@@@@O     --     O@                         */
	{ .name ="XMM5", .t=XMM, .v=F_REG 	|	0x605 },	/*           "{  O@@@@@@@@     Id j@d   @O@@J@>                    */
	{ .name ="YMM5", .t=YMM, .v=F_REG 	|	0x705 },	/*            c@@@@@@@@@@-      "dMj@M j@@O  a                     */
	{ .name ="GS", .t=SEG16, .v=F_REG 	|	0x805 },	/*              I@@@@@@@@I     >@" |@@@@@"                         */
	{ .name ="CR5", .t=CTL32, .v=F_REG 	|	0x905 },	/*               a@@@@@@@M      c M@|"                             */
	{ .name ="DR5", .t=DBG32, .v=F_REG 	|	0xa05 },	/*              "@@@@@@@@@@"      M{                               */
	{ .name ="SIL1", .t=GP_8, .v=F_REG 	|	0x016 },	/*             |@@@@@@@@@@@@@I                                     */
	{ .name ="DH", .t=GP_8, .v=F_REG 	|	0x006 },	/*                 {@@@@@@@@@@@O                                   */
	{ .name ="SI", .t=GP_16, .v=F_REG 	|	0x106 },	/*                 {@@@@@@@@@@@@@@>                                */
	{ .name ="ESI", .t=GP_32, .v=F_REG 	|	0x206 },	/*               "a@@O @@@@@@@@@@@@@-                              */
	{ .name ="RSI", .t=GP_64, .v=F_REG 	|	0x306 },	/*                      M@@@@@@@@@@@@@                             */
	{ .name ="ST6", .t=FPU_X86, .v=F_REG	|	0x406 },	/*                    "a@@MI@@@@@@@@@@@"                           */
	{ .name ="MMX6", .t=MMX, .v=F_REG 	|	0x506 },	/*                           c@@@@@@@@@@                           */
	{ .name ="XMM6", .t=XMM, .v=F_REG 	|	0x606 },	/*                         "d@@@@@@@@@@@J                          */
	{ .name ="YMM6", .t=YMM, .v=F_REG 	|	0x706 },	/*                              {@@@@@@@@                          */
	{ .name ="CR6", .t=CTL32, .v=F_REG 	|	0x906 },	/*                              I@@@@@@@@                          */
	{ .name ="DR6", .t=DBG32, .v=F_REG 	|	0xa06 },	/*                         -"   M@@@@@@@M                          */
	{ .name ="DIL1", .t=GP_8, .v=F_REG 	|	0x017 },	/*                         @@-I@@@@@@@@@>                          */
	{ .name ="BH", .t=GP_8, .v=F_REG 	|	0x007 },	/*                     c   d@@@@@@@@@@@O                           */
	{ .name ="DI", .t=GP_16, .v=F_REG 	|	0x107 },	/*                    M@" O@@@@@@@@@@@c                            */
	{ .name ="EDI", .t=GP_32, .v=F_REG 	|	0x207 },	/*                    a@@@@@@@@@@@@@@                              */
	{ .name ="RDI", .t=GP_64, .v=F_REG 	|	0x307 },	/*               J>  -@@@@@@@@@@@@@"                               */
	{ .name ="ST7", .t=FPU_X86, .v=F_REG	|	0x407 },	/*               a@@@@@@@@@@@@@@a                                  */
	{ .name ="MMX7", .t=MMX, .v=F_REG 	|	0x507 },	/*                M@@@@@@@@@@@-          a"                        */
	{ .name ="XMM7", .t=XMM, .v=F_REG 	|	0x607 },	/*                @@@@@@@@@M             cM                        */
	{ .name ="YMM7", .t=YMM, .v=F_REG 	|	0x707 },	/*           "J  a@@@@@@@@I        j@M@@@@  c                      */
	{ .name ="CR7", .t=CTL32, .v=F_REG 	|	0x907 },	/*            {@@@@@@@@@@j   Ia  j@@@>@@@MJ@O                      */
	{ .name ="DR7", .t=DBG32, .v=F_REG 	|	0xa07 },	/*               @@@@@@@@>    @@@@a@   @d                          */
	{ .name ="R8L", .t=GP_8, .v=F_REG 	|	0x008 },	/*               M@@@@@@@M       "@>   I@@a@                       */
	{ .name ="R8W", .t=GP_16, .v=F_REG 	|	0x108 },	/*              -@@@@@@@@@@"     d@                                */
	{ .name ="R8D", .t=GP_32, .v=F_REG 	|	0x208 },	/*             >MMM@@@@@@@@@@"   @@@@@@@@@                         */
	{ .name ="R8", .t=GP_64, .v=F_REG 	|	0x308 },	/*                 O@@@@@@@@@@@O I  I@@@@@a                        */
	{ .name ="MMX0", .t=MMX, .v=F_REG 	|	0x508 },	/*                 j@@@@@@@@@@@@@@I "@@@@@M                        */
	{ .name ="XMM8", .t=XMM, .v=F_REG 	|	0x608 },	/*                J@M|I@@@@@@@@@@@@@@@@@@@"                        */
	{ .name ="YMM8", .t=YMM, .v=F_REG 	|	0x708 },	/*                      M@@@@@@@@@@@@@@@a                          */
	{ .name ="ES", .t=SEG16, .v=F_REG 	|	0x808 },	/*                    >@@@O>@@@@@@@@@@@"                           */
	{ .name ="CR8", .t=CTL32, .v=F_REG 	|	0x908 },	/*                           c@@@@@@@@@@                           */
	{ .name ="DR8", .t=DBG32, .v=F_REG 	|	0xa08 },	/*                         >M@@@@@@@@@@@c                          */
	{ .name ="R9L", .t=GP_8, .v=F_REG 	|	0x009 },	/*                              |@@@@@@@@                          */
	{ .name ="R9W", .t=GP_16, .v=F_REG 	|	0x109 },	/*                              I@@@@@@@@                          */
	{ .name ="R9D", .t=GP_32, .v=F_REG 	|	0x209 },	/*                         -    M@@@@@@@a                          */
	{ .name ="R9", .t=GP_64, .v=F_REG 	|	0x309 },	/*                         @@" @@@@@@@@@>                          */
	{ .name ="MMX1", .t=MMX, .v=F_REG 	|	0x509 },	/*                     c   a@@@@@@@@@@@O                           */
	{ .name ="XMM9", .t=XMM, .v=F_REG 	|	0x609 },	/*                    M@I |@@@@@@@@@@@O                            */
	{ .name ="YMM9", .t=YMM, .v=F_REG 	|	0x709 },	/*                    a@@@@@@@@@@@@@@M                             */
	{ .name ="CS", .t=SEG16, .v=F_REG 	|	0x809 },	/*               O>  "@@@@@@@@@@@@@@@@   a                         */
	{ .name ="CR9", .t=CTL32, .v=F_REG 	|	0x909 },	/*               a@@@@@@@@@@@@@@@@@@@@@@@@                         */
	{ .name ="DR9", .t=DBG32, .v=F_REG 	|	0xa09 },	/*                M@@@@@@@@@@@-   >jjI  |@                         */
	{ .name ="R10L", .t=GP_8, .v=F_REG 	|	0x00a },	/*                @@@@@@@@@M    -MM-    a@ -cI                     */
	{ .name ="R10W", .t=GP_16, .v=F_REG 	|	0x10a },	/*           "O "a@@@@@@@@>    >I "@@   @a@a d-                    */
	{ .name ="R10D", .t=GP_32, .v=F_REG 	|	0x20a },	/*            {@@@@@@@@@@{      j@@@@@>O@@>  O                     */
	{ .name ="R10", .t=GP_64, .v=F_REG 	|	0x30a },	/*               @@@@@@@@"     -a  {@@@@a                          */
	{ .name ="MMX2", .t=MMX, .v=F_REG 	|	0x50a },	/*               a@@@@@@@d      " @M                               */
	{ .name ="XMM10", .t=XMM, .v=F_REG 	|	0x60a },	/*              {@@@@@@@@@M       JJ                               */
	{ .name ="YMM10", .t=YMM, .v=F_REG 	|	0x70a },	/*             IdMM@@@@@@@@@a                                      */
	{ .name ="SS", .t=SEG16, .v=F_REG 	|	0x80a },	/*                 j@@@@@@@@@@@-                                   */
	{ .name ="CR10", .t=CTL32, .v=F_REG 	|	0x90a },	/*                 c@@@@@@@@@@@@@a                                 */
	{ .name ="DR10", .t=DBG32, .v=F_REG 	|	0xa0a },	/*                JMa|I@@@@@@@@@@@@M"                              */
	{ .name ="R11L", .t=GP_8, .v=F_REG 	|	0x00b },	/*                      M@@@@@@@@@@@@O                             */
	{ .name ="R11W", .t=GP_16, .v=F_REG 	|	0x10b },	/*                    -@@@JI@@@@@@@@@@@                            */
	{ .name ="R11D", .t=GP_32, .v=F_REG 	|	0x20b },	/*                           c@@@@@@@@@a                           */
	{ .name ="R11", .t=GP_64, .v=F_REG 	|	0x30b },	/*                         -@@@@@@@@@@@@>                          */
	{ .name ="MMX3", .t=MMX, .v=F_REG 	|	0x50b },	/*                              I@@@@@@@d                          */
	{ .name ="XMM11", .t=XMM, .v=F_REG 	|	0x60b },	/*                               @@@@@@@a                          */
	{ .name ="YMM11", .t=YMM, .v=F_REG 	|	0x70b },	/*                           @> I@@@@@@@J                          */
	{ .name ="DS", .t=SEG16, .v=F_REG 	|	0x80b },	/*                           j@@@@@@@@@@I                          */
	{ .name ="CR11", .t=CTL32, .v=F_REG 	|	0x90b },	/*                        c    @@@@@@@@M                           */
	{ .name ="DR11", .t=DBG32, .v=F_REG	|	0xa0b },	/*                        @a">@@@@@@@@@                            */
	{ .name ="R12L", .t=GP_8, .v=F_REG 	|	0x00c },	/*                        M@@@@@@@@@@@                             */
	{ .name ="R12W", .t=GP_16, .v=F_REG 	|	0x10c },	/*                     >  I@@@@@@@@@a                              */
	{ .name ="R12D", .t=GP_32, .v=F_REG 	|	0x20c },	/*                     @@@@@@@@@@@@I                               */
	{ .name ="R12", .t=GP_64, .v=F_REG 	|	0x30c },	/*         >M@I         M@@@@@@@@J                                 */
	{ .name ="MMX4", .t=MMX, .v=F_REG 	|	0x50c },	/*        J@| O@     @JO@@@@@@@@"                                  */
	{ .name ="XMM12", .t=XMM, .v=F_REG 	|	0x60c },	/*           I""@I " >@@@@@@@@@                                    */
	{ .name ="YMM12", .t=YMM, .v=F_REG 	|	0x70c },	/*          IO   @> Mj"@@@@@@@>                                    */
	{ .name ="FS", .t=SEG16, .v=F_REG 	|	0x80c },	/*           ad  "@  @@@@@@@@@d@a                                  */
	{ .name ="CR12", .t=CTL32, .v=F_REG 	|	0x90c },	/*     I      I@@M@d{@@@@@@@@@@-d                                  */
	{ .name ="DR12", .t=DBG32, .v=F_REG 	|	0xa0c },	/*     a          >@ @@@@@@@@@@>                                   */
	{ .name ="R13L", .t=GP_8, .v=F_REG 	|	0x00d },	/* |    {J"       @@@@@@@@@@@@O                                    */
	{ .name ="R13W", .t=GP_16, .v=F_REG	|	0x10d },	/*  c"       >aI I@@I@ @@@@@@@O                                    */
	{ .name ="R13D", .t=GP_32, .v=F_REG 	|	0x20d },	/*     "|Oa>    O a@a|@@|  J@@@I                                   */
	{ .name ="R13", .t=GP_64, .v=F_REG 	|	0x30d },	/*          M   j   I@@      |@@                                   */
	{ .name ="MMX5", .t=MMX, .v=F_REG 	|	0x50d },	/*          J   d   >@@MI    {c@{                                  */
	{ .name ="XMM13", .t=XMM, .v=F_REG 	|	0x60d },	/*         d   a    M@          @"                                 */
	{ .name ="YMM13", .t=YMM, .v=F_REG 	|	0x70d },	/*        d   a     M@          @@I                                */
	{ .name ="GS", .t=SEG16, .v=F_REG 	|	0x80d },	/*       J   J   ""j@@@@d        J@M|                              */
	{ .name ="CR13", .t=CTL32, .v=F_REG 	|	0x90d },	/*      I   I"  ac{@@@c           {cI                              */
	{ .name ="DR13", .t=DBG32, .v=F_REG 	|	0xa0d },	/*      O   a    @@@@@@O                                           */
	{ .name ="R14L", .t=GP_8, .v=F_REG 	|	0x00e },	/*      J   |    Id@@@O                                            */
	{ .name ="R14W", .t=GP_16, .v=F_REG 	|	0x10e },	/*      J    "a>Ija>@                                              */
	{ .name ="R14D", .t=GP_32, .v=F_REG 	|	0x20e },	/*       |j     c{                                                 */
	{ .name ="R14", .t=GP_64, .v=F_REG 	|	0x30e },
	{ .name ="MMX6", .t=MMX, .v=F_REG 	|	0x50e },
	{ .name ="XMM14", .t=XMM, .v=F_REG 	|	0x60e },
	{ .name ="YMM14", .t=YMM, .v=F_REG 	|	0x70e },
	{ .name ="CR14", .t=CTL32, .v=F_REG 	|	0x90e },
	{ .name ="DR14", .t=DBG32, .v=F_REG 	|	0xa0e },
	{ .name ="R15L", .t=GP_8, .v=F_REG 	|	0x00f },
	{ .name ="R15W", .t=GP_16, .v=F_REG 	|	0x10f },
	{ .name ="R15D", .t=GP_32, .v=F_REG 	|	0x20f },
	{ .name ="R15", .t=GP_64, .v=F_REG 	|	0x30f },
	{ .name ="MMX7", .t=MMX, .v=F_REG 	|	0x50f },
	{ .name ="XMM15", .t=XMM, .v=F_REG 	|	0x60f },
	{ .name ="YMM15", .t=YMM, .v=F_REG 	|	0x70f },
	{ .name ="CR15", .t=CTL32, .v=F_REG	 |	0x90f },
	{ .name ="DR15", .t=DBG32, .v=F_REG 	|	0xa0f },
};


/** END **/