/*""FILE COMMENT""*******************************************************
* System Name	: API for RX210xx
* File Name		: r_pdl_common_defs_RX210xx.h
* Version		: 0.20
* Contents		: API common definitions
* Customer		:
* Model			:
* Order			:
* CPU			: RX
* Compiler		: RXC
* OS			: Nothing
* Programmer	:
* Note			:
************************************************************************
* Copyright, 2011. Renesas Electronics Corporation
* and Renesas Solutions Corporation
************************************************************************
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FILE COMMENT END""**************************************************/

#ifndef R_PDL_COMMON_DEFS_RX210xx_H
#define R_PDL_COMMON_DEFS_RX210xx_H

#include <stdint.h>
#include <stdbool.h>
#include <machine.h>
#include <stddef.h>
#include "iodefine_RPDL.h"

/* Callback function type */
typedef void (* VoidCallBackFunc)(void);

/* The supported MCU group */
#define PDL_MCU_GROUP RX210

/* The highest interrupt priority level */
#define IPL_MAX	15

/* Use the I/O register area to indicate that a callback function pointer is not to be used */
#define PDL_NO_FUNC	(VoidCallBackFunc)0x00080000ul
/* Use the ROM area to indicate that a data pointer is not to be used */
#define PDL_NO_PTR (void *)0xFFFFFFFCul
/* When no parameters options are required */
#define PDL_NO_DATA 0

/* The number of clock oscillators */
#define CGC_CLOCK_OSCILLATORS	6

/* The number of active bits in the PRCR register */
#define RWP_PRCR_BITS 3

/* Shared global variables */
extern volatile double rpdl_CGC_f_iclk;
extern volatile double rpdl_CGC_f_pclkd;
extern volatile double rpdl_CGC_f_pclkb;
extern volatile double rpdl_CGC_f_fclk;
extern volatile double rpdl_CGC_f_bclk;
extern volatile double rpdl_CGC_f_source_clock[CGC_CLOCK_OSCILLATORS];
extern volatile	 uint8_t rpdl_INTC_brk_command;
extern volatile	 uint8_t rpdl_INTC_brk_data8;
extern volatile uint32_t rpdl_INTC_saved_isp;

/* Shared functions */
uint8_t rpdl_DMAC_get_channel(const uint8_t);

/* Utility functions */
uint8_t rpdl_BCD8_to_dec(const uint8_t);
uint16_t rpdl_BCD16_to_dec(const uint16_t);
bool rpdl_common_BCD8_check(const uint8_t);
bool rpdl_common_BCD16_check(const uint16_t);
bool rpdl_common_BCD32_check(const uint32_t);
void rpdl_register_protection(const uint8_t);
void rpdl_modify_protection(const uint8_t);
uint8_t rpdl_bit_number(const uint32_t);
void rpdl_pin_function_disable(
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	const uint8_t,
	const uint8_t 
	);
void rpdl_pin_function_enable(
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	const uint8_t,
	const uint8_t
	);

void rpdl_pin_analog_enable(
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	const uint8_t
	);

void rpdl_pin_analog_disable(
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	volatile uint8_t __evenaccess * const,
	const uint8_t
	);

/* BRK handler command options */
typedef enum {
	BRK_NO_COMMAND,
	BRK_SLEEP,
	BRK_ALL_MODULE_CLOCK_STOP,
	BRK_STANDBY,
	BRK_DEEP_STANDBY,
	BRK_LOAD_FINTV_REGISTER,
	BRK_WRITE_IPL,
	BRK_CMT_START,
	BRK_CMT_STOP,
	BRK_MODIFY_PROTECTION
} brk_commands;

/* CGC clock source CKSEL values */
#define CGC_CKSEL_LOCO	0x0u
#define CGC_CKSEL_HOCO	0x1u
#define CGC_CKSEL_MAIN	0x2u
#define CGC_CKSEL_SUB	0x3u
#define CGC_CKSEL_PLL	0x4u

/* Clock source array values (the CAC is used for the values) */
#define F_CLOCK_MAIN		0x0u
#define F_CLOCK_SUB			0x1u
#define F_CLOCK_HOCO		0x2u
#define F_CLOCK_LOCO		0x3u
#define F_CLOCK_IWDTLOCO	0x4u
#define F_CLOCK_PLL			0x5u

/* Register protection command options */
#define REG_ENABLE_CGC_WRITE			0x01u
#define REG_DISABLE_CGC_WRITE			0x02u
#define REG_ENABLE_MODE_RESET_WRITE		0x04u
#define REG_DISABLE_MODE_RESET_WRITE	0x08u
#define REG_ENABLE_LVD_WRITE			0x10u
#define REG_DISABLE_LVD_WRITE			0x20u
#define REG_ENABLE_MPC_WRITE			0x40u
#define REG_DISABLE_MPC_WRITE			0x80u

