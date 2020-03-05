#include "stdint.h"
#include "memio.h"
#include "Interrupt.h"
#include "HalInterrupt.h"
#include "armcpu.h"

extern volatile interrupt_register* ARM_INT;

static InterHdlr_fptr sHandlers[INTERRUPT_HANDLER_NUM];


void Hal_interrupt_init(void)
{
}


void Hal_interrupt_endble(uint32_t interrupt_num)
{
}

void Hal_interrupt_disable(uint32_t interrupt_num)
{
}

void Hal_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrypt_num)
{
}

void Hal_interrupt_run_handler(void)
{
}
