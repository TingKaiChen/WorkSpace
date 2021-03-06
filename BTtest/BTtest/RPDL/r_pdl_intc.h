/*""FILE COMMENT""*******************************************************
* System Name	: External interrupt API
* File Name		: r_pdl_intc.h
* Version		: 0.20
* Contents		: External interrupt API header
* Customer		:
* Model			:
* Order			:
* CPU			: RX
* Compiler		: RXC
* OS			:
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

#ifndef R_PDL_INTC_H
#define R_PDL_INTC_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_INTC_SetExtInterrupt(
	uint32_t
);
bool R_INTC_CreateExtInterrupt(
	uint8_t,
	uint32_t,
	void *,
	uint8_t
);
bool R_INTC_CreateSoftwareInterrupt(
	uint8_t,
	void *,
	uint8_t
);
bool R_INTC_CreateFastInterrupt(
	uint8_t
);
bool R_INTC_CreateExceptionHandlers(
	void *,
	void *
);
bool R_INTC_ControlExtInterrupt(
	uint8_t,
	uint32_t
);
bool R_INTC_GetExtInterruptStatus(
	uint8_t,
	uint8_t *
);
bool R_INTC_Read(
	uint16_t,
	uint8_t *
);
bool R_INTC_Write(
	uint16_t,
	uint8_t
);
bool R_INTC_Modify(
	uint16_t,
	uint8_t,
	uint8_t
);

/* IRQn alternate pin selections */
#define PDL_INTC_IRQ0_PORT_3_0	0x00000001ul
#define PDL_INTC_IRQ0_PORT_D_0	0x00000002ul
#define PDL_INTC_IRQ0_PORT_H_1	0x00000004ul
#define PDL_INTC_IRQ1_PORT_3_1	0x00000008ul
#define PDL_INTC_IRQ1_PORT_D_1	0x00000010ul
#define PDL_INTC_IRQ1_PORT_H_2	0x00000020ul
#define PDL_INTC_IRQ2_PORT_3_2	0x00000040ul
#define PDL_INTC_IRQ2_PORT_1_2	0x00000080ul
#define PDL_INTC_IRQ2_PORT_D_2	0x00000100ul
#define PDL_INTC_IRQ3_PORT_3_3	0x00000200ul
#define PDL_INTC_IRQ3_PORT_1_3	0x00000400ul
#define PDL_INTC_IRQ3_PORT_D_3	0x00000800ul
#define PDL_INTC_IRQ4_PORT_B_1	0x00001000ul
#define PDL_INTC_IRQ4_PORT_1_4	0x00002000ul
#define PDL_INTC_IRQ4_PORT_3_4	0x00004000ul
#define PDL_INTC_IRQ4_PORT_D_4	0x00008000ul
#define PDL_INTC_IRQ5_PORT_A_4	0x00010000ul
#define PDL_INTC_IRQ5_PORT_1_5	0x00020000ul
#define PDL_INTC_IRQ5_PORT_D_5	0x00040000ul
#define PDL_INTC_IRQ5_PORT_E_5	0x00080000ul
#define PDL_INTC_IRQ6_PORT_A_3	0x00100000ul
#define PDL_INTC_IRQ6_PORT_1_6	0x00200000ul
#define PDL_INTC_IRQ6_PORT_D_6	0x00400000ul
#define PDL_INTC_IRQ6_PORT_E_6	0x00800000ul
#define PDL_INTC_IRQ7_PORT_E_2	0x01000000ul
#define PDL_INTC_IRQ7_PORT_1_7	0x02000000ul
#define PDL_INTC_IRQ7_PORT_D_7	0x04000000ul
#define PDL_INTC_IRQ7_PORT_E_7	0x08000000ul

/* Interrupt pins */
#define PDL_INTC_IRQ0			0
#define PDL_INTC_IRQ1			1
#define PDL_INTC_IRQ2			2
#define PDL_INTC_IRQ3			3
#define PDL_INTC_IRQ4			4
#define PDL_INTC_IRQ5			5
#define PDL_INTC_IRQ6			6
#define PDL_INTC_IRQ7			7
#define PDL_INTC_PRIVILEGED		8
#define PDL_INTC_UNDEFINED		9
#define PDL_INTC_NMI			10
#define PDL_INTC_SWINT			11

/* Detection sense selection */
#define PDL_INTC_LOW						0x00000001ul
#define PDL_INTC_FALLING					0x00000002ul
#define PDL_INTC_RISING						0x00000004ul
#define PDL_INTC_BOTH						0x00000008ul

/* Digital filter selection */
#define PDL_INTC_FILTER_DISABLE				0x00000010ul
#define PDL_INTC_FILTER_DIV_1				0x00000020ul
#define PDL_INTC_FILTER_DIV_8				0x00000040ul
#define PDL_INTC_FILTER_DIV_32				0x00000080ul
#define PDL_INTC_FILTER_DIV_64				0x00000100ul

/* DMAC / DTC trigger control */
#define PDL_INTC_DMAC_DTC_TRIGGER_DISABLE	0x00000200ul
#define PDL_INTC_DMAC_TRIGGER_ENABLE		0x00000400ul
#define PDL_INTC_DTC_TRIGGER_ENABLE			0x00000800ul

/* Oscillation stop detection control */
#define PDL_INTC_OSD_DISABLE				0x00001000ul
#define PDL_INTC_OSD_ENABLE					0x00002000ul

/* WDT detection control */
#define PDL_INTC_WDT_DISABLE				0x00004000ul
#define PDL_INTC_WDT_ENABLE					0x00008000ul

/* IWDT detection control */
#define PDL_INTC_IWDT_DISABLE				0x00010000ul
#define PDL_INTC_IWDT_ENABLE				0x00020000ul

/* LVD1 detection control */
#define PDL_INTC_LVD1_DISABLE				0x00040000ul
#define PDL_INTC_LVD1_ENABLE				0x00080000ul

/* LVD2 detection control */
#define PDL_INTC_LVD2_DISABLE				0x00100000ul
#define PDL_INTC_LVD2_ENABLE				0x00200000ul

/* Interrupt control */
#define PDL_INTC_ENABLE						0x00400000ul
#define PDL_INTC_DISABLE					0x00800000ul

