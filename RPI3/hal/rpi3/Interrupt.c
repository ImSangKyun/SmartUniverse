#include "stdint.h"
#include "memio.h"
#include "Interrupt.h"
#include "HalInterrupt.h"
#include "armcpu.h"

extern volatile interrupt_register* ARM_INT;

static InterHdlr_fptr sHandlers[INTERRUPT_HANDLER_NUM];


void Hal_interrupt_init(void)
{
	ARM_INT->disableirqs1.all = 0x0;
	ARM_INT->disableirqs2.all = 0x0;
	ARM_INT->disablebasicirqs.all = 0x0;
}


void Hal_interrupt_enable(uint32_t interrupt_num)
{
	if (interrupt_num < 0 && interrupt_num > 71) return;
	else if (interrupt_num < 31) {
		ARM_INT->enableirqs1.all |= interrupt_num;
	}
	else if (interrupt_num < 63) {
		interrupt_num -= 32;
		ARM_INT->enableirqs2.all |= interrupt_num;
	}
	else {
		interrupt_num -= 64;
		ARM_INT->enablebasicirqs.all |= interrupt_num;
	}

}

void Hal_interrupt_disable(uint32_t interrupt_num)
{
	if (interrupt_num < 0 && interrupt_num > 71) return;
	else if (interrupt_num < 31) {
		ARM_INT->disableirqs1.all |= interrupt_num;
	}
	else if (interrupt_num < 63) {
		interrupt_num -= 32;
		ARM_INT->disableirqs2.all |= interrupt_num;
	}
	else {
		interrupt_num -= 64;
		ARM_INT->disablebasicirqs.all |= interrupt_num;
	}
	
}

void Hal_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrupt_num)
{
	sHandlers[interrupt_num] = handler;
}

void Hal_interrupt_run_handler(void)
{
	
	if (ARM_INT-> irqbasicpending.bits.One_or_more_bits_set_in_pending_register_1 == 1)
	{
		
	}
	else if (ARM_INT-> irqbasicpending.bits.One_or_more_bits_set_in_pending_register_2 == 1)
	{
	}
	else if (ARM_INT-> irqbasicpending.bits.ARM_Timer_IRQ_pending == 1)
	{
		sHandlers[64]();
	}
	else if (ARM_INT-> irqbasicpending.bits.ARM_Mailbox_IRQ_pending == 1)
	{
		sHandlers[65]();
	}
	else if (ARM_INT-> irqbasicpending.bits.ARM_Doorbell_0_IRQ_pending == 1)
	{
		sHandlers[66]();
	}
	else if (ARM_INT-> irqbasicpending.bits.ARM_Doorbell_1_IRQ_pending == 1)
	{
		sHandlers[67]();
	}
	else if (ARM_INT-> irqbasicpending.bits.GPU0_halted_IRQ_pending == 1)
	{
		sHandlers[68]();
	}
	else if (ARM_INT-> irqbasicpending.bits.GPU1_halted_IRQ_pending == 1)
	{
		sHandlers[69]();
	}
	else if (ARM_INT-> irqbasicpending.bits.Illegal_access_type_1_IRQ_pending == 1)
	{
		sHandlers[70]();
	}
	else if (ARM_INT-> irqbasicpending.bits.Illegal_access_type_0_IRQ_pending == 1)
	{
		sHandlers[71]();
	}

}
