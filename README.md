
## x86disass
An x86_64 and x86(partially) disassembler written C
###### Ring0 instructions are not supported as of now

#### To Build
```shell
make example; ./main
sudo make install
```
### Example
```c
#include <stdio.h>
#include <sys/mman.h>
#include <x86disass/disass.h>

void main() {
	do_disass((void*)mmap, 0xd9);

	instr_dat_t in;
	__u8 *sc = "\x48\x8d\x05\x9d\x3b\x00\x00";
	puts(" + Source instr");

	if (init_instr(X86_64, &in, sc) == -1) DIE("failed");
	pr_in_str(&in);

	__u64 v = 0;
	if (!get_rip_ptr_addr(&in, 0x1000, &v))
		printf("%s @ 0x1000 points to 0x%lx\n\n", get_instr_name(&in), v);

	puts(" + Modified");
	change_ptr(&in, 0x1337, CHNG_REL);
	pr_in_str(&in);

	__u8 ret[0x10] = {0};
	assemble(&in, ret);
}

```
### Output
```
0x000000:   41 89 ca                      MOV     R10D, ECX
0x000003:   41 f7 c1 ff 0f 00 00          TEST    R9D, 0xfff
0x00000a:   75 14                         JNE     [RIP+0x14]
0x00000c:   b8 09 00 00 00                MOV     EAX, 0x9
0x000011:   0f 05                         SYSCALL RCX, R11L, SS
0x000013:   48 3d 00 f0 ff ff             CMP     , 0xfffff000
0x000019:   77 25                         JA      [RIP+0x25]
0x00001b:   c3                            RETN    
0x00001c:   0f 1f 40 00                   NOP     DWORD ptr [RAX+0x0]
...
0x0000d0:   48 3d 00 f0 ff ff             CMP     , 0xfffff000
0x0000d6:   77 58                         JA      [RIP+0x58]
0x0000d8:   c3                            RETN    

======================================================================

 + Source instr
48 8d 05 9d 3b 00 00          LEA     RAX, QWORD ptr [RIP+0x3b9d]
LEA @ 0x1000 points to 0x4ba4

 + Modified
48 8d 05 37 13 00 00          LEA     RAX, QWORD ptr [RIP+0x1337]
```

#### Resources used

[X86-64 Instruction Encoding](https://wiki.osdev.org/X86-64_Instruction_Encoding).
[X86 Opcode and Instruction Reference Home](http://ref.x86asm.net/geek64.html).
[Online x86 / x64 Assembler and Disassembler](https://defuse.ca/online-x86-assembler.htm).