/* Flag control */
#define PDL_INTC_CLEAR_IR_FLAG				0x01000000ul
#define PDL_INTC_CLEAR_OSD_FLAG				0x02000000ul
#define PDL_INTC_CLEAR_WDT_FLAG				0x04000000ul
#define PDL_INTC_CLEAR_IWDT_FLAG			0x08000000ul
#define PDL_INTC_CLEAR_LVD1_FLAG			0x10000000ul
#define PDL_INTC_CLEAR_LVD2_FLAG			0x20000000ul

/* DTC software trigger control */
#define PDL_INTC_DTC_SW_TRIGGER_DISABLE	0x01u
#define PDL_INTC_DTC_SW_TRIGGER_ENABLE	0x02u

/* Interrupt registers */
#define PDL_INTC_REG_IPL	0x0100u
#define PDL_INTC_REG_IR		0x0200u
#define PDL_INTC_REG_IER	0x0400u
#define PDL_INTC_REG_IPR	0x0800u
#define PDL_INTC_REG_DTCER	0x1000u
#define PDL_INTC_REG_SWINTR	0x2000u

/* Logical operations */
#define PDL_INTC_AND	0x01u
#define PDL_INTC_OR		0x02u
#define PDL_INTC_XOR	0x04u

/* IR registers */
#define PDL_INTC_REG_IR_BSC_BUSERR		(PDL_INTC_REG_IR | IR_BSC_BUSERR)
#define PDL_INTC_REG_IR_FCU_FIFERR		(PDL_INTC_REG_IR | IR_FCU_FIFERR)
#define PDL_INTC_REG_IR_FCU_FRDYI		(PDL_INTC_REG_IR | IR_FCU_FRDYI)
#define PDL_INTC_REG_IR_ICU_SWINT		(PDL_INTC_REG_IR | IR_ICU_SWINT)
#define PDL_INTC_REG_IR_CMT0_CMI		(PDL_INTC_REG_IR | IR_CMT0_CMI0)
#define PDL_INTC_REG_IR_CMT1_CMI		(PDL_INTC_REG_IR | IR_CMT1_CMI1)
#define PDL_INTC_REG_IR_CMT2_CMI		(PDL_INTC_REG_IR | IR_CMT2_CMI2)
#define PDL_INTC_REG_IR_CMT3_CMI		(PDL_INTC_REG_IR | IR_CMT3_CMI3)
#define PDL_INTC_REG_IR_CAC_FERRF		(PDL_INTC_REG_IR | IR_CAC_FERRF)
#define PDL_INTC_REG_IR_CAC_MENDF		(PDL_INTC_REG_IR | IR_CAC_MENDF)
#define PDL_INTC_REG_IR_CAC_OVFF		(PDL_INTC_REG_IR | IR_CAC_OVFF)
#define PDL_INTC_REG_IR_SPI0_SPEI		(PDL_INTC_REG_IR | IR_RSPI0_SPEI0)
#define PDL_INTC_REG_IR_SPI0_SPRI		(PDL_INTC_REG_IR | IR_RSPI0_SPRI0)
#define PDL_INTC_REG_IR_SPI0_SPTI		(PDL_INTC_REG_IR | IR_RSPI0_SPTI0)
#define PDL_INTC_REG_IR_SPI0_SPII		(PDL_INTC_REG_IR | IR_RSPI0_SPII0)
#define PDL_INTC_REG_IR_DOC_DOPCF		(PDL_INTC_REG_IR | IR_DOC_DOPCF)
#define PDL_INTC_REG_IR_COMPB_COMPB0	(PDL_INTC_REG_IR | IR_COMPB_COMPB0)
#define PDL_INTC_REG_IR_COMPB_COMPB1	(PDL_INTC_REG_IR | IR_COMPB_COMPB1)
#define PDL_INTC_REG_IR_RTC_COUNTUP		(PDL_INTC_REG_IR | IR_RTC_COUNTUP)
#define PDL_INTC_REG_IR_ICU_IRQ0		(PDL_INTC_REG_IR | IR_ICU_IRQ0)
#define PDL_INTC_REG_IR_ICU_IRQ1		(PDL_INTC_REG_IR | IR_ICU_IRQ1)
#define PDL_INTC_REG_IR_ICU_IRQ2		(PDL_INTC_REG_IR | IR_ICU_IRQ2)
#define PDL_INTC_REG_IR_ICU_IRQ3		(PDL_INTC_REG_IR | IR_ICU_IRQ3)
#define PDL_INTC_REG_IR_ICU_IRQ4		(PDL_INTC_REG_IR | IR_ICU_IRQ4)
#define PDL_INTC_REG_IR_ICU_IRQ5		(PDL_INTC_REG_IR | IR_ICU_IRQ5)
#define PDL_INTC_REG_IR_ICU_IRQ6		(PDL_INTC_REG_IR | IR_ICU_IRQ6)
#define PDL_INTC_REG_IR_ICU_IRQ7		(PDL_INTC_REG_IR | IR_ICU_IRQ7)
#define PDL_INTC_REG_IR_LVD_LVD1		(PDL_INTC_REG_IR | IR_LVD_LVD1)
#define PDL_INTC_REG_IR_LVD_LVD2		(PDL_INTC_REG_IR | IR_LVD_LVD2)
#define PDL_INTC_REG_IR_COMPA_COMPA1	(PDL_INTC_REG_IR | IR_COMPA_COMPA1)
#define PDL_INTC_REG_IR_COMPA_COMPA2	(PDL_INTC_REG_IR | IR_COMPA_COMPA2)
#define PDL_INTC_REG_IR_RTC_ALM			(PDL_INTC_REG_IR | IR_RTC_ALM)
#define PDL_INTC_REG_IR_RTC_PRD			(PDL_INTC_REG_IR | IR_RTC_PRD)
#define PDL_INTC_REG_IR_S12AD0_S12ADI	(PDL_INTC_REG_IR | IR_S12AD_S12ADI0)
#define PDL_INTC_REG_IR_S12AD0_GBADI	(PDL_INTC_REG_IR | IR_S12AD_GBADI)
#define PDL_INTC_REG_IR_ELC_ELSR18I		(PDL_INTC_REG_IR | IR_ELC_ELSR18I)
#define PDL_INTC_REG_IR_ELC_ELSR19I		(PDL_INTC_REG_IR | IR_ELC_ELSR19I)
#define PDL_INTC_REG_IR_MTU0_TGIA		(PDL_INTC_REG_IR | IR_MTU0_TGIA0)
#define PDL_INTC_REG_IR_MTU0_TGIB		(PDL_INTC_REG_IR | IR_MTU0_TGIB0)
#define PDL_INTC_REG_IR_MTU0_TGIC		(PDL_INTC_REG_IR | IR_MTU0_TGIC0)
#define PDL_INTC_REG_IR_MTU0_TGID		(PDL_INTC_REG_IR | IR_MTU0_TGID0)
#define PDL_INTC_REG_IR_MTU0_TCIV		(PDL_INTC_REG_IR | IR_MTU0_TCIV0)
#define PDL_INTC_REG_IR_MTU0_TGIE		(PDL_INTC_REG_IR | IR_MTU0_TGIE0)
#define PDL_INTC_REG_IR_MTU0_TGIF		(PDL_INTC_REG_IR | IR_MTU0_TGIF0)
#define PDL_INTC_REG_IR_MTU1_TGIA		(PDL_INTC_REG_IR | IR_MTU1_TGIA1)
#define PDL_INTC_REG_IR_MTU1_TGIB		(PDL_INTC_REG_IR | IR_MTU1_TGIB1)
#define PDL_INTC_REG_IR_MTU1_TCIV		(PDL_INTC_REG_IR | IR_MTU1_TCIV1)
#define PDL_INTC_REG_IR_MTU1_TCIU		(PDL_INTC_REG_IR | IR_MTU1_TCIU1)
#define PDL_INTC_REG_IR_MTU2_TGIA		(PDL_INTC_REG_IR | IR_MTU2_TGIA2)
#define PDL_INTC_REG_IR_MTU2_TGIB		(PDL_INTC_REG_IR | IR_MTU2_TGIB2)
#define PDL_INTC_REG_IR_MTU2_TCIV		(PDL_INTC_REG_IR | IR_MTU2_TCIV2)
#define PDL_INTC_REG_IR_MTU2_TCIU		(PDL_INTC_REG_IR | IR_MTU2_TCIU2)
#define PDL_INTC_REG_IR_MTU3_TGIA		(PDL_INTC_REG_IR | IR_MTU3_TGIA3)
#define PDL_INTC_REG_IR_MTU3_TGIB		(PDL_INTC_REG_IR | IR_MTU3_TGIB3)
#define PDL_INTC_REG_IR_MTU3_TGIC		(PDL_INTC_REG_IR | IR_MTU3_TGIC3)
#define PDL_INTC_REG_IR_MTU3_TGID		(PDL_INTC_REG_IR | IR_MTU3_TGID3)
#define PDL_INTC_REG_IR_MTU3_TCIV		(PDL_INTC_REG_IR | IR_MTU3_TCIV3)
#define PDL_INTC_REG_IR_MTU4_TGIA		(PDL_INTC_REG_IR | IR_MTU4_TGIA4)
#define PDL_INTC_REG_IR_MTU4_TGIB		(PDL_INTC_REG_IR | IR_MTU4_TGIB4)
#define PDL_INTC_REG_IR_MTU4_TGIC		(PDL_INTC_REG_IR | IR_MTU4_TGIC4)
#define PDL_INTC_REG_IR_MTU4_TGID		(PDL_INTC_REG_IR | IR_MTU4_TGID4)
#define PDL_INTC_REG_IR_MTU4_TCIV		(PDL_INTC_REG_IR | IR_MTU4_TCIV4)
#define PDL_INTC_REG_IR_MTU5_TGIU		(PDL_INTC_REG_IR | IR_MTU5_TGIU5)
#define PDL_INTC_REG_IR_MTU5_TGIV		(PDL_INTC_REG_IR | IR_MTU5_TGIV5)
#define PDL_INTC_REG_IR_MTU5_TGIW		(PDL_INTC_REG_IR | IR_MTU5_TGIW5)
#define PDL_INTC_REG_IR_POE_OEI1		(PDL_INTC_REG_IR | IR_POE_OEI1)
#define PDL_INTC_REG_IR_POE_OEI2		(PDL_INTC_REG_IR | IR_POE_OEI2)
#define PDL_INTC_REG_IR_TMR0_CMIA		(PDL_INTC_REG_IR | IR_TMR0_CMIA0)
#define PDL_INTC_REG_IR_TMR0_CMIB		(PDL_INTC_REG_IR | IR_TMR0_CMIB0)
#define PDL_INTC_REG_IR_TMR0_OVI		(PDL_INTC_REG_IR | IR_TMR0_OVI0)
#define PDL_INTC_REG_IR_TMR1_CMIA		(PDL_INTC_REG_IR | IR_TMR1_CMIA1)
#define PDL_INTC_REG_IR_TMR1_CMIB		(PDL_INTC_REG_IR | IR_TMR1_CMIB1)
#define PDL_INTC_REG_IR_TMR1_OVI		(PDL_INTC_REG_IR | IR_TMR1_OVI1)
#define PDL_INTC_REG_IR_TMR2_CMIA		(PDL_INTC_REG_IR | IR_TMR2_CMIA2)
#define PDL_INTC_REG_IR_TMR2_CMIB		(PDL_INTC_REG_IR | IR_TMR2_CMIB2)
#define PDL_INTC_REG_IR_TMR2_OVI		(PDL_INTC_REG_IR | IR_TMR2_OVI2)
#define PDL_INTC_REG_IR_TMR3_CMIA		(PDL_INTC_REG_IR | IR_TMR3_CMIA3)
#define PDL_INTC_REG_IR_TMR3_CMIB		(PDL_INTC_REG_IR | IR_TMR3_CMIB3)
#define PDL_INTC_REG_IR_TMR3_OVI		(PDL_INTC_REG_IR | IR_TMR3_OVI3)
#define PDL_INTC_REG_IR_DMAC_DMAC0I		(PDL_INTC_REG_IR | IR_DMAC_DMAC0I)
#define PDL_INTC_REG_IR_DMAC_DMAC1I		(PDL_INTC_REG_IR | IR_DMAC_DMAC1I)
#define PDL_INTC_REG_IR_DMAC_DMAC2I		(PDL_INTC_REG_IR | IR_DMAC_DMAC2I)
#define PDL_INTC_REG_IR_DMAC_DMAC3I		(PDL_INTC_REG_IR | IR_DMAC_DMAC3I)
#define PDL_INTC_REG_IR_SCI0_ERI		(PDL_INTC_REG_IR | IR_SCI0_ERI0)
#define PDL_INTC_REG_IR_SCI0_RXI		(PDL_INTC_REG_IR | IR_SCI0_RXI0)
#define PDL_INTC_REG_IR_SCI0_TXI		(PDL_INTC_REG_IR | IR_SCI0_TXI0)
#define PDL_INTC_REG_IR_SCI0_TEI		(PDL_INTC_REG_IR | IR_SCI0_TEI0)
#define PDL_INTC_REG_IR_SCI1_ERI		(PDL_INTC_REG_IR | IR_SCI1_ERI1)
#define PDL_INTC_REG_IR_SCI1_RXI		(PDL_INTC_REG_IR | IR_SCI1_RXI1)
#define PDL_INTC_REG_IR_SCI1_TXI		(PDL_INTC_REG_IR | IR_SCI1_TXI1)
#define PDL_INTC_REG_IR_SCI1_TEI		(PDL_INTC_REG_IR | IR_SCI1_TEI1)
#define PDL_INTC_REG_IR_SCI5_ERI		(PDL_INTC_REG_IR | IR_SCI5_ERI5)
#define PDL_INTC_REG_IR_SCI5_RXI		(PDL_INTC_REG_IR | IR_SCI5_RXI5)
#define PDL_INTC_REG_IR_SCI5_TXI		(PDL_INTC_REG_IR | IR_SCI5_TXI5)
#define PDL_INTC_REG_IR_SCI5_TEI		(PDL_INTC_REG_IR | IR_SCI5_TEI5)
#define PDL_INTC_REG_IR_SCI6_ERI		(PDL_INTC_REG_IR | IR_SCI6_ERI6)
#define PDL_INTC_REG_IR_SCI6_RXI		(PDL_INTC_REG_IR | IR_SCI6_RXI6)
#define PDL_INTC_REG_IR_SCI6_TXI		(PDL_INTC_REG_IR | IR_SCI6_TXI6)
#define PDL_INTC_REG_IR_SCI6_TEI		(PDL_INTC_REG_IR | IR_SCI6_TEI6)
#define PDL_INTC_REG_IR_SCI8_ERI		(PDL_INTC_REG_IR | IR_SCI8_ERI8)
#define PDL_INTC_REG_IR_SCI8_RXI		(PDL_INTC_REG_IR | IR_SCI8_RXI8)
#define PDL_INTC_REG_IR_SCI8_TXI		(PDL_INTC_REG_IR | IR_SCI8_TXI8)
#define PDL_INTC_REG_IR_SCI8_TEI		(PDL_INTC_REG_IR | IR_SCI8_TEI8)
#define PDL_INTC_REG_IR_SCI9_ERI		(PDL_INTC_REG_IR | IR_SCI9_ERI9)
#define PDL_INTC_REG_IR_SCI9_RXI		(PDL_INTC_REG_IR | IR_SCI9_RXI9)
#define PDL_INTC_REG_IR_SCI9_TXI		(PDL_INTC_REG_IR | IR_SCI9_TXI9)
#define PDL_INTC_REG_IR_SCI9_TEI		(PDL_INTC_REG_IR | IR_SCI9_TEI9)
#define PDL_INTC_REG_IR_SCI12_ERI		(PDL_INTC_REG_IR | IR_SCI12_ERI12)
#define PDL_INTC_REG_IR_SCI12_RXI		(PDL_INTC_REG_IR | IR_SCI12_RXI12)
#define PDL_INTC_REG_IR_SCI12_TXI		(PDL_INTC_REG_IR | IR_SCI12_TXI12)
#define PDL_INTC_REG_IR_SCI12_TEI		(PDL_INTC_REG_IR | IR_SCI12_TEI12)
#define PDL_INTC_REG_IR_SCI12_SCIX0		(PDL_INTC_REG_IR | IR_SCI12_SCIX0)
#define PDL_INTC_REG_IR_SCI12_SCIX1		(PDL_INTC_REG_IR | IR_SCI12_SCIX1)
#define PDL_INTC_REG_IR_SCI12_SCIX2		(PDL_INTC_REG_IR | IR_SCI12_SCIX2)
#define PDL_INTC_REG_IR_SCI12_SCIX3		(PDL_INTC_REG_IR | IR_SCI12_SCIX3)
#define PDL_INTC_REG_IR_IIC0_EEI		(PDL_INTC_REG_IR | IR_RIIC0_EEI0)
#define PDL_INTC_REG_IR_IIC0_RXI		(PDL_INTC_REG_IR | IR_RIIC0_RXI0)
#define PDL_INTC_REG_IR_IIC0_TXI		(PDL_INTC_REG_IR | IR_RIIC0_TXI0)
#define PDL_INTC_REG_IR_IIC0_TEI		(PDL_INTC_REG_IR | IR_RIIC0_TEI0)

