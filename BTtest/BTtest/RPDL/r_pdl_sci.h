/*""FILE COMMENT""*******************************************************
* System Name	: Serial Communication Interface API for RX210xx
* File Name		: r_pdl_sci.h
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

#ifndef R_PDL_SCI_H
#define R_PDL_SCI_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_SCI_Set(
	uint32_t
);
bool R_SCI_Create(
	uint8_t,
	uint32_t,
	uint32_t,
	uint8_t
);
bool R_SCI_Destroy(
	uint8_t
);
bool R_SCI_Send(
	uint8_t,
	uint16_t,
	uint8_t *,
	uint16_t,
	void *
);
bool R_SCI_Receive(
	uint8_t,
	uint16_t,
	uint8_t *,
	uint16_t,
	void *,
	void *
);
bool R_SCI_Control(
	uint8_t,
	uint8_t
);
bool R_SCI_GetStatus(
	uint8_t,
	uint8_t *,
	uint8_t *,
	uint16_t *,
	uint16_t *
);
bool R_SCI_SPI_Transfer(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	volatile const uint8_t*,
	VoidCallBackFunc const,
	volatile uint8_t* const,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_IIC_Write(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	const uint16_t,
	volatile uint8_t * const,
	VoidCallBackFunc const
);
bool R_SCI_IIC_Read(
	const uint8_t,
	const uint16_t,
	const uint16_t,
	const uint16_t,
	volatile const uint8_t * const,
	VoidCallBackFunc const
);
bool R_SCI_IIC_ReadLastByte(
	const uint8_t,
	volatile uint8_t * const);

/* ------------------------ */
/* R_SCI_Set, Configuration */
/* ------------------------ */
/* Pin selection (See HW manual Table 20.1)*/
/*SCI0*/
/*No choices*/

/***SCI1***/
/*RXD1 (SMISO1, SSCL1) */
#define PDL_SCI_PIN_SCI1_RXD1_P15		0x00000001
#define PDL_SCI_PIN_SCI1_RXD1_P30		0x00000002
/*Duplicate pin names*/
/*SMISO1*/
#define PDL_SCI_PIN_SCI1_SMISO1_P15 	PDL_SCI_PIN_SCI1_RXD1_P15
#define PDL_SCI_PIN_SCI1_SMISO1_P30 	PDL_SCI_PIN_SCI1_RXD1_P30
/*SSCL1*/
#define PDL_SCI_PIN_SCI1_SSCL1_P15		PDL_SCI_PIN_SCI1_RXD1_P15
#define PDL_SCI_PIN_SCI1_SSCL1_P30 		PDL_SCI_PIN_SCI1_RXD1_P30

/*TXD1 (SMOSI1, SSDA1)*/
#define PDL_SCI_PIN_SCI1_TXD1_P16		0x00000004
#define PDL_SCI_PIN_SCI1_TXD1_P26		0x00000008
/*Duplicate pin names*/
/*SMOSI1*/
#define PDL_SCI_PIN_SCI1_SMOSI1_P16 	PDL_SCI_PIN_SCI1_TXD1_P16
#define PDL_SCI_PIN_SCI1_SMOSI1_P26 	PDL_SCI_PIN_SCI1_TXD1_P26
/*SSDA1*/
#define PDL_SCI_PIN_SCI1_SSDA1_P16		PDL_SCI_PIN_SCI1_TXD1_P16
#define PDL_SCI_PIN_SCI1_SSDA1_P26 		PDL_SCI_PIN_SCI1_TXD1_P26

/*SCK1*/
#define PDL_SCI_PIN_SCI1_SCK1_P17		0x00000010
#define PDL_SCI_PIN_SCI1_SCK1_P27		0x00000020

/*CTS1 (RTS1,SS1) */
#define PDL_SCI_PIN_SCI1_CTS1_P14		0x00000040
#define PDL_SCI_PIN_SCI1_CTS1_P31		0x00000080
/*Duplicate pin names*/
/*RTS1*/
#define PDL_SCI_PIN_SCI1_RTS1_P14		PDL_SCI_PIN_SCI1_CTS1_P14
#define PDL_SCI_PIN_SCI1_RTS1_P31		PDL_SCI_PIN_SCI1_CTS1_P31
/*SS1*/
#define PDL_SCI_PIN_SCI1_SS1_P14		PDL_SCI_PIN_SCI1_CTS1_P14
#define PDL_SCI_PIN_SCI1_SS1_P31		PDL_SCI_PIN_SCI1_CTS1_P31

