#include "gpio.h"
#include "stdint.h"
#include "Uart.h"
#include "HalUart.h"

extern volatile AUX_IO_t*   Uart;

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
void Hal_uart_init(void)
{
    register unsigned int r;
    
    /* initialize UART */
    Uart->aux_enables.bits.MUARTE |=1;
    Uart->miniuart.aux_mu_ier.all =0;
    Uart->miniuart.aux_mu_cntl.all =0;
    Uart->miniuart.aux_mu_lcr.bits.DS = 3; // 8bits
    Uart->miniuart.aux_mu_mcr.all =0;
    Uart->miniuart.aux_mu_ier.all =0;
    Uart->miniuart.aux_mu_iir.bits.RII_WFC = 3; // set 11
    Uart->miniuart.aux_mu_iir.bits.FE = 3; // set 11
    Uart->miniuart.aux_mu_baud.all = 270; // 115200 baud

    /* map UART1 to GPIO pins */
    r=*GPFSEL1;
    r&=~((7<<12)|(7<<15)); // gpio14, gpio15
    r|=(2<<12)|(2<<15);    // alt5
    *GPFSEL1 = r;
    *GPPUD = 0;            // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        // flush GPIO setup

    Uart->miniuart.aux_mu_cntl.bits.RE=1;
    Uart->miniuart.aux_mu_cntl.bits.TE=1;
}

/**
 * Send a character
 */
void Hal_uart_put_char(char c)
{
    /* wait until we can send */
    do{
        asm volatile("nop");
    }
    while(!(Uart->miniuart.aux_mu_lsr.bits.TE & 0x01));
    /* write the character to the buffer */
    Uart->miniuart.aux_mu_io.TDW = c;
}

/**
 * Receive a character
 */
char Hal_uart_get_char(void)
{
    char r;
    /* wait until something is in the buffer */
    do{
        asm volatile("nop");
    }while(!(Uart->miniuart.aux_mu_lsr.bits.DR & 0x01));
    /* read it and return */
    r=(char)( Uart->miniuart.aux_mu_io.RDR);
    /* convert carrige return to newline */
    //return r;
    return r=='\r'?'\n':r;
}
