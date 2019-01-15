XLEN = 64
RISCV_PREFIX ?= riscv$(XLEN)-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
RISCV_GCC_OPTS ?= -g -Og 
RISCV_LINK_OPTS ?= -march=rv64g -Wa,-march=rv64gxhwacha -T ../common/openocd.ld  -nostartfiles 

target = vec-vvadd.riscv

src_dir = ./vec-vvadd

objs_asm = $(wildcard *.S $(src_dir)/*.S)

objs_c = $(wildcard *.c $(src_dir)/*.c)

objs = $(patsubst %c, %o, $(objs_c))

$(target): $(objs) $(objs_asm)
	$(RISCV_GCC) $(RISCV_LINK_OPTS) -o $@ $^

$(objs):$(objs_c)
	$(RISCV_GCC) $(RISCV_GCC_OPTS) -I$(src_dir) -c $< -o $@


all: $(target)

debug:
	@echo $(src_dir)
	@echo $(objs_asm)
	@echo $(objs_c)
clean:
	rm $(src_dir)/*.o
	rm $(target)