/***SCI5***/
/*RXD5 (SMISO5, SSCL5) */
#define PDL_SCI_PIN_SCI5_RXD5_PA2		0x00000100
#define PDL_SCI_PIN_SCI5_RXD5_PA3		0x00000200
#define PDL_SCI_PIN_SCI5_RXD5_PC2		0x00000400
/*Duplicate pin names*/
/*SMISO5*/
#define PDL_SCI_PIN_SCI5_SMISO5_PA2 	PDL_SCI_PIN_SCI5_RXD5_PA2
#define PDL_SCI_PIN_SCI5_SMISO5_PA3 	PDL_SCI_PIN_SCI5_RXD5_PA3
#define PDL_SCI_PIN_SCI5_SMISO5_PC2 	PDL_SCI_PIN_SCI5_RXD5_PC2
/*SSCL5*/
#define PDL_SCI_PIN_SCI5_SSCL5_PA2 		PDL_SCI_PIN_SCI5_RXD5_PA2
#define PDL_SCI_PIN_SCI5_SSCL5_PA3 		PDL_SCI_PIN_SCI5_RXD5_PA3
#define PDL_SCI_PIN_SCI5_SSCL5_PC2 		PDL_SCI_PIN_SCI5_RXD5_PC2

/*TXD5 (SMOSI5, SSDA5)*/
#define PDL_SCI_PIN_SCI5_TXD5_PA4		0x00000800
#define PDL_SCI_PIN_SCI5_TXD5_PC3		0x00001000
/*Duplicate pin names*/
/*SMOSI5*/
#define PDL_SCI_PIN_SCI5_SMOSI5_PA4 	PDL_SCI_PIN_SCI5_TXD5_PA4
#define PDL_SCI_PIN_SCI5_SMOSI5_PC3 	PDL_SCI_PIN_SCI5_TXD5_PC3
/*SSDA5*/
#define PDL_SCI_PIN_SCI5_SSDA5_PA4		PDL_SCI_PIN_SCI5_TXD5_PA4
#define PDL_SCI_PIN_SCI5_SSDA5_PC3 		PDL_SCI_PIN_SCI5_TXD5_PC3

/*SCK5*/
#define PDL_SCI_PIN_SCI5_SCK5_PA1		0x00004000
#define PDL_SCI_PIN_SCI5_SCK5_PC1		0x00008000
#define PDL_SCI_PIN_SCI5_SCK5_PC4		0x00010000

/*CTS5 (RTS5,SS15) */
#define PDL_SCI_PIN_SCI5_CTS5_PA6		0x00020000
#define PDL_SCI_PIN_SCI5_CTS5_PC0		0x00040000
/*Duplicate pin names*/
/*RTS5*/
#define PDL_SCI_PIN_SCI5_RTS5_PA6		PDL_SCI_PIN_SCI5_CTS5_PA6
#define PDL_SCI_PIN_SCI5_RTS5_PC0		PDL_SCI_PIN_SCI5_CTS5_PC0
/*SS5*/
#define PDL_SCI_PIN_SCI5_SS5_PA6		PDL_SCI_PIN_SCI5_CTS5_PA6
#define PDL_SCI_PIN_SCI5_SS5_PC0		PDL_SCI_PIN_SCI5_CTS5_PC0

/***SCI6***/
/*RXD6 (SMISO6, SSCL6) */
#define PDL_SCI_PIN_SCI6_RXD6_P33		0x00080000
#define PDL_SCI_PIN_SCI6_RXD6_PB0		0x00100000
/*Duplicate pin names*/
/*SMISO6*/
#define PDL_SCI_PIN_SCI6_SMISO6_P33 	PDL_SCI_PIN_SCI6_RXD6_P33
#define PDL_SCI_PIN_SCI6_SMISO6_PB0 	PDL_SCI_PIN_SCI6_RXD6_PB0
/*SSCL6*/
#define PDL_SCI_PIN_SCI6_SSCL6_P33 		PDL_SCI_PIN_SCI6_RXD6_P33
#define PDL_SCI_PIN_SCI6_SSCL6_PB0 		PDL_SCI_PIN_SCI6_RXD6_PB0

