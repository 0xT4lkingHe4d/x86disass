#define INSTR_TABLE_H
#include "../include/def.h"
#undef INSTR_TABLE_H


__attribute__((section(".x86_tabl"), aligned(0x1000))) const instr x86_tabl[1031] = (const instr[1031]){
	{ .opcode1=0x00, .reg_op='r', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x01, .reg_op='r', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x02, .reg_op='r', .mnemonic="ADD", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x03, .reg_op='r', .mnemonic="ADD", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x04, .mnemonic="ADD", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x05, .mnemonic="ADD", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x06, .mnemonic="PUSH", .op={ 0, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x07, .mnemonic="POP", .op={ 0, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x08, .reg_op='r', .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x09, .reg_op='r', .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x0A, .reg_op='r', .mnemonic="OR", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x0B, .reg_op='r', .mnemonic="OR", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x0C, .mnemonic="OR", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x0D, .mnemonic="OR", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x0E, .mnemonic="PUSH", .op={ 0, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x0F, .mnemonic="POP", .op={ 0, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x0F, .op={ 0, 0, 0, 0}, },            /* desc= */
	{ .opcode1=0x0F, .op={ 0, 0, 0, 0}, },            /* desc= */
	{ .opcode1=0x10, .reg_op='r', .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x11, .reg_op='r', .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x12, .reg_op='r', .mnemonic="ADC", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x13, .reg_op='r', .mnemonic="ADC", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x14, .mnemonic="ADC", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x15, .mnemonic="ADC", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x16, .mnemonic="PUSH", .op={ {.reg="SS"}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x17, .mnemonic="POP", .op={ {.reg="SS"}, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x18, .reg_op='r', .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x19, .reg_op='r', .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x1A, .reg_op='r', .mnemonic="SBB", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x1B, .reg_op='r', .mnemonic="SBB", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x1C, .mnemonic="SBB", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x1D, .mnemonic="SBB", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x1E, .mnemonic="PUSH", .op={ 0, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x1F, .mnemonic="POP", .op={ 0, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x20, .reg_op='r', .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x21, .reg_op='r', .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x22, .reg_op='r', .mnemonic="AND", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x23, .reg_op='r', .mnemonic="AND", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x24, .mnemonic="AND", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x25, .mnemonic="AND", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical AND */
	{ .prefix=0x26, .mnemonic="ES", .op={ 0, 0, 0, 0}, },            /* desc=ES segment override prefix */
	{ .prefix=0x26, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=(use with any branch instruction is reserved) */
	{ .opcode1=0x27, .mnemonic="DAA", .op={ {.reg="AL"}, 0, 0, 0}, },            /* desc=Decimal Adjust AL after Addition */
	{ .opcode1=0x28, .reg_op='r', .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x29, .reg_op='r', .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x2A, .reg_op='r', .mnemonic="SUB", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x2B, .reg_op='r', .mnemonic="SUB", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x2C, .mnemonic="SUB", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x2D, .mnemonic="SUB", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .prefix=0x2E, .mnemonic="CS", .op={ 0, 0, 0, 0}, },            /* desc=CS segment override prefix */
	{ .prefix=0x2E, .mnemonic="NTAKEN", .op={ 0, 0, 0, 0}, },            /* desc=Branch not taken prefix (only with Jcc instructions) */
	{ .opcode1=0x2F, .mnemonic="DAS", .op={ {.reg="AL"}, 0, 0, 0}, },            /* desc=Decimal Adjust AL after Subtraction */
	{ .opcode1=0x30, .reg_op='r', .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x31, .reg_op='r', .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x32, .reg_op='r', .mnemonic="XOR", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x33, .reg_op='r', .mnemonic="XOR", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x34, .mnemonic="XOR", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x35, .mnemonic="XOR", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .prefix=0x36, .mnemonic="SS", .op={ {.reg="SS"}, 0, 0, 0}, },            /* desc=SS segment override prefix */
	{ .prefix=0x36, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=(use with any branch instruction is reserved) */
	{ .opcode1=0x37, .mnemonic="AAA", .op={ {.reg="AL"}, {.reg="AH"}, 0, 0}, },            /* desc=ASCII Adjust After Addition */
	{ .opcode1=0x38, .reg_op='r', .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x39, .reg_op='r', .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x3A, .reg_op='r', .mnemonic="CMP", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x3B, .reg_op='r', .mnemonic="CMP", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x3C, .mnemonic="CMP", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x3D, .mnemonic="CMP", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .prefix=0x3E, .mnemonic="DS", .op={ 0, 0, 0, 0}, },            /* desc=DS segment override prefix */
	{ .prefix=0x3E, .mnemonic="TAKEN", .op={ 0, 0, 0, 0}, },            /* desc=Branch taken prefix (only with Jcc instructions) */
	{ .opcode1=0x3F, .mnemonic="AAS", .op={ {.reg="AL"}, {.reg="AH"}, 0, 0}, },            /* desc=ASCII Adjust AL After Subtraction */
	{ .opcode1=0x40, .flds=1, .mnemonic="INC", .op={ {.f=F_ADDR_Z | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Increment by 1 */
	{ .opcode1=0x48, .flds=1, .mnemonic="DEC", .op={ {.f=F_ADDR_Z | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Decrement by 1 */
	{ .opcode1=0x50, .flds=1, .mnemonic="PUSH", .op={ {.f=F_ADDR_Z | F_OPER_V}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x58, .flds=1, .mnemonic="POP", .op={ {.f=F_ADDR_Z | F_OPER_V}, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x60, .mnemonic="PUSHA", .op={ {.reg="AX"}, {.reg="CX"}, {.reg="DX"}, 0}, },            /* desc=Push All General-Purpose Registers */
	{ .opcode1=0x60, .mnemonic="PUSHAD", .op={ {.reg="EAX"}, {.reg="ECX"}, {.reg="EDX"}, 0}, },            /* desc=Push All General-Purpose Registers */
	{ .opcode1=0x61, .mnemonic="POPA", .op={ 0, 0, 0, 0}, },            /* desc=Pop All General-Purpose Registers */
	{ .opcode1=0x61, .mnemonic="POPAD", .op={ 0, 0, 0, 0}, },            /* desc=Pop All General-Purpose Registers */
	{ .opcode1=0x62, .reg_op='r', .mnemonic="BOUND", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_A}, {.f=F_ADDR_F | F_OPER_V}, 0}, },            /* desc=Check Array Index Against Bounds */
	{ .opcode1=0x63, .reg_op='r', .mnemonic="ARPL", .op={ {.f=F_ADDR_E | F_OPER_W}, {.f=F_ADDR_G | F_OPER_W}, 0, 0}, },            /* desc=Adjust RPL Field of Segment Selector */
	{ .prefix=0x64, .mnemonic="FS", .op={ {.reg="FS"}, 0, 0, 0}, },            /* desc=FS segment override prefix */
	{ .prefix=0x64, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=(only with Jcc instructions) */
	{ .prefix=0x64, .mnemonic="ALTER", .op={ 0, 0, 0, 0}, },            /* desc=Alternating branch prefix (only with Jcc instructions) */
	{ .prefix=0x65, .mnemonic="GS", .op={ {.reg="GS"}, 0, 0, 0}, },            /* desc=GS segment override prefix */
	{ .prefix=0x65, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=(only with Jcc instructions) */
	{ .prefix=0x66, .op={ 0, 0, 0, 0}, },            /* desc=Operand-size override prefix */
	{ .prefix=0x66, .op={ 0, 0, 0, 0}, },            /* desc=Precision-size override prefix */
	{ .prefix=0x67, .op={ 0, 0, 0, 0}, },            /* desc=Address-size override prefix */
	{ .opcode1=0x68, .mnemonic="PUSH", .op={ {.f=F_ADDR_I | F_OPER_VS}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x69, .reg_op='r', .mnemonic="IMUL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Multiply */
	{ .opcode1=0x6A, .mnemonic="PUSH", .op={ {.f=F_ADDR_I | F_OPER_BSS}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .opcode1=0x6B, .reg_op='r', .mnemonic="IMUL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Multiply */
	{ .opcode1=0x6C, .ops=(x86_in_ops[]){ { .mnemonic="INS", .op={ {.f=F_ADDR_Y | F_OPER_B}, {.reg="DX"}, 0, 0 }, }, { .mnemonic="INSB", .op={ {.f=F_ADDR_Y | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Input from Port to String */
	{ .opcode1=0x6D, .ops=(x86_in_ops[]){ { .mnemonic="INS", .op={ {.f=F_ADDR_Y | F_OPER_WO}, {.reg="DX"}, 0, 0 }, }, { .mnemonic="INSW", .op={ {.f=F_ADDR_Y | F_OPER_WO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Input from Port to String */
	{ .opcode1=0x6D, .ops=(x86_in_ops[]){ { .mnemonic="INS", .op={ {.f=F_ADDR_Y | F_OPER_V}, {.reg="DX"}, 0, 0 }, }, { .mnemonic="INSD", .op={ {.f=F_ADDR_Y | F_OPER_DO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Input from Port to String */
	{ .opcode1=0x6E, .ops=(x86_in_ops[]){ { .mnemonic="OUTS", .op={ {.reg="DX"}, {.f=F_ADDR_X | F_OPER_B}, 0, 0 }, }, { .mnemonic="OUTSB", .op={ {.reg="DX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Output String to Port */
	{ .opcode1=0x6F, .ops=(x86_in_ops[]){ { .mnemonic="OUTS", .op={ {.reg="DX"}, {.f=F_ADDR_X | F_OPER_WO}, 0, 0 }, }, { .mnemonic="OUTSW", .op={ {.reg="DX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Output String to Port */
	{ .opcode1=0x6F, .ops=(x86_in_ops[]){ { .mnemonic="OUTS", .op={ {.reg="DX"}, {.f=F_ADDR_X | F_OPER_V}, 0, 0 }, }, { .mnemonic="OUTSD", .op={ {.reg="DX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Output String to Port */
	{ .opcode1=0x70, .mnemonic="JO", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump short if overflow (OF=1) */
	{ .opcode1=0x71, .mnemonic="JNO", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump short if not overflow (OF=0) */
	{ .opcode1=0x72, .ops=(x86_in_ops[]){ { .mnemonic="JB", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNAE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JC", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=3,  },            /* desc=Jump short if below/not above or equal/carry (CF=1) */
	{ .opcode1=0x73, .ops=(x86_in_ops[]){ { .mnemonic="JNB", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JAE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNC", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=3,  },            /* desc=Jump short if not below/above or equal/not carry (CF=0) */
	{ .opcode1=0x74, .ops=(x86_in_ops[]){ { .mnemonic="JZ", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if zero/equal (ZF=1) */
	{ .opcode1=0x75, .ops=(x86_in_ops[]){ { .mnemonic="JNZ", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if not zero/not equal (ZF=0) */
	{ .opcode1=0x76, .ops=(x86_in_ops[]){ { .mnemonic="JBE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNA", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if below or equal/not above (CF=1 OR ZF=1) */
	{ .opcode1=0x77, .ops=(x86_in_ops[]){ { .mnemonic="JNBE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JA", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if not below or equal/above (CF=0 AND ZF=0) */
	{ .opcode1=0x78, .mnemonic="JS", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump short if sign (SF=1) */
	{ .opcode1=0x79, .mnemonic="JNS", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump short if not sign (SF=0) */
	{ .opcode1=0x7A, .ops=(x86_in_ops[]){ { .mnemonic="JP", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JPE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if parity/parity even (PF=1) */
	{ .opcode1=0x7B, .ops=(x86_in_ops[]){ { .mnemonic="JNP", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JPO", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if not parity/parity odd (PF=0) */
	{ .opcode1=0x7C, .ops=(x86_in_ops[]){ { .mnemonic="JL", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNGE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if less/not greater (SF!=OF) */
	{ .opcode1=0x7D, .ops=(x86_in_ops[]){ { .mnemonic="JNL", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JGE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if not less/greater or equal (SF=OF) */
	{ .opcode1=0x7E, .ops=(x86_in_ops[]){ { .mnemonic="JLE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNG", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
	{ .opcode1=0x7F, .ops=(x86_in_ops[]){ { .mnemonic="JNLE", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JG", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
	{ .opcode1=0x80, .reg_op='0', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x80, .reg_op=1, .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x80, .reg_op=2, .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x80, .reg_op=3, .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x80, .reg_op=4, .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x80, .reg_op=5, .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x80, .reg_op=6, .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x80, .reg_op=7, .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x81, .reg_op='0', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x81, .reg_op=1, .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x81, .reg_op=2, .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x81, .reg_op=3, .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x81, .reg_op=4, .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x81, .reg_op=5, .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x81, .reg_op=6, .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x81, .reg_op=7, .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x82, .reg_op='0', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x82, .reg_op=1, .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x82, .reg_op=2, .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x82, .reg_op=3, .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x82, .reg_op=4, .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x82, .reg_op=5, .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x82, .reg_op=6, .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x82, .reg_op=7, .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x83, .reg_op='0', .mnemonic="ADD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add */
	{ .opcode1=0x83, .reg_op=1, .mnemonic="OR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, },            /* desc=Logical Inclusive OR */
	{ .opcode1=0x83, .reg_op=2, .mnemonic="ADC", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Add with Carry */
	{ .opcode1=0x83, .reg_op=3, .mnemonic="SBB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Integer Subtraction with Borrow */
	{ .opcode1=0x83, .reg_op=4, .mnemonic="AND", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, },            /* desc=Logical AND */
	{ .opcode1=0x83, .reg_op=5, .mnemonic="SUB", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Subtract */
	{ .opcode1=0x83, .reg_op=6, .mnemonic="XOR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .opcode1=0x83, .reg_op=7, .mnemonic="CMP", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Compare Two Operands */
	{ .opcode1=0x84, .reg_op='r', .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0x85, .reg_op='r', .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0x86, .reg_op='r', .mnemonic="XCHG", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Exchange Register/Memory with Register */
	{ .opcode1=0x87, .reg_op='r', .mnemonic="XCHG", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Exchange Register/Memory with Register */
	{ .opcode1=0x88, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0x89, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0x8A, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_G | F_OPER_B}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0x8B, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0x8C, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="MOV", .op={ {.f=F_ADDR_M | F_OPER_W}, {.f=F_ADDR_S | F_OPER_W}, 0, 0 }, }, { .mnemonic="MOV", .op={ {.f=F_ADDR_R | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Move */
	{ .opcode1=0x8D, .reg_op='r', .mnemonic="LEA", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M}, 0, 0}, },            /* desc=Load Effective Address */
	{ .opcode1=0x8E, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_S | F_OPER_W}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0x8F, .reg_op='0', .mnemonic="POP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .opcode1=0x90, .flds=1, .mnemonic="XCHG", .op={ {.f=F_ADDR_Z | F_OPER_V}, {.reg="eAX"}, 0, 0}, },            /* desc=Exchange Register/Memory with Register */
	{ .opcode1=0x90, .mnemonic="NOP", .op={ 0, 0, 0, 0}, },            /* desc=No Operation */
	{ .prefix=0xF3, .opcode1=0x90, .mnemonic="NOP NOP", .op={ 0, 0, 0, 0}, },            /* desc=No Operation */
	{ .prefix=0xF3, .opcode1=0x90, .mnemonic="PAUSE", .op={ 0, 0, 0, 0}, },            /* desc=Spin Loop Hint */
	{ .opcode1=0x98, .mnemonic="CBW", .op={ {.reg="AX"}, {.reg="AL"}, 0, 0}, },            /* desc=Convert Byte to Word */
	{ .opcode1=0x98, .mnemonic="CWDE", .op={ {.reg="EAX"}, {.reg="AX"}, 0, 0}, },            /* desc=Convert Word to Doubleword */
	{ .opcode1=0x99, .mnemonic="CWD", .op={ {.reg="DX"}, {.reg="AX"}, 0, 0}, },            /* desc=Convert Word to Doubleword */
	{ .opcode1=0x99, .mnemonic="CDQ", .op={ {.reg="EDX"}, {.reg="EAX"}, 0, 0}, },            /* desc=Convert Doubleword to Quadword */
	{ .opcode1=0x9A, .mnemonic="CALLF", .op={ {.f=F_ADDR_A | F_OPER_P}, 0, 0, 0}, },            /* desc=Call Procedure */
	{ .opcode1=0x9B, .ops=(x86_in_ops[]){ { .mnemonic="FWAIT", .op={ 0, 0, 0, 0 }, }, { .mnemonic="WAIT", .op={ 0, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Check pending unmasked floating-point exceptions */
	{ .prefix=0x9B, .op={ 0, 0, 0, 0}, },            /* desc=Wait Prefix */
	{ .opcode1=0x9C, .mnemonic="PUSHF", .op={ {.f=F_ADDR_F | F_OPER_WO}, 0, 0, 0}, },            /* desc=Push FLAGS Register onto the Stack */
	{ .opcode1=0x9C, .mnemonic="PUSHFD", .op={ {.f=F_ADDR_F | F_OPER_DO}, 0, 0, 0}, },            /* desc=Push eFLAGS Register onto the Stack */
	{ .opcode1=0x9D, .mnemonic="POPF", .op={ {.f=F_ADDR_F | F_OPER_WO}, 0, 0, 0}, },            /* desc=Pop Stack into FLAGS Register */
	{ .opcode1=0x9D, .mnemonic="POPFD", .op={ {.f=F_ADDR_F | F_OPER_DO}, 0, 0, 0}, },            /* desc=Pop Stack into eFLAGS Register */
	{ .opcode1=0x9E, .mnemonic="SAHF", .op={ {.reg="AH"}, 0, 0, 0}, },            /* desc=Store AH into Flags */
	{ .opcode1=0x9F, .mnemonic="LAHF", .op={ {.reg="AH"}, 0, 0, 0}, },            /* desc=Load Status Flags into AH Register */
	{ .opcode1=0xA0, .mnemonic="MOV", .op={ {.reg="AL"}, {.f=F_ADDR_O | F_OPER_B}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xA1, .mnemonic="MOV", .op={ {.reg="eAX"}, {.f=F_ADDR_O | F_OPER_V}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xA2, .mnemonic="MOV", .op={ {.f=F_ADDR_O | F_OPER_B}, {.reg="AL"}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xA3, .mnemonic="MOV", .op={ {.f=F_ADDR_O | F_OPER_V}, {.reg="eAX"}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xA4, .ops=(x86_in_ops[]){ { .mnemonic="MOVS", .op={ {.f=F_ADDR_Y | F_OPER_B}, {.f=F_ADDR_X | F_OPER_B}, 0, 0 }, }, { .mnemonic="MOVSB", .op={ {.f=F_ADDR_Y | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Move Data from String to String */
	{ .opcode1=0xA5, .ops=(x86_in_ops[]){ { .mnemonic="MOVS", .op={ {.f=F_ADDR_Y | F_OPER_WO}, {.f=F_ADDR_X | F_OPER_WO}, 0, 0 }, }, { .mnemonic="MOVSW", .op={ {.f=F_ADDR_Y | F_OPER_WO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Move Data from String to String */
	{ .opcode1=0xA5, .ops=(x86_in_ops[]){ { .mnemonic="MOVS", .op={ {.f=F_ADDR_Y | F_OPER_V}, {.f=F_ADDR_X | F_OPER_V}, 0, 0 }, }, { .mnemonic="MOVSD", .op={ {.f=F_ADDR_Y | F_OPER_DO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Move Data from String to String */
	{ .opcode1=0xA6, .ops=(x86_in_ops[]){ { .mnemonic="CMPS", .op={ {.f=F_ADDR_Y | F_OPER_B}, {.f=F_ADDR_X | F_OPER_B}, 0, 0 }, }, { .mnemonic="CMPSB", .op={ {.f=F_ADDR_Y | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Compare String Operands */
	{ .opcode1=0xA7, .ops=(x86_in_ops[]){ { .mnemonic="CMPS", .op={ {.f=F_ADDR_Y | F_OPER_WO}, {.f=F_ADDR_X | F_OPER_WO}, 0, 0 }, }, { .mnemonic="CMPSW", .op={ {.f=F_ADDR_Y | F_OPER_WO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Compare String Operands */
	{ .opcode1=0xA7, .ops=(x86_in_ops[]){ { .mnemonic="CMPS", .op={ {.f=F_ADDR_Y | F_OPER_V}, {.f=F_ADDR_X | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMPSD", .op={ {.f=F_ADDR_Y | F_OPER_DO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Compare String Operands */
	{ .opcode1=0xA8, .mnemonic="TEST", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xA9, .mnemonic="TEST", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xAA, .ops=(x86_in_ops[]){ { .mnemonic="STOS", .op={ {.f=F_ADDR_Y | F_OPER_B}, {.reg="AL"}, 0, 0 }, }, { .mnemonic="STOSB", .op={ {.f=F_ADDR_Y | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store String */
	{ .opcode1=0xAB, .ops=(x86_in_ops[]){ { .mnemonic="STOS", .op={ {.f=F_ADDR_Y | F_OPER_WO}, {.reg="AX"}, 0, 0 }, }, { .mnemonic="STOSW", .op={ {.f=F_ADDR_Y | F_OPER_WO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store String */
	{ .opcode1=0xAB, .ops=(x86_in_ops[]){ { .mnemonic="STOS", .op={ {.f=F_ADDR_Y | F_OPER_V}, {.reg="eAX"}, 0, 0 }, }, { .mnemonic="STOSD", .op={ {.f=F_ADDR_Y | F_OPER_DO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store String */
	{ .opcode1=0xAC, .ops=(x86_in_ops[]){ { .mnemonic="LODS", .op={ {.reg="AL"}, {.f=F_ADDR_X | F_OPER_B}, 0, 0 }, }, { .mnemonic="LODSB", .op={ {.reg="AL"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Load String */
	{ .opcode1=0xAD, .ops=(x86_in_ops[]){ { .mnemonic="LODS", .op={ {.reg="AX"}, {.f=F_ADDR_X | F_OPER_WO}, 0, 0 }, }, { .mnemonic="LODSW", .op={ {.reg="AX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Load String */
	{ .opcode1=0xAD, .ops=(x86_in_ops[]){ { .mnemonic="LODS", .op={ {.reg="eAX"}, {.f=F_ADDR_X | F_OPER_V}, 0, 0 }, }, { .mnemonic="LODSD", .op={ {.reg="EAX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Load String */
	{ .opcode1=0xAE, .ops=(x86_in_ops[]){ { .mnemonic="SCAS", .op={ {.f=F_ADDR_Y | F_OPER_B}, {.reg="AL"}, 0, 0 }, }, { .mnemonic="SCASB", .op={ {.f=F_ADDR_Y | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Scan String */
	{ .opcode1=0xAF, .ops=(x86_in_ops[]){ { .mnemonic="SCAS", .op={ {.f=F_ADDR_Y | F_OPER_WO}, {.reg="AX"}, 0, 0 }, }, { .mnemonic="SCASW", .op={ {.f=F_ADDR_Y | F_OPER_WO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Scan String */
	{ .opcode1=0xAF, .ops=(x86_in_ops[]){ { .mnemonic="SCAS", .op={ {.f=F_ADDR_Y | F_OPER_V}, {.reg="eAX"}, 0, 0 }, }, { .mnemonic="SCASD", .op={ {.f=F_ADDR_Y | F_OPER_DO}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Scan String */
	{ .opcode1=0xB0, .flds=1, .mnemonic="MOV", .op={ {.f=F_ADDR_Z | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xB8, .flds=1, .mnemonic="MOV", .op={ {.f=F_ADDR_Z | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xC0, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC0, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC0, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC0, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC0, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xC0, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xC0, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xC0, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xC1, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC1, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC1, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC1, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xC1, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xC1, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xC1, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xC1, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xC2, .mnemonic="RETN", .op={ {.f=F_ADDR_I | F_OPER_W}, 0, 0, 0}, },            /* desc=Return from procedure */
	{ .opcode1=0xC3, .mnemonic="RETN", .op={ 0, 0, 0, 0}, },            /* desc=Return from procedure */
	{ .opcode1=0xC4, .reg_op='r', .mnemonic="LES", .op={ {.reg="ES"}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_P}, 0}, },            /* desc=Load Far Pointer */
	{ .opcode1=0xC5, .reg_op='r', .mnemonic="LDS", .op={ {.reg="DS"}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_P}, 0}, },            /* desc=Load Far Pointer */
	{ .opcode1=0xC6, .reg_op='0', .mnemonic="MOV", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xC7, .reg_op='0', .mnemonic="MOV", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Move */
	{ .opcode1=0xC8, .mnemonic="ENTER", .op={ {.reg="eBP"}, {.f=F_ADDR_I | F_OPER_W}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Make Stack Frame for Procedure Parameters */
	{ .opcode1=0xC9, .mnemonic="LEAVE", .op={ {.reg="eBP"}, 0, 0, 0}, },            /* desc=High Level Procedure Exit */
	{ .opcode1=0xCA, .mnemonic="RETF", .op={ {.f=F_ADDR_I | F_OPER_W}, 0, 0, 0}, },            /* desc=Return from procedure */
	{ .opcode1=0xCB, .mnemonic="RETF", .op={ 0, 0, 0, 0}, },            /* desc=Return from procedure */
	{ .opcode1=0xCC, .mnemonic="INT", .op={ {.v=3}, {.f=F_ADDR_F | F_OPER_V}, 0, 0}, },            /* desc=Call to Interrupt Procedure */
	{ .opcode1=0xCD, .mnemonic="INT", .op={ {.f=F_ADDR_I | F_OPER_B}, {.f=F_ADDR_F | F_OPER_V}, 0, 0}, },            /* desc=Call to Interrupt Procedure */
	{ .opcode1=0xCE, .mnemonic="INTO", .op={ {.f=F_ADDR_F | F_OPER_V}, 0, 0, 0}, },            /* desc=Call to Interrupt Procedure */
	{ .opcode1=0xCF, .mnemonic="IRET", .op={ {.f=F_ADDR_F | F_OPER_WO}, 0, 0, 0}, },            /* desc=Interrupt Return */
	{ .opcode1=0xCF, .mnemonic="IRETD", .op={ {.f=F_ADDR_F | F_OPER_DO}, 0, 0, 0}, },            /* desc=Interrupt Return */
	{ .opcode1=0xD0, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD0, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD0, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD0, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD0, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD0, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD0, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD0, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.v=1}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD1, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD1, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD1, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD1, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD1, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD1, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD1, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD1, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.v=1}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD2, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD2, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD2, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD2, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD2, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD2, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD2, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD2, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="CL"}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD3, .reg_op='0', .mnemonic="ROL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD3, .reg_op=1, .mnemonic="ROR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD3, .reg_op=2, .mnemonic="RCL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD3, .reg_op=3, .mnemonic="RCR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Rotate */
	{ .opcode1=0xD3, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0 }, }, { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD3, .reg_op=5, .mnemonic="SHR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD3, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="SAL", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0 }, }, { .mnemonic="SHL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Shift */
	{ .opcode1=0xD3, .reg_op=7, .mnemonic="SAR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="CL"}, 0, 0}, },            /* desc=Shift */
	{ .opcode1=0xD4, .opcode2=0x0A, .mnemonic="AAM", .op={ {.reg="AL"}, {.reg="AH"}, 0, 0}, },            /* desc=ASCII Adjust AX After Multiply */
	{ .opcode1=0xD4, .mnemonic="AMX", .op={ {.reg="AL"}, {.reg="AH"}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Adjust AX After Multiply */
	{ .opcode1=0xD5, .opcode2=0x0A, .mnemonic="AAD", .op={ {.reg="AL"}, {.reg="AH"}, 0, 0}, },            /* desc=ASCII Adjust AX Before Division */
	{ .opcode1=0xD5, .mnemonic="ADX", .op={ {.reg="AL"}, {.reg="AH"}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Adjust AX Before Division */
	{ .opcode1=0xD6, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=Undefined and Reserved; Does not Generate #UD */
	{ .opcode1=0xD6, .ops=(x86_in_ops[]){ { .mnemonic="SALC", .op={ {.reg="AL"}, 0, 0, 0 }, }, { .mnemonic="SETALC", .op={ {.reg="AL"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set AL If Carry */
	{ .opcode1=0xD7, .ops=(x86_in_ops[]){ { .mnemonic="XLAT", .op={ {.reg="AL"}, {.f=F_ADDR_BB | F_OPER_B}, 0, 0 }, }, { .mnemonic="XLATB", .op={ {.reg="AL"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Table Look-up Translation */
	{ .opcode1=0xD8, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="FADD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FADD", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Add */
	{ .opcode1=0xD8, .reg_op=1, .ops=(x86_in_ops[]){ { .mnemonic="FMUL", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FMUL", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Multiply */
	{ .opcode1=0xD8, .reg_op=2, .mnemonic="FCOM", .op={ {.reg="ST"}, {.f=F_ADDR_ES | F_OPER_SR}, 0, 0}, },            /* desc=Compare Real */
	{ .opcode1=0xD8, .opcode2=0xD1, .reg_op=2, .mnemonic="FCOM", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Compare Real */
	{ .opcode1=0xD8, .reg_op=3, .mnemonic="FCOMP", .op={ {.reg="ST"}, {.f=F_ADDR_ES | F_OPER_SR}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xD8, .opcode2=0xD9, .reg_op=3, .mnemonic="FCOMP", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xD8, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="FSUB", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FSUB", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Subtract */
	{ .opcode1=0xD8, .reg_op=5, .ops=(x86_in_ops[]){ { .mnemonic="FSUBR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FSUBR", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Reverse Subtract */
	{ .opcode1=0xD8, .reg_op=6, .ops=(x86_in_ops[]){ { .mnemonic="FDIV", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FDIV", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Divide */
	{ .opcode1=0xD8, .reg_op=7, .ops=(x86_in_ops[]){ { .mnemonic="FDIVR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_SR}, 0, 0 }, }, { .mnemonic="FDIVR", .op={ {.reg="ST"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Reverse Divide */
	{ .opcode1=0xD9, .reg_op='0', .mnemonic="FLD", .op={ {.reg="ST"}, {.f=F_ADDR_ES | F_OPER_SR}, 0, 0}, },            /* desc=Load Floating Point Value */
	{ .opcode1=0xD9, .reg_op=1, .mnemonic="FXCH", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xD9, .opcode2=0xC9, .reg_op=1, .mnemonic="FXCH", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xD9, .reg_op=2, .mnemonic="FST", .op={ {.f=F_ADDR_M | F_OPER_SR}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value */
	{ .opcode1=0xD9, .opcode2=0xD0, .reg_op=2, .mnemonic="FNOP", .op={ 0, 0, 0, 0}, },            /* desc=No Operation */
	{ .opcode1=0xD9, .reg_op=3, .mnemonic="FSTP", .op={ {.f=F_ADDR_M | F_OPER_SR}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xD9, .reg_op=3, .mnemonic="FSTP1", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xD9, .reg_op=3, .mnemonic="FSTP1", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xD9, .reg_op=4, .mnemonic="FLDENV", .op={ {.f=F_ADDR_M | F_OPER_E}, 0, 0, 0}, },            /* desc=Load x87 FPU Environment */
	{ .opcode1=0xD9, .opcode2=0xE0, .reg_op=4, .mnemonic="FCHS", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Change Sign */
	{ .opcode1=0xD9, .opcode2=0xE1, .reg_op=4, .mnemonic="FABS", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Absolute Value */
	{ .opcode1=0xD9, .opcode2=0xE4, .reg_op=4, .mnemonic="FTST", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Test */
	{ .opcode1=0xD9, .opcode2=0xE5, .reg_op=4, .mnemonic="FXAM", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Examine */
	{ .opcode1=0xD9, .reg_op=5, .mnemonic="FLDCW", .op={ {.f=F_ADDR_M | F_OPER_W}, 0, 0, 0}, },            /* desc=Load x87 FPU Control Word */
	{ .opcode1=0xD9, .opcode2=0xE8, .reg_op=5, .mnemonic="FLD1", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant +1.0 */
	{ .opcode1=0xD9, .opcode2=0xE9, .reg_op=5, .mnemonic="FLDL2T", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant log210 */
	{ .opcode1=0xD9, .opcode2=0xEA, .reg_op=5, .mnemonic="FLDL2E", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant log2e */
	{ .opcode1=0xD9, .opcode2=0xEB, .reg_op=5, .mnemonic="FLDPI", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant π */
	{ .opcode1=0xD9, .opcode2=0xEC, .reg_op=5, .mnemonic="FLDLG2", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant log102 */
	{ .opcode1=0xD9, .opcode2=0xED, .reg_op=5, .mnemonic="FLDLN2", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant loge2 */
	{ .opcode1=0xD9, .opcode2=0xEE, .reg_op=5, .mnemonic="FLDZ", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Load Constant +0.0 */
	{ .opcode1=0xD9, .reg_op=6, .mnemonic="FNSTENV", .op={ {.f=F_ADDR_M | F_OPER_E}, 0, 0, 0}, },            /* desc=Store x87 FPU Environment */
	{ .prefix=0x9B, .opcode1=0xD9, .reg_op=6, .mnemonic="FSTENV", .op={ {.f=F_ADDR_M | F_OPER_E}, 0, 0, 0}, },            /* desc=Store x87 FPU Environment */
	{ .opcode1=0xD9, .opcode2=0xF0, .reg_op=6, .mnemonic="F2XM1", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Compute 2x-1 */
	{ .opcode1=0xD9, .opcode2=0xF1, .reg_op=6, .mnemonic="FYL2X", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Compute y × log2x and Pop */
	{ .opcode1=0xD9, .opcode2=0xF2, .reg_op=6, .mnemonic="FPTAN", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Partial Tangent */
	{ .opcode1=0xD9, .opcode2=0xF3, .reg_op=6, .mnemonic="FPATAN", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Partial Arctangent and Pop */
	{ .opcode1=0xD9, .opcode2=0xF4, .reg_op=6, .mnemonic="FXTRACT", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Extract Exponent and Significand */
	{ .opcode1=0xD9, .opcode2=0xF5, .reg_op=6, .mnemonic="FPREM1", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=IEEE Partial Remainder */
	{ .opcode1=0xD9, .opcode2=0xF6, .reg_op=6, .mnemonic="FDECSTP", .op={ 0, 0, 0, 0}, },            /* desc=Decrement Stack-Top Pointer */
	{ .opcode1=0xD9, .opcode2=0xF7, .reg_op=6, .mnemonic="FINCSTP", .op={ 0, 0, 0, 0}, },            /* desc=Increment Stack-Top Pointer */
	{ .opcode1=0xD9, .reg_op=7, .mnemonic="FNSTCW", .op={ {.f=F_ADDR_M | F_OPER_W}, 0, 0, 0}, },            /* desc=Store x87 FPU Control Word */
	{ .prefix=0x9B, .opcode1=0xD9, .reg_op=7, .mnemonic="FSTCW", .op={ {.f=F_ADDR_M | F_OPER_W}, 0, 0, 0}, },            /* desc=Store x87 FPU Control Word */
	{ .opcode1=0xD9, .opcode2=0xF8, .reg_op=7, .mnemonic="FPREM", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Partial Remainder (for compatibility with i8087 and i287) */
	{ .opcode1=0xD9, .opcode2=0xF9, .reg_op=7, .mnemonic="FYL2XP1", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Compute y × log2(x+1) and Pop */
	{ .opcode1=0xD9, .opcode2=0xFA, .reg_op=7, .mnemonic="FSQRT", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Square Root */
	{ .opcode1=0xD9, .opcode2=0xFB, .reg_op=7, .mnemonic="FSINCOS", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Sine and Cosine */
	{ .opcode1=0xD9, .opcode2=0xFC, .reg_op=7, .mnemonic="FRNDINT", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Round to Integer */
	{ .opcode1=0xD9, .opcode2=0xFD, .reg_op=7, .mnemonic="FSCALE", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Scale */
	{ .opcode1=0xD9, .opcode2=0xFE, .reg_op=7, .mnemonic="FSIN", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Sine */
	{ .opcode1=0xD9, .opcode2=0xFF, .reg_op=7, .mnemonic="FCOS", .op={ {.reg="ST"}, 0, 0, 0}, },            /* desc=Cosine */
	{ .opcode1=0xDA, .reg_op='0', .mnemonic="FIADD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Add */
	{ .opcode1=0xDA, .reg_op='0', .mnemonic="FCMOVB", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - below (CF=1) */
	{ .opcode1=0xDA, .reg_op=1, .mnemonic="FIMUL", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Multiply */
	{ .opcode1=0xDA, .reg_op=1, .mnemonic="FCMOVE", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - equal (ZF=1) */
	{ .opcode1=0xDA, .reg_op=2, .mnemonic="FICOM", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Compare Integer */
	{ .opcode1=0xDA, .reg_op=2, .mnemonic="FCMOVBE", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - below or equal (CF=1 or ZF=1) */
	{ .opcode1=0xDA, .reg_op=3, .mnemonic="FICOMP", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Compare Integer and Pop */
	{ .opcode1=0xDA, .reg_op=3, .mnemonic="FCMOVU", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - unordered (PF=1) */
	{ .opcode1=0xDA, .reg_op=4, .mnemonic="FISUB", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Subtract */
	{ .opcode1=0xDA, .reg_op=5, .mnemonic="FISUBR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Reverse Subtract */
	{ .opcode1=0xDA, .opcode2=0xE9, .reg_op=5, .mnemonic="FUCOMPP", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values and Pop Twice */
	{ .opcode1=0xDA, .reg_op=6, .mnemonic="FIDIV", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Divide */
	{ .opcode1=0xDA, .reg_op=7, .mnemonic="FIDIVR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Reverse Divide */
	{ .opcode1=0xDB, .reg_op='0', .mnemonic="FILD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DI}, 0, 0}, },            /* desc=Load Integer */
	{ .opcode1=0xDB, .reg_op='0', .mnemonic="FCMOVNB", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - not below (CF=0) */
	{ .opcode1=0xDB, .reg_op=1, .mnemonic="FISTTP", .op={ {.f=F_ADDR_M | F_OPER_DI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer with Truncation and Pop */
	{ .opcode1=0xDB, .reg_op=1, .mnemonic="FCMOVNE", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - not equal (ZF=0) */
	{ .opcode1=0xDB, .reg_op=2, .mnemonic="FIST", .op={ {.f=F_ADDR_M | F_OPER_DI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer */
	{ .opcode1=0xDB, .reg_op=2, .mnemonic="FCMOVNBE", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - below or equal (CF=0 and ZF=0) */
	{ .opcode1=0xDB, .reg_op=3, .mnemonic="FISTP", .op={ {.f=F_ADDR_M | F_OPER_DI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer and Pop */
	{ .opcode1=0xDB, .reg_op=3, .mnemonic="FCMOVNU", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=FP Conditional Move - not unordered (PF=0) */
	{ .opcode1=0xDB, .opcode2=0xE0, .reg_op=4, .mnemonic="FNENI", .op={ 0, 0, 0, 0}, },            /* desc=Enable NPX Interrupt */
	{ .prefix=0x9B, .opcode1=0xDB, .opcode2=0xE0, .reg_op=4, .mnemonic="FENI", .op={ 0, 0, 0, 0}, },            /* desc=Enable NPX Interrupt */
	{ .opcode1=0xDB, .opcode2=0xE0, .reg_op=4, .mnemonic="FNENI NOP", .op={ 0, 0, 0, 0}, },            /* desc=Treated as Integer NOP */
	{ .opcode1=0xDB, .opcode2=0xE1, .reg_op=4, .mnemonic="FNDISI", .op={ 0, 0, 0, 0}, },            /* desc=Disable NPX Interrupt */
	{ .prefix=0x9B, .opcode1=0xDB, .opcode2=0xE1, .reg_op=4, .mnemonic="FDISI", .op={ 0, 0, 0, 0}, },            /* desc=Disable NPX Interrupt */
	{ .opcode1=0xDB, .opcode2=0xE1, .reg_op=4, .mnemonic="FNDISI NOP", .op={ 0, 0, 0, 0}, },            /* desc=Treated as Integer NOP */
	{ .opcode1=0xDB, .opcode2=0xE2, .reg_op=4, .mnemonic="FNCLEX", .op={ 0, 0, 0, 0}, },            /* desc=Clear Exceptions */
	{ .prefix=0x9B, .opcode1=0xDB, .opcode2=0xE2, .reg_op=4, .mnemonic="FCLEX", .op={ 0, 0, 0, 0}, },            /* desc=Clear Exceptions */
	{ .opcode1=0xDB, .opcode2=0xE3, .reg_op=4, .mnemonic="FNINIT", .op={ 0, 0, 0, 0}, },            /* desc=Initialize Floating-Point Unit */
	{ .prefix=0x9B, .opcode1=0xDB, .opcode2=0xE3, .reg_op=4, .mnemonic="FINIT", .op={ 0, 0, 0, 0}, },            /* desc=Initialize Floating-Point Unit */
	{ .opcode1=0xDB, .opcode2=0xE4, .reg_op=4, .mnemonic="FNSETPM", .op={ 0, 0, 0, 0}, },            /* desc=Set Protected Mode */
	{ .prefix=0x9B, .opcode1=0xDB, .opcode2=0xE4, .reg_op=4, .mnemonic="FSETPM", .op={ 0, 0, 0, 0}, },            /* desc=Set Protected Mode */
	{ .opcode1=0xDB, .opcode2=0xE4, .reg_op=4, .mnemonic="FNSETPM NOP", .op={ 0, 0, 0, 0}, },            /* desc=Treated as Integer NOP */
	{ .opcode1=0xDB, .reg_op=5, .mnemonic="FLD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_ER}, 0, 0}, },            /* desc=Load Floating Point Value */
	{ .opcode1=0xDB, .reg_op=5, .mnemonic="FUCOMI", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values and Set EFLAGS */
	{ .opcode1=0xDB, .reg_op=6, .mnemonic="FCOMI", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Floating Point Values and Set EFLAGS */
	{ .opcode1=0xDB, .reg_op=7, .mnemonic="FSTP", .op={ {.f=F_ADDR_M | F_OPER_ER}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDC, .reg_op='0', .mnemonic="FADD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Add */
	{ .opcode1=0xDC, .reg_op='0', .mnemonic="FADD", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Add */
	{ .opcode1=0xDC, .reg_op=1, .mnemonic="FMUL", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Multiply */
	{ .opcode1=0xDC, .reg_op=1, .mnemonic="FMUL", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Multiply */
	{ .opcode1=0xDC, .reg_op=2, .mnemonic="FCOM", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Compare Real */
	{ .opcode1=0xDC, .reg_op=2, .mnemonic="FCOM2", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real */
	{ .opcode1=0xDC, .reg_op=2, .mnemonic="FCOM2", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real */
	{ .opcode1=0xDC, .reg_op=3, .mnemonic="FCOMP", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xDC, .reg_op=3, .mnemonic="FCOMP3", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xDC, .reg_op=3, .mnemonic="FCOMP3", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xDC, .reg_op=4, .mnemonic="FSUB", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Subtract */
	{ .opcode1=0xDC, .reg_op=4, .mnemonic="FSUBR", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Subtract */
	{ .opcode1=0xDC, .reg_op=5, .mnemonic="FSUBR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Reverse Subtract */
	{ .opcode1=0xDC, .reg_op=5, .mnemonic="FSUB", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Subtract */
	{ .opcode1=0xDC, .reg_op=6, .mnemonic="FDIV", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Divide */
	{ .opcode1=0xDC, .reg_op=6, .mnemonic="FDIVR", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Divide */
	{ .opcode1=0xDC, .reg_op=7, .mnemonic="FDIVR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Reverse Divide */
	{ .opcode1=0xDC, .reg_op=7, .mnemonic="FDIV", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Divide and Pop */
	{ .opcode1=0xDD, .reg_op='0', .mnemonic="FLD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_DR}, 0, 0}, },            /* desc=Load Floating Point Value */
	{ .opcode1=0xDD, .reg_op='0', .mnemonic="FFREE", .op={ {.v=X86_FPU_ANY}, 0, 0, 0}, },            /* desc=Free Floating-Point Register */
	{ .opcode1=0xDD, .reg_op=1, .mnemonic="FISTTP", .op={ {.f=F_ADDR_M | F_OPER_QI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer with Truncation and Pop */
	{ .opcode1=0xDD, .reg_op=1, .mnemonic="FXCH4", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xDD, .reg_op=1, .mnemonic="FXCH4", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xDD, .reg_op=2, .mnemonic="FST", .op={ {.f=F_ADDR_M | F_OPER_DR}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value */
	{ .opcode1=0xDD, .reg_op=2, .mnemonic="FST", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Store Floating Point Value */
	{ .opcode1=0xDD, .reg_op=3, .mnemonic="FSTP", .op={ {.f=F_ADDR_M | F_OPER_DR}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDD, .reg_op=3, .mnemonic="FSTP", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDD, .reg_op=4, .mnemonic="FRSTOR", .op={ {.reg="ST"}, {.reg="ST1"}, {.reg="ST2"}, 0}, },            /* desc=Restore x87 FPU State */
	{ .opcode1=0xDD, .reg_op=4, .mnemonic="FUCOM", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values */
	{ .opcode1=0xDD, .opcode2=0xE1, .reg_op=4, .mnemonic="FUCOM", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values */
	{ .opcode1=0xDD, .reg_op=5, .mnemonic="FUCOMP", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values and Pop */
	{ .opcode1=0xDD, .opcode2=0xE9, .reg_op=5, .mnemonic="FUCOMP", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values and Pop */
	{ .opcode1=0xDD, .reg_op=6, .mnemonic="FNSAVE", .op={ {.f=F_ADDR_M | F_OPER_ST}, {.reg="ST"}, {.reg="ST1"}, 0}, },            /* desc=Store x87 FPU State */
	{ .prefix=0x9B, .opcode1=0xDD, .reg_op=6, .mnemonic="FSAVE", .op={ {.f=F_ADDR_M | F_OPER_ST}, {.reg="ST"}, {.reg="ST1"}, 0}, },            /* desc=Store x87 FPU State */
	{ .opcode1=0xDD, .reg_op=7, .mnemonic="FNSTSW", .op={ {.f=F_ADDR_M | F_OPER_W}, 0, 0, 0}, },            /* desc=Store x87 FPU Status Word */
	{ .prefix=0x9B, .opcode1=0xDD, .reg_op=7, .mnemonic="FSTSW", .op={ {.f=F_ADDR_M | F_OPER_W}, 0, 0, 0}, },            /* desc=Store x87 FPU Status Word */
	{ .opcode1=0xDE, .reg_op='0', .mnemonic="FIADD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Add */
	{ .opcode1=0xDE, .reg_op='0', .mnemonic="FADDP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Add and Pop */
	{ .opcode1=0xDE, .opcode2=0xC1, .reg_op='0', .mnemonic="FADDP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Add and Pop */
	{ .opcode1=0xDE, .reg_op=1, .mnemonic="FIMUL", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Multiply */
	{ .opcode1=0xDE, .reg_op=1, .mnemonic="FMULP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Multiply and Pop */
	{ .opcode1=0xDE, .opcode2=0xC9, .reg_op=1, .mnemonic="FMULP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Multiply and Pop */
	{ .opcode1=0xDE, .reg_op=2, .mnemonic="FICOM", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Compare Integer */
	{ .opcode1=0xDE, .reg_op=2, .mnemonic="FCOMP5", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xDE, .reg_op=2, .mnemonic="FCOMP5", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Real and Pop */
	{ .opcode1=0xDE, .reg_op=3, .mnemonic="FICOMP", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Compare Integer and Pop */
	{ .opcode1=0xDE, .opcode2=0xD9, .reg_op=3, .mnemonic="FCOMPP", .op={ {.reg="ST"}, {.reg="ST1"}, 0, 0}, },            /* desc=Compare Real and Pop Twice */
	{ .opcode1=0xDE, .reg_op=4, .mnemonic="FISUB", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Subtract */
	{ .opcode1=0xDE, .reg_op=4, .mnemonic="FSUBRP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Subtract and Pop */
	{ .opcode1=0xDE, .opcode2=0xE1, .reg_op=4, .mnemonic="FSUBRP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Subtract and Pop */
	{ .opcode1=0xDE, .reg_op=5, .mnemonic="FISUBR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Reverse Subtract */
	{ .opcode1=0xDE, .reg_op=5, .mnemonic="FSUBP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Subtract and Pop */
	{ .opcode1=0xDE, .opcode2=0xE9, .reg_op=5, .mnemonic="FSUBP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Subtract and Pop */
	{ .opcode1=0xDE, .reg_op=6, .mnemonic="FIDIV", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Divide */
	{ .opcode1=0xDE, .reg_op=6, .mnemonic="FDIVRP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Divide and Pop */
	{ .opcode1=0xDE, .opcode2=0xF1, .reg_op=6, .mnemonic="FDIVRP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Reverse Divide and Pop */
	{ .opcode1=0xDE, .reg_op=7, .mnemonic="FIDIVR", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Reverse Divide */
	{ .opcode1=0xDE, .reg_op=7, .mnemonic="FDIVP", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Divide and Pop */
	{ .opcode1=0xDE, .opcode2=0xF9, .reg_op=7, .mnemonic="FDIVP", .op={ {.reg="ST1"}, {.reg="ST"}, 0, 0}, },            /* desc=Divide and Pop */
	{ .opcode1=0xDF, .reg_op='0', .mnemonic="FILD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_WI}, 0, 0}, },            /* desc=Load Integer */
	{ .opcode1=0xDF, .reg_op='0', .mnemonic="FFREEP", .op={ {.v=X86_FPU_ANY}, 0, 0, 0}, },            /* desc=Free Floating-Point Register and Pop */
	{ .opcode1=0xDF, .reg_op=1, .mnemonic="FISTTP", .op={ {.f=F_ADDR_M | F_OPER_WI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer with Truncation and Pop */
	{ .opcode1=0xDF, .reg_op=1, .mnemonic="FXCH7", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xDF, .reg_op=1, .mnemonic="FXCH7", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Exchange Register Contents */
	{ .opcode1=0xDF, .reg_op=2, .mnemonic="FIST", .op={ {.f=F_ADDR_M | F_OPER_WI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer */
	{ .opcode1=0xDF, .reg_op=2, .mnemonic="FSTP8", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDF, .reg_op=2, .mnemonic="FSTP8", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDF, .reg_op=3, .mnemonic="FISTP", .op={ {.f=F_ADDR_M | F_OPER_WI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer and Pop */
	{ .opcode1=0xDF, .reg_op=3, .mnemonic="FSTP9", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDF, .reg_op=3, .mnemonic="FSTP9", .op={ {.v=X86_FPU_ANY}, {.reg="ST"}, 0, 0}, },            /* desc=Store Floating Point Value and Pop */
	{ .opcode1=0xDF, .reg_op=4, .mnemonic="FBLD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_BCD}, 0, 0}, },            /* desc=Load Binary Coded Decimal */
	{ .opcode1=0xDF, .opcode2=0xE0, .reg_op=4, .mnemonic="FNSTSW", .op={ {.reg="AX"}, 0, 0, 0}, },            /* desc=Store x87 FPU Status Word */
	{ .prefix=0x9B, .opcode1=0xDF, .opcode2=0xE0, .reg_op=4, .mnemonic="FSTSW", .op={ {.reg="AX"}, 0, 0, 0}, },            /* desc=Store x87 FPU Status Word */
	{ .opcode1=0xDF, .reg_op=5, .mnemonic="FILD", .op={ {.reg="ST"}, {.f=F_ADDR_M | F_OPER_QI}, 0, 0}, },            /* desc=Load Integer */
	{ .opcode1=0xDF, .reg_op=5, .mnemonic="FUCOMIP", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Unordered Compare Floating Point Values and Set EFLAGS and Pop */
	{ .opcode1=0xDF, .reg_op=6, .mnemonic="FBSTP", .op={ {.f=F_ADDR_M | F_OPER_BCD}, {.reg="ST"}, 0, 0}, },            /* desc=Store BCD Integer and Pop */
	{ .opcode1=0xDF, .reg_op=6, .mnemonic="FCOMIP", .op={ {.reg="ST"}, {.v=X86_FPU_ANY}, 0, 0}, },            /* desc=Compare Floating Point Values and Set EFLAGS and Pop */
	{ .opcode1=0xDF, .reg_op=7, .mnemonic="FISTP", .op={ {.f=F_ADDR_M | F_OPER_QI}, {.reg="ST"}, 0, 0}, },            /* desc=Store Integer and Pop */
	{ .opcode1=0xE0, .ops=(x86_in_ops[]){ { .mnemonic="LOOPNZ", .op={ {.reg="eCX"}, {.f=F_ADDR_J | F_OPER_BS}, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="LOOPNE", .op={ {.reg="eCX"}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Decrement count; Jump short if count!=0 and ZF=0 */
	{ .opcode1=0xE1, .ops=(x86_in_ops[]){ { .mnemonic="LOOPZ", .op={ {.reg="eCX"}, {.f=F_ADDR_J | F_OPER_BS}, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="LOOPE", .op={ {.reg="eCX"}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Decrement count; Jump short if count!=0 and ZF=1 */
	{ .opcode1=0xE2, .mnemonic="LOOP", .op={ {.reg="eCX"}, {.f=F_ADDR_J | F_OPER_BS}, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Decrement count; Jump short if count!=0 */
	{ .opcode1=0xE3, .ops=(x86_in_ops[]){ { .mnemonic="JCXZ", .op={ {.f=F_ADDR_J | F_OPER_BS}, {.reg="CX"}, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JECXZ", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump short if eCX register is 0 */
	{ .opcode1=0xE4, .mnemonic="IN", .op={ {.reg="AL"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Input from Port */
	{ .opcode1=0xE5, .mnemonic="IN", .op={ {.reg="eAX"}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Input from Port */
	{ .opcode1=0xE6, .mnemonic="OUT", .op={ {.f=F_ADDR_I | F_OPER_B}, {.reg="AL"}, 0, 0}, },            /* desc=Output to Port */
	{ .opcode1=0xE7, .mnemonic="OUT", .op={ {.f=F_ADDR_I | F_OPER_B}, {.reg="eAX"}, 0, 0}, },            /* desc=Output to Port */
	{ .opcode1=0xE8, .mnemonic="CALL", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, },            /* desc=Call Procedure */
	{ .opcode1=0xE9, .mnemonic="JMP", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, },            /* desc=Jump */
	{ .opcode1=0xEA, .mnemonic="JMPF", .op={ {.f=F_ADDR_A | F_OPER_P}, 0, 0, 0}, },            /* desc=Jump */
	{ .opcode1=0xEB, .mnemonic="JMP", .op={ {.f=F_ADDR_J | F_OPER_BS}, 0, 0, 0}, },            /* desc=Jump */
	{ .opcode1=0xEC, .mnemonic="IN", .op={ {.reg="AL"}, {.reg="DX"}, 0, 0}, },            /* desc=Input from Port */
	{ .opcode1=0xED, .mnemonic="IN", .op={ {.reg="eAX"}, {.reg="DX"}, 0, 0}, },            /* desc=Input from Port */
	{ .opcode1=0xEE, .mnemonic="OUT", .op={ {.reg="DX"}, {.reg="AL"}, 0, 0}, },            /* desc=Output to Port */
	{ .opcode1=0xEF, .mnemonic="OUT", .op={ {.reg="DX"}, {.reg="eAX"}, 0, 0}, },            /* desc=Output to Port */
	{ .prefix=0xF0, .mnemonic="LOCK", .op={ 0, 0, 0, 0}, },            /* desc=Assert LOCK# Signal Prefix */
	{ .opcode1=0xF1, .mnemonic="UNDEFINED", .op={ 0, 0, 0, 0}, },            /* desc=Undefined and Reserved; Does not Generate #UD */
	{ .opcode1=0xF1, .ops=(x86_in_ops[]){ { .mnemonic="INT1", .op={ {.f=F_ADDR_F | F_OPER_V}, 0, 0, 0 }, }, { .mnemonic="ICEBP", .op={ {.f=F_ADDR_F | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Call to Interrupt Procedure */
	{ .prefix=0xF2, .ops=(x86_in_ops[]){ { .mnemonic="REPNZ", .op={ {.reg="eCX"}, 0, 0, 0 }, }, { .mnemonic="REPNE", .op={ {.reg="eCX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Repeat String Operation Prefix */
	{ .prefix=0xF2, .mnemonic="REP", .op={ {.reg="eCX"}, 0, 0, 0}, },            /* desc=Repeat String Operation Prefix */
	{ .prefix=0xF2, .op={ 0, 0, 0, 0}, },            /* desc=Scalar Double-precision Prefix */
	{ .prefix=0xF3, .ops=(x86_in_ops[]){ { .mnemonic="REPZ", .op={ {.reg="eCX"}, 0, 0, 0 }, }, { .mnemonic="REPE", .op={ {.reg="eCX"}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Repeat String Operation Prefix */
	{ .prefix=0xF3, .mnemonic="REP", .op={ {.reg="eCX"}, 0, 0, 0}, },            /* desc=Repeat String Operation Prefix */
	{ .prefix=0xF3, .op={ 0, 0, 0, 0}, },            /* desc=Scalar Single-precision Prefix */
	{ .opcode1=0xF4, .mnemonic="HLT", .op={ 0, 0, 0, 0}, },            /* desc=Halt */
	{ .opcode1=0xF5, .mnemonic="CMC", .op={ 0, 0, 0, 0}, },            /* desc=Complement Carry Flag */
	{ .opcode1=0xF6, .reg_op='0', .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xF6, .reg_op=1, .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xF6, .reg_op=2, .mnemonic="NOT", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, },            /* desc=One's Complement Negation */
	{ .opcode1=0xF6, .reg_op=3, .mnemonic="NEG", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Two's Complement Negation */
	{ .opcode1=0xF6, .reg_op=4, .mnemonic="MUL", .op={ {.reg="AX"}, {.reg="AL"}, {.f=F_ADDR_E | F_OPER_B}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Unsigned Multiply */
	{ .opcode1=0xF6, .reg_op=5, .mnemonic="IMUL", .op={ {.reg="AX"}, {.reg="AL"}, {.f=F_ADDR_E | F_OPER_B}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Multiply */
	{ .opcode1=0xF6, .reg_op=6, .mnemonic="DIV", .op={ {.reg="AL"}, {.reg="AH"}, {.reg="AX"}, {.f=F_ADDR_E | F_OPER_B}}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Unsigned Divide */
	{ .opcode1=0xF6, .reg_op=7, .mnemonic="IDIV", .op={ {.reg="AL"}, {.reg="AH"}, {.reg="AX"}, {.f=F_ADDR_E | F_OPER_B}}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Divide */
	{ .opcode1=0xF7, .reg_op='0', .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xF7, .reg_op=1, .mnemonic="TEST", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_V}, 0, 0}, },            /* desc=Logical Compare */
	{ .opcode1=0xF7, .reg_op=2, .mnemonic="NOT", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=One's Complement Negation */
	{ .opcode1=0xF7, .reg_op=3, .mnemonic="NEG", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Two's Complement Negation */
	{ .opcode1=0xF7, .reg_op=4, .mnemonic="MUL", .op={ {.reg="eDX"}, {.reg="eAX"}, {.f=F_ADDR_E | F_OPER_V}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Unsigned Multiply */
	{ .opcode1=0xF7, .reg_op=5, .mnemonic="IMUL", .op={ {.reg="eDX"}, {.reg="eAX"}, {.f=F_ADDR_E | F_OPER_V}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Multiply */
	{ .opcode1=0xF7, .reg_op=6, .mnemonic="DIV", .op={ {.reg="eDX"}, {.reg="eAX"}, {.f=F_ADDR_E | F_OPER_V}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Unsigned Divide */
	{ .opcode1=0xF7, .reg_op=7, .mnemonic="IDIV", .op={ {.reg="eDX"}, {.reg="eAX"}, {.f=F_ADDR_E | F_OPER_V}, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Divide */
	{ .opcode1=0xF8, .mnemonic="CLC", .op={ 0, 0, 0, 0}, },            /* desc=Clear Carry Flag */
	{ .opcode1=0xF9, .mnemonic="STC", .op={ 0, 0, 0, 0}, },            /* desc=Set Carry Flag */
	{ .opcode1=0xFA, .mnemonic="CLI", .op={ 0, 0, 0, 0}, },            /* desc=Clear Interrupt Flag */
	{ .opcode1=0xFB, .mnemonic="STI", .op={ 0, 0, 0, 0}, },            /* desc=Set Interrupt Flag */
	{ .opcode1=0xFC, .mnemonic="CLD", .op={ 0, 0, 0, 0}, },            /* desc=Clear Direction Flag */
	{ .opcode1=0xFD, .mnemonic="STD", .op={ 0, 0, 0, 0}, },            /* desc=Set Direction Flag */
	{ .opcode1=0xFE, .reg_op='0', .mnemonic="INC", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Increment by 1 */
	{ .opcode1=0xFE, .reg_op=1, .mnemonic="DEC", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Decrement by 1 */
	{ .opcode1=0xFF, .reg_op='0', .mnemonic="INC", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Increment by 1 */
	{ .opcode1=0xFF, .reg_op=1, .mnemonic="DEC", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Decrement by 1 */
	{ .opcode1=0xFF, .reg_op=2, .mnemonic="CALL", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Call Procedure */
	{ .opcode1=0xFF, .reg_op=3, .mnemonic="CALLF", .op={ {.f=F_ADDR_M | F_OPER_P}, 0, 0, 0}, },            /* desc=Call Procedure */
	{ .opcode1=0xFF, .reg_op=4, .mnemonic="JMP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Jump */
	{ .opcode1=0xFF, .reg_op=5, .mnemonic="JMPF", .op={ {.f=F_ADDR_M | F_OPER_P}, 0, 0, 0}, },            /* desc=Jump */
	{ .opcode1=0xFF, .reg_op=6, .mnemonic="PUSH", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */

	/**
	 * Two-Byte Instr
	**/

	{ .two_byte=0x0f, .opcode1=0x00, .reg_op='0', .m=MODOP_P, .ops=(x86_in_ops[]){ { .mnemonic="SLDT", .op={ {.f=F_ADDR_M | F_OPER_W}, {.reg="X86_LDTR"}, 0, 0 }, }, { .mnemonic="SLDT", .op={ {.f=F_ADDR_R | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store Local Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=1, .m=MODOP_P, .ops=(x86_in_ops[]){ { .mnemonic="STR", .op={ {.f=F_ADDR_M | F_OPER_W}, {.reg="TR"}, 0, 0 }, }, { .mnemonic="STR", .op={ {.f=F_ADDR_R | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store Task Register */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=2, .m=MODOP_P, .mnemonic="LLDT", .op={ {.reg="X86_LDTR"}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Load Local Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=3, .m=MODOP_P, .mnemonic="LTR", .op={ {.reg="TR"}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Load Task Register */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=4, .m=MODOP_P, .mnemonic="VERR", .op={ {.f=F_ADDR_E | F_OPER_W}, 0, 0, 0}, },            /* desc=Verify a Segment for Reading */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=5, .m=MODOP_P, .mnemonic="VERW", .op={ {.f=F_ADDR_E | F_OPER_W}, 0, 0, 0}, },            /* desc=Verify a Segment for Writing */
	{ .two_byte=0x0f, .opcode1=0x00, .reg_op=6, .mnemonic="JMPE", .op={ 0, 0, 0, 0}, },            /* desc=Jump to IA-64 Instruction Set */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op='0', .mnemonic="SGDT", .op={ {.f=F_ADDR_M | F_OPER_S}, {.reg="X86_GDTR"}, 0, 0}, },            /* desc=Store Global Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC1, .reg_op='0', .m=MODOP_P, .mnemonic="VMCALL", .op={ 0, 0, 0, 0}, },            /* desc=Call to VM Monitor */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC2, .reg_op='0', .m=MODOP_P, .mnemonic="VMLAUNCH", .op={ 0, 0, 0, 0}, },            /* desc=Launch Virtual Machine */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC3, .reg_op='0', .m=MODOP_P, .mnemonic="VMRESUME", .op={ 0, 0, 0, 0}, },            /* desc=Resume Virtual Machine */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC4, .reg_op='0', .m=MODOP_P, .mnemonic="VMXOFF", .op={ 0, 0, 0, 0}, },            /* desc=Leave VMX Operation */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=1, .mnemonic="SIDT", .op={ {.f=F_ADDR_M | F_OPER_S}, {.reg="X86_IDTR"}, 0, 0}, },            /* desc=Store Interrupt Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC8, .reg_op=1, .mnemonic="MONITOR", .op={ {.f=F_ADDR_BA | F_OPER_B}, {.reg="ECX"}, {.reg="EDX"}, 0}, },            /* desc=Set Up Monitor Address */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xC9, .reg_op=1, .mnemonic="MWAIT", .op={ {.reg="EAX"}, {.reg="ECX"}, 0, 0}, },            /* desc=Monitor Wait */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=2, .mnemonic="LGDT", .op={ {.reg="X86_GDTR"}, {.f=F_ADDR_M | F_OPER_S}, 0, 0}, },            /* desc=Load Global Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xD0, .reg_op=2, .mnemonic="XGETBV", .op={ {.reg="EDX"}, {.reg="EAX"}, {.reg="ECX"}, {.reg="XCR"}}, },            /* desc=Get Value of Extended Control Register */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xD1, .reg_op=2, .mnemonic="XSETBV", .op={ {.reg="XCR"}, {.reg="ECX"}, {.reg="EDX"}, {.reg="EAX"}}, },            /* desc=Set Extended Control Register */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=3, .mnemonic="LIDT", .op={ {.reg="X86_IDTR"}, {.f=F_ADDR_M | F_OPER_S}, 0, 0}, },            /* desc=Load Interrupt Descriptor Table Register */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=4, .ops=(x86_in_ops[]){ { .mnemonic="SMSW", .op={ {.f=F_ADDR_M | F_OPER_W}, {.reg="MSW"}, 0, 0 }, }, { .mnemonic="SMSW", .op={ {.f=F_ADDR_R | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Store Machine Status Word */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=6, .mnemonic="LMSW", .op={ {.reg="MSW"}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Load Machine Status Word */
	{ .two_byte=0x0f, .opcode1=0x01, .reg_op=7, .mnemonic="INVLPG", .op={ {.f=F_ADDR_M}, 0, 0, 0}, },            /* desc=Invalidate TLB Entry */
	{ .two_byte=0x0f, .opcode1=0x01, .opcode2=0xF9, .reg_op=7, .mnemonic="RDTSCP", .op={ {.reg="EAX"}, {.reg="EDX"}, {.reg="ECX"}, 0}, },            /* desc=Read Time-Stamp Counter and Processor ID */
	{ .two_byte=0x0f, .opcode1=0x02, .reg_op='r', .m=MODOP_P, .ops=(x86_in_ops[]){ { .mnemonic="LAR", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_W}, 0, 0 }, }, { .mnemonic="LAR", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Load Access Rights Byte */
	{ .two_byte=0x0f, .opcode1=0x03, .reg_op='r', .m=MODOP_P, .ops=(x86_in_ops[]){ { .mnemonic="LSL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_W}, 0, 0 }, }, { .mnemonic="LSL", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Load Segment Limit */
	{ .two_byte=0x0f, .opcode1=0x05, .m=MODOP_P, .mnemonic="LOADALL", .op={ {.reg="AX"}, {.reg="CX"}, {.reg="DX"}, 0}, },            /* desc=Load All of the CPU Registers */
	{ .two_byte=0x0f, .opcode1=0x06, .mnemonic="CLTS", .op={ {.reg="CR0"}, 0, 0, 0}, },            /* desc=Clear Task-Switched Flag in CR0 */
	{ .two_byte=0x0f, .opcode1=0x07, .m=MODOP_P, .mnemonic="LOADALL", .op={ {.reg="EAX"}, {.reg="ECX"}, {.reg="EDX"}, 0}, },            /* desc=Load All of the CPU Registers */
	{ .two_byte=0x0f, .opcode1=0x08, .mnemonic="INVD", .op={ 0, 0, 0, 0}, },            /* desc=Invalidate Internal Caches */
	{ .two_byte=0x0f, .opcode1=0x09, .mnemonic="WBINVD", .op={ 0, 0, 0, 0}, },            /* desc=Write Back and Invalidate Cache */
	{ .two_byte=0x0f, .opcode1=0x0B, .mnemonic="UD2", .op={ 0, 0, 0, 0}, },            /* desc=Undefined Instruction */
	{ .two_byte=0x0f, .opcode1=0x0D, .mnemonic="NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=No Operation */
	{ .two_byte=0x0f, .opcode1=0x10, .reg_op='r', .mnemonic="MOVUPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Move Unaligned Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x10, .reg_op='r', .mnemonic="MOVSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Move Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x10, .reg_op='r', .mnemonic="MOVUPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Move Unaligned Packed Double-FP Value */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x10, .reg_op='r', .mnemonic="MOVSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Move Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x11, .reg_op='r', .mnemonic="MOVUPS", .op={ {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_V | F_OPER_PS}, 0, 0}, },            /* desc=Move Unaligned Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x11, .reg_op='r', .mnemonic="MOVSS", .op={ {.f=F_ADDR_W | F_OPER_SS}, {.f=F_ADDR_V | F_OPER_SS}, 0, 0}, },            /* desc=Move Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x11, .reg_op='r', .mnemonic="MOVUPD", .op={ {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_V | F_OPER_PD}, 0, 0}, },            /* desc=Move Unaligned Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x11, .reg_op='r', .mnemonic="MOVSD", .op={ {.f=F_ADDR_W | F_OPER_SD}, {.f=F_ADDR_V | F_OPER_SD}, 0, 0}, },            /* desc=Move Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x12, .reg_op='r', .mnemonic="MOVHLPS", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_U | F_OPER_Q}, 0, 0}, },            /* desc=Move Packed Single-FP Values High to Low */
	{ .two_byte=0x0f, .opcode1=0x12, .reg_op='r', .mnemonic="MOVLPS", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0}, },            /* desc=Move Low Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x12, .reg_op='r', .mnemonic="MOVLPD", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0}, },            /* desc=Move Low Packed Double-FP Value */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x12, .reg_op='r', .mnemonic="MOVDDUP", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Move One Double-FP and Duplicate */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x12, .reg_op='r', .mnemonic="MOVSLDUP", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Move Packed Single-FP Low and Duplicate */
	{ .two_byte=0x0f, .opcode1=0x13, .reg_op='r', .mnemonic="MOVLPS", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.f=F_ADDR_V | F_OPER_Q}, 0, 0}, },            /* desc=Move Low Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x13, .reg_op='r', .mnemonic="MOVLPD", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.f=F_ADDR_V | F_OPER_Q}, 0, 0}, },            /* desc=Move Low Packed Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x14, .reg_op='r', .mnemonic="UNPCKLPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Unpack and Interleave Low Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x14, .reg_op='r', .mnemonic="UNPCKLPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Unpack and Interleave Low Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x15, .reg_op='r', .mnemonic="UNPCKHPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Unpack and Interleave High Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x15, .reg_op='r', .mnemonic="UNPCKHPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Unpack and Interleave High Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x16, .reg_op='r', .mnemonic="MOVLHPS", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_U | F_OPER_Q}, 0, 0}, },            /* desc=Move Packed Single-FP Values Low to High */
	{ .two_byte=0x0f, .opcode1=0x16, .reg_op='r', .mnemonic="MOVHPS", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0}, },            /* desc=Move High Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x16, .reg_op='r', .mnemonic="MOVHPD", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0}, },            /* desc=Move High Packed Double-FP Value */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x16, .reg_op='r', .mnemonic="MOVSHDUP", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Move Packed Single-FP High and Duplicate */
	{ .two_byte=0x0f, .opcode1=0x17, .reg_op='r', .mnemonic="MOVHPS", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.f=F_ADDR_V | F_OPER_Q}, 0, 0}, },            /* desc=Move High Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x17, .reg_op='r', .mnemonic="MOVHPD", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.f=F_ADDR_V | F_OPER_Q}, 0, 0}, },            /* desc=Move High Packed Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x18, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op='0', .mnemonic="PREFETCHNTA", .op={ {.f=F_ADDR_M | F_OPER_B}, 0, 0, 0}, },            /* desc=Prefetch Data Into Caches */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=1, .mnemonic="PREFETCHT0", .op={ {.f=F_ADDR_M | F_OPER_B}, 0, 0, 0}, },            /* desc=Prefetch Data Into Caches */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=2, .mnemonic="PREFETCHT1", .op={ {.f=F_ADDR_M | F_OPER_B}, 0, 0, 0}, },            /* desc=Prefetch Data Into Caches */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=3, .mnemonic="PREFETCHT2", .op={ {.f=F_ADDR_M | F_OPER_B}, 0, 0, 0}, },            /* desc=Prefetch Data Into Caches */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=4, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=5, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=6, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x18, .reg_op=7, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x19, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1A, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1B, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1C, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1D, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1E, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op='0', .mnemonic="NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=No Operation */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=1, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=2, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=3, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=4, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=5, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=6, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x1F, .reg_op=7, .mnemonic="HINT_NOP", .op={ {.f=F_ADDR_E | F_OPER_V}, 0, 0, 0}, },            /* desc=Hintable NOP */
	{ .two_byte=0x0f, .opcode1=0x20, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_R | F_OPER_D}, {.f=F_ADDR_C | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Control Registers */
	{ .two_byte=0x0f, .opcode1=0x20, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_H | F_OPER_D}, {.f=F_ADDR_C | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Control Registers */
	{ .two_byte=0x0f, .opcode1=0x21, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_R | F_OPER_D}, {.f=F_ADDR_D | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Debug Registers */
	{ .two_byte=0x0f, .opcode1=0x21, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_H | F_OPER_D}, {.f=F_ADDR_D | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Debug Registers */
	{ .two_byte=0x0f, .opcode1=0x22, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_C | F_OPER_D}, {.f=F_ADDR_R | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Control Registers */
	{ .two_byte=0x0f, .opcode1=0x22, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_C | F_OPER_D}, {.f=F_ADDR_H | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Control Registers */
	{ .two_byte=0x0f, .opcode1=0x23, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_D | F_OPER_D}, {.f=F_ADDR_R | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Debug Registers */
	{ .two_byte=0x0f, .opcode1=0x23, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_D | F_OPER_Q}, {.f=F_ADDR_H | F_OPER_Q}, 0, 0}, },            /* desc=Move to/from Debug Registers */
	{ .two_byte=0x0f, .opcode1=0x24, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_R | F_OPER_D}, {.f=F_ADDR_T | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Test Registers */
	{ .two_byte=0x0f, .opcode1=0x24, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_H | F_OPER_D}, {.f=F_ADDR_T | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Test Registers */
	{ .two_byte=0x0f, .opcode1=0x26, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_T | F_OPER_D}, {.f=F_ADDR_R | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Test Registers */
	{ .two_byte=0x0f, .opcode1=0x26, .reg_op='r', .mnemonic="MOV", .op={ {.f=F_ADDR_T | F_OPER_D}, {.f=F_ADDR_H | F_OPER_D}, 0, 0}, },            /* desc=Move to/from Test Registers */
	{ .two_byte=0x0f, .opcode1=0x28, .reg_op='r', .mnemonic="MOVAPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Move Aligned Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x28, .reg_op='r', .mnemonic="MOVAPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Move Aligned Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x29, .reg_op='r', .mnemonic="MOVAPS", .op={ {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_V | F_OPER_PS}, 0, 0}, },            /* desc=Move Aligned Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x29, .reg_op='r', .mnemonic="MOVAPD", .op={ {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_V | F_OPER_PD}, 0, 0}, },            /* desc=Move Aligned Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x2A, .reg_op='r', .mnemonic="CVTPI2PS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_Q | F_OPER_PI}, 0, 0}, },            /* desc=Convert Packed DW Integers to Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x2A, .reg_op='r', .mnemonic="CVTSI2SS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_E | F_OPER_D}, 0, 0}, },            /* desc=Convert DW Integer to Scalar Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2A, .reg_op='r', .mnemonic="CVTPI2PD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_Q | F_OPER_PI}, 0, 0}, },            /* desc=Convert Packed DW Integers to Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x2A, .reg_op='r', .mnemonic="CVTSI2SD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_E | F_OPER_D}, 0, 0}, },            /* desc=Convert DW Integer to Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x2B, .reg_op='r', .mnemonic="MOVNTPS", .op={ {.f=F_ADDR_M | F_OPER_PS}, {.f=F_ADDR_V | F_OPER_PS}, 0, 0}, },            /* desc=Store Packed Single-FP Values Using Non-Temporal Hint */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2B, .reg_op='r', .mnemonic="MOVNTPD", .op={ {.f=F_ADDR_M | F_OPER_PD}, {.f=F_ADDR_V | F_OPER_PD}, 0, 0}, },            /* desc=Store Packed Double-FP Values Using Non-Temporal Hint */
	{ .two_byte=0x0f, .opcode1=0x2C, .reg_op='r', .mnemonic="CVTTPS2PI", .op={ {.f=F_ADDR_P | F_OPER_PI}, {.f=F_ADDR_W | F_OPER_PSQ}, 0, 0}, },            /* desc=Convert with Trunc. Packed Single-FP Values to DW Integers */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x2C, .reg_op='r', .mnemonic="CVTTSS2SI", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Convert with Trunc. Scalar Single-FP Value to DW Integer */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2C, .reg_op='r', .mnemonic="CVTTPD2PI", .op={ {.f=F_ADDR_P | F_OPER_PI}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Convert with Trunc. Packed Double-FP Values to DW Integers */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x2C, .reg_op='r', .mnemonic="CVTTSD2SI", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Conv. with Trunc. Scalar Double-FP Value to Signed DW Int */
	{ .two_byte=0x0f, .opcode1=0x2D, .reg_op='r', .mnemonic="CVTPS2PI", .op={ {.f=F_ADDR_P | F_OPER_PI}, {.f=F_ADDR_W | F_OPER_PSQ}, 0, 0}, },            /* desc=Convert Packed Single-FP Values to DW Integers */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x2D, .reg_op='r', .mnemonic="CVTSS2SI", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Convert Scalar Single-FP Value to DW Integer */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2D, .reg_op='r', .mnemonic="CVTPD2PI", .op={ {.f=F_ADDR_P | F_OPER_PI}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Convert Packed Double-FP Values to DW Integers */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x2D, .reg_op='r', .mnemonic="CVTSD2SI", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Convert Scalar Double-FP Value to DW Integer */
	{ .two_byte=0x0f, .opcode1=0x2E, .reg_op='r', .mnemonic="UCOMISS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Unordered Compare Scalar Single-FP Values and Set EFLAGS */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2E, .reg_op='r', .mnemonic="UCOMISD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Unordered Compare Scalar Double-FP Values and Set EFLAGS */
	{ .two_byte=0x0f, .opcode1=0x2F, .reg_op='r', .mnemonic="COMISS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Compare Scalar Ordered Single-FP Values and Set EFLAGS */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x2F, .reg_op='r', .mnemonic="COMISD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Compare Scalar Ordered Double-FP Values and Set EFLAGS */
	{ .two_byte=0x0f, .opcode1=0x30, .mnemonic="WRMSR", .op={ {.reg="MSR"}, {.reg="ECX"}, {.reg="EAX"}, {.reg="EDX"}}, },            /* desc=Write to Model Specific Register */
	{ .two_byte=0x0f, .opcode1=0x31, .mnemonic="RDTSC", .op={ {.reg="EAX"}, {.reg="EDX"}, {.f=F_ADDR_I}, 0}, },            /* desc=Read Time-Stamp Counter */
	{ .two_byte=0x0f, .opcode1=0x32, .mnemonic="RDMSR", .op={ {.reg="EAX"}, {.reg="EDX"}, {.reg="ECX"}, {.reg="MSR"}}, },            /* desc=Read from Model Specific Register */
	{ .two_byte=0x0f, .opcode1=0x33, .mnemonic="RDPMC", .op={ {.reg="EAX"}, {.reg="EDX"}, {.reg="PMC"}, 0}, },            /* desc=Read Performance-Monitoring Counters */
	{ .two_byte=0x0f, .opcode1=0x34, .m=MODOP_P, .mnemonic="SYSENTER", .op={ {.reg="SS"}, {.reg="ESP"}, {.f=F_ADDR_I}, 0}, },            /* desc=Fast System Call */
	{ .two_byte=0x0f, .opcode1=0x35, .m=MODOP_P, .mnemonic="SYSEXIT", .op={ {.reg="SS"}, {.reg="eSP"}, {.f=F_ADDR_I}, 0}, .grp=GRP(SYSTEM, BRANCH, TRANS),  },            /* desc=Fast Return from Fast System Call */
	{ .two_byte=0x0f, .opcode1=0x37, .mnemonic="GETSEC", .op={ {.reg="EAX"}, 0, 0, 0}, },            /* desc=GETSEC Leaf Functions */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x00, .reg_op='r', .mnemonic="PSHUFB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Shuffle Bytes */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x00, .reg_op='r', .mnemonic="PSHUFB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Shuffle Bytes */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x01, .reg_op='r', .mnemonic="PHADDW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Add */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x01, .reg_op='r', .mnemonic="PHADDW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Add */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x02, .reg_op='r', .mnemonic="PHADDD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Add */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x02, .reg_op='r', .mnemonic="PHADDD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Add */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x03, .reg_op='r', .mnemonic="PHADDSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Add and Saturate */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x03, .reg_op='r', .mnemonic="PHADDSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Add and Saturate */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x04, .reg_op='r', .mnemonic="PMADDUBSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Multiply and Add Packed Signed and Unsigned Bytes */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x04, .reg_op='r', .mnemonic="PMADDUBSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply and Add Packed Signed and Unsigned Bytes */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x05, .reg_op='r', .mnemonic="PHSUBW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Subtract */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x05, .reg_op='r', .mnemonic="PHSUBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Subtract */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x06, .reg_op='r', .mnemonic="PHSUBD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Subtract */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x06, .reg_op='r', .mnemonic="PHSUBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Subtract */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x07, .reg_op='r', .mnemonic="PHSUBSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Horizontal Subtract and Saturate */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x07, .reg_op='r', .mnemonic="PHSUBSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Subtract and Saturate */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x08, .reg_op='r', .mnemonic="PSIGNB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed SIGN */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x08, .reg_op='r', .mnemonic="PSIGNB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed SIGN */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x09, .reg_op='r', .mnemonic="PSIGNW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed SIGN */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x09, .reg_op='r', .mnemonic="PSIGNW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed SIGN */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x0A, .reg_op='r', .mnemonic="PSIGND", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed SIGN */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x0A, .reg_op='r', .mnemonic="PSIGND", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed SIGN */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x0B, .reg_op='r', .mnemonic="PMULHRSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Multiply High with Round and Scale */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x0B, .reg_op='r', .mnemonic="PMULHRSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Multiply High with Round and Scale */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x10, .reg_op='r', .mnemonic="PBLENDVB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.reg="XMM0"}, 0}, },            /* desc=Variable Blend Packed Bytes */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x14, .reg_op='r', .mnemonic="BLENDVPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, {.reg="XMM0"}, 0}, },            /* desc=Variable Blend Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x15, .reg_op='r', .mnemonic="BLENDVPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, {.reg="XMM0"}, 0}, },            /* desc=Variable Blend Packed Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x17, .reg_op='r', .mnemonic="PTEST", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Logical Compare */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1C, .reg_op='r', .mnemonic="PABSB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1C, .reg_op='r', .mnemonic="PABSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1D, .reg_op='r', .mnemonic="PABSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1D, .reg_op='r', .mnemonic="PABSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1E, .reg_op='r', .mnemonic="PABSD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x1E, .reg_op='r', .mnemonic="PABSD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Absolute Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x20, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVSXBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x21, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_D}, 0, 0 }, }, { .mnemonic="PMOVSXBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x22, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXBQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_W}, 0, 0 }, }, { .mnemonic="PMOVSXBQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x23, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVSXWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x24, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXWQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_D}, 0, 0 }, }, { .mnemonic="PMOVSXWQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x25, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVSXDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVSXDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Sign Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x28, .reg_op='r', .mnemonic="PMULDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Signed Dword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x29, .reg_op='r', .mnemonic="PCMPEQQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Qword Data for Equal */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x2A, .reg_op='r', .mnemonic="MOVNTDQA", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_DQ}, 0, 0}, },            /* desc=Load Double Quadword Non-Temporal Aligned Hint */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x2B, .reg_op='r', .mnemonic="PACKUSDW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Pack with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x30, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVZXBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x31, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_D}, 0, 0 }, }, { .mnemonic="PMOVZXBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x32, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXBQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_W}, 0, 0 }, }, { .mnemonic="PMOVZXBQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x33, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVZXWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x34, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXWQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_D}, 0, 0 }, }, { .mnemonic="PMOVZXWQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x35, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PMOVZXDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_Q}, 0, 0 }, }, { .mnemonic="PMOVZXDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Packed Move with Zero Extend */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x37, .reg_op='r', .mnemonic="PCMPGTQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Qword Data for Greater Than */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x38, .reg_op='r', .mnemonic="PMINSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Signed Byte Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x39, .reg_op='r', .mnemonic="PMINSD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Signed Dword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3A, .reg_op='r', .mnemonic="PMINUW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Unsigned Word Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3B, .reg_op='r', .mnemonic="PMINUD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Unsigned Dword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3C, .reg_op='r', .mnemonic="PMAXSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Signed Byte Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3D, .reg_op='r', .mnemonic="PMAXSD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Signed Dword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3E, .reg_op='r', .mnemonic="PMAXUW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Unsigned Word Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x3F, .reg_op='r', .mnemonic="PMAXUD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Unsigned Dword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x40, .reg_op='r', .mnemonic="PMULLD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Signed Dword Integers and Store Low Result */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x41, .reg_op='r', .mnemonic="PHMINPOSUW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Horizontal Word Minimum */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x80, .reg_op='r', .m=MODOP_P, .mnemonic="INVEPT", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_M | F_OPER_DQ}, 0, 0}, },            /* desc=Invalidate Translations Derived from EPT */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x38, .opcode2=0x81, .reg_op='r', .m=MODOP_P, .mnemonic="INVVPID", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_M | F_OPER_DQ}, 0, 0}, },            /* desc=Invalidate Translations Based on VPID */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0xF0, .reg_op='r', .mnemonic="MOVBE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_V}, 0, 0}, },            /* desc=Move Data After Swapping Bytes */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x38, .opcode2=0xF0, .reg_op='r', .mnemonic="CRC32", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Accumulate CRC32 Value */
	{ .two_byte=0x0f, .opcode1=0x38, .opcode2=0xF1, .reg_op='r', .mnemonic="MOVBE", .op={ {.f=F_ADDR_M | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Move Data After Swapping Bytes */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x38, .opcode2=0xF1, .reg_op='r', .mnemonic="CRC32", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Accumulate CRC32 Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x08, .reg_op='r', .mnemonic="ROUNDPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Round Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x09, .reg_op='r', .mnemonic="ROUNDPD", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Round Packed Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0A, .reg_op='r', .mnemonic="ROUNDSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Round Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0B, .reg_op='r', .mnemonic="ROUNDSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Round Scalar Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0C, .reg_op='r', .mnemonic="BLENDPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Blend Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0D, .reg_op='r', .mnemonic="BLENDPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Blend Packed Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0E, .reg_op='r', .mnemonic="PBLENDW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Blend Packed Words */
	{ .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0F, .reg_op='r', .mnemonic="PALIGNR", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Packed Align Right */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x0F, .reg_op='r', .mnemonic="PALIGNR", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Packed Align Right */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x14, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PEXTRB", .op={ {.f=F_ADDR_M | F_OPER_B}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PEXTRB", .op={ {.f=F_ADDR_R | F_OPER_D}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Extract Byte */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x15, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PEXTRW", .op={ {.f=F_ADDR_M | F_OPER_W}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PEXTRW", .op={ {.f=F_ADDR_R | F_OPER_D}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Extract Word */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x16, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PEXTRD", .op={ {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PEXTRQ", .op={ {.f=F_ADDR_E | F_OPER_QP}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Extract Dword/Qword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x17, .reg_op='r', .mnemonic="EXTRACTPS", .op={ {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Extract Packed Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x20, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PINSRB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_B}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PINSRB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Insert Byte */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x21, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="INSERTPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_M | F_OPER_D}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="INSERTPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Insert Packed Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x22, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PINSRD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PINSRQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Insert Dword/Qword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x40, .reg_op='r', .mnemonic="DPPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Dot Product of Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x41, .reg_op='r', .mnemonic="DPPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Dot Product of Packed Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x42, .reg_op='r', .mnemonic="MPSADBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Compute Multiple Packed Sums of Absolute Difference */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x60, .reg_op='r', .mnemonic="PCMPESTRM", .op={ {.reg="XMM0"}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0}, },            /* desc=Packed Compare Explicit Length Strings, Return Mask */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x61, .reg_op='r', .mnemonic="PCMPESTRI", .op={ {.reg="ECX"}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0}, },            /* desc=Packed Compare Explicit Length Strings, Return Index */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x62, .reg_op='r', .mnemonic="PCMPISTRM", .op={ {.reg="XMM0"}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}}, },            /* desc=Packed Compare Implicit Length Strings, Return Mask */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x3A, .opcode2=0x63, .reg_op='r', .mnemonic="PCMPISTRI", .op={ {.reg="ECX"}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}}, },            /* desc=Packed Compare Implicit Length Strings, Return Index */
	{ .two_byte=0x0f, .opcode1=0x40, .reg_op='r', .mnemonic="CMOVO", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Conditional Move - overflow (OF=1) */
	{ .two_byte=0x0f, .opcode1=0x41, .reg_op='r', .mnemonic="CMOVNO", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Conditional Move - not overflow (OF=0) */
	{ .two_byte=0x0f, .opcode1=0x42, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVB", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNAE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVC", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, },  }, .ops_count=3,  },            /* desc=Conditional Move - below/not above or equal/carry (CF=1) */
	{ .two_byte=0x0f, .opcode1=0x43, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNB", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVAE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNC", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, },  }, .ops_count=3,  },            /* desc=Conditional Move - not below/above or equal/not carry (CF=0) */
	{ .two_byte=0x0f, .opcode1=0x44, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVZ", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVE", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - zero/equal (ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x45, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNZ", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNE", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - not zero/not equal (ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x46, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVBE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNA", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - below or equal/not above (CF=1 OR ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x47, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNBE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVA", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - not below or equal/above (CF=0 AND ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x48, .reg_op='r', .mnemonic="CMOVS", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Conditional Move - sign (SF=1) */
	{ .two_byte=0x0f, .opcode1=0x49, .reg_op='r', .mnemonic="CMOVNS", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Conditional Move - not sign (SF=0) */
	{ .two_byte=0x0f, .opcode1=0x4A, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVP", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVPE", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - parity/parity even (PF=1) */
	{ .two_byte=0x0f, .opcode1=0x4B, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNP", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVPO", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - not parity/parity odd (PF=0) */
	{ .two_byte=0x0f, .opcode1=0x4C, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNGE", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - less/not greater (SF!=OF) */
	{ .two_byte=0x0f, .opcode1=0x4D, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVGE", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - not less/greater or equal (SF=OF) */
	{ .two_byte=0x0f, .opcode1=0x4E, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVLE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVNG", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - less or equal/not greater ((ZF=1) OR (SF!=OF)) */
	{ .two_byte=0x0f, .opcode1=0x4F, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="CMOVNLE", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0 }, }, { .mnemonic="CMOVG", .op={ {.f=F_ADDR_G | F_OPER_V}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Conditional Move - not less nor equal/greater ((ZF=0) AND (SF=OF)) */
	{ .two_byte=0x0f, .opcode1=0x50, .reg_op='r', .mnemonic="MOVMSKPS", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_U | F_OPER_PS}, 0, 0}, },            /* desc=Extract Packed Single-FP Sign Mask */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x50, .reg_op='r', .mnemonic="MOVMSKPD", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_U | F_OPER_PD}, 0, 0}, },            /* desc=Extract Packed Double-FP Sign Mask */
	{ .two_byte=0x0f, .opcode1=0x51, .reg_op='r', .mnemonic="SQRTPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Compute Square Roots of Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x51, .reg_op='r', .mnemonic="SQRTSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Compute Square Root of Scalar Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x51, .reg_op='r', .mnemonic="SQRTPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Compute Square Roots of Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x51, .reg_op='r', .mnemonic="SQRTSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Compute Square Root of Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x52, .reg_op='r', .mnemonic="RSQRTPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Compute Recipr. of Square Roots of Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x52, .reg_op='r', .mnemonic="RSQRTSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Compute Recipr. of Square Root of Scalar Single-FP Value */
	{ .two_byte=0x0f, .opcode1=0x53, .reg_op='r', .mnemonic="RCPPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Compute Reciprocals of Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x53, .reg_op='r', .mnemonic="RCPSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Compute Reciprocal of Scalar Single-FP Values */
	{ .two_byte=0x0f, .opcode1=0x54, .reg_op='r', .mnemonic="ANDPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Bitwise Logical AND of Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x54, .reg_op='r', .mnemonic="ANDPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Bitwise Logical AND of Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x55, .reg_op='r', .mnemonic="ANDNPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Bitwise Logical AND NOT of Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x55, .reg_op='r', .mnemonic="ANDNPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Bitwise Logical AND NOT of Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x56, .reg_op='r', .mnemonic="ORPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Bitwise Logical OR of Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x56, .reg_op='r', .mnemonic="ORPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Bitwise Logical OR of Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x57, .reg_op='r', .mnemonic="XORPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Bitwise Logical XOR for Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x57, .reg_op='r', .mnemonic="XORPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Bitwise Logical XOR for Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x58, .reg_op='r', .mnemonic="ADDPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Add Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x58, .reg_op='r', .mnemonic="ADDSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Add Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x58, .reg_op='r', .mnemonic="ADDPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Add Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x58, .reg_op='r', .mnemonic="ADDSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Add Scalar Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x59, .reg_op='r', .mnemonic="MULPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Multiply Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x59, .reg_op='r', .mnemonic="MULSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Multiply Scalar Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x59, .reg_op='r', .mnemonic="MULPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Multiply Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x59, .reg_op='r', .mnemonic="MULSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Multiply Scalar Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x5A, .reg_op='r', .mnemonic="CVTPS2PD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Convert Packed Single-FP Values to Double-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5A, .reg_op='r', .mnemonic="CVTPD2PS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Convert Packed Double-FP Values to Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5A, .reg_op='r', .mnemonic="CVTSS2SD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Convert Scalar Single-FP Value to Scalar Double-FP Value */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x5A, .reg_op='r', .mnemonic="CVTSD2SS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Convert Scalar Double-FP Value to Scalar Single-FP Value */
	{ .two_byte=0x0f, .opcode1=0x5B, .reg_op='r', .mnemonic="CVTDQ2PS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Convert Packed DW Integers to Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5B, .reg_op='r', .mnemonic="CVTPS2DQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Convert Packed Single-FP Values to DW Integers */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5B, .reg_op='r', .mnemonic="CVTTPS2DQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Convert with Trunc. Packed Single-FP Values to DW Integers */
	{ .two_byte=0x0f, .opcode1=0x5C, .reg_op='r', .mnemonic="SUBPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Subtract Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5C, .reg_op='r', .mnemonic="SUBSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Subtract Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5C, .reg_op='r', .mnemonic="SUBPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Subtract Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x5C, .reg_op='r', .mnemonic="SUBSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Subtract Scalar Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x5D, .reg_op='r', .mnemonic="MINPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Return Minimum Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5D, .reg_op='r', .mnemonic="MINSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Return Minimum Scalar Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5D, .reg_op='r', .mnemonic="MINPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Return Minimum Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x5D, .reg_op='r', .mnemonic="MINSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Return Minimum Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x5E, .reg_op='r', .mnemonic="DIVPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Divide Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5E, .reg_op='r', .mnemonic="DIVSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Divide Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5E, .reg_op='r', .mnemonic="DIVPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Divide Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x5E, .reg_op='r', .mnemonic="DIVSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Divide Scalar Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0x5F, .reg_op='r', .mnemonic="MAXPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Return Maximum Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x5F, .reg_op='r', .mnemonic="MAXSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, 0, 0}, },            /* desc=Return Maximum Scalar Single-FP Value */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x5F, .reg_op='r', .mnemonic="MAXPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Return Maximum Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x5F, .reg_op='r', .mnemonic="MAXSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, 0, 0}, },            /* desc=Return Maximum Scalar Double-FP Value */
	{ .two_byte=0x0f, .opcode1=0x60, .reg_op='r', .mnemonic="PUNPCKLBW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x60, .reg_op='r', .mnemonic="PUNPCKLBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .two_byte=0x0f, .opcode1=0x61, .reg_op='r', .mnemonic="PUNPCKLWD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x61, .reg_op='r', .mnemonic="PUNPCKLWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .two_byte=0x0f, .opcode1=0x62, .reg_op='r', .mnemonic="PUNPCKLDQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x62, .reg_op='r', .mnemonic="PUNPCKLDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .two_byte=0x0f, .opcode1=0x63, .reg_op='r', .mnemonic="PACKSSWB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Pack with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x63, .reg_op='r', .mnemonic="PACKSSWB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Pack with Signed Saturation */
	{ .two_byte=0x0f, .opcode1=0x64, .reg_op='r', .mnemonic="PCMPGTB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x64, .reg_op='r', .mnemonic="PCMPGTB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .two_byte=0x0f, .opcode1=0x65, .reg_op='r', .mnemonic="PCMPGTW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x65, .reg_op='r', .mnemonic="PCMPGTW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .two_byte=0x0f, .opcode1=0x66, .reg_op='r', .mnemonic="PCMPGTD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x66, .reg_op='r', .mnemonic="PCMPGTD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Signed Integers for Greater Than */
	{ .two_byte=0x0f, .opcode1=0x67, .reg_op='r', .mnemonic="PACKUSWB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Pack with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x67, .reg_op='r', .mnemonic="PACKUSWB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Pack with Unsigned Saturation */
	{ .two_byte=0x0f, .opcode1=0x68, .reg_op='r', .mnemonic="PUNPCKHBW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Unpack High Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x68, .reg_op='r', .mnemonic="PUNPCKHBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack High Data */
	{ .two_byte=0x0f, .opcode1=0x69, .reg_op='r', .mnemonic="PUNPCKHWD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Unpack High Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x69, .reg_op='r', .mnemonic="PUNPCKHWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack High Data */
	{ .two_byte=0x0f, .opcode1=0x6A, .reg_op='r', .mnemonic="PUNPCKHDQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Unpack High Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6A, .reg_op='r', .mnemonic="PUNPCKHDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack High Data */
	{ .two_byte=0x0f, .opcode1=0x6B, .reg_op='r', .mnemonic="PACKSSDW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Pack with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6B, .reg_op='r', .mnemonic="PACKSSDW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Pack with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6C, .reg_op='r', .mnemonic="PUNPCKLQDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack Low Data */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6D, .reg_op='r', .mnemonic="PUNPCKHQDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Unpack High Data */
	{ .two_byte=0x0f, .opcode1=0x6E, .reg_op='r', .mnemonic="MOVD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_E | F_OPER_D}, 0, 0}, },            /* desc=Move Doubleword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6E, .reg_op='r', .mnemonic="MOVD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_E | F_OPER_D}, 0, 0}, },            /* desc=Move Doubleword */
	{ .two_byte=0x0f, .opcode1=0x6F, .reg_op='r', .mnemonic="MOVQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x6F, .reg_op='r', .mnemonic="MOVDQA", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Move Aligned Double Quadword */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x6F, .reg_op='r', .mnemonic="MOVDQU", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Move Unaligned Double Quadword */
	{ .two_byte=0x0f, .opcode1=0x70, .reg_op='r', .mnemonic="PSHUFW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed Words */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x70, .reg_op='r', .mnemonic="PSHUFLW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed Low Words */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x70, .reg_op='r', .mnemonic="PSHUFHW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed High Words */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x70, .reg_op='r', .mnemonic="PSHUFD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed Doublewords */
	{ .two_byte=0x0f, .opcode1=0x71, .reg_op=2, .mnemonic="PSRLW", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x71, .reg_op=2, .mnemonic="PSRLW", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .two_byte=0x0f, .opcode1=0x71, .reg_op=4, .mnemonic="PSRAW", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x71, .reg_op=4, .mnemonic="PSRAW", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .two_byte=0x0f, .opcode1=0x71, .reg_op=6, .mnemonic="PSLLW", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x71, .reg_op=6, .mnemonic="PSLLW", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .two_byte=0x0f, .opcode1=0x72, .reg_op=2, .mnemonic="PSRLD", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Double Quadword Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x72, .reg_op=2, .mnemonic="PSRLD", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Double Quadword Right Logical */
	{ .two_byte=0x0f, .opcode1=0x72, .reg_op=4, .mnemonic="PSRAD", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x72, .reg_op=4, .mnemonic="PSRAD", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .two_byte=0x0f, .opcode1=0x72, .reg_op=6, .mnemonic="PSLLD", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x72, .reg_op=6, .mnemonic="PSLLD", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .two_byte=0x0f, .opcode1=0x73, .reg_op=2, .mnemonic="PSRLQ", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x73, .reg_op=2, .mnemonic="PSRLQ", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x73, .reg_op=3, .mnemonic="PSRLDQ", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Double Quadword Right Logical */
	{ .two_byte=0x0f, .opcode1=0x73, .reg_op=6, .mnemonic="PSLLQ", .op={ {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x73, .reg_op=6, .mnemonic="PSLLQ", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x73, .reg_op=7, .mnemonic="PSLLDQ", .op={ {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Shift Double Quadword Left Logical */
	{ .two_byte=0x0f, .opcode1=0x74, .reg_op='r', .mnemonic="PCMPEQB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x74, .reg_op='r', .mnemonic="PCMPEQB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .two_byte=0x0f, .opcode1=0x75, .reg_op='r', .mnemonic="PCMPEQW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x75, .reg_op='r', .mnemonic="PCMPEQW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .two_byte=0x0f, .opcode1=0x76, .reg_op='r', .mnemonic="PCMPEQD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x76, .reg_op='r', .mnemonic="PCMPEQD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compare Packed Data for Equal */
	{ .two_byte=0x0f, .opcode1=0x77, .mnemonic="EMMS", .op={ 0, 0, 0, 0}, },            /* desc=Empty MMX Technology State */
	{ .two_byte=0x0f, .opcode1=0x78, .reg_op='r', .m=MODOP_P, .mnemonic="VMREAD", .op={ {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_G | F_OPER_D}, 0, 0}, },            /* desc=Read Field from Virtual-Machine Control Structure */
	{ .two_byte=0x0f, .opcode1=0x79, .reg_op='r', .m=MODOP_P, .mnemonic="VMWRITE", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_E | F_OPER_D}, 0, 0}, },            /* desc=Write Field to Virtual-Machine Control Structure */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x7C, .reg_op='r', .mnemonic="HADDPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Packed Double-FP Horizontal Add */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x7C, .reg_op='r', .mnemonic="HADDPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Packed Single-FP Horizontal Add */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x7D, .reg_op='r', .mnemonic="HSUBPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Packed Double-FP Horizontal Subtract */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0x7D, .reg_op='r', .mnemonic="HSUBPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Packed Single-FP Horizontal Subtract */
	{ .two_byte=0x0f, .opcode1=0x7E, .reg_op='r', .mnemonic="MOVD", .op={ {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_P | F_OPER_Q}, 0, 0}, },            /* desc=Move Doubleword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x7E, .reg_op='r', .mnemonic="MOVD", .op={ {.f=F_ADDR_E | F_OPER_D}, {.f=F_ADDR_V | F_OPER_DQ}, 0, 0}, },            /* desc=Move Doubleword */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x7E, .reg_op='r', .mnemonic="MOVQ", .op={ {.f=F_ADDR_V | F_OPER_Q}, {.f=F_ADDR_W | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword */
	{ .two_byte=0x0f, .opcode1=0x7F, .reg_op='r', .mnemonic="MOVQ", .op={ {.f=F_ADDR_Q | F_OPER_Q}, {.f=F_ADDR_P | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0x7F, .reg_op='r', .mnemonic="MOVDQA", .op={ {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_V | F_OPER_DQ}, 0, 0}, },            /* desc=Move Aligned Double Quadword */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0x7F, .reg_op='r', .mnemonic="MOVDQU", .op={ {.f=F_ADDR_W | F_OPER_DQ}, {.f=F_ADDR_V | F_OPER_DQ}, 0, 0}, },            /* desc=Move Unaligned Double Quadword */
	{ .two_byte=0x0f, .opcode1=0x80, .mnemonic="JO", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump near if overflow (OF=1) */
	{ .two_byte=0x0f, .opcode1=0x81, .mnemonic="JNO", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump near if not overflow (OF=0) */
	{ .two_byte=0x0f, .opcode1=0x82, .ops=(x86_in_ops[]){ { .mnemonic="JB", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNAE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JC", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=3,  },            /* desc=Jump near if below/not above or equal/carry (CF=1) */
	{ .two_byte=0x0f, .opcode1=0x83, .ops=(x86_in_ops[]){ { .mnemonic="JNB", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JAE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNC", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=3,  },            /* desc=Jump near if not below/above or equal/not carry (CF=0) */
	{ .two_byte=0x0f, .opcode1=0x84, .ops=(x86_in_ops[]){ { .mnemonic="JZ", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if zero/equal (ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x85, .ops=(x86_in_ops[]){ { .mnemonic="JNZ", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if not zero/not equal (ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x86, .ops=(x86_in_ops[]){ { .mnemonic="JBE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNA", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if below or equal/not above (CF=1 OR ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x87, .ops=(x86_in_ops[]){ { .mnemonic="JNBE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JA", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if not below or equal/above (CF=0 AND ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x88, .mnemonic="JS", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump near if sign (SF=1) */
	{ .two_byte=0x0f, .opcode1=0x89, .mnemonic="JNS", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0}, .grp=GRP(GEN, BRANCH, COND),  },            /* desc=Jump near if not sign (SF=0) */
	{ .two_byte=0x0f, .opcode1=0x8A, .ops=(x86_in_ops[]){ { .mnemonic="JP", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JPE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if parity/parity even (PF=1) */
	{ .two_byte=0x0f, .opcode1=0x8B, .ops=(x86_in_ops[]){ { .mnemonic="JNP", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JPO", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if not parity/parity odd (PF=0) */
	{ .two_byte=0x0f, .opcode1=0x8C, .ops=(x86_in_ops[]){ { .mnemonic="JL", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNGE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if less/not greater (SF!=OF) */
	{ .two_byte=0x0f, .opcode1=0x8D, .ops=(x86_in_ops[]){ { .mnemonic="JNL", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JGE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if not less/greater or equal (SF=OF) */
	{ .two_byte=0x0f, .opcode1=0x8E, .ops=(x86_in_ops[]){ { .mnemonic="JLE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JNG", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
	{ .two_byte=0x0f, .opcode1=0x8F, .ops=(x86_in_ops[]){ { .mnemonic="JNLE", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), }, { .mnemonic="JG", .op={ {.f=F_ADDR_J | F_OPER_V}, 0, 0, 0 },  .grp=GRP(GEN, BRANCH, COND), },  }, .ops_count=2,  },            /* desc=Jump near if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
	{ .two_byte=0x0f, .opcode1=0x90, .reg_op='0', .mnemonic="SETO", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, },            /* desc=Set Byte on Condition - overflow (OF=1) */
	{ .two_byte=0x0f, .opcode1=0x91, .reg_op='0', .mnemonic="SETNO", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, },            /* desc=Set Byte on Condition - not overflow (OF=0) */
	{ .two_byte=0x0f, .opcode1=0x92, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETB", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNAE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETC", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=3,  },            /* desc=Set Byte on Condition - below/not above or equal/carry (CF=1) */
	{ .two_byte=0x0f, .opcode1=0x93, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNB", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETAE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNC", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=3,  },            /* desc=Set Byte on Condition - not below/above or equal/not carry (CF=0) */
	{ .two_byte=0x0f, .opcode1=0x94, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETZ", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - zero/equal (ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x95, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNZ", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - not zero/not equal (ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x96, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETBE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNA", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - below or equal/not above (CF=1 OR ZF=1) */
	{ .two_byte=0x0f, .opcode1=0x97, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNBE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETA", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - not below or equal/above (CF=0 AND ZF=0) */
	{ .two_byte=0x0f, .opcode1=0x98, .reg_op='0', .mnemonic="SETS", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, },            /* desc=Set Byte on Condition - sign (SF=1) */
	{ .two_byte=0x0f, .opcode1=0x99, .reg_op='0', .mnemonic="SETNS", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0}, },            /* desc=Set Byte on Condition - not sign (SF=0) */
	{ .two_byte=0x0f, .opcode1=0x9A, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETP", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETPE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - parity/parity even (PF=1) */
	{ .two_byte=0x0f, .opcode1=0x9B, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNP", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETPO", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - not parity/parity odd (PF=0) */
	{ .two_byte=0x0f, .opcode1=0x9C, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNGE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - less/not greater (SF!=OF) */
	{ .two_byte=0x0f, .opcode1=0x9D, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNL", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETGE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - not less/greater or equal (SF=OF) */
	{ .two_byte=0x0f, .opcode1=0x9E, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETLE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETNG", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - less or equal/not greater ((ZF=1) OR (SF!=OF)) */
	{ .two_byte=0x0f, .opcode1=0x9F, .reg_op='0', .ops=(x86_in_ops[]){ { .mnemonic="SETNLE", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, }, { .mnemonic="SETG", .op={ {.f=F_ADDR_E | F_OPER_B}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Set Byte on Condition - not less nor equal/greater ((ZF=0) AND (SF=OF)) */
	{ .two_byte=0x0f, .opcode1=0xA0, .mnemonic="PUSH", .op={ {.reg="FS"}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .two_byte=0x0f, .opcode1=0xA1, .mnemonic="POP", .op={ {.reg="FS"}, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .two_byte=0x0f, .opcode1=0xA2, .mnemonic="CPUID", .op={ {.f=F_ADDR_I}, {.reg="EAX"}, {.reg="ECX"}, 0}, },            /* desc=CPU Identification */
	{ .two_byte=0x0f, .opcode1=0xA3, .reg_op='r', .mnemonic="BT", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Bit Test */
	{ .two_byte=0x0f, .opcode1=0xA4, .reg_op='r', .mnemonic="SHLD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Double Precision Shift Left */
	{ .two_byte=0x0f, .opcode1=0xA5, .reg_op='r', .mnemonic="SHLD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, {.reg="CL"}, 0}, },            /* desc=Double Precision Shift Left */
	{ .two_byte=0x0f, .opcode1=0xA8, .mnemonic="PUSH", .op={ {.reg="GS"}, 0, 0, 0}, },            /* desc=Push Word, Doubleword or Quadword Onto the Stack */
	{ .two_byte=0x0f, .opcode1=0xA9, .mnemonic="POP", .op={ {.reg="GS"}, 0, 0, 0}, },            /* desc=Pop a Value from the Stack */
	{ .two_byte=0x0f, .opcode1=0xAA, .m=MODOP_S, .mnemonic="RSM", .op={ {.f=F_ADDR_F | F_OPER_W}, 0, 0, 0}, },            /* desc=Resume from System Management Mode */
	{ .two_byte=0x0f, .opcode1=0xAB, .reg_op='r', .mnemonic="BTS", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Bit Test and Set */
	{ .two_byte=0x0f, .opcode1=0xAC, .reg_op='r', .mnemonic="SHRD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Double Precision Shift Right */
	{ .two_byte=0x0f, .opcode1=0xAD, .reg_op='r', .mnemonic="SHRD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, {.reg="CL"}, 0}, },            /* desc=Double Precision Shift Right */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op='0', .mnemonic="FXSAVE", .op={ {.f=F_ADDR_M | F_OPER_STX}, {.reg="ST"}, {.reg="ST1"}, 0}, },            /* desc=Save x87 FPU, MMX, XMM, and MXCSR State */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=1, .mnemonic="FXRSTOR", .op={ {.reg="ST"}, {.reg="ST1"}, {.reg="ST2"}, 0}, },            /* desc=Restore x87 FPU, MMX, XMM, and MXCSR State */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=2, .mnemonic="LDMXCSR", .op={ {.f=F_ADDR_M | F_OPER_D}, 0, 0, 0}, },            /* desc=Load MXCSR Register */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=3, .mnemonic="STMXCSR", .op={ {.f=F_ADDR_M | F_OPER_D}, 0, 0, 0}, },            /* desc=Store MXCSR Register State */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=4, .mnemonic="XSAVE", .op={ {.f=F_ADDR_M}, {.reg="EDX"}, {.reg="EAX"}, 0}, },            /* desc=Save Processor Extended States */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=5, .mnemonic="LFENCE", .op={ 0, 0, 0, 0}, },            /* desc=Load Fence */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=5, .mnemonic="XRSTOR", .op={ {.reg="ST"}, {.reg="ST1"}, {.reg="ST2"}, 0}, },            /* desc=Restore Processor Extended States */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=6, .mnemonic="MFENCE", .op={ 0, 0, 0, 0}, },            /* desc=Memory Fence */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=7, .mnemonic="SFENCE", .op={ 0, 0, 0, 0}, },            /* desc=Store Fence */
	{ .two_byte=0x0f, .opcode1=0xAE, .reg_op=7, .mnemonic="CLFLUSH", .op={ {.f=F_ADDR_M | F_OPER_B}, 0, 0, 0}, },            /* desc=Flush Cache Line */
	{ .two_byte=0x0f, .opcode1=0xAF, .reg_op='r', .mnemonic="IMUL", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, .grp=GRP(GEN, ARITH, BINARY),  },            /* desc=Signed Multiply */
	{ .two_byte=0x0f, .opcode1=0xB0, .reg_op='r', .mnemonic="CMPXCHG", .op={ {.f=F_ADDR_E | F_OPER_B}, {.reg="AL"}, {.f=F_ADDR_G | F_OPER_B}, 0}, .grp=GRP(GEN, DATAMOV_ARITH, BINARY),  },            /* desc=Compare and Exchange */
	{ .two_byte=0x0f, .opcode1=0xB1, .reg_op='r', .mnemonic="CMPXCHG", .op={ {.f=F_ADDR_E | F_OPER_V}, {.reg="eAX"}, {.f=F_ADDR_G | F_OPER_V}, 0}, .grp=GRP(GEN, DATAMOV_ARITH, BINARY),  },            /* desc=Compare and Exchange */
	{ .two_byte=0x0f, .opcode1=0xB2, .reg_op='r', .mnemonic="LSS", .op={ {.reg="SS"}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_P}, 0}, },            /* desc=Load Far Pointer */
	{ .two_byte=0x0f, .opcode1=0xB3, .reg_op='r', .mnemonic="BTR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Bit Test and Reset */
	{ .two_byte=0x0f, .opcode1=0xB4, .reg_op='r', .mnemonic="LFS", .op={ {.reg="FS"}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_P}, 0}, },            /* desc=Load Far Pointer */
	{ .two_byte=0x0f, .opcode1=0xB5, .reg_op='r', .mnemonic="LGS", .op={ {.reg="GS"}, {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_M | F_OPER_P}, 0}, },            /* desc=Load Far Pointer */
	{ .two_byte=0x0f, .opcode1=0xB6, .reg_op='r', .mnemonic="MOVZX", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Move with Zero-Extend */
	{ .two_byte=0x0f, .opcode1=0xB7, .reg_op='r', .mnemonic="MOVZX", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Move with Zero-Extend */
	{ .two_byte=0x0f, .opcode1=0xB8, .mnemonic="JMPE", .op={ 0, 0, 0, 0}, },            /* desc=Jump to IA-64 Instruction Set */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0xB8, .reg_op='r', .mnemonic="POPCNT", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Bit Population Count */
	{ .two_byte=0x0f, .opcode1=0xB9, .reg_op='r', .mnemonic="UD", .op={ {.f=F_ADDR_G}, {.f=F_ADDR_E}, 0, 0}, },            /* desc=Undefined Instruction */
	{ .two_byte=0x0f, .opcode1=0xBA, .reg_op=4, .mnemonic="BT", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Bit Test */
	{ .two_byte=0x0f, .opcode1=0xBA, .reg_op=5, .mnemonic="BTS", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Bit Test and Set */
	{ .two_byte=0x0f, .opcode1=0xBA, .reg_op=6, .mnemonic="BTR", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Bit Test and Reset */
	{ .two_byte=0x0f, .opcode1=0xBA, .reg_op=7, .mnemonic="BTC", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_I | F_OPER_B}, 0, 0}, },            /* desc=Bit Test and Complement */
	{ .two_byte=0x0f, .opcode1=0xBB, .reg_op='r', .mnemonic="BTC", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, },            /* desc=Bit Test and Complement */
	{ .two_byte=0x0f, .opcode1=0xBC, .reg_op='r', .mnemonic="BSF", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Bit Scan Forward */
	{ .two_byte=0x0f, .opcode1=0xBD, .reg_op='r', .mnemonic="BSR", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_V}, 0, 0}, },            /* desc=Bit Scan Reverse */
	{ .two_byte=0x0f, .opcode1=0xBE, .reg_op='r', .mnemonic="MOVSX", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_B}, 0, 0}, },            /* desc=Move with Sign-Extension */
	{ .two_byte=0x0f, .opcode1=0xBF, .reg_op='r', .mnemonic="MOVSX", .op={ {.f=F_ADDR_G | F_OPER_V}, {.f=F_ADDR_E | F_OPER_W}, 0, 0}, },            /* desc=Move with Sign-Extension */
	{ .two_byte=0x0f, .opcode1=0xC0, .reg_op='r', .mnemonic="XADD", .op={ {.f=F_ADDR_E | F_OPER_B}, {.f=F_ADDR_G | F_OPER_B}, 0, 0}, .grp=GRP(GEN, DATAMOV_ARITH, BINARY),  },            /* desc=Exchange and Add */
	{ .two_byte=0x0f, .opcode1=0xC1, .reg_op='r', .mnemonic="XADD", .op={ {.f=F_ADDR_E | F_OPER_V}, {.f=F_ADDR_G | F_OPER_V}, 0, 0}, .grp=GRP(GEN, DATAMOV_ARITH, BINARY),  },            /* desc=Exchange and Add */
	{ .two_byte=0x0f, .opcode1=0xC2, .reg_op='r', .mnemonic="CMPPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Compare Packed Single-FP Values */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0xC2, .reg_op='r', .mnemonic="CMPSS", .op={ {.f=F_ADDR_V | F_OPER_SS}, {.f=F_ADDR_W | F_OPER_SS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Compare Scalar Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xC2, .reg_op='r', .mnemonic="CMPPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Compare Packed Double-FP Values */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0xC2, .reg_op='r', .mnemonic="CMPSD", .op={ {.f=F_ADDR_V | F_OPER_SD}, {.f=F_ADDR_W | F_OPER_SD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Compare Scalar Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0xC3, .reg_op='r', .mnemonic="MOVNTI", .op={ {.f=F_ADDR_M | F_OPER_D}, {.f=F_ADDR_G | F_OPER_D}, 0, 0}, },            /* desc=Store Doubleword Using Non-Temporal Hint */
	{ .two_byte=0x0f, .opcode1=0xC4, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PINSRW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_R | F_OPER_D}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PINSRW", .op={ {.f=F_ADDR_P | F_OPER_Q}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Insert Word */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xC4, .reg_op='r', .ops=(x86_in_ops[]){ { .mnemonic="PINSRW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_R | F_OPER_D}, {.f=F_ADDR_I | F_OPER_B}, 0 }, }, { .mnemonic="PINSRW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, 0, 0, 0 }, },  }, .ops_count=2,  },            /* desc=Insert Word */
	{ .two_byte=0x0f, .opcode1=0xC5, .reg_op='r', .mnemonic="PEXTRW", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_N | F_OPER_Q}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Extract Word */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xC5, .reg_op='r', .mnemonic="PEXTRW", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_U | F_OPER_DQ}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Extract Word */
	{ .two_byte=0x0f, .opcode1=0xC6, .reg_op='r', .mnemonic="SHUFPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed Single-FP Values */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xC6, .reg_op='r', .mnemonic="SHUFPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, {.f=F_ADDR_I | F_OPER_B}, 0}, },            /* desc=Shuffle Packed Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0xC7, .reg_op=1, .mnemonic="CMPXCHG8B", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.reg="EAX"}, {.reg="EDX"}, 0}, .grp=GRP(GEN, DATAMOV_ARITH, BINARY),  },            /* desc=Compare and Exchange Bytes */
	{ .two_byte=0x0f, .opcode1=0xC7, .reg_op=6, .m=MODOP_P, .mnemonic="VMPTRLD", .op={ {.f=F_ADDR_M | F_OPER_Q}, 0, 0, 0}, },            /* desc=Load Pointer to Virtual-Machine Control Structure */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xC7, .reg_op=6, .m=MODOP_P, .mnemonic="VMCLEAR", .op={ {.f=F_ADDR_M | F_OPER_Q}, 0, 0, 0}, },            /* desc=Clear Virtual-Machine Control Structure */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0xC7, .reg_op=6, .m=MODOP_P, .mnemonic="VMXON", .op={ {.f=F_ADDR_M | F_OPER_Q}, 0, 0, 0}, },            /* desc=Enter VMX Operation */
	{ .two_byte=0x0f, .opcode1=0xC7, .reg_op=7, .m=MODOP_P, .mnemonic="VMPTRST", .op={ {.f=F_ADDR_M | F_OPER_Q}, 0, 0, 0}, },            /* desc=Store Pointer to Virtual-Machine Control Structure */
	{ .two_byte=0x0f, .opcode1=0xC8, .flds=1, .mnemonic="BSWAP", .op={ {.f=F_ADDR_Z | F_OPER_V}, 0, 0, 0}, },            /* desc=Byte Swap */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD0, .reg_op='r', .mnemonic="ADDSUBPD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Packed Double-FP Add/Subtract */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0xD0, .reg_op='r', .mnemonic="ADDSUBPS", .op={ {.f=F_ADDR_V | F_OPER_PS}, {.f=F_ADDR_W | F_OPER_PS}, 0, 0}, },            /* desc=Packed Single-FP Add/Subtract */
	{ .two_byte=0x0f, .opcode1=0xD1, .reg_op='r', .mnemonic="PSRLW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD1, .reg_op='r', .mnemonic="PSRLW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .two_byte=0x0f, .opcode1=0xD2, .reg_op='r', .mnemonic="PSRLD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD2, .reg_op='r', .mnemonic="PSRLD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .two_byte=0x0f, .opcode1=0xD3, .reg_op='r', .mnemonic="PSRLQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD3, .reg_op='r', .mnemonic="PSRLQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Right Logical */
	{ .two_byte=0x0f, .opcode1=0xD4, .reg_op='r', .mnemonic="PADDQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Quadword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD4, .reg_op='r', .mnemonic="PADDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Quadword Integers */
	{ .two_byte=0x0f, .opcode1=0xD5, .reg_op='r', .mnemonic="PMULLW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Multiply Packed Signed Integers and Store Low Result */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD5, .reg_op='r', .mnemonic="PMULLW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Signed Integers and Store Low Result */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD6, .reg_op='r', .mnemonic="MOVQ", .op={ {.f=F_ADDR_W | F_OPER_Q}, {.f=F_ADDR_V | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0xD6, .reg_op='r', .mnemonic="MOVQ2DQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_N | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword from MMX Technology to XMM Register */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0xD6, .reg_op='r', .mnemonic="MOVDQ2Q", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_U | F_OPER_Q}, 0, 0}, },            /* desc=Move Quadword from XMM to MMX Technology Register */
	{ .two_byte=0x0f, .opcode1=0xD7, .reg_op='r', .mnemonic="PMOVMSKB", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_N | F_OPER_Q}, 0, 0}, },            /* desc=Move Byte Mask */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD7, .reg_op='r', .mnemonic="PMOVMSKB", .op={ {.f=F_ADDR_G | F_OPER_D}, {.f=F_ADDR_U | F_OPER_DQ}, 0, 0}, },            /* desc=Move Byte Mask */
	{ .two_byte=0x0f, .opcode1=0xD8, .reg_op='r', .mnemonic="PSUBUSB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Unsigned Integers with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD8, .reg_op='r', .mnemonic="PSUBUSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Unsigned Integers with Unsigned Saturation */
	{ .two_byte=0x0f, .opcode1=0xD9, .reg_op='r', .mnemonic="PSUBUSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Unsigned Integers with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xD9, .reg_op='r', .mnemonic="PSUBUSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Unsigned Integers with Unsigned Saturation */
	{ .two_byte=0x0f, .opcode1=0xDA, .reg_op='r', .mnemonic="PMINUB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Minimum of Packed Unsigned Byte Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDA, .reg_op='r', .mnemonic="PMINUB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Unsigned Byte Integers */
	{ .two_byte=0x0f, .opcode1=0xDB, .reg_op='r', .mnemonic="PAND", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Logical AND */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDB, .reg_op='r', .mnemonic="PAND", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Logical AND */
	{ .two_byte=0x0f, .opcode1=0xDC, .reg_op='r', .mnemonic="PADDUSB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Unsigned Integers with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDC, .reg_op='r', .mnemonic="PADDUSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Unsigned Integers with Unsigned Saturation */
	{ .two_byte=0x0f, .opcode1=0xDD, .reg_op='r', .mnemonic="PADDUSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Unsigned Integers with Unsigned Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDD, .reg_op='r', .mnemonic="PADDUSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Unsigned Integers with Unsigned Saturation */
	{ .two_byte=0x0f, .opcode1=0xDE, .reg_op='r', .mnemonic="PMAXUB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Maximum of Packed Unsigned Byte Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDE, .reg_op='r', .mnemonic="PMAXUB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Unsigned Byte Integers */
	{ .two_byte=0x0f, .opcode1=0xDF, .reg_op='r', .mnemonic="PANDN", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Logical AND NOT */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xDF, .reg_op='r', .mnemonic="PANDN", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Logical AND NOT */
	{ .two_byte=0x0f, .opcode1=0xE0, .reg_op='r', .mnemonic="PAVGB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Average Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE0, .reg_op='r', .mnemonic="PAVGB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Average Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xE1, .reg_op='r', .mnemonic="PSRAW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE1, .reg_op='r', .mnemonic="PSRAW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .two_byte=0x0f, .opcode1=0xE2, .reg_op='r', .mnemonic="PSRAD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE2, .reg_op='r', .mnemonic="PSRAD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Right Arithmetic */
	{ .two_byte=0x0f, .opcode1=0xE3, .reg_op='r', .mnemonic="PAVGW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Average Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE3, .reg_op='r', .mnemonic="PAVGW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Average Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xE4, .reg_op='r', .mnemonic="PMULHUW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Multiply Packed Unsigned Integers and Store High Result */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE4, .reg_op='r', .mnemonic="PMULHUW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Unsigned Integers and Store High Result */
	{ .two_byte=0x0f, .opcode1=0xE5, .reg_op='r', .mnemonic="PMULHW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Multiply Packed Signed Integers and Store High Result */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE5, .reg_op='r', .mnemonic="PMULHW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Signed Integers and Store High Result */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0xE6, .reg_op='r', .mnemonic="CVTPD2DQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Convert Packed Double-FP Values to DW Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE6, .reg_op='r', .mnemonic="CVTTPD2DQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_PD}, 0, 0}, },            /* desc=Convert with Trunc. Packed Double-FP Values to DW Integers */
	{ .prefix=0xF3, .two_byte=0x0f, .opcode1=0xE6, .reg_op='r', .mnemonic="CVTDQ2PD", .op={ {.f=F_ADDR_V | F_OPER_PD}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Convert Packed DW Integers to Double-FP Values */
	{ .two_byte=0x0f, .opcode1=0xE7, .reg_op='r', .mnemonic="MOVNTQ", .op={ {.f=F_ADDR_M | F_OPER_Q}, {.f=F_ADDR_P | F_OPER_Q}, 0, 0}, },            /* desc=Store of Quadword Using Non-Temporal Hint */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE7, .reg_op='r', .mnemonic="MOVNTDQ", .op={ {.f=F_ADDR_M | F_OPER_DQ}, {.f=F_ADDR_V | F_OPER_DQ}, 0, 0}, },            /* desc=Store Double Quadword Using Non-Temporal Hint */
	{ .two_byte=0x0f, .opcode1=0xE8, .reg_op='r', .mnemonic="PSUBSB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Signed Integers with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE8, .reg_op='r', .mnemonic="PSUBSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Signed Integers with Signed Saturation */
	{ .two_byte=0x0f, .opcode1=0xE9, .reg_op='r', .mnemonic="PSUBSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Signed Integers with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xE9, .reg_op='r', .mnemonic="PSUBSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Signed Integers with Signed Saturation */
	{ .two_byte=0x0f, .opcode1=0xEA, .reg_op='r', .mnemonic="PMINSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Minimum of Packed Signed Word Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xEA, .reg_op='r', .mnemonic="PMINSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Minimum of Packed Signed Word Integers */
	{ .two_byte=0x0f, .opcode1=0xEB, .reg_op='r', .mnemonic="POR", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Bitwise Logical OR */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xEB, .reg_op='r', .mnemonic="POR", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Bitwise Logical OR */
	{ .two_byte=0x0f, .opcode1=0xEC, .reg_op='r', .mnemonic="PADDSB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Signed Integers with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xEC, .reg_op='r', .mnemonic="PADDSB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Signed Integers with Signed Saturation */
	{ .two_byte=0x0f, .opcode1=0xED, .reg_op='r', .mnemonic="PADDSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Signed Integers with Signed Saturation */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xED, .reg_op='r', .mnemonic="PADDSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Signed Integers with Signed Saturation */
	{ .two_byte=0x0f, .opcode1=0xEE, .reg_op='r', .mnemonic="PMAXSW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Maximum of Packed Signed Word Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xEE, .reg_op='r', .mnemonic="PMAXSW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Maximum of Packed Signed Word Integers */
	{ .two_byte=0x0f, .opcode1=0xEF, .reg_op='r', .mnemonic="PXOR", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xEF, .reg_op='r', .mnemonic="PXOR", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Logical Exclusive OR */
	{ .prefix=0xF2, .two_byte=0x0f, .opcode1=0xF0, .reg_op='r', .mnemonic="LDDQU", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_M | F_OPER_DQ}, 0, 0}, },            /* desc=Load Unaligned Integer 128 Bits */
	{ .two_byte=0x0f, .opcode1=0xF1, .reg_op='r', .mnemonic="PSLLW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF1, .reg_op='r', .mnemonic="PSLLW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .two_byte=0x0f, .opcode1=0xF2, .reg_op='r', .mnemonic="PSLLD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF2, .reg_op='r', .mnemonic="PSLLD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .two_byte=0x0f, .opcode1=0xF3, .reg_op='r', .mnemonic="PSLLQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF3, .reg_op='r', .mnemonic="PSLLQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Shift Packed Data Left Logical */
	{ .two_byte=0x0f, .opcode1=0xF4, .reg_op='r', .mnemonic="PMULUDQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Multiply Packed Unsigned DW Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF4, .reg_op='r', .mnemonic="PMULUDQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply Packed Unsigned DW Integers */
	{ .two_byte=0x0f, .opcode1=0xF5, .reg_op='r', .mnemonic="PMADDWD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_D}, 0, 0}, },            /* desc=Multiply and Add Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF5, .reg_op='r', .mnemonic="PMADDWD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Multiply and Add Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xF6, .reg_op='r', .mnemonic="PSADBW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Compute Sum of Absolute Differences */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF6, .reg_op='r', .mnemonic="PSADBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Compute Sum of Absolute Differences */
	{ .two_byte=0x0f, .opcode1=0xF7, .reg_op='r', .mnemonic="MASKMOVQ", .op={ {.f=F_ADDR_BD | F_OPER_Q}, {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_N | F_OPER_Q}, 0}, },            /* desc=Store Selected Bytes of Quadword */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF7, .reg_op='r', .mnemonic="MASKMOVDQU", .op={ {.f=F_ADDR_BD | F_OPER_DQ}, {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_U | F_OPER_DQ}, 0}, },            /* desc=Store Selected Bytes of Double Quadword */
	{ .two_byte=0x0f, .opcode1=0xF8, .reg_op='r', .mnemonic="PSUBB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF8, .reg_op='r', .mnemonic="PSUBB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xF9, .reg_op='r', .mnemonic="PSUBW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xF9, .reg_op='r', .mnemonic="PSUBW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xFA, .reg_op='r', .mnemonic="PSUBD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xFA, .reg_op='r', .mnemonic="PSUBD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xFB, .reg_op='r', .mnemonic="PSUBQ", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Subtract Packed Quadword Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xFB, .reg_op='r', .mnemonic="PSUBQ", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Subtract Packed Quadword Integers */
	{ .two_byte=0x0f, .opcode1=0xFC, .reg_op='r', .mnemonic="PADDB", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xFC, .reg_op='r', .mnemonic="PADDB", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xFD, .reg_op='r', .mnemonic="PADDW", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xFD, .reg_op='r', .mnemonic="PADDW", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Integers */
	{ .two_byte=0x0f, .opcode1=0xFE, .reg_op='r', .mnemonic="PADDD", .op={ {.f=F_ADDR_P | F_OPER_Q}, {.f=F_ADDR_Q | F_OPER_Q}, 0, 0}, },            /* desc=Add Packed Integers */
	{ .prefix=0x66, .two_byte=0x0f, .opcode1=0xFE, .reg_op='r', .mnemonic="PADDD", .op={ {.f=F_ADDR_V | F_OPER_DQ}, {.f=F_ADDR_W | F_OPER_DQ}, 0, 0}, },            /* desc=Add Packed Integers */
};