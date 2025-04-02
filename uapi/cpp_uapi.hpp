#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <memory>
#include <variant>
// #include "../include/disass.h"
#include "../include/uapi.h"

#ifndef DISASS_CPP_H
#define DISASS_CPP_H
#define __recv_extern(fn) extern "C" decltype(fn) (*c_##fn);
__recv_extern(reg_by_name);
__recv_extern(get_reg_name);
__recv_extern(reg_by_val);
__recv_extern(init_instr);
__recv_extern(get_oper_sz);
__recv_extern(get_instr_name);
__recv_extern(get_rip_oper);
__recv_extern(pr_in_str);
__recv_extern(_build_instr);
__recv_extern(change_ptr);
__recv_extern(stick_in_instr);
__recv_extern(assemble);
__recv_extern(seg_reg_str);
__recv_extern(get_rip_str);
__recv_extern(get_signed_char);
__recv_extern(word_sz_to_str);
__recv_extern(get_reg_name);
__recv_extern(reg_4bits_name);
__recv_extern(get_addr_size);
#endif

extern "C" {
	__u64 c_ptr_val(instr_dat_t *, __u64);
	__u64 c_operptr(instr_dat_t *in, operand *op);
}

enum class ReAsmT : __u8
{ REL=CHNG_REL, FXD=CHNG_FXD };

class Regs {
	const reg_st *reg{};

public:
	Regs() = default;
	template<typename T>
	Regs(T *str) : reg{c_reg_by_name((__u8*)str)} {}
	Regs(__u32 v): reg{c_reg_by_val(v)} {}

	template <typename T> Regs& operator()(T v) {
		return *this=Regs(v);
	}

	const char *name()	{ return ok() ? reg->name : NULL; }
	unsigned int val()	{ return ok() ? reg->v : -1; }
	enum regs_t_enum type() {
		return ok() ? reg->t : (enum regs_t_enum)-1;
	}

	bool ok() { return !!reg; }
};

enum class OperType : char
{
	NONE=0, IMM=1, PTR=2, REG=4, FXD=8
};

#define MAX_OPS_COUNT 4

class Operand : public operand {
	char *name;
	instr_dat_t *instr{};
	struct {
		Regs 	v;				// value
		Regs	index, base;	// [RAX + RDX + EAX]
	} regs;
public:
	char * Str();
	Operand() = default;
	__s64 Value() {
		if (!!is_ptr) 	return c_operptr(instr, this);
		if (!!is_imm) 	return *(__s64*)imm;
		if (!!disp_sz)	return *(__s64*)disp;
		return !!v ? v :-1;
	}

	__u8 IsRIP()	{ return rip; }
	__u8 Scale()	{ return sib.s; }
	Regs& IndexReg(){ return regs.index; }
	Regs& BaseReg() { return regs.base; }
	Regs& Reg()		{ return regs.v; }

	OperType Type() {
		using OP = OperType;
		if (!!is_empty) return OP::NONE;
		char r{};

		if (is_imm)	r |= (char)OP::IMM;		// Immediate
		if (reg)	r |= (char)OP::REG;		// Register
		if (v)		r |= (char)OP::FXD;		// Fixed Val
		if (rip || is_ptr)
					r |= (char)OP::PTR;		// Pointer

		return (OperType)r;
	}

	__u64 size() { return ((!!sz) ? sz : disp_sz); }//c_get_oper_sz(instr, this); }

	bool IsType(OperType p) {
		char a{(char)Type()}, b{(char)p};
		return (a==b || a&b);
	}
private:
	void link(instr_dat_t *in) {
		instr = in;
		if (!!this->reg) regs.v = Regs(reg);
		if (!!this->sib.on) {
			// regs.s = this->sib.s;
			regs.index	= this->sib.i_reg;
			regs.base	= this->sib.b_reg;

		}
	}
	friend void linkOper(Operand& op, instr_dat_t *in);
};

class insn_t : public instr_dat_t {
private:
	Operand op[4];
	void *addr{};

public:
	__u8 OperCount();
	__u8 ModRM();
	__u8 Sib();
	__u8 size();
	bool IsPtr();
	bool IsRip();
	bool IsRet();
	bool IsCall();
	bool IsJump();
	bool IsShortJump();
	bool IsBranch();
	bool IsShortBranch();
	bool IsDatamov();
	bool IsNull();
	const char *Mnemo();
	void Print();
	void *Addr();
	__u8 dump(__u8 *ptr);
	void stick_ptr(__u64 diff, ReAsmT f);
	__u8 stick_in(void *ptr, __u64 imm, __u64 virt, ReAsmT t);

	/* C++ impl */
	__u64 PtrAddr(__u64 off=0) { return PtrAddr(0, off); }
	__u64 PtrAddr(int i, __u64 off) {
		return c_ptr_val(this, off);
	}

	insn_t() = default;
	template<typename T>
	insn_t(T *p) { init((void*)p); }
	insn_t(void *p, instr_dat_t& in) : addr{ p } {
		std::memcpy(this, &in, sizeof(instr_dat_t));
	}

	template<typename T>
	insn_t& init(T *p) {
		c_init_instr(X86_64, this, (void*)set_addr(p));
		for (int i{}; i < MAX_OPS_COUNT; linkOper(op[i++], this))
			*(dynamic_cast<operand*>(&op[i])) = std::move(oper[i]);

		return *this;
	}
	Operand *operator[](__u8 i);

	template<typename T>
	T *set_addr(T *p) { return (T*)(addr = (void *)(p)); }
};

typedef void(*insn_iter_t)(__u64, insn_t&);

enum DisassFlag { DisassQuit };

class Disass {
public:
	Disass()	= default;
	~Disass()	= default;

	template<typename T>
	insn_t& disass(T *ptr) {
		return vec.emplace_back().init(ptr);
	}
	__u64 flush() {
		for (auto& in : vec) std::memset(&in, 0, sizeof(in));
		vec.clear();
	}

	int disass(instr_dat_t *dat, void *ptr) {
		init_instr(X86_64, dat, ptr);
		return (dat->insn) ? dat->in_sz : 0;
	}

	template<typename T, typename Y>
	void iter(T *p, __u64 size, Y fn) {
		insn_t in = insn_t();
		void *ptr = (void*)p;
		try {
			for (__u64 i{0}; i < size; i += (!!in.insn) ? in.in_sz : 1) {
				in.init(ptr + i);
				fn(i, in);
			}
		} catch (enum DisassFlag const& e) {}
	}
private:
	std::vector<insn_t> vec;
};
// #endif