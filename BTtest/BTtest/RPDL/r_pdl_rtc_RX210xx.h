/*""FILE COMMENT""*******************************************************
* System Name	: Real-time clock API for RX210xx
* File Name		: r_pdl_rtc_RX210xx.h
* Version		: 0.20
* Contents		: RTC header
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

#ifndef R_PDL_RTC_RX210xx_H
#define R_PDL_RTC_RX210xx_H

extern VoidCallBackFunc rpdl_RTC_Periodic_callback_func;
extern VoidCallBackFunc rpdl_RTC_Alarm_callback_func;

/* Library prototypes */
bool R_RTC_CreateAll(
	const uint32_t,
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint16_t,
	const uint32_t,
	const uint32_t,
	VoidCallBackFunc const,
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_RTC_ControlAll(
	const uint32_t,
	const uint16_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint16_t error_adjust,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint16_t
);
bool R_RTC_ReadAll(
	const uint8_t,
	volatile uint8_t * const,
	volatile uint32_t * const,
	volatile uint32_t * const
);
bool R_RTC_DestroyAll(void);

bool ReturnFalse(void);

/* Macro definitions */

#define R_RTC_Create(a, b, c, d, e, f, g, h, i, j, k, l, m , n) \
( \
( ((l) <= IPL_MAX) && ((n) <= IPL_MAX) ) ? \
R_RTC_CreateAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k), (l), (m), (n) ): \
ReturnFalse() \
)

#define R_RTC_Control(a, b, c, d, e, f, g, h, i, j, k) \
( \
R_RTC_ControlAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k) ) \
)

#define R_RTC_Read(a, b, c, d) \
( \
R_RTC_ReadAll( (a), (b), (c), (d) ) \
)

#define R_RTC_Destroy() \
( \
R_RTC_DestroyAll() \
)

#endif
/* End of file */