/* Bit definitions */
#define  BIT_0 0x00000001ul
#define  BIT_1 0x00000002ul
#define  BIT_2 0x00000004ul
#define  BIT_3 0x00000008ul
#define  BIT_4 0x00000010ul
#define  BIT_5 0x00000020ul
#define  BIT_6 0x00000040ul
#define  BIT_7 0x00000080ul
#define  BIT_8 0x00000100ul
#define  BIT_9 0x00000200ul
#define BIT_10 0x00000400ul
#define BIT_11 0x00000800ul
#define BIT_12 0x00001000ul
#define BIT_13 0x00002000ul
#define BIT_14 0x00004000ul
#define BIT_15 0x00008000ul
#define BIT_16 0x00010000ul
#define BIT_17 0x00020000ul
#define BIT_18 0x00040000ul
#define BIT_19 0x00080000ul
#define BIT_20 0x00100000ul
#define BIT_21 0x00200000ul
#define BIT_22 0x00400000ul
#define BIT_23 0x00800000ul
#define BIT_24 0x01000000ul
#define BIT_25 0x02000000ul
#define BIT_26 0x04000000ul
#define BIT_27 0x08000000ul
#define BIT_28 0x10000000ul
#define BIT_29 0x20000000ul
#define BIT_30 0x40000000ul
#define BIT_31 0x80000000ul

#define INV_BIT_0  0xFFFFFFFEul
#define INV_BIT_1  0xFFFFFFFDul
#define INV_BIT_2  0xFFFFFFFBul
#define INV_BIT_3  0xFFFFFFF7ul
#define INV_BIT_4  0xFFFFFFEFul
#define INV_BIT_5  0xFFFFFFDFul
#define INV_BIT_6  0xFFFFFFBFul
#define INV_BIT_7  0xFFFFFF7Ful
#define INV_BIT_8  0xFFFFFEFFul
#define INV_BIT_9  0xFFFFFDFFul
#define INV_BIT_10 0xFFFFFBFFul
#define INV_BIT_11 0xFFFFF7FFul
#define INV_BIT_12 0xFFFFEFFFul
#define INV_BIT_13 0xFFFFDFFFul
#define INV_BIT_14 0xFFFFBFFFul
#define INV_BIT_15 0xFFFF7FFFul
#define INV_BIT_16 0xFFFEFFFFul
#define INV_BIT_17 0xFFFDFFFFul
#define INV_BIT_18 0xFFFBFFFFul
#define INV_BIT_19 0xFFF7FFFFul
#define INV_BIT_20 0xFFEFFFFFul
#define INV_BIT_21 0xFFDFFFFFul
#define INV_BIT_22 0xFFBFFFFFul
#define INV_BIT_23 0xFF7FFFFFul
#define INV_BIT_24 0xFEFFFFFFul
#define INV_BIT_25 0xFDFFFFFFul
#define INV_BIT_26 0xFBFFFFFFul
#define INV_BIT_27 0xF7FFFFFFul
#define INV_BIT_28 0xEFFFFFFFul
#define INV_BIT_29 0xDFFFFFFFul
#define INV_BIT_30 0xBFFFFFFFul
#define INV_BIT_31 0x7FFFFFFFul

