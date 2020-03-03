#include "stdint.h"
#include "Timer.h"
#include "HalTimer.h"
#include "HalInterrupt.h"

extern volatile Timer_t* Timer;

static void interrupt_handler(void);

static uint32_t sInternal_1ms_counter;
void Hal_timer_init(void)
{
	// reset.

	    // inerface reset
    // Timer->timerxcontrol.bits.TimerEn = 0;
    Timer->control.bits.TE = 0;

    // Timer->timerxcontrol.bits.TimerMode = 0;
    Timer->control.bits.NU_MODE = 0;

    // Timer->timerxcontrol.bits.OneShot = 0;
    Timer-> control.bits.NU_WO = 0;

    // Timer->timerxcontrol.bits.TimerSize = 0;
    Timer->control.bits.BC =  0;

    // Timer->timerxcontrol.bits.TimerPre = 0;
    Timer->control.bits.PSB = 0;

    // Timer->timerxcontrol.bits.IntEnable = 1;
    Timer->control.bits.TIE = 1;

    // Timer->timerxload = 0;
    Timer->load =0;

    // Timer->timerxvalue = 0xFFFFFFFF;
    Timer->value = 0xFFFFFFFF;


	
    // set periodic mode
    // Timer->timerxcontrol.bits.TimerMode = TIMER_PERIOIC;
    Timer->control.bits.FRCE = 0;

    // Timer->timerxcontrol.bits.TimerSize = TIMER_32BIT_COUNTER;
    Timer->control.bits.BC = TIMER_32BIT_COUNTER;

    // Timer->timerxcontrol.bits.OneShot = 0;
    Timer->control.bits.NU_WO = 0;


    // Timer->timerxcontrol.bits.TimerPre = 0;
    // Timer->timerxcontrol.bits.IntEnable = 1;

}