/*TXD6 (SMOSI6, SSDA6)*/
#define PDL_SCI_PIN_SCI6_TXD6_P32		0x00200000
#define PDL_SCI_PIN_SCI6_TXD6_PB1		0x00400000
/*Duplicate pin names*/
/*SMOSI6*/
#define PDL_SCI_PIN_SCI6_SMOSI6_P32 	PDL_SCI_PIN_SCI6_TXD6_P32
#define PDL_SCI_PIN_SCI6_SMOSI6_PB1 	PDL_SCI_PIN_SCI6_TXD6_PB1
/*SSDA6*/
#define PDL_SCI_PIN_SCI6_SSDA6_P32		PDL_SCI_PIN_SCI6_TXD6_P32
#define PDL_SCI_PIN_SCI6_SSDA6_PB1 		PDL_SCI_PIN_SCI6_TXD6_PB1

/*SCK6*/
#define PDL_SCI_PIN_SCI6_SCK6_P34		0x00800000
#define PDL_SCI_PIN_SCI6_SCK6_PB3		0x01000000

/*CTS6 (RTS6,SS6) */
#define PDL_SCI_PIN_SCI6_CTS6_PB2		0x02000000
#define PDL_SCI_PIN_SCI6_CTS6_PJ3		0x04000000
/*Duplicate pin names*/
/*RTS6*/
#define PDL_SCI_PIN_SCI6_RTS6_PB2		PDL_SCI_PIN_SCI6_CTS6_PB2
#define PDL_SCI_PIN_SCI6_RTS6_PJ3		PDL_SCI_PIN_SCI6_CTS6_PJ3
/*SS6*/
#define PDL_SCI_PIN_SCI6_SS6_PB2		PDL_SCI_PIN_SCI6_CTS6_PB2
#define PDL_SCI_PIN_SCI6_SS6_PJ3		PDL_SCI_PIN_SCI6_CTS6_PJ3

/***SCI8***/
/*No choices*/

/***SCI9***/
/*No choices*/

/***SCI12***/
/*No choices*/

/* ----------------------------------------- */
/* R_SCI_Create, data2 Channel configuration */
/* ----------------------------------------- */
/* Operation mode */
#define PDL_SCI_ASYNC			0x00000001ul
#define PDL_SCI_SYNC			0x00000002ul
#define PDL_SCI_SMART			0x00000004ul
#define PDL_SCI_ASYNC_MP		0x00000008ul

/* Common selections */

/* Transmit / Receive connections */
#define PDL_SCI_TX_CONNECTED	0x00000010ul
#define PDL_SCI_TX_DISCONNECTED	0x00000020ul
#define PDL_SCI_RX_CONNECTED	0x00000040ul
#define PDL_SCI_RX_DISCONNECTED	0x00000080ul

/* Data clock source */
#define PDL_SCI_CLK_INT_OUT		0x00000100ul
#define PDL_SCI_CLK_EXT			0x00000200ul

/* Parity selection */
#define PDL_SCI_PARITY_EVEN		0x00000400ul
#define PDL_SCI_PARITY_ODD		0x00000800ul

/* Asynchronous-only selections */

/* Data clock source */
#define PDL_SCI_CLK_INT_IO		0x00001000ul
#define PDL_SCI_CLK_TMR			0x00002000ul

/* Data length */
#define PDL_SCI_8_BIT_LENGTH	0x00004000ul
#define PDL_SCI_7_BIT_LENGTH	0x00008000ul

/* Parity selection */
#define PDL_SCI_PARITY_NONE		0x00010000ul

/* Stop bit length */
#define PDL_SCI_STOP_1			0x00020000ul
#define PDL_SCI_STOP_2			0x00040000ul

#define PDL_SCI_8N1	(PDL_SCI_8_BIT_LENGTH | PDL_SCI_PARITY_NONE | PDL_SCI_STOP_1)

