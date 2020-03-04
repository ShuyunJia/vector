## Hwacha v4 VVADD ASM code

#include "vec-util.h"

.text
.align 2

.globl vec_vvadd_asm
.type  vec_vvadd_asm,@function

# assumes calling convention:
# a0 has int n
# a1 has float* result  <---
# a2 has float* x
# a3 has float* y
vec_vvadd_asm:
    li a4, VCFG(0, 2, 0, 1)
    vsetcfg a4

    li a2, 4
    vsetvl t0, a2

    vmca va0, a0
    vmca va1, a1

    la t5, TestLdStVec
    vf 0(t5)

    ret
# vector thread asm
.align 3
TestLdStVec:
    vpset vp0
    vld vv0, va0
    vfmul.d vv1, vv0, vv0
    #vaddw vv0, vv0, vv0
    vsw vv1, va1
    vstop