/* Interrupt vector numbers */
#define PDL_INTC_VECTOR_BUSERR		VECT_BSC_BUSERR
#define PDL_INTC_VECTOR_FIFERR		VECT_FCU_FIFERR
#define PDL_INTC_VECTOR_FRDYI		VECT_FCU_FRDYI
#define PDL_INTC_VECTOR_SWINT		VECT_ICU_SWINT
#define PDL_INTC_VECTOR_CMT0		VECT_CMT0_CMI0
#define PDL_INTC_VECTOR_CMT1		VECT_CMT1_CMI1
#define PDL_INTC_VECTOR_CMT2		VECT_CMT2_CMI2
#define PDL_INTC_VECTOR_CMT3		VECT_CMT3_CMI3
#define PDL_INTC_VECTOR_FERRF		VECT_CAC_FERRF
#define PDL_INTC_VECTOR_MENDF		VECT_CAC_MENDF
#define PDL_INTC_VECTOR_OVFF		VECT_CAC_OVFF
#define PDL_INTC_VECTOR_SPEI0		VECT_RSPI0_SPEI0
#define PDL_INTC_VECTOR_SPRI0		VECT_RSPI0_SPRI0
#define PDL_INTC_VECTOR_SPTI0		VECT_RSPI0_SPTI0
#define PDL_INTC_VECTOR_SPII0		VECT_RSPI0_SPII0
#define PDL_INTC_VECTOR_DOPCF		VECT_DOC_DOPCF
#define PDL_INTC_VECTOR_COMPB0		VECT_COMPB_COMPB0
#define PDL_INTC_VECTOR_COMPB1		VECT_COMPB_COMPB1
#define PDL_INTC_VECTOR_COUNTUP		VECT_RTC_COUNTUP
#define PDL_INTC_VECTOR_IRQ0		VECT_ICU_IRQ0
#define PDL_INTC_VECTOR_IRQ1		VECT_ICU_IRQ1
#define PDL_INTC_VECTOR_IRQ2		VECT_ICU_IRQ2
#define PDL_INTC_VECTOR_IRQ3		VECT_ICU_IRQ3
#define PDL_INTC_VECTOR_IRQ4		VECT_ICU_IRQ4
#define PDL_INTC_VECTOR_IRQ5		VECT_ICU_IRQ5
#define PDL_INTC_VECTOR_IRQ6		VECT_ICU_IRQ6
#define PDL_INTC_VECTOR_IRQ7		VECT_ICU_IRQ7
#define PDL_INTC_VECTOR_LVD1		VECT_LVD_LVD1
#define PDL_INTC_VECTOR_LVD2		VECT_LVD_LVD2
#define PDL_INTC_VECTOR_COMPA1		VECT_COMPA_COMPA1
#define PDL_INTC_VECTOR_COMPA2		VECT_COMPA_COMPA2
#define PDL_INTC_VECTOR_ALM			VECT_RTC_ALM
#define PDL_INTC_VECTOR_PRD			VECT_RTC_PRD
#define PDL_INTC_VECTOR_S12ADI0		VECT_S12AD_S12ADI0
#define PDL_INTC_VECTOR_GBADI		VECT_S12AD_GBADI
#define PDL_INTC_VECTOR_ELSR18I		VECT_ELC_ELSR18I
#define PDL_INTC_VECTOR_ELSR19I		VECT_ELC_ELSR19I
#define PDL_INTC_VECTOR_TGIA0		VECT_MTU0_TGIA0
#define PDL_INTC_VECTOR_TGIB0		VECT_MTU0_TGIB0
#define PDL_INTC_VECTOR_TGIC0		VECT_MTU0_TGIC0
#define PDL_INTC_VECTOR_TGID0		VECT_MTU0_TGID0
#define PDL_INTC_VECTOR_TCIV0		VECT_MTU0_TCIV0
#define PDL_INTC_VECTOR_TGIE0		VECT_MTU0_TGIE0
#define PDL_INTC_VECTOR_TGIF0		VECT_MTU0_TGIF0
#define PDL_INTC_VECTOR_TGIA1		VECT_MTU1_TGIA1
#define PDL_INTC_VECTOR_TGIB1		VECT_MTU1_TGIB1
#define PDL_INTC_VECTOR_TCIV1		VECT_MTU1_TCIV1
#define PDL_INTC_VECTOR_TCIU1		VECT_MTU1_TCIU1
#define PDL_INTC_VECTOR_TGIA2		VECT_MTU2_TGIA2
#define PDL_INTC_VECTOR_TGIB2		VECT_MTU2_TGIB2
#define PDL_INTC_VECTOR_TCIV2		VECT_MTU2_TCIV2
#define PDL_INTC_VECTOR_TCIU2		VECT_MTU2_TCIU2
#define PDL_INTC_VECTOR_TGIA3		VECT_MTU3_TGIA3
#define PDL_INTC_VECTOR_TGIB3		VECT_MTU3_TGIB3
#define PDL_INTC_VECTOR_TGIC3		VECT_MTU3_TGIC3
#define PDL_INTC_VECTOR_TGID3		VECT_MTU3_TGID3
#define PDL_INTC_VECTOR_TCIV3		VECT_MTU3_TCIV3
#define PDL_INTC_VECTOR_TGIA4		VECT_MTU4_TGIA4
#define PDL_INTC_VECTOR_TGIB4		VECT_MTU4_TGIB4
#define PDL_INTC_VECTOR_TGIC4		VECT_MTU4_TGIC4
#define PDL_INTC_VECTOR_TGID4		VECT_MTU4_TGID4
#define PDL_INTC_VECTOR_TCIV4		VECT_MTU4_TCIV4
#define PDL_INTC_VECTOR_TGIU5		VECT_MTU5_TGIU5
#define PDL_INTC_VECTOR_TGIV5		VECT_MTU5_TGIV5
#define PDL_INTC_VECTOR_TGIW5		VECT_MTU5_TGIW5
#define PDL_INTC_VECTOR_OEI1		VECT_POE_OEI1
#define PDL_INTC_VECTOR_OEI2		VECT_POE_OEI2
#define PDL_INTC_VECTOR_CMIA0		VECT_TMR0_CMIA0
#define PDL_INTC_VECTOR_CMIB0		VECT_TMR0_CMIB0
#define PDL_INTC_VECTOR_OVI0		VECT_TMR0_OVI0
#define PDL_INTC_VECTOR_CMIA1		VECT_TMR1_CMIA1
#define PDL_INTC_VECTOR_CMIB1		VECT_TMR1_CMIB1
#define PDL_INTC_VECTOR_OVI1		VECT_TMR1_OVI1
#define PDL_INTC_VECTOR_CMIA2		VECT_TMR2_CMIA2
#define PDL_INTC_VECTOR_CMIB2		VECT_TMR2_CMIB2
#define PDL_INTC_VECTOR_OVI2		VECT_TMR2_OVI2
#define PDL_INTC_VECTOR_CMIA3		VECT_TMR3_CMIA3
#define PDL_INTC_VECTOR_CMIB3		VECT_TMR3_CMIB3
#define PDL_INTC_VECTOR_OVI3		VECT_TMR3_OVI3
#define PDL_INTC_VECTOR_DMAC0I		VECT_DMAC_DMAC0I
#define PDL_INTC_VECTOR_DMAC1I		VECT_DMAC_DMAC1I
#define PDL_INTC_VECTOR_DMAC2I		VECT_DMAC_DMAC2I
#define PDL_INTC_VECTOR_DMAC3I		VECT_DMAC_DMAC3I
#define PDL_INTC_VECTOR_ERI0		VECT_SCI0_ERI0
#define PDL_INTC_VECTOR_RXI0		VECT_SCI0_RXI0
#define PDL_INTC_VECTOR_TXI0		VECT_SCI0_TXI0
#define PDL_INTC_VECTOR_TEI0		VECT_SCI0_TEI0
#define PDL_INTC_VECTOR_ERI1		VECT_SCI1_ERI1
#define PDL_INTC_VECTOR_RXI1		VECT_SCI1_RXI1
#define PDL_INTC_VECTOR_TXI1		VECT_SCI1_TXI1
#define PDL_INTC_VECTOR_TEI1		VECT_SCI1_TEI1
#define PDL_INTC_VECTOR_ERI5		VECT_SCI5_ERI5
#define PDL_INTC_VECTOR_RXI5		VECT_SCI5_RXI5
#define PDL_INTC_VECTOR_TXI5		VECT_SCI5_TXI5
#define PDL_INTC_VECTOR_TEI5		VECT_SCI5_TEI5
#define PDL_INTC_VECTOR_ERI6		VECT_SCI6_ERI6
#define PDL_INTC_VECTOR_RXI6		VECT_SCI6_RXI6
#define PDL_INTC_VECTOR_TXI6		VECT_SCI6_TXI6
#define PDL_INTC_VECTOR_TEI6		VECT_SCI6_TEI6
#define PDL_INTC_VECTOR_ERI8		VECT_SCI8_ERI8
#define PDL_INTC_VECTOR_RXI8		VECT_SCI8_RXI8
#define PDL_INTC_VECTOR_TXI8		VECT_SCI8_TXI8
#define PDL_INTC_VECTOR_TEI8		VECT_SCI8_TEI8
#define PDL_INTC_VECTOR_ERI9		VECT_SCI9_ERI9
#define PDL_INTC_VECTOR_RXI9		VECT_SCI9_RXI9
#define PDL_INTC_VECTOR_TXI9		VECT_SCI9_TXI9
#define PDL_INTC_VECTOR_TEI9		VECT_SCI9_TEI9
#define PDL_INTC_VECTOR_ERI12		VECT_SCI12_ERI12
#define PDL_INTC_VECTOR_RXI12		VECT_SCI12_RXI12
#define PDL_INTC_VECTOR_TXI12		VECT_SCI12_TXI12
#define PDL_INTC_VECTOR_TEI12		VECT_SCI12_TEI12
#define PDL_INTC_VECTOR_SCIX0		VECT_SCI12_SCIX0
#define PDL_INTC_VECTOR_SCIX1		VECT_SCI12_SCIX1
#define PDL_INTC_VECTOR_SCIX2		VECT_SCI12_SCIX2
#define PDL_INTC_VECTOR_SCIX3		VECT_SCI12_SCIX3
#define PDL_INTC_VECTOR_ICEEI0		VECT_RIIC0_EEI0
#define PDL_INTC_VECTOR_ICRXI0		VECT_RIIC0_RXI0
#define PDL_INTC_VECTOR_ICTXI0		VECT_RIIC0_TXI0
#define PDL_INTC_VECTOR_ICTEI0		VECT_RIIC0_TEI0

#endif

/* End of file */
