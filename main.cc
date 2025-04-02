#include <stdio.h>
#include <x86disass/disass.hpp>

#define p(s,...) printf(s, __VA_ARGS__);

int main() {
	// auto x = x_t_c();
	auto d = Disass();
	auto& in = d.disass("\x48\x8d\x05\x9d\x3b\x00\x00");
	// __u8 sc[15] = {};
	// __u64 y[4] = {0, _BYTE_, 0, 0};
	// x.get((__u8*)sc, in, y);
	// for (__u8 i = 0; i < 0x10; i++)
	// 	printf("%02x ", sc[i]);
	puts("");
	in.Print();
	// 48 8d 05 9d 3b 00 00          LEA     RAX, QWORD ptr [RIP+0x3b9d]

	d.flush();	// free insn_t vec inside ~Disass

	d.iter(main, 0x10, [](__u64 i, insn_t& in) {
		p("%s\n", in.Mnemo());

		for (int i = 0; i < in.OperCount(); i++) {
			auto op = in[i];
			p("Operand [%i] - ", i);
			prf("%s\n", in[i]->Str());

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