/* IER registers */
#define PDL_INTC_REG_IER02	(PDL_INTC_REG_IER | 0x02)
#define PDL_INTC_REG_IER03	(PDL_INTC_REG_IER | 0x03)
#define PDL_INTC_REG_IER04	(PDL_INTC_REG_IER | 0x04)
#define PDL_INTC_REG_IER05	(PDL_INTC_REG_IER | 0x05)
#define PDL_INTC_REG_IER07	(PDL_INTC_REG_IER | 0x07)
#define PDL_INTC_REG_IER08	(PDL_INTC_REG_IER | 0x08)
#define PDL_INTC_REG_IER0B	(PDL_INTC_REG_IER | 0x0B)
#define PDL_INTC_REG_IER0C	(PDL_INTC_REG_IER | 0x0C)
#define PDL_INTC_REG_IER0E	(PDL_INTC_REG_IER | 0x0E)
#define PDL_INTC_REG_IER0F	(PDL_INTC_REG_IER | 0x0F)
#define PDL_INTC_REG_IER10	(PDL_INTC_REG_IER | 0x10)
#define PDL_INTC_REG_IER11	(PDL_INTC_REG_IER | 0x11)
#define PDL_INTC_REG_IER15	(PDL_INTC_REG_IER | 0x15)
#define PDL_INTC_REG_IER16	(PDL_INTC_REG_IER | 0x16)
#define PDL_INTC_REG_IER17	(PDL_INTC_REG_IER | 0x17)
#define PDL_INTC_REG_IER18	(PDL_INTC_REG_IER | 0x18)
#define PDL_INTC_REG_IER19	(PDL_INTC_REG_IER | 0x19)
#define PDL_INTC_REG_IER1A	(PDL_INTC_REG_IER | 0x1A)
#define PDL_INTC_REG_IER1B	(PDL_INTC_REG_IER | 0x1B)
#define PDL_INTC_REG_IER1C	(PDL_INTC_REG_IER | 0x1C)
#define PDL_INTC_REG_IER1D	(PDL_INTC_REG_IER | 0x1D)
#define PDL_INTC_REG_IER1E	(PDL_INTC_REG_IER | 0x1E)
#define PDL_INTC_REG_IER1F	(PDL_INTC_REG_IER | 0x1F)

