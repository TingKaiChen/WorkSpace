/*""FILE COMMENT""*******************************************************
* System Name	: MCU API for RX210xx
* File Name		: r_pdl_mcu_RX210xx.h
* Version		: 0.20
* Contents		: MCU API header
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

#ifndef R_PDL_MCU_RX210xx_H
#define R_PDL_MCU_RX210xx_H

/* Library prototypes */
bool R_MCU_ControlAll(
	const uint8_t
);
bool R_MCU_GetStatusAll(
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint32_t * const,
	volatile uint32_t * const
);

/* Macro definitions */
#define R_MCU_Control(a) \
( \
R_MCU_ControlAll( (a) ) \
)

#define R_MCU_GetStatus(a, b, c, d) \
( \
R_MCU_GetStatusAll( (a), (b), (c), (d) ) \
)

#endif
/* End of file */
