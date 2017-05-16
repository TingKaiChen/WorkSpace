/*""FILE COMMENT""*******************************************************
* System Name	: BSC API for RX210xx
* File Name		: r_pdl_bsc.h
* Version		: 0.20
* Contents		: BSC API header
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

#ifndef R_PDL_BSC_H
#define R_PDL_BSC_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_BSC_Set(
	uint16_t
);
bool R_BSC_Create(
	uint16_t,
	uint32_t,
	uint16_t,
	uint8_t,
	void *,
	uint8_t
);
bool R_BSC_CreateArea(
	uint8_t,
	uint16_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t
);
bool R_BSC_Destroy(
	uint8_t
);
bool R_BSC_Control(
	uint8_t
);
bool R_BSC_GetStatus(
	uint8_t *,
	uint16_t *
);

/* Bus priority selection */
#define PDL_BSC_PRIORITY_RAM_MB2	0x0001u
#define PDL_BSC_PRIORITY_RAM_CPU	0x0002u
#define PDL_BSC_PRIORITY_ROM_MB2	0x0004u
#define PDL_BSC_PRIORITY_ROM_CPU	0x0008u
#define PDL_BSC_PRIORITY_PB1_MB2	0x0010u
#define PDL_BSC_PRIORITY_PB1_MB1	0x0020u
#define PDL_BSC_PRIORITY_PB23_MB2	0x0040u
#define PDL_BSC_PRIORITY_PB23_MB1	0x0080u
#define PDL_BSC_PRIORITY_PB6_MB2	0x0100u
#define PDL_BSC_PRIORITY_PB6_MB1	0x0200u
#define PDL_BSC_PRIORITY_EB_MB2		0x0400u
#define PDL_BSC_PRIORITY_EB_MB1		0x0800u

/* Chip select pin selection */
#define PDL_BSC_CS0_P24			0x0001u
#define PDL_BSC_CS0_PC7			0x0002u
#define PDL_BSC_CS1_P25			0x0004u
#define PDL_BSC_CS1_PC6			0x0008u
#define PDL_BSC_CS2_P26			0x0010u
#define PDL_BSC_CS2_PC5			0x0020u
#define PDL_BSC_CS3_P27			0x0040u
#define PDL_BSC_CS3_PC4			0x0080u
#define PDL_BSC_WAIT_P51		0x0100u
#define PDL_BSC_WAIT_P55		0x0200u
#define PDL_BSC_WAIT_PC5		0x0400u
#define PDL_BSC_ALE_ENABLE		0x0800u

/* Address output control */        	
#define PDL_BSC_A7_A0_DISABLE	0x00000001ul
#define PDL_BSC_A8_DISABLE		0x00000002ul
#define PDL_BSC_A9_DISABLE		0x00000004ul
#define PDL_BSC_A10_DISABLE		0x00000008ul
#define PDL_BSC_A11_DISABLE		0x00000010ul
#define PDL_BSC_A12_DISABLE		0x00000020ul
#define PDL_BSC_A13_DISABLE		0x00000040ul
#define PDL_BSC_A14_DISABLE		0x00000080ul
#define PDL_BSC_A15_DISABLE		0x00000100ul
#define PDL_BSC_A16_DISABLE		0x00000200ul
#define PDL_BSC_A17_DISABLE		0x00000400ul
#define PDL_BSC_A18_DISABLE		0x00000800ul
#define PDL_BSC_A19_DISABLE		0x00001000ul
#define PDL_BSC_A20_DISABLE		0x00002000ul
#define PDL_BSC_A21_DISABLE		0x00004000ul
#define PDL_BSC_A22_DISABLE		0x00008000ul
#define PDL_BSC_A23_DISABLE		0x00010000ul

/* Recovery cycle insertion control */        	
#define PDL_BSC_RCV_SRRS_ENABLE		0x0001u
#define PDL_BSC_RCV_SRRD_ENABLE		0x0002u
#define PDL_BSC_RCV_SRWS_ENABLE		0x0004u
#define PDL_BSC_RCV_SRWD_ENABLE		0x0008u
#define PDL_BSC_RCV_SWRS_ENABLE		0x0010u
#define PDL_BSC_RCV_SWRD_ENABLE		0x0020u
#define PDL_BSC_RCV_SWWS_ENABLE		0x0040u
#define PDL_BSC_RCV_SWWD_ENABLE		0x0080u
#define PDL_BSC_RCV_MRRS_ENABLE		0x0100u
#define PDL_BSC_RCV_MRRD_ENABLE		0x0200u
#define PDL_BSC_RCV_MRWS_ENABLE		0x0400u
#define PDL_BSC_RCV_MRWD_ENABLE		0x0800u
#define PDL_BSC_RCV_MWRS_ENABLE		0x1000u
#define PDL_BSC_RCV_MWRD_ENABLE		0x2000u
#define PDL_BSC_RCV_MWWS_ENABLE		0x4000u
#define PDL_BSC_RCV_MWWD_ENABLE		0x8000u

/* Error monitoring */
#define PDL_BSC_ERROR_ILLEGAL_ADDRESS_ENABLE	0x01u
#define PDL_BSC_ERROR_ILLEGAL_ADDRESS_DISABLE	0x02u
#define PDL_BSC_ERROR_TIME_OUT_ENABLE			0x04u
#define PDL_BSC_ERROR_TIME_OUT_DISABLE			0x08u

/* Bus width */
#define PDL_BSC_WIDTH_8					0x0001u
#define PDL_BSC_WIDTH_16				0x0002u

/* Endian mode */
#define PDL_BSC_ENDIAN_SAME				0x0004u
#define PDL_BSC_ENDIAN_OPPOSITE			0x0008u

/* Multiplexed mode */
#define PDL_BSC_SEPARATE				0x0010u
#define PDL_BSC_MULTIPLEXED				0x0020u

/* Write access mode */
#define PDL_BSC_WRITE_BYTE				0x0040u
#define PDL_BSC_WRITE_SINGLE			0x0080u

/* External wait control */
#define PDL_BSC_WAIT_DISABLE			0x0100u
#define PDL_BSC_WAIT_ENABLE				0x0200u

/* Page access control */
#define PDL_BSC_PAGE_READ_DISABLE		0x0400u
#define PDL_BSC_PAGE_READ_NORMAL		0x0800u
#define PDL_BSC_PAGE_READ_CONTINUOUS	0x1000u
#define PDL_BSC_PAGE_WRITE_DISABLE		0x2000u
#define PDL_BSC_PAGE_WRITE_ENABLE		0x4000u

/* R_BSC_Control parameter options */
#define PDL_BSC_ENABLE				0x01u
#define PDL_BSC_DISABLE				0x02u
#define PDL_BSC_ERROR_CLEAR	 		0x04u
#define PDL_BSC_DISABLE_BUSERR_IRQ	0x08u

#endif
/* End of file */
