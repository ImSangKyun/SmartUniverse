#ifndef HAL_RPI3_INTERRUPT_H_
#define HAL_RPI3_INTERRUPT_H_
/* rpi3 data sheet p112 */

typedef union IRQ_basic_pending	
{
	uint32_t all;
	struct {
		uint32_t ARM_Timer_IRQ_pending:1;						// 0
		uint32_t ARM_Mailbox_IRQ_pending:1;						// 1
		uint32_t ARM Doorbell_0_IRQ_pending:1;					// 2
		uint32_t ARM Doorbell_1_IRQ_pending:1;					// 3
		uint32_t GPU0_halted_IRQ_pending:1;						// 4
		uint32_t GPU1_halted_IRQ_pending:1;						// 5
		uint32_t Illegal_access_type_1_IRQ_pending:1;			// 6
		uint32_t Illegal_access_type_0_IRQ_pending:1;			// 7
		uint32_t One_or_more_bits_set_in_pending_register_1:1;	// 8
		uint32_t One_or_more_bits_set_in_pending_register_2:1;	// 9
		uint32_t GPU_IRQ_7:1;									// 10
		uint32_t GPU_IRQ_9:1;									// 11
		uint32_t GPU_IRQ_10:1;									// 12
		uint32_t GPU_IRQ_18:1;									// 13
		uint32_t GPU_IRQ_19:1;									// 14
		uint32_t GPU_IRQ_53:1;									// 15
		uint32_t GPU_IRQ_54:1;									// 16
		uint32_t GPU_IRQ_55:1;									// 17
		uint32_t GPU_IRQ_56:1;									// 18
		uint32_t GPU_IRQ_57:1;									// 19
		uint32_t GPU_IRQ_62:1;									// 20
		uint32_t unused:11;										// 31:21
	} bits;
} IRQ_basic_pending;

typedef union IRQ_pending_1 // address offset : 0x204
{
	uint32_t all;
	struct {
		uint32_t IRQ_pending_source_31_0:32;	// 31:0
	} bits;
} IRQ_pending_1;

typedef union IRQ_pending_2
{
	uint32_t all;
	struct {
		uint32_t IRQ_pending_source_63_32:32;	// 31:0
	} bits;
} IRQ_pending_2;

typedef union FIQ_control
{
	uint32_t all;
	struct {
		uint32_t Select_FIQ_Source:7;	// 6:0
		uint32_t FIQ_enable:1;			// 7
		uint32_t unused:24;				// 31:8
	} bits;
} FIQ_control;

typedef union Enable_IRQs_1
{
	uint32_t all;
	struct {
		uint32_t Set_to_enable_IRQ_source_31_0:32;	// 31:0
	} bits;
} Enable_IRQs_1

typedef union Enable_IRQs_2
{
	uint32_t all;
		uint32_t Set_to_enable_IRQ_source_63_32:32;	// 31:0
	struct {
	} bits;
} Enable_IRQs_2;

typedef union Enable_Basic_IRQs
{
	uint32_t all;
	struct {
		uint32_t Set_to_enable_ARM_Timer_IRQ:1;				// 0
		uint32_t Set_to_enable_ARM_Mailbox_IRQ:1;			// 1
		uint32_t Set_to_enable_ARM_Doorbell_0_IRQ:1;		// 2
		uint32_t Set_to_enable_ARM_Doorbell_1_IRQ:1;		// 3
		uint32_t Set_to_enable_GPU_0_Halted_IRQ:1;			// 4
		uint32_t Set_to_enable_GPU_1_Halted_IRQ:1;			// 5
		uint32_t Set_to_enable_Access_error_type_1_IRQ:1;	// 6
		uint32_t Set_to_enable_Access_error_type_0_IRQ:1;	// 7
		uint32_t unused:24;									// 31:8
	} bits;
} Enable_Basic_IRQs;

typedef union Disable_IRQs_1
{
	uint32_t all;
	struct {
		uint32_t Set_to_disable_IRQ_source_31_0:32;	// 31:0
	} bits;
} Disable_IRQs_1;

typedef union Disable_IRQs_2
{
	uint32_t all;
	struct {
		uint32_t Set_to_disable_IRQ_source_63_32:32;	// 31:0
	} bits;
} Disable_IRQs_2;

typedef union Disable_Basic_IRQs
{
	uint32_t all;
	struct {
		uint32_t Set_to_disable_ARM_Timer_IRQ:1;			// 0
		uint32_t Set_to_disable_ARM_Mailbox_IRQ:1;			// 1
		uint32_t Set_to_disable_ARM_Doorbell_0_IRQ:1; 		// 2
		uint32_t Set_to_disable_ARM_Doorbell_1_IRQ:1; 		// 3
		uint32_t Set_to_disable_GPU_0_Halted_IRQ:1;			// 4
		uint32_t Set_to_disable_GPU_1_Halted_IRQ:1;			// 5
		uint32_t Set_to_disable_Acess_error_type_1_IRQ:1;	// 6
		uint32_t Set_to_disable_Acess_error_type_0_IRQ:1;	// 7
		uint32_t unused:24;									// 31:8
	} bits;
} Disable_Basic_IRQs;

typedef struct interrupt_register
{
	IRQ_basic_pending irqbasicpending;		// 0x200
	IRQ_pending_1 irqpending1;				// 0x204
	IRQ_pending_2 irqpending2;				// 0x208
	FIQ_control fiqcontrol;					// 0x20C
	Enable_IRQs_1 enableirqs1;				// 0x210
	Enable_IRQs_2 enableirqs2;				// 0x214
	Enable_Basic_IRQs enablebasicirqs;		// 0x218
	Disable_IRQs_1 disableirqs1;			// 0x21C
	Disable_IRQs_2 disableirqs2;			// 0x220
	Disable_Basic_IRQs disablebasicirqs;	// 0x224
}

#define ARM_INTERRUPT_BASE 0x7E00B000


#endif /* HAL_RPI3_INTERRUPT_H_ */
