
## x86disass
x86_64 (with partial x86 support) disassembler with C and C++ API<br>
Supports rewriting instructions (Registers, IMM, Disp...)
###### Ring0 instructions are a bit funky as of now

#### To Build
```shell
sudo make install
make example
```

### Example
```c++
#include <stdio.h>
#include <x86disass/disass.hpp>

#define p(s,...) printf(s, __VA_ARGS__);

int main() {
	auto d = Disass();
	auto& in = d.disass("\x48\x8d\x05\x9d\x3b\x00\x00");
	in.Print();
	// 48 8d 05 9d 3b 00 00          LEA     RAX, QWORD ptr [RIP+0x3b9d]

	d.flush();	// free insn_t vec inside ~Disass

	d.iter(main, 0x10, [](__u64 i, insn_t& in) {
		in.Print();
	});
	return 0;
}

```
###### Helpful links (If you decide to make your own)

[X86-64 Instruction Encoding](https://wiki.osdev.org/X86-64_Instruction_Encoding).
[X86 Opcode and Instruction Reference Home](http://ref.x86asm.net/geek64.html).
[Online x86 / x64 Assembler and Disassembler](https://defuse.ca/online-x86-assembler.htm).
