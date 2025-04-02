#ifndef X86DISASS_H
#define X86DISASS_H
#include "./uapi/cpp_uapi.hpp"
#include "./uapi/xtc.hpp"

#define _disasm(ptr, off, size, i, in)											\
		for (__u64 i{}; i < (size); i += (!!(in).insn) ? (in).in_sz : 1)	\
			if (!!&(in).init((void*)ptr + off + i) && !(in).IsNull())
#endif