obj = c_uapi.o cpp_uapi.o xtc.o reg_table.o disass.o pfx.o x86_64_tabl.o modrm.o reconstruct.o x_tuple.o x86_tabl.o operand.o uapi.o utils.o
BDIR = ./build
CFLAGS = -w -fPIC
PWD = "$(shell pwd)"

all: library
example: #library
	clear; g++ main.cc -lx86disass -o ./main -fpermissive
	./main

install: library
	sudo cp -r $(PWD) /usr/local/include/
	sudo cp $(PWD)/$(BDIR)/libx86disass.a /usr/local/lib/
	sudo ldconfig

clean:
	sudo rm -rf /usr/local/include/x86disass
	sudo rm /usr/local/lib/libx86disass.a

.PHONY: library
library: $(obj)
	cd $(BDIR); ar rvs libx86disass.a $^


%.o: uapi/%.cc
	g++ -std=c++2b -c $< -o $(BDIR)/$@ $(CFLAGS)

%.o: uapi/%.c
	gcc -c $< -o $(BDIR)/$@ $(CFLAGS)

%.o: instr/%.c
	gcc -c $< -o $(BDIR)/$@ $(CFLAGS)

%.o: src/%.c
	gcc -c $< -o $(BDIR)/$@ $(CFLAGS)