/* IPR registers */
#define PDL_INTC_REG_IPR_BSC_BUSERR		(PDL_INTC_REG_IPR | IPR_BSC_BUSERR)
#define PDL_INTC_REG_IPR_FCU_FIFERR		(PDL_INTC_REG_IPR | IPR_FCU_FIFERR)
#define PDL_INTC_REG_IPR_FCU_FRDYI		(PDL_INTC_REG_IPR | IPR_FCU_FRDYI)
#define PDL_INTC_REG_IPR_ICU_SWINT		(PDL_INTC_REG_IPR | IPR_ICU_SWINT)
#define PDL_INTC_REG_IPR_CMT0_CMI		(PDL_INTC_REG_IPR | IPR_CMT0_CMI0)
#define PDL_INTC_REG_IPR_CMT1_CMI		(PDL_INTC_REG_IPR | IPR_CMT1_CMI1)
#define PDL_INTC_REG_IPR_CMT2_CMI		(PDL_INTC_REG_IPR | IPR_CMT2_CMI2)
#define PDL_INTC_REG_IPR_CMT3_CMI		(PDL_INTC_REG_IPR | IPR_CMT3_CMI3)
#define PDL_INTC_REG_IPR_CAC_FERRF		(PDL_INTC_REG_IPR | IPR_CAC_FERRF)
#define PDL_INTC_REG_IPR_CAC_MENDF		(PDL_INTC_REG_IPR | IPR_CAC_MENDF)
#define PDL_INTC_REG_IPR_CAC_OVFF		(PDL_INTC_REG_IPR | IPR_CAC_OVFF)
#define PDL_INTC_REG_IPR_SPI0_SPEI		(PDL_INTC_REG_IPR | IPR_RSPI0_SPEI0)
#define PDL_INTC_REG_IPR_SPI0_SPRI		(PDL_INTC_REG_IPR | IPR_RSPI0_SPRI0)
#define PDL_INTC_REG_IPR_SPI0_SPTI		(PDL_INTC_REG_IPR | IPR_RSPI0_SPTI0)
#define PDL_INTC_REG_IPR_SPI0_SPII		(PDL_INTC_REG_IPR | IPR_RSPI0_SPII0)
#define PDL_INTC_REG_IPR_DOC_DOPCF		(PDL_INTC_REG_IPR | IPR_DOC_DOPCF)
#define PDL_INTC_REG_IPR_COMPB_COMPB0	(PDL_INTC_REG_IPR | IPR_COMPB_COMPB0)
#define PDL_INTC_REG_IPR_COMPB_COMPB1	(PDL_INTC_REG_IPR | IPR_COMPB_COMPB1)
#define PDL_INTC_REG_IPR_RTC_COUNTUP	(PDL_INTC_REG_IPR | IPR_RTC_COUNTUP)
#define PDL_INTC_REG_IPR_ICU_IRQ0		(PDL_INTC_REG_IPR | IPR_ICU_IRQ0)
#define PDL_INTC_REG_IPR_ICU_IRQ1		(PDL_INTC_REG_IPR | IPR_ICU_IRQ1)
#define PDL_INTC_REG_IPR_ICU_IRQ2		(PDL_INTC_REG_IPR | IPR_ICU_IRQ2)
#define PDL_INTC_REG_IPR_ICU_IRQ3		(PDL_INTC_REG_IPR | IPR_ICU_IRQ3)
#define PDL_INTC_REG_IPR_ICU_IRQ4		(PDL_INTC_REG_IPR | IPR_ICU_IRQ4)
#define PDL_INTC_REG_IPR_ICU_IRQ5		(PDL_INTC_REG_IPR | IPR_ICU_IRQ5)
#define PDL_INTC_REG_IPR_ICU_IRQ6		(PDL_INTC_REG_IPR | IPR_ICU_IRQ6)
#define PDL_INTC_REG_IPR_ICU_IRQ7		(PDL_INTC_REG_IPR | IPR_ICU_IRQ7)
#define PDL_INTC_REG_IPR_LVD_LVD1		(PDL_INTC_REG_IPR | IPR_LVD_LVD1)
#define PDL_INTC_REG_IPR_LVD_LVD2		(PDL_INTC_REG_IPR | IPR_LVD_LVD2)
#define PDL_INTC_REG_IPR_COMPA_COMPA1	(PDL_INTC_REG_IPR | IPR_COMPA_COMPA1)
#define PDL_INTC_REG_IPR_COMPA_COMPA2	(PDL_INTC_REG_IPR | IPR_COMPA_COMPA2)
#define PDL_INTC_REG_IPR_RTC_ALM		(PDL_INTC_REG_IPR | IPR_RTC_ALM)
#define PDL_INTC_REG_IPR_RTC_PRD		(PDL_INTC_REG_IPR | IPR_RTC_PRD)
#define PDL_INTC_REG_IPR_S12AD0_S12ADI	(PDL_INTC_REG_IPR | IPR_S12AD_S12ADI0)
#define PDL_INTC_REG_IPR_S12AD0_GBADI	(PDL_INTC_REG_IPR | IPR_S12AD_GBADI)
#define PDL_INTC_REG_IPR_ELC_ELSR18I	(PDL_INTC_REG_IPR | IPR_ELC_ELSR18I)
#define PDL_INTC_REG_IPR_ELC_ELSR19I	(PDL_INTC_REG_IPR | IPR_ELC_ELSR19I)
#define PDL_INTC_REG_IPR_MTU0_TGIA		(PDL_INTC_REG_IPR | IPR_MTU0_TGIA0)
#define PDL_INTC_REG_IPR_MTU0_TGIB		(PDL_INTC_REG_IPR | IPR_MTU0_TGIB0)
#define PDL_INTC_REG_IPR_MTU0_TGIC		(PDL_INTC_REG_IPR | IPR_MTU0_TGIC0)
#define PDL_INTC_REG_IPR_MTU0_TGID		(PDL_INTC_REG_IPR | IPR_MTU0_TGID0)
#define PDL_INTC_REG_IPR_MTU0_TCIV		(PDL_INTC_REG_IPR | IPR_MTU0_TCIV0)
#define PDL_INTC_REG_IPR_MTU0_TGIE		(PDL_INTC_REG_IPR | IPR_MTU0_TGIE0)
#define PDL_INTC_REG_IPR_MTU0_TGIF		(PDL_INTC_REG_IPR | IPR_MTU0_TGIF0)
#define PDL_INTC_REG_IPR_MTU1_TGIA		(PDL_INTC_REG_IPR | IPR_MTU1_TGIA1)
#define PDL_INTC_REG_IPR_MTU1_TGIB		(PDL_INTC_REG_IPR | IPR_MTU1_TGIB1)
#define PDL_INTC_REG_IPR_MTU1_TCIV		(PDL_INTC_REG_IPR | IPR_MTU1_TCIV1)
#define PDL_INTC_REG_IPR_MTU1_TCIU		(PDL_INTC_REG_IPR | IPR_MTU1_TCIU1)
#define PDL_INTC_REG_IPR_MTU2_TGIA		(PDL_INTC_REG_IPR | IPR_MTU2_TGIA2)
#define PDL_INTC_REG_IPR_MTU2_TGIB		(PDL_INTC_REG_IPR | IPR_MTU2_TGIB2)
#define PDL_INTC_REG_IPR_MTU2_TCIV		(PDL_INTC_REG_IPR | IPR_MTU2_TCIV2)
#define PDL_INTC_REG_IPR_MTU2_TCIU		(PDL_INTC_REG_IPR | IPR_MTU2_TCIU2)
#define PDL_INTC_REG_IPR_MTU3_TGIA		(PDL_INTC_REG_IPR | IPR_MTU3_TGIA3)
#define PDL_INTC_REG_IPR_MTU3_TGIB		(PDL_INTC_REG_IPR | IPR_MTU3_TGIB3)
#define PDL_INTC_REG_IPR_MTU3_TGIC		(PDL_INTC_REG_IPR | IPR_MTU3_TGIC3)
#define PDL_INTC_REG_IPR_MTU3_TGID		(PDL_INTC_REG_IPR | IPR_MTU3_TGID3)
#define PDL_INTC_REG_IPR_MTU3_TCIV		(PDL_INTC_REG_IPR | IPR_MTU3_TCIV3)
#define PDL_INTC_REG_IPR_MTU4_TGIA		(PDL_INTC_REG_IPR | IPR_MTU4_TGIA4)
#define PDL_INTC_REG_IPR_MTU4_TGIB		(PDL_INTC_REG_IPR | IPR_MTU4_TGIB4)
#define PDL_INTC_REG_IPR_MTU4_TGIC		(PDL_INTC_REG_IPR | IPR_MTU4_TGIC4)
#define PDL_INTC_REG_IPR_MTU4_TGID		(PDL_INTC_REG_IPR | IPR_MTU4_TGID4)
#define PDL_INTC_REG_IPR_MTU4_TCIV		(PDL_INTC_REG_IPR | IPR_MTU4_TCIV4)
#define PDL_INTC_REG_IPR_MTU5_TGIU		(PDL_INTC_REG_IPR | IPR_MTU5_TGIU5)
#define PDL_INTC_REG_IPR_MTU5_TGIV		(PDL_INTC_REG_IPR | IPR_MTU5_TGIV5)
#define PDL_INTC_REG_IPR_MTU5_TGIW		(PDL_INTC_REG_IPR | IPR_MTU5_TGIW5)
#define PDL_INTC_REG_IPR_POE_OEI1		(PDL_INTC_REG_IPR | IPR_POE_OEI1)
#define PDL_INTC_REG_IPR_POE_OEI2		(PDL_INTC_REG_IPR | IPR_POE_OEI2)
#define PDL_INTC_REG_IPR_TMR0_CMIA		(PDL_INTC_REG_IPR | IPR_TMR0_CMIA0)
#define PDL_INTC_REG_IPR_TMR0_CMIB		(PDL_INTC_REG_IPR | IPR_TMR0_CMIB0)
#define PDL_INTC_REG_IPR_TMR0_OVI		(PDL_INTC_REG_IPR | IPR_TMR0_OVI0)
#define PDL_INTC_REG_IPR_TMR1_CMIA		(PDL_INTC_REG_IPR | IPR_TMR1_CMIA1)
#define PDL_INTC_REG_IPR_TMR1_CMIB		(PDL_INTC_REG_IPR | IPR_TMR1_CMIB1)
#define PDL_INTC_REG_IPR_TMR1_OVI		(PDL_INTC_REG_IPR | IPR_TMR1_OVI1)
#define PDL_INTC_REG_IPR_TMR2_CMIA		(PDL_INTC_REG_IPR | IPR_TMR2_CMIA2)
#define PDL_INTC_REG_IPR_TMR2_CMIB		(PDL_INTC_REG_IPR | IPR_TMR2_CMIB2)
#define PDL_INTC_REG_IPR_TMR2_OVI		(PDL_INTC_REG_IPR | IPR_TMR2_OVI2)
#define PDL_INTC_REG_IPR_TMR3_CMIA		(PDL_INTC_REG_IPR | IPR_TMR3_CMIA3)
#define PDL_INTC_REG_IPR_TMR3_CMIB		(PDL_INTC_REG_IPR | IPR_TMR3_CMIB3)
#define PDL_INTC_REG_IPR_TMR3_OVI		(PDL_INTC_REG_IPR | IPR_TMR3_OVI3)
#define PDL_INTC_REG_IPR_DMAC_DMAC0I	(PDL_INTC_REG_IPR | IPR_DMAC_DMAC0I)
#define PDL_INTC_REG_IPR_DMAC_DMAC1I	(PDL_INTC_REG_IPR | IPR_DMAC_DMAC1I)
#define PDL_INTC_REG_IPR_DMAC_DMAC2I	(PDL_INTC_REG_IPR | IPR_DMAC_DMAC2I)
#define PDL_INTC_REG_IPR_DMAC_DMAC3I	(PDL_INTC_REG_IPR | IPR_DMAC_DMAC3I)
#define PDL_INTC_REG_IPR_SCI0_ERI		(PDL_INTC_REG_IPR | IPR_SCI0_ERI0)
#define PDL_INTC_REG_IPR_SCI0_RXI		(PDL_INTC_REG_IPR | IPR_SCI0_RXI0)
#define PDL_INTC_REG_IPR_SCI0_TXI		(PDL_INTC_REG_IPR | IPR_SCI0_TXI0)
#define PDL_INTC_REG_IPR_SCI0_TEI		(PDL_INTC_REG_IPR | IPR_SCI0_TEI0)
#define PDL_INTC_REG_IPR_SCI1_ERI		(PDL_INTC_REG_IPR | IPR_SCI1_ERI1)
#define PDL_INTC_REG_IPR_SCI1_RXI		(PDL_INTC_REG_IPR | IPR_SCI1_RXI1)
#define PDL_INTC_REG_IPR_SCI1_TXI		(PDL_INTC_REG_IPR | IPR_SCI1_TXI1)
#define PDL_INTC_REG_IPR_SCI1_TEI		(PDL_INTC_REG_IPR | IPR_SCI1_TEI1)
#define PDL_INTC_REG_IPR_SCI5_ERI		(PDL_INTC_REG_IPR | IPR_SCI5_ERI5)
#define PDL_INTC_REG_IPR_SCI5_RXI		(PDL_INTC_REG_IPR | IPR_SCI5_RXI5)
#define PDL_INTC_REG_IPR_SCI5_TXI		(PDL_INTC_REG_IPR | IPR_SCI5_TXI5)
#define PDL_INTC_REG_IPR_SCI5_TEI		(PDL_INTC_REG_IPR | IPR_SCI5_TEI5)
#define PDL_INTC_REG_IPR_SCI6_ERI		(PDL_INTC_REG_IPR | IPR_SCI6_ERI6)
#define PDL_INTC_REG_IPR_SCI6_RXI		(PDL_INTC_REG_IPR | IPR_SCI6_RXI6)
#define PDL_INTC_REG_IPR_SCI6_TXI		(PDL_INTC_REG_IPR | IPR_SCI6_TXI6)
#define PDL_INTC_REG_IPR_SCI6_TEI		(PDL_INTC_REG_IPR | IPR_SCI6_TEI6)
#define PDL_INTC_REG_IPR_SCI8_ERI		(PDL_INTC_REG_IPR | IPR_SCI8_ERI8)
#define PDL_INTC_REG_IPR_SCI8_RXI		(PDL_INTC_REG_IPR | IPR_SCI8_RXI8)
#define PDL_INTC_REG_IPR_SCI8_TXI		(PDL_INTC_REG_IPR | IPR_SCI8_TXI8)
#define PDL_INTC_REG_IPR_SCI8_TEI		(PDL_INTC_REG_IPR | IPR_SCI8_TEI8)
#define PDL_INTC_REG_IPR_SCI9_ERI		(PDL_INTC_REG_IPR | IPR_SCI9_ERI9)
#define PDL_INTC_REG_IPR_SCI9_RXI		(PDL_INTC_REG_IPR | IPR_SCI9_RXI9)
#define PDL_INTC_REG_IPR_SCI9_TXI		(PDL_INTC_REG_IPR | IPR_SCI9_TXI9)
#define PDL_INTC_REG_IPR_SCI9_TEI		(PDL_INTC_REG_IPR | IPR_SCI9_TEI9)
#define PDL_INTC_REG_IPR_SCI12_ERI		(PDL_INTC_REG_IPR | IPR_SCI12_ERI12)
#define PDL_INTC_REG_IPR_SCI12_RXI		(PDL_INTC_REG_IPR | IPR_SCI12_RXI12)
#define PDL_INTC_REG_IPR_SCI12_TXI		(PDL_INTC_REG_IPR | IPR_SCI12_TXI12)
#define PDL_INTC_REG_IPR_SCI12_TEI		(PDL_INTC_REG_IPR | IPR_SCI12_TEI12)
#define PDL_INTC_REG_IPR_SCI12_SCIX0	(PDL_INTC_REG_IPR | IPR_SCI12_SCIX0)
#define PDL_INTC_REG_IPR_SCI12_SCIX1	(PDL_INTC_REG_IPR | IPR_SCI12_SCIX1)
#define PDL_INTC_REG_IPR_SCI12_SCIX2	(PDL_INTC_REG_IPR | IPR_SCI12_SCIX2)
#define PDL_INTC_REG_IPR_SCI12_SCIX3	(PDL_INTC_REG_IPR | IPR_SCI12_SCIX3)
#define PDL_INTC_REG_IPR_IIC0_EEI		(PDL_INTC_REG_IPR | IPR_RIIC0_EEI0)
#define PDL_INTC_REG_IPR_IIC0_RXI		(PDL_INTC_REG_IPR | IPR_RIIC0_RXI0)
#define PDL_INTC_REG_IPR_IIC0_TXI		(PDL_INTC_REG_IPR | IPR_RIIC0_TXI0)
#define PDL_INTC_REG_IPR_IIC0_TEI		(PDL_INTC_REG_IPR | IPR_RIIC0_TEI0)

