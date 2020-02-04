#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_

void Hal_uart_init(void);
void Hal_uart_put_char(char ch);
char Hal_uart_get_char(void);

#endif /* HAL_HALUART_H_ */
