#ifndef HAL_RPI3_DELAY_H_
#define HAL_RPI3_DELAY_H_

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

#endif /* HAL_RPI3_DELAY_H_ */