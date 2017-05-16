/*""FILE COMMENT""*******************************************************
* System Name	: Voltage detection circuit API for RX210xx
* File Name		: r_pdl_lvd.h
* Version		: 0.20
* Contents		: LVD API header
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

#ifndef R_PDL_LVD_H
#define R_PDL_LVD_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_LVD_Create(const uint32_t,
					 const uint32_t,
					 const uint32_t,
					 const uint16_t,
					 const uint16_t,
					 VoidCallBackFunc const,
					 const uint8_t,
					 VoidCallBackFunc const,
					 const uint8_t
);
					 
bool R_LVD_Control(
	const uint32_t,
	const uint16_t
);

bool R_LVD_GetStatus(
	volatile uint8_t * const
);

/* Create and Control (Parameter Configuration)*/
/* VDET1 and VDET2 applicable*/
#define PDL_LVD_ENABLE					0x00000001ul
#define PDL_LVD_DISABLE					0x00000002ul

/*Reset or Interrupt.
If reset; what type of reset negation.
If interrupt; what type and what to detect.*/
#define PDL_LVD_RESET_NEGATION_VCC_MORE_THAN_VDET	0x00000004ul
#define PDL_LVD_RESET_NEGATION_AFTER_DELAY			0x00000008ul
#define PDL_LVD_INTERRUPT_NMI_DETECT_RISE			0x00000010ul
#define PDL_LVD_INTERRUPT_NMI_DETECT_FALL			0x00000020ul
#define PDL_LVD_INTERRUPT_NMI_DETECT_RISE_AND_FALL	0x00000040ul
#define PDL_LVD_INTERRUPT_MI_DETECT_RISE			0x00000080ul
#define PDL_LVD_INTERRUPT_MI_DETECT_FALL			0x00000100ul
#define PDL_LVD_INTERRUPT_MI_DETECT_RISE_AND_FALL	0x00000200ul

/* Digital Filter */
#define PDL_LVD_FILTER_DISABLE			0x00000400ul
#define PDL_LVD_FILTER_LOCO_DIV_1		0x00000800ul
#define PDL_LVD_FILTER_LOCO_DIV_2		0x00001000ul
#define PDL_LVD_FILTER_LOCO_DIV_4		0x00002000ul
#define PDL_LVD_FILTER_LOCO_DIV_8		0x00004000ul

/* VDET2 specific */
#define PDL_LVD_VDET2_PIN_VCC			0x00008000ul
#define PDL_LVD_VDET2_PIN_CMPA2			0x00010000ul

/* Control Specific*/
#define PDL_LVD_VDET1					0x00020000ul
#define PDL_LVD_VDET2					0x00040000ul

/* Create and Control (Parameter Voltage)*/
/*Voltage Level (415 represents 4.15V*/
#define PDL_LVD_VOLTAGE_LEVEL_415		0x0001u
#define PDL_LVD_VOLTAGE_LEVEL_400		0x0002u
#define PDL_LVD_VOLTAGE_LEVEL_385		0x0004u
#define PDL_LVD_VOLTAGE_LEVEL_370		0x0008u
#define PDL_LVD_VOLTAGE_LEVEL_355		0x0010u
#define PDL_LVD_VOLTAGE_LEVEL_340		0x0020u
#define PDL_LVD_VOLTAGE_LEVEL_325		0x0040u
#define PDL_LVD_VOLTAGE_LEVEL_310		0x0080u
#define PDL_LVD_VOLTAGE_LEVEL_295		0x0100u
#define PDL_LVD_VOLTAGE_LEVEL_280		0x0200u
#define PDL_LVD_VOLTAGE_LEVEL_265		0x0400u
#define PDL_LVD_VOLTAGE_LEVEL_250		0x0800u
#define PDL_LVD_VOLTAGE_LEVEL_235		0x1000u
#define PDL_LVD_VOLTAGE_LEVEL_220		0x2000u
#define PDL_LVD_VOLTAGE_LEVEL_205		0x4000u
#define PDL_LVD_VOLTAGE_LEVEL_190		0x8000u


#endif
/* End of file */
