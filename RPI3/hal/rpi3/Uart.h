#ifndef HAL_RPI3_UART_H_
#define HAL_RPI3_UART_H_
typedef union AUX_IRQ_t
{
	uint32_t all;
	struct {
		uint32_t MUARTIRQ:1; // 0
		uint32_t SPI1IRQ:1; //1
		uint32_t SPI2IRQ:1; //2
	}bits;
} AUX_IRQ_t;


typedef union AUX_ENABLES_t
{
	uint32_t all;
	struct {
		uint32_t MUARTE:1; // 0
		uint32_t SPI1E:1; //1
		uint32_t SPI2E:1; //2
	}bits;
} AUX_ENABLES_t;

typedef union AUX_MU_IO_t
{
	uint32_t all;
	uint8_t RDR; // 7:0
	uint8_t TDW; //7:0
	uint8_t BRW; //7:0
} AUX_MU_IO_t;

typedef union AUX_MU_IER_t
{
	uint32_t all;
	struct {
		uint32_t ERI:1; // 0
		uint32_t ETI:1; //1
	}bits;
	uint8_t BRW; //7:0
} AUX_MU_IER_t;

typedef union AUX_MU_IIR_t
{
	uint32_t all;
	struct {
		uint32_t IP:1; // 0
		uint32_t RII_WFC:2; //2:1
	}bits;
} AUX_MU_IIR_t;

typedef union AUX_MU_LCR_t
{
	uint32_t all;
	struct {
		uint32_t DS:2; // 1:0
		uint32_t RESERVED:4; //5:2
		uint32_t BREAK:1; //6
		uint32_t DLABA:1; //7 DLAB access
	}bits;
} AUX_MU_LCR_t;

typedef union AUX_MU_MCR_t
{
	uint32_t all;
	struct {
		uint32_t RESERVED0:1; // 0
		uint32_t RTS:1; //1
		uint32_t RESERVED1:6; // 7:2
	}bits;

} AUX_MU_MCR_t;

typedef union AUX_MU_LSR_t
{
	uint32_t all;
	struct {
		uint32_t DR:1; // 0
		uint32_t RO:1; //1
		uint32_t RESERVED0:3; // 4:2
		uint32_t TE:1; //5
		uint32_t TI:1; //6
	}bits;
} AUX_MU_LSR_t;

typedef union AUX_MU_MSR_t
{
	uint32_t all;
	struct {
		uint32_t RESERVED0:5; // 4:0  but 3:0 in book. error?
		uint32_t CTSS:1; //5
		uint32_t RESERVED1:2; // 7:6
	}bits;
} AUX_MU_MSR_t;

typedef union AUX_MU_SCRATCH_t
{
	uint32_t all;
	struct {
		uint32_t Scratch:8; // 7:0
	}bits;	
} AUX_MU_SCRATCH_t;

typedef union AUX_MU_CNTL_t
{
	uint32_t all;
	struct {
		uint32_t RE:1; // 0
		uint32_t TE:1; // 1
		uint32_t ERAFC_RTS:1; // 2
		uint32_t ERAFC_CTS:1; // 3
		uint32_t RAFL:2; // 5:4
		uint32_t RAL:1; // 6
		uint32_t CAL:2; // 7
	}bits;
} AUX_MU_CNTL_t;

typedef union AUX_MU_STAT_t
{
	uint32_t all;
	struct {
		uint32_t SYA:1; // 0
		uint32_t SPA:1; // 1
		uint32_t RII:1; // 2
		uint32_t TII:1; // 3
		uint32_t RO:1; // 4
		uint32_t TFIF:1; // 5
		uint32_t RTSS:1; // 6
		uint32_t CTSL:1; // 7
		uint32_t TFIE:1; // 8
		uint32_t TD:1; // 9
		uint32_t RESERVED0:6; // 15:10
		uint32_t RFFL:4; // 19:16 Receive FIFO fill level
		uint32_t RESERVED1:4; // 23:20
		uint32_t TFFL:4; // 27:24 Transmit FIFO fill level
	}bits;
} AUX_MU_STAT_t;

typedef union AUX_MU_BAUD_t
{
	uint32_t all;
	struct {
		uint32_t BAUDRATE:16; // 15:0
	}bits;
} AUX_MU_BAUD_t;



typedef struct MINIUART_t
{
	AUX_MU_IO_t aux_mu_io;
	AUX_MU_IER_t aux_mu_ier;
	AUX_MU_IIR_t aux_mu_iir;
	AUX_MU_LCR_t aux_mu_lcr;
	AUX_MU_MCR_t aux_mu_mcr;
	AUX_MU_LSR_t aux_mu_lsr;
	AUX_MU_MSR_t aux_mu_msr;
	AUX_MU_SCRATCH_t aux_mu_scratch;
	AUX_MU_CNTL_t aux_mu_cntl;
	AUX_MU_STAT_t aux_mu_stat;
	AUX_MU_BAUD_t aux_mu_baud;//all 11 variables.
}MINIUART_t;

typedef struct AUX_IO_t
{
	AUX_IRQ_t auxirq;
	AUX_ENABLES_t aux_enables;
	MINIUART_t miniuart;
	uint32_t reserved0[22]; //88bytes reserved. SP1, SP2
}AUX_IO_t;

#define AUX_IO_BASE_ADDRESS		0x3F215000
#define MINIUART_BASE_ADDRESS	0x3F21

#endif /* HAL_RPI3_GPIO_H_ */