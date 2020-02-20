/*
 * HalTimer.h
 *
 *  Created on: Sep 27, 2018
 *      Author: yiman
 */

#ifndef HAL_HALTIMER_H_
#define HAL_HALTIMER_H_

//void     Hal_timer_init(void);
//uint32_t Hal_timer_get_1ms_counter(void);


// about delay...
void wait_cycles(unsigned int n);
void wait_msec(unsigned int n);
unsigned long get_system_timer();
void wait_msec_st(unsigned int n);

#endif /* HAL_HALTIMER_H_ */
