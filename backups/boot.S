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
/*
	// Shut off extra cores
	mrc p15, 0, r5, c0, c0, 5
	and r5, r5, #3
	cmp r5, #0
	bne halt
 */
	// Setup the stack.

vector_start:
	LDR		PC, reset_handler_addr
	LDR		PC, undef_handler_addr
	LDR		PC, svc_handler_addr
	LDR		PC, pftch_abt_handler_addr
	LDR 	PC, data_abt_handler_addr
	B		.
	LDR		PC, irq_handler_addr
	LDR		PC, fiq_handler_addr

	reset_handler_addr:		.word reset_handler
	undef_handler_addr:		.word halt
	svc_handler_addr:		.word halt
	pftch_abt_handler_addr:	.word halt
	data_abt_handler_addr:	.word halt
	irq_handler_addr:		.word Irq_Handler
	fiq_handler_addr:		.word Fiq_Handler
vector_end:

reset_handler:
	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_SVC
	MSR cpsr, r1
	LDR sp, =SVC_STACK_TOP

	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_IRQ
	MSR cpsr, r1
	LDR sp, =IRQ_STACK_TOP

	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_FIQ
	MSR cpsr, r1
	LDR sp, =FIQ_STACK_TOP

	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_ABT
	MSR cpsr, r1
	LDR sp, =ABT_STACK_TOP

	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_UND
	MSR cpsr, r1
	LDR sp, =UND_STACK_TOP

	MRS r0, cpsr
	BIC r1, r0, #0x1F
	ORR r1, r1, #ARM_MODE_BIT_SYS
	MSR cpsr, r1
	LDR sp, =USRSYS_STACK_TOP


//	ldr r5, =_start
//	mov sp, r5
 
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
