#ifndef HAL_RPI3_TIMER_H_
#define HAL_RPI3_TIMER_H_

typedef union CS_t
{
	uint32_t all;
	struct {
		uint32_t M0:1; // 0
		uint32_t M1:1; //1
		uint32_t M2:1; //2
		uint32_t M3:1; //3
	}bits;
} CS_t;


// from now, timer register structs begin...
typedef union CONTROL_t
{
	uint32_t all;
	struct {
		uint32_t RESERVED0:1; // 0
		uint32_t BC:1; //1 Bit Counter.. 16 or 23.
		uint32_t PSB:2; //3:2 Pre-scale bits
		uint32_t RESERVED1:1; //4
		uint32_t TIE:1; //5 timer interrupt enable..
		uint32_t MODE:1; //6. not used 1 periodic mode will not be supported...
		uint32_t TE:1; //7 timer enabled..
		uint32_t DHMTH:1; //8 Timers halted if ARM is in debug halted mode
		uint32_t FRCE:1; //9 free running counter enabled.
		uint32_t RESERVED2:6; // 15:10 
		uint32_t FRCPS:8; //23:16
	}bits;
} CONTROL_t;



typedef union RIRQ_t
{
	uint32_t all;
	struct {
		uint32_t IPB:1; // 0
	}bits;
} RIRQ_t;

typedef union MIRQ_t
{
	uint32_t all;
	struct {
		uint32_t ILIS:1; //0
	}bits;
} MIRQ_t;

typedef union PD_t
{
	uint32_t all;
	struct {
		uint32_t PDV:10; // 9:0
	}bits;
} PD_t;


// timer register end..




typedef struct S_Timer_t
{
	CS_t cs; //	0x0 CS System Timer Control/Status 32
	uint32_t clo;//0x4 CLO System Timer Counter Lower 32 bits 32
	uint32_t chi;//0x8 CHI System Timer Counter Higher 32 bits 32
	uint32_t c0; //0xc C0 System Timer Compare 0 32
	uint32_t c1;//0x10 C1 System Timer Compare 1 32
	uint32_t c2;//0x14 C2 System Timer Compare 2 32
	uint32_t c3;//0x18 C3 System Timer Compare 3 32
}S_Timer_t;


typedef struct Timer_t
{
	uint32_t load;		// 0x400 Load
	uint32_t value;		// 0x404 Value (Read Only)
	CONTROL_t control;	// 0x408 Control
	uint32_t irqca; 		// 0x40C IRQ Clear/Ack (Write only)
	RIRQ_t rirq; 		// 0x410 RAW IRQ (Read Only)
	MIRQ_t mirq;		// 0x414 Masked IRQ (Read Only)
	uint32_t reload;	// 0x418 Reload
	PD_t pd;			// 0x41C Pre-divider (Not in real 804!)
	FRC_t frc;			// 0x420 Free running counter (Not in real 804!)
}Timer_t;


#endif /* HAL_RPI3_TIMER_H_ */