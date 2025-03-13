
## x86disass
An x86_64 and x86(partially) disassembler written C with C++ API
###### Ring0 instructions are not supported as of now

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
		p("%s\n", in.Mnemo());

		for (int i = 0; i < in.OperCount(); i++) {
			auto op = in[i];
			p("Operand [%i] - ", i);

			switch (in[i]->Type()) {
				case OperType::REG: p("%s\n", op->Reg().name());		break;
				case OperType::IMM: p("Immediate %lx\n", op->Value());	break;
				case OperType::FXD: p("Fixed %lx\n", op->Value());		break;
				case OperType::PTR:
					if (!!in.Sib()) {
						p("[%i * %s + %s + %lx]\n", op->Scale(), op->IndexReg(), op->BaseReg(), op->Value());
					} else if (op->IsRIP()) {
						p("[%s + %lx ]\n", in[i]->IsRIP() == 32 ? "EIP" : "RIP", in[i]->Value());
					}
			}
		}
		puts("\n");
	});
	return 0;
}

```
#### Helpful links (If you decide to make your own)

[X86-64 Instruction Encoding](https://wiki.osdev.org/X86-64_Instruction_Encoding).
[X86 Opcode and Instruction Reference Home](http://ref.x86asm.net/geek64.html).
[Online x86 / x64 Assembler and Disassembler](https://defuse.ca/online-x86-assembler.htm).
