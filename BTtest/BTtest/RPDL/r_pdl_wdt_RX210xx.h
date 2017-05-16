/*""FILE COMMENT""*******************************************************
* System Name	: WDT API for RX210xx
* File Name		: r_pdl_wdt_RX210xx.h
* Version		: 0.20
* Contents		: WDT API header
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

#ifndef R_PDL_WDT_RX210xx_H
#define R_PDL_WDT_RX210xx_H

/* Callback function storage */
extern VoidCallBackFunc rpdl_WDT_callback_func;

/* Library prototypes */
bool R_WDT_SetAll(
	const uint32_t
);
bool R_WDT_ControlAll(
	const uint8_t
);
bool R_WDT_ReadAll(
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_WDT_Set(a) \
( \
R_WDT_SetAll( (a) ) \
)

#define R_WDT_Control(a) \
( \
R_WDT_ControlAll( (a) ) \
)

#define R_WDT_Read(a) \
( \
R_WDT_ReadAll( (a) ) \
)

#endif
/* End of file */
