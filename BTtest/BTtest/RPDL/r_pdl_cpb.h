/*""FILE COMMENT""*******************************************************
* System Name	: CPB API for RX210xx
* File Name		: r_pdl_cpb.h
* Version		: 0.20
* Contents		: CPB API header
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

#ifndef R_PDL_CPB_H
#define R_PDL_CPB_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_CPB_Create(
	uint8_t,
	uint16_t,
	void *,
	uint8_t
);
bool R_CPB_Destroy(
	uint8_t
); 
bool R_CPB_GetStatus(
	uint8_t *
);

/* Comparator B interrupt/ELC control */
#define PDL_CPB_IRQ_DISABLE					0x0001u
#define PDL_CPB_IRQ_ENABLE					0x0002u
#define PDL_CPB_IRQ_ELC_FALLING_EDGE		0x0004u
#define PDL_CPB_IRQ_ELC_RISING_EDGE			0x0008u
#define PDL_CPB_IRQ_ELC_BOTH_EDGE			0x0010u

/* Comparator B filter control */
#define PDL_CPB_FILTER_DISABLE				0x0020u
#define PDL_CPB_PCLK_DIV_1					0x0040u
#define PDL_CPB_PCLK_DIV_8					0x0080u
#define PDL_CPB_PCLK_DIV_32					0x0100u
#define PDL_CPB_PCLK_DIV_64					0x0200u

/* DMAC / DTC trigger control */
#define PDL_CPB_DMAC_DTC_TRIGGER_DISABLE	0x0400u
#define PDL_CPB_DMAC_TRIGGER_ENABLE			0x0800u
#define PDL_CPB_DTC_TRIGGER_ENABLE			0x1000u

#endif
/* End of file */
