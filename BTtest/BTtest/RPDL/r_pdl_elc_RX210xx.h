/*""FILE COMMENT""*******************************************************
* System Name	: ELC API for RX210xx
* File Name		: r_pdl_elc_RX210xx.h
* Version		: 0.20
* Contents		: ELC API header
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

#ifndef R_PDL_ELC_RX210xx_H
#define R_PDL_ELC_RX210xx_H

/* Callback function storage for ELC interrupts.*/
extern VoidCallBackFunc rpdl_ELC_callback_func[2];

bool R_ELC_CreateAll(VoidCallBackFunc const,
					const uint8_t,
					VoidCallBackFunc const,
					const uint8_t);
bool R_ELC_ControlAll(const uint16_t, const uint32_t, const uint32_t);
bool R_ELC_ReadAll(const uint8_t, uint8_t* const);
bool R_ELC_WriteAll(const uint8_t, const uint8_t);
bool R_ELC_DestroyAll(void);

/*Call R_ELC_CreateAll if interrupt priorities are within max limit.*/
#define R_ELC_Create(a, b, c, d) \
( \
( ((b) <= IPL_MAX) &&  ((d) <= IPL_MAX)) ? \
R_ELC_CreateAll((a), (b), (c), (d))  : \
ReturnFalse() \
)

#define R_ELC_Control(a, b, c) \
( \
R_ELC_ControlAll( (a), (b), (c) ) \
)

#define R_ELC_Read(a, b) \
( \
R_ELC_ReadAll( (a), (b) ) \
)

#define R_ELC_Write(a, b) \
( \
R_ELC_WriteAll( (a), (b) ) \
)

#define R_ELC_Destroy() \
( \
R_ELC_DestroyAll() \
)

#endif
/* End of file */