/*Digital Noise Filter */
#define PDL_SCI_RX_FILTER_DISABLE	0x00080000ul
#define PDL_SCI_RX_FILTER_ENABLE	0x00100000ul

/*NOTE: See "Asynchronous and Synchronous only selections" following
 "Synchronous only section".*/

/* Synchronous only selections */
#define PDL_SCI_SPI_MODE		0x00001000ul
#define PDL_SCI_IIC_MODE		0x00002000ul

/* Synchronous SPI only selections */

/*SS pin Enable/Disable usage*/
#define PDL_SCI_SPI_SS_ENABLE	0x00004000ul
#define PDL_SCI_SPI_SS_DISABLE	0x00008000ul

/*Clock selection*/
#define PDL_SCI_SPI_CLOCK_POLARITY_INVERTED	0x00010000ul
#define PDL_SCI_SPI_CLOCK_PHASE_DELAYED		0x00020000ul

/* Synchronous IIC only selections */
/*Noise Filter: If using select clock.*/
#define PDL_SCI_IIC_FILTER_DISABLED		0x00004000ul
#define PDL_SCI_IIC_FILTER_CLOCK_DIV1	0x00008000ul
#define PDL_SCI_IIC_FILTER_CLOCK_DIV2	0x00010000ul
#define PDL_SCI_IIC_FILTER_CLOCK_DIV4	0x00020000ul
#define PDL_SCI_IIC_FILTER_CLOCK_DIV8	0x00040000ul

/*IIC SDA Delay Output Select*/
/*Note: These are not bit flags, they are values shifted
to next available bit position*/
#define PDL_SCI_IIC_DELAY_SDA_0_1		(1ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_1_2		(2ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_2_3		(3ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_3_4		(4ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_4_5		(5ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_5_6		(6ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_6_7		(7ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_7_8		(8ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_8_9		(9ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_9_10		(10ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_10_11		(11ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_11_12		(12ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_12_13		(13ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_13_14		(14ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_14_15		(15ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_15_16		(16ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_16_17		(17ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_17_18		(18ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_18_19		(19ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_19_20		(20ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_20_21		(21ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_21_22		(22ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_22_23		(23ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_23_24		(24ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_24_25		(25ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_25_26		(26ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_26_27		(27ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_27_28		(28ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_28_29		(29ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_29_30		(30ul << 20u)
#define PDL_SCI_IIC_DELAY_SDA_30_31		(31ul << 20u)

/* Asynchronous and Synchronous only selections*/

/*HW (CTS/RTS) Flow Control (Choose one of the following)*/
#define PDL_SCI_HW_FLOW_NONE	0x20000000ul
#define PDL_SCI_HW_FLOW_CTS		0x40000000ul
#define PDL_SCI_HW_FLOW_RTS		0x80000000ul

/* Smart card-only selections */

/* Data transfer format */
#define PDL_SCI_LSB_FIRST		0x00001000ul
#define PDL_SCI_MSB_FIRST		0x00002000ul
                                            
/* Data inversion */                        
#define PDL_SCI_INVERSION_OFF	0x00004000ul
#define PDL_SCI_INVERSION_ON	0x00008000ul
                                            
/* Base clock pulse cycle count */          
#define PDL_SCI_BCP_32			0x00010000ul
#define PDL_SCI_BCP_64			0x00020000ul
#define PDL_SCI_BCP_93			0x00040000ul
#define PDL_SCI_BCP_128			0x00080000ul
#define PDL_SCI_BCP_186			0x00100000ul
#define PDL_SCI_BCP_256			0x00200000ul
#define PDL_SCI_BCP_372			0x00400000ul
#define PDL_SCI_BCP_512			0x00800000ul
                                            
/* Block transfer mode */                   
#define PDL_SCI_BLOCK_MODE_OFF	0x01000000ul
#define PDL_SCI_BLOCK_MODE_ON	0x02000000ul
                                            
/* GSM mode */                              
#define PDL_SCI_GSM_MODE_OFF	0x04000000ul
#define PDL_SCI_GSM_MODE_ON		0x08000000ul
                                            
/* Clock output control */                  
#define PDL_SCI_SCK_OUTPUT_OFF	0x10000000ul
#define PDL_SCI_SCK_OUTPUT_LOW	0x20000000ul
#define PDL_SCI_SCK_OUTPUT_ON	0x40000000ul
#define PDL_SCI_SCK_OUTPUT_HIGH	0x80000000ul

