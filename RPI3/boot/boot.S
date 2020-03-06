#include "ARMv7l.h"
#include "MemoryMap.h"
// AArch32 mode
 
// To keep this in the first portion of the binary.
.section ".text.boot"
 
// Make _start global.
.globl _start
 
        .org 0x8000
// Entry point for the kernel.
// r15 -> should begin execution at 0x8000.
// r0 -> 0x00000000
// r1 -> 0x00000C42 - machine id
// r2 -> 0x00000100 - start of ATAGS
// preserve these registers as argument for kernel_main
_start:
	ldr		pc, reset_handler_addr
	ldr		pc, undef_handler_addr
	ldr		pc, svc_handler_addr
	ldr		pc, pftch_abt_handler_addr
	ldr		pc, data_abt_handler_addr
	B		.
	ldr		pc, irq_handler_addr
	ldr		pc, fiq_handler_addr

reset_handler_addr:		.word reset
undef_handler_addr:		.word hang
svc_handler_addr:		.word hang
pftch_abt_handler_addr:	.word hang
data_abt_handler_addr:	.word hang
irq_handler_addr:		.word Irq_Handler
fiq_handler_addr:		.word Fiq_Handler

reset:

    mov r0,#0x8000
    mov r1,#0x0000

    ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

    ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

	ldr	sp, =USRSYS_STACK_TOP

	// Clear out bss.
	ldr r4, =__bss_start
	ldr r9, =__bss_end
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	b       2f
 
1:
	// store multiple at r4.
	stmia r4!, {r5-r8}
 
	// If we are still below bss_end, loop.
2:
	cmp r4, r9
	blo 1b
 
	// Call kernel_main
	ldr r3, =main
	blx r3
 
	// halt
halt:
	wfe
	b halt

hang:
	B	.
