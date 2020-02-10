#include "HalUart.h"

static void Hw_init(void);

void main(void)
{
    Hw_init();
    // Hal_uart_put_char('S');
    // Hal_uart_put_char('U');
    // Hal_uart_put_char('\r');
    // Hal_uart_put_char('\n');

    while(1)
    {
     // char ch = Hal_uart_get_char();
     //    Hal_uart_put_char(ch);
     //    if(ch == '\r')
     //    	Hal_uart_put_char('\n');
    	Hal_uart_put_char(Hal_uart_get_char());
    }
}

static void Hw_init(void)
{
    Hal_uart_init();
} 
