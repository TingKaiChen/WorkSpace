/*""FILE COMMENT""*******************************************************
* System Name	: DOC API for RX210xx
* File Name		: r_pdl_DOC_RX210xx.h
* Version		: 0.20
* Contents		: DOC API header
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

#ifndef R_PDL_DOC_RX210xx_H
#define R_PDL_DOC_RX210xx_H

/* Callback function storage for DOC interrupt.*/
extern VoidCallBackFunc rpdl_DOC_callback_func;

bool R_DOC_CreateAll(const uint8_t,
					 uint16_t,
					 VoidCallBackFunc const,
					 const uint8_t);
					 
bool R_DOC_ControlAll(const uint8_t, const uint16_t);
bool R_DOC_ReadAll(uint8_t *pStatus, uint16_t* const pValue);
bool R_DOC_WriteAll(const uint16_t*, uint16_t);
bool R_DOC_DestroyAll(void);

#define R_DOC_Create(a, b, c, d) \
( \
( ((d) <= IPL_MAX)) ? \
R_DOC_CreateAll((a), (b), (c), (d)) : \
ReturnFalse() \
)

#define R_DOC_Control(a, b) \
( \
R_DOC_ControlAll( (a), (b) ) \
)

#define R_DOC_Read(a, b) \
( \
R_DOC_ReadAll( (a), (b) ) \
)

#define R_DOC_Write(a, b) \
( \
R_DOC_WriteAll( (a), (b) ) \
)

#define R_DOC_Destroy() \
( \
R_DOC_DestroyAll() \
)

#endif
/* End of file */
