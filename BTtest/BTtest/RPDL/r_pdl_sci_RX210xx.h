/*""FILE COMMENT""*******************************************************
* System Name	: Serial Communication Interface API for RX210xx
* File Name		: r_pdl_sci_RX210xx.h
* Version		: 0.20
* Contents		: Serial Interface API header
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

#ifndef R_PDL_SCI_RX210xx_H
#define R_PDL_SCI_RX210xx_H

/*NOTE: This is the number of channels but the channel numbers are 0,1,5,6,8,9,12*/
#define SCI_NUM_CHANNELS 7

typedef enum _RPDL_MP_MODE
{
	RPDL_MP_MODE_DISABLED,
	RPDL_MP_MODE_ENABLED,
	RPDL_MP_MODE_EXPECTING_ID
}RPDL_MP_MODE;

typedef struct _RPDL_SCI_MP_SPECIFIC
{
	volatile RPDL_MP_MODE MP_mode;
	volatile uint8_t MP_rx_stationID;
}RPDL_SCI_MP_SPECIFIC;

typedef struct _RPDL_SCI_IIC_SPECIFIC
{
	volatile bool bReStart;
	volatile bool bStop;
}RPDL_SCI_IIC_SPECIFIC;

typedef struct _RPDL_SCI_DATA_GLOBAL
{
	volatile const uint8_t * tx_string_pointer;
	volatile uint8_t * rx_string_pointer;
	volatile uint8_t * rx_string_start;
	volatile uint16_t rx_counter;
	volatile uint16_t tx_counter;
	volatile uint16_t rx_threshold;
	volatile uint16_t tx_threshold;
	volatile uint8_t tx_using_irq;
	volatile uint8_t rx_using_irq;
	volatile uint8_t sync_simultaneous;
	/*union used  as can never be in MP and IIC mode.*/
	union
	{
		RPDL_SCI_MP_SPECIFIC MP;
		RPDL_SCI_IIC_SPECIFIC IIC;		
	};

	/* Callback functions pointer storage*/
	VoidCallBackFunc TX_End_callback_func;
	VoidCallBackFunc RX_End_callback_func;
	VoidCallBackFunc RX_Error_callback_func;
}RPDL_SCI_DATA_GLOBAL;

/*Global data access*/
RPDL_SCI_DATA_GLOBAL* rpdl_SCI_GlobalData(uint8_t channel);

/* Library prototypes */
bool R_SCI_SetAll(
	const uint32_t
);
bool R_SCI_CreateAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateAsyncAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateSyncAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateSmartAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_DestroyAll(
	const uint8_t
);
bool R_SCI_SendAll(
	const uint8_t,
	const uint16_t,
	volatile const uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const
);
bool R_SCI_SendStationID(
	const uint8_t,
	const uint16_t 
);
bool R_SCI_SendData(
	const uint8_t,
	const uint16_t,
	volatile const uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveAll(
	const uint8_t,
	const uint16_t,
	volatile uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveStationID(
	const uint8_t,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveData(
	const uint8_t,
	const uint16_t,
	volatile uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ControlAll(
	const uint8_t,
	const uint16_t
);
bool R_SCI_GetStatusAll(
	const uint8_t,
	volatile uint8_t * const,
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);
bool ReturnFalse(void);

/*SPI uses this rather than Recieve/Send*/
bool R_SCI_SPI_TransferAll(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	volatile const uint8_t * const,
	VoidCallBackFunc const,
	volatile uint8_t * const,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
/*IIC uses these rather than Recieve/Send*/
bool R_SCI_IIC_WriteAll(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	const uint16_t,
	volatile const uint8_t *,
	VoidCallBackFunc const
);
bool R_SCI_IIC_ReadAll(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	const uint16_t,
	volatile uint8_t * const,
	VoidCallBackFunc const
);
	
bool R_SCI_IIC_ReadLastByteAll(const uint8_t,
							volatile uint8_t * const);

/* Macro definitions */
#define R_SCI_Set(a) \
( R_SCI_SetAll( (a) ) )

#define R_SCI_Create(a, b, c, d) \
( \
((!( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ||\
((c) == 0) || ((d) > IPL_MAX) )? \
ReturnFalse(): \
R_SCI_CreateAll( (a), (b), (c), (d) )\
)

#define R_SCI_Destroy(a) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_DestroyAll( (a) ) \
)

#define R_SCI_Send(a, b, c, d, e) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_SendAll( (a), (b), (c), (d), (e) ) \
)

#define R_SCI_Receive(a, b, c, d, e, f) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_ReceiveAll( (a), (b), (c), (d), (e), (f) ) \
)

/*SPI uses this rather than R_SCI_Receive / R_SCI_Send*/
/*If a valid channel is supplied R_SCI_SPI_TransferAll will be called.*/
#define R_SCI_SPI_Transfer(a, b, c, d, e, f, g, h) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_SPI_TransferAll( (a), (b), (c), (d), (e), (f), (g), (h) ) \
)

/*IIC uses these rather than R_SCI_Receive / R_SCI_Send*/
/*If a valid channel is supplied R_SCI_IIC_WriteAll will be called.*/
#define R_SCI_IIC_Write(a, b, c, d, e, f) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_IIC_WriteAll( (a), (b), (c), (d), (e), (f) ) \
)

/*If a valid channel is supplied R_SCI_IIC_ReadAll will be called.*/
#define R_SCI_IIC_Read(a, b, c, d, e, f) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_IIC_ReadAll( (a), (b), (c), (d), (e), (f) ) \
)

/*If a valid channel is supplied R_SCI_IIC_ReadLastByteAll will be called.*/
#define R_SCI_IIC_ReadLastByte(a, b) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_IIC_ReadLastByteAll( (a), (b) ) \
)

#define R_SCI_Control(a, b) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_ControlAll( (a), (b) ) \
)

#define R_SCI_GetStatus(a, b, c, d, e) \
( \
( !( ((a) == 0) || ((a) == 1) || ((a) == 5) || ((a) == 6) ||\
((a) == 8) || ((a) == 9) || ((a) == 12) )) ? \
ReturnFalse(): \
R_SCI_GetStatusAll( (a), (b), (c), (d), (e) ) \
)

#endif
/* End of file */
