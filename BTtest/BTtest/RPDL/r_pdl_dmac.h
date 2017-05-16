/*""FILE COMMENT""*******************************************************
* System Name	: DMAC API for RX210xx
* File Name		: r_pdl_dmac.h
* Version		: 0.20
* Contents		: DMAC API header
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

#ifndef R_PDL_DMAC_H
#define R_PDL_DMAC_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_DMAC_Create(
	uint8_t,
	uint32_t,
	uint8_t,
	void *,
	void *,
	uint16_t,
	uint16_t,
	int32_t,
	uint32_t,
	uint32_t,
	void *,
	uint8_t
);
bool R_DMAC_Destroy(
	uint8_t
);
bool R_DMAC_Control(
	uint8_t,
	uint16_t,
	void *,
	void *,
	uint16_t,
	uint16_t,
	int32_t,
	uint32_t,
	uint32_t
);
bool R_DMAC_GetStatus(
	uint8_t,
	uint8_t *,
	uint32_t *,
	uint32_t *,
	uint16_t *,
	uint16_t *
);
	
/* Transfer mode selection */
#define PDL_DMAC_NORMAL						0x00000001ul
#define PDL_DMAC_REPEAT						0x00000002ul
#define PDL_DMAC_BLOCK						0x00000004ul
#define PDL_DMAC_SOURCE						0x00000008ul
#define PDL_DMAC_DESTINATION				0x00000010ul

/* Address addition direction selection */
#define PDL_DMAC_SOURCE_ADDRESS_FIXED		0x00000020ul
#define PDL_DMAC_SOURCE_ADDRESS_PLUS		0x00000040ul
#define PDL_DMAC_SOURCE_ADDRESS_MINUS		0x00000080ul
#define PDL_DMAC_SOURCE_ADDRESS_OFFSET		0x00000100ul
#define PDL_DMAC_DESTINATION_ADDRESS_FIXED	0x00000200ul
#define PDL_DMAC_DESTINATION_ADDRESS_PLUS	0x00000400ul
#define PDL_DMAC_DESTINATION_ADDRESS_MINUS	0x00000800ul
#define PDL_DMAC_DESTINATION_ADDRESS_OFFSET	0x00001000ul

/* Transfer data size */
#define PDL_DMAC_SIZE_8						0x00002000ul
#define PDL_DMAC_SIZE_16					0x00004000ul
#define PDL_DMAC_SIZE_32					0x00008000ul

/* Interrupt generation */
#define PDL_DMAC_IRQ_END					0x00010000ul
#define PDL_DMAC_IRQ_ESCAPE_END				0x00020000ul
#define PDL_DMAC_IRQ_REPEAT_SIZE_END		0x00040000ul
#define PDL_DMAC_IRQ_EXT_SOURCE				0x00080000ul
#define PDL_DMAC_IRQ_EXT_DESTINATION		0x00100000ul

/* Start trigger forwarding */
#define PDL_DMAC_TRIGGER_CLEAR				0x00200000ul
#define PDL_DMAC_TRIGGER_FORWARD			0x00400000ul

/* DTC trigger control */
#define PDL_DMAC_DTC_TRIGGER_DISABLE		0x00800000ul
#define PDL_DMAC_DTC_TRIGGER_ENABLE			0x01000000ul