/* ----------------------------------- */
/* R_SCI_Create, data3 register value  */
/* ----------------------------------- */
/* Transfer clock control */

/* CKS selection (optional) */
/*WARNING: THESE BIT VALUES MUST NOT CHANGE*/
#define PDL_SCI_PCLK_DIV_1		0x01000000ul
#define PDL_SCI_PCLK_DIV_4		0x02000000ul
#define PDL_SCI_PCLK_DIV_16		0x03000000ul
#define PDL_SCI_PCLK_DIV_64		0x04000000ul

/* ABCS selection (optional) */
/*WARNING: THESE BIT VALUES MUST NOT CHANGE*/
#define PDL_SCI_CYCLE_BIT_16	0x10000000ul
#define PDL_SCI_CYCLE_BIT_8		0x20000000ul

/* ----------------------------------------------- */
/* R_SCI_Send/R_SCI_Receive, Channel configuration */
/* ----------------------------------------------- */
/* DMAC / DTC trigger control */
#define PDL_SCI_DMAC_DTC_TRIGGER_DISABLE	0x0001u
#define PDL_SCI_DMAC_TRIGGER_ENABLE			0x0002u
#define PDL_SCI_DTC_TRIGGER_ENABLE			0x0004u
#define PDL_SCI_MP_ID_CYCLE					0x0008u

/* ----------------------------------------------- */
/* R_SCI_SPI_TransferAll */
/* ----------------------------------------------- */
/* DMAC / DTC trigger control */
/*Tx Trigger*/
#define PDL_SCI_SPI_TX_DMAC_DTC_TRIGGER_DISABLE	0x0001u
#define PDL_SCI_SPI_TX_DMAC_TRIGGER_ENABLE		0x0002u
#define PDL_SCI_SPI_TX_DTC_TRIGGER_ENABLE		0x0004u
/*Rx Trigger*/
#define PDL_SCI_SPI_RX_DMAC_DTC_TRIGGER_DISABLE	0x0008u
#define PDL_SCI_SPI_RX_DMAC_TRIGGER_ENABLE		0x0010u
#define PDL_SCI_SPI_RX_DTC_TRIGGER_ENABLE		0x0020u

/* ----------------------------------------------- */
/* R_SCI_IIC_TransferAll						   */
/* ----------------------------------------------- */
#define PDL_SCI_IIC_7_BIT_SLAVE_ADDRESS			0x0001u
#define PDL_SCI_IIC_10_BIT_SLAVE_ADDRESS		0x0002u

#define PDL_SCI_IIC_DMAC_DTC_TRIGGER_DISABLE	0x0004u
#define PDL_SCI_IIC_DMAC_TRIGGER_ENABLE			0x0008u
#define PDL_SCI_IIC_DTC_TRIGGER_ENABLE			0x0010u

#define PDL_SCI_IIC_RESTART						0x0020u
#define PDL_SCI_IIC_NOSTOP						0x0040u

/* ------------------------------ */
/* R_SCI_Control, Channel control */
/* ------------------------------ */
/* Stop control */
#define PDL_SCI_STOP_TX						0x0001u
#define PDL_SCI_STOP_RX						0x0002u
#define PDL_SCI_STOP_TX_AND_RX	(PDL_SCI_STOP_TX | PDL_SCI_STOP_RX)

/* Break output control */
#define PDL_SCI_OUTPUT_MARK					0x0004u
#define PDL_SCI_OUTPUT_SPACE				0x0008u

/* Error flag control */
#define PDL_SCI_CLEAR_RECEIVE_ERROR_FLAGS	0x0010u

/* Manual SCK control */
#define PDL_SCI_GSM_SCK_STOP				0x0020u
#define PDL_SCI_GSM_SCK_START 				0x0040u

/*IIC Specific*/
#define PDL_SCI_IIC_STOP					0x0080u
#define PDL_SCI_IIC_CLOCK_SYNC_ENABLE		0x0100u
#define PDL_SCI_IIC_CLOCK_SYNC_DISABLE		0x0200u

#endif
/* End of file */
