#include "HalUart.h"

static void Hw_init(void);

void main(void)
{
    Hw_init();

    while(1)
    {
        Hal_uart_put_char(Hal_uart_get_char());
    }
}

static void Hw_init(void)
{
    Hal_uart_init();
} 
