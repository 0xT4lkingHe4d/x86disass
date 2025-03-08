obj = reg_table.o disass.o pfx.o x86_64_tabl.o modrm.o reconstruct.o x_tuple.o x86_tabl.o operand.o uapi.o utils.o
BDIR = ./build
CFLAGS = -w -fPIC

all: library
example:
	gcc main.c -lx86disass -o ./main

install: library
	sudo cp -r $(PWD) /usr/local/include/
	sudo cp $(PWD)/$(BDIR)/libx86disass.a /usr/local/lib/
	sudo ldconfig

.PHONY: library
library: $(obj)
	cd $(BDIR); ar rvs libx86disass.a $^

%.o: instr/%.c
	gcc -c $< -o $(BDIR)/$@ $(CFLAGS)

%.o: src/%.c
	gcc -c $< -o $(BDIR)/$@ $(CFLAGS)
