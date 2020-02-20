#include "stdint.h"
#include "Uart.h"
//#include "Interrupt.h"
//#include "Timer.h"
#include "Delay.h"

volatile AUX_IO_t*   Uart = (AUX_IO_t *)AUX_IO_BASE_ADDRESS;
volatile S_Timer_t * S_Timer = (S_Timer_t *)(MMIO_BASE + 0x00003000)