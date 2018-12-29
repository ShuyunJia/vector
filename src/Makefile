#=======================================================================
# UCB VLSI FLOW: Makefile for riscv-vector
#-----------------------------------------------------------------------
# Yunsup Lee (yunsup@cs.berkeley.edu)
#

XLEN ?= 64

default: all

src_dir = .

instname = riscv-vector

#--------------------------------------------------------------------
# Sources
#--------------------------------------------------------------------

#median
targets= \
	vec-vvadd \

#--------------------------------------------------------------------
# Build rules
#--------------------------------------------------------------------

RISCV_PREFIX ?= riscv$(XLEN)-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
RISCV_GCC_OPTS ?= -DPREALLOCATE=1 -DMULTITHREAD=$(CORES) -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -march=rv64g -Wa,-march=rv64gxhwacha
RISCV_LINK ?= $(RISCV_GCC) -T $(src_dir)/../common/test.ld $(incs)
RISCV_LINK_OPTS ?= -static -nostdlib -nostartfiles -lm -lgcc -T $(src_dir)/../common/test.ld
RISCV_OBJDUMP ?= $(RISCV_PREFIX)objdump --disassemble-all --disassemble-zeroes --section=.text --section=.text.init --section=.data
RISCV_SIM ?= spike -p$(CORES) --isa=rv$(XLEN)gc --extension=hwacha

incs  += -I$(src_dir)/../env -I$(src_dir)/../common $(addprefix -I$(src_dir)/, $(targets))
objs  :=

define compile_template
$(1).riscv: $(wildcard $(src_dir)/$(1)/*) $(wildcard $(src_dir)/../common/*)
	$$(RISCV_GCC) $$(incs) $$(RISCV_GCC_OPTS) -o $$@ $(wildcard $(src_dir)/$(1)/*.c) $(wildcard $(src_dir)/../common/*.c) $(wildcard $(src_dir)/$(1)/*.S) $(wildcard $(src_dir)/../common/*.S) $$(RISCV_LINK_OPTS)
endef

$(foreach target,$(targets),$(eval $(call compile_template,$(target))))

#------------------------------------------------------------
# Build and run benchmarks on riscv simulator

riscv_elf  = $(addsuffix .riscv,  $(targets))
riscv_dump = $(addsuffix .riscv.dump,  $(targets))
riscv_out  = $(addsuffix .riscv.out,  $(targets))

CORES ?= 1


$(riscv_dump): %.riscv.dump: %.riscv
	$(RISCV_OBJDUMP) $< > $@

$(riscv_out): %.riscv.out: %.riscv
	$(RISCV_SIM) $< > $@

riscv: $(riscv_dump)

run: $(riscv_out)

junk += $(riscv_elf) $(riscv_hex) $(riscv_dump) $(riscv_out)

#------------------------------------------------------------
# Default

all: riscv

#------------------------------------------------------------
# Clean up

clean:
	rm -rf $(objs) $(junk)