/* DMAC activation source */
#define PDL_DMAC_TRIGGER_SW					0x00u
#define PDL_DMAC_TRIGGER_CMT0				VECT_CMT0_CMI0
#define PDL_DMAC_TRIGGER_CMT1				VECT_CMT1_CMI1
#define PDL_DMAC_TRIGGER_CMT2				VECT_CMT2_CMI2
#define PDL_DMAC_TRIGGER_CMT3				VECT_CMT3_CMI3
#define PDL_DMAC_TRIGGER_SPI0_RX			VECT_RSPI0_SPRI0
#define PDL_DMAC_TRIGGER_SPI0_TX			VECT_RSPI0_SPTI0
#define PDL_DMAC_TRIGGER_COMPB0				VECT_COMPB_COMPB0
#define PDL_DMAC_TRIGGER_COMPB1				VECT_COMPB_COMPB1
#define PDL_DMAC_TRIGGER_IRQ0				VECT_ICU_IRQ0
#define PDL_DMAC_TRIGGER_IRQ1				VECT_ICU_IRQ1
#define PDL_DMAC_TRIGGER_IRQ2				VECT_ICU_IRQ2
#define PDL_DMAC_TRIGGER_IRQ3				VECT_ICU_IRQ3
#define PDL_DMAC_TRIGGER_ADC12				VECT_S12AD_S12ADI0
#define PDL_DMAC_TRIGGER_ADC12_GBADI		VECT_S12AD_GBADI
#define PDL_DMAC_TRIGGER_ELSR18I			VECT_ELC_ELSR18I
#define PDL_DMAC_TRIGGER_ELSR19I			VECT_ELC_ELSR19I
#define PDL_DMAC_TRIGGER_MTU0				VECT_MTU0_TGIA0
#define PDL_DMAC_TRIGGER_MTU1				VECT_MTU1_TGIA1
#define PDL_DMAC_TRIGGER_MTU2				VECT_MTU2_TGIA2
#define PDL_DMAC_TRIGGER_MTU3				VECT_MTU3_TGIA3
#define PDL_DMAC_TRIGGER_MTU4				VECT_MTU4_TGIA4
#define PDL_DMAC_TRIGGER_SCI0_RX			VECT_SCI0_RXI0
#define PDL_DMAC_TRIGGER_SCI0_TX			VECT_SCI0_TXI0
#define PDL_DMAC_TRIGGER_SCI1_RX			VECT_SCI1_RXI1
#define PDL_DMAC_TRIGGER_SCI1_TX			VECT_SCI1_TXI1
#define PDL_DMAC_TRIGGER_SCI5_RX			VECT_SCI5_RXI5
#define PDL_DMAC_TRIGGER_SCI5_TX			VECT_SCI5_TXI5
#define PDL_DMAC_TRIGGER_SCI6_RX			VECT_SCI6_RXI6
#define PDL_DMAC_TRIGGER_SCI6_TX			VECT_SCI6_TXI6
#define PDL_DMAC_TRIGGER_SCI8_RX			VECT_SCI8_RXI8
#define PDL_DMAC_TRIGGER_SCI8_TX			VECT_SCI8_TXI8
#define PDL_DMAC_TRIGGER_SCI9_RX			VECT_SCI9_RXI9
#define PDL_DMAC_TRIGGER_SCI9_TX			VECT_SCI9_TXI9
#define PDL_DMAC_TRIGGER_SCI12_RX			VECT_SCI12_RXI12
#define PDL_DMAC_TRIGGER_SCI12_TX			VECT_SCI12_TXI12
#define PDL_DMAC_TRIGGER_IIC0_RX			VECT_RIIC0_RXI0
#define PDL_DMAC_TRIGGER_IIC0_TX			VECT_RIIC0_TXI0

/* Enable / suspend control */
#define PDL_DMAC_ENABLE						0x0001u
#define PDL_DMAC_SUSPEND					0x0002u

/* Software trigger control */
#define PDL_DMAC_START						0x0004u
#define PDL_DMAC_START_RUN					0x0008u
#define PDL_DMAC_STOP						0x0010u

/* Transfer end interrupt flag control */
#define PDL_DMAC_CLEAR_DTIF					0x0020u
#define PDL_DMAC_CLEAR_ESIF					0x0040u

/* Modify registers selection */
#define PDL_DMAC_UPDATE_SOURCE				0x0080u
#define PDL_DMAC_UPDATE_DESTINATION			0x0100u
#define PDL_DMAC_UPDATE_COUNT				0x0200u
#define PDL_DMAC_UPDATE_SIZE				0x0400u
#define PDL_DMAC_UPDATE_OFFSET				0x0800u
#define PDL_DMAC_UPDATE_REPEAT_SOURCE		0x1000u
#define PDL_DMAC_UPDATE_REPEAT_DESTINATION	0x2000u

#endif
/* End of file */