/* DTCER registers */
#define PDL_INTC_REG_DTCER_ICU_SWINT		(PDL_INTC_REG_DTCER | DTCE_ICU_SWINT)
#define PDL_INTC_REG_DTCER_CMT0_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT0_CMI0)
#define PDL_INTC_REG_DTCER_CMT1_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT1_CMI1)
#define PDL_INTC_REG_DTCER_CMT2_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT2_CMI2)
#define PDL_INTC_REG_DTCER_CMT3_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT3_CMI3)
#define PDL_INTC_REG_DTCER_SPI0_SPRI		(PDL_INTC_REG_DTCER | DTCE_RSPI0_SPRI0)
#define PDL_INTC_REG_DTCER_SPI0_SPTI		(PDL_INTC_REG_DTCER | DTCE_RSPI0_SPTI0)
#define PDL_INTC_REG_DTCER_COMPB_COMPB0		(PDL_INTC_REG_DTCER | DTCE_COMPB_COMPB0)
#define PDL_INTC_REG_DTCER_COMPB_COMPB1		(PDL_INTC_REG_DTCER | DTCE_COMPB_COMPB1)
#define PDL_INTC_REG_DTCER_ICU_IRQ0			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ0)
#define PDL_INTC_REG_DTCER_ICU_IRQ1			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ1)
#define PDL_INTC_REG_DTCER_ICU_IRQ2			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ2)
#define PDL_INTC_REG_DTCER_ICU_IRQ3			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ3)
#define PDL_INTC_REG_DTCER_ICU_IRQ4			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ4)
#define PDL_INTC_REG_DTCER_ICU_IRQ5			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ5)
#define PDL_INTC_REG_DTCER_ICU_IRQ6			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ6)
#define PDL_INTC_REG_DTCER_ICU_IRQ7			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ7)
#define PDL_INTC_REG_DTCER_S12AD0_S12ADI	(PDL_INTC_REG_DTCER | DTCE_S12AD_S12ADI0)
#define PDL_INTC_REG_DTCER_S12AD0_GBADI		(PDL_INTC_REG_DTCER | DTCE_S12AD_GBADI)
#define PDL_INTC_REG_DTCER_ELC_ELSR18I		(PDL_INTC_REG_DTCER | DTCE_ELC_ELSR18I)
#define PDL_INTC_REG_DTCER_ELC_ELSR19I		(PDL_INTC_REG_DTCER | DTCE_ELC_ELSR19I)
#define PDL_INTC_REG_DTCER_MTU0_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIA0)
#define PDL_INTC_REG_DTCER_MTU0_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIB0)
#define PDL_INTC_REG_DTCER_MTU0_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIC0)
#define PDL_INTC_REG_DTCER_MTU0_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGID0)
#define PDL_INTC_REG_DTCER_MTU1_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU1_TGIA1)
#define PDL_INTC_REG_DTCER_MTU1_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU1_TGIB1)
#define PDL_INTC_REG_DTCER_MTU2_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU2_TGIA2)
#define PDL_INTC_REG_DTCER_MTU2_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU2_TGIB2)
#define PDL_INTC_REG_DTCER_MTU3_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIA3)
#define PDL_INTC_REG_DTCER_MTU3_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIB3)
#define PDL_INTC_REG_DTCER_MTU3_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIC3)
#define PDL_INTC_REG_DTCER_MTU3_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGID3)
#define PDL_INTC_REG_DTCER_MTU4_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIA4)
#define PDL_INTC_REG_DTCER_MTU4_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIB4)
#define PDL_INTC_REG_DTCER_MTU4_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIC4)
#define PDL_INTC_REG_DTCER_MTU4_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGID4)
#define PDL_INTC_REG_DTCER_MTU4_TCIV		(PDL_INTC_REG_DTCER | DTCE_MTU4_TCIV4)
#define PDL_INTC_REG_DTCER_MTU5_TGIU		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIU5)
#define PDL_INTC_REG_DTCER_MTU5_TGIV		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIV5)
#define PDL_INTC_REG_DTCER_MTU5_TGIW		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIW5)
#define PDL_INTC_REG_DTCER_TMR0_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR0_CMIA0)
#define PDL_INTC_REG_DTCER_TMR0_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR0_CMIB0)
#define PDL_INTC_REG_DTCER_TMR1_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR1_CMIA1)
#define PDL_INTC_REG_DTCER_TMR1_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR1_CMIB1)
#define PDL_INTC_REG_DTCER_TMR2_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR2_CMIA2)
#define PDL_INTC_REG_DTCER_TMR2_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR2_CMIB2)
#define PDL_INTC_REG_DTCER_TMR3_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR3_CMIA3)
#define PDL_INTC_REG_DTCER_TMR3_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR3_CMIB3)
#define PDL_INTC_REG_DTCER_DMAC_DMAC0I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC0I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC1I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC1I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC2I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC2I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC3I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC3I)
#define PDL_INTC_REG_DTCER_SCI0_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI0_RXI0)
#define PDL_INTC_REG_DTCER_SCI0_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI0_TXI0)
#define PDL_INTC_REG_DTCER_SCI1_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI1_RXI1)
#define PDL_INTC_REG_DTCER_SCI1_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI1_TXI1)
#define PDL_INTC_REG_DTCER_SCI5_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI5_RXI5)
#define PDL_INTC_REG_DTCER_SCI5_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI5_TXI5)
#define PDL_INTC_REG_DTCER_SCI6_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI6_RXI6)
#define PDL_INTC_REG_DTCER_SCI6_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI6_TXI6)
#define PDL_INTC_REG_DTCER_SCI8_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI8_RXI8)
#define PDL_INTC_REG_DTCER_SCI8_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI8_TXI8)
#define PDL_INTC_REG_DTCER_SCI9_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI9_RXI9)
#define PDL_INTC_REG_DTCER_SCI9_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI9_TXI9)
#define PDL_INTC_REG_DTCER_SCI12_RXI		(PDL_INTC_REG_DTCER | DTCE_SCI12_RXI12)
#define PDL_INTC_REG_DTCER_SCI12_TXI		(PDL_INTC_REG_DTCER | DTCE_SCI12_TXI12)
#define PDL_INTC_REG_DTCER_IIC0_RXI			(PDL_INTC_REG_DTCER | DTCE_RIIC0_RXI0)
#define PDL_INTC_REG_DTCER_IIC0_TXI			(PDL_INTC_REG_DTCER | DTCE_RIIC0_TXI0)

#endif
/* End of file */
