/*""FILE COMMENT""*******************************************************
* System Name	: OFS API for RX210xx
* File Name		: r_pdl_mcu_ofs.h
* Version		: 0.20
* Contents		: OFS API header
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

#ifndef R_PDL_MCU_OFS_H
#define R_PDL_MCU_OFS_H

#include "r_pdl_common_defs_RX210xx.h"

/* Set the register locations */
#pragma address OFS0_location = 0xFFFFFF8Cul
#pragma address OFS1_location = 0xFFFFFF88ul

/* Store the OFS values */
#define R_MCU_OFS(iwdt, wdt, lvd, cgc) \
 const uint32_t OFS0_location = iwdt | wdt; \
 const uint32_t OFS1_location = 0xFFFF0000ul | lvd | cgc

/* IWDT auto-start control */
#define PDL_MCU_OFS_IWDT_HALTED 		0x0000FFFFul
#define PDL_MCU_OFS_IWDT_AUTOSTART		(BIT_15 | BIT_13 | BIT_0)

/* IWDT timeout */
#define PDL_MCU_OFS_IWDT_TIMEOUT_1024	0
#define PDL_MCU_OFS_IWDT_TIMEOUT_4096	BIT_2
#define PDL_MCU_OFS_IWDT_TIMEOUT_8192	BIT_3
#define PDL_MCU_OFS_IWDT_TIMEOUT_16384	(BIT_3 | BIT_2)

/* IWDT clock division */
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_1	0
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_16	BIT_5
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_32	(BIT_5 | BIT_4)
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_64	BIT_6
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_128	(BIT_7 | BIT_6 | BIT_5 | BIT_4)
#define PDL_MCU_OFS_IWDT_CLOCK_LOCO_256	(BIT_6 | BIT_4)

/* IWDT window end position */
#define PDL_MCU_OFS_IWDT_WIN_END_75		0
#define PDL_MCU_OFS_IWDT_WIN_END_50		BIT_8
#define PDL_MCU_OFS_IWDT_WIN_END_25		BIT_9
#define PDL_MCU_OFS_IWDT_WIN_END_0		(BIT_9 | BIT_8)

/* IWDT window start position */
#define PDL_MCU_OFS_IWDT_WIN_START_25	0
#define PDL_MCU_OFS_IWDT_WIN_START_50	BIT_10
#define PDL_MCU_OFS_IWDT_WIN_START_75	BIT_11
#define PDL_MCU_OFS_IWDT_WIN_START_100	(BIT_11 | BIT_10)

/* IWDT reset type */
#define PDL_MCU_OFS_IWDT_NMI			0
#define PDL_MCU_OFS_IWDT_RESET			BIT_12

/* IWDT count control */
#define PDL_MCU_OFS_IWDT_STOP_DISABLE	0
#define PDL_MCU_OFS_IWDT_STOP_ENABLE	BIT_14

/* WDT auto-start control */
#define PDL_MCU_OFS_WDT_HALTED 			0xFFFF0000ul
#define PDL_MCU_OFS_WDT_AUTOSTART		(BIT_31 | BIT_30 | BIT_29 | BIT_16)

/* WDT timeout */
#define PDL_MCU_OFS_WDT_TIMEOUT_1024	0
#define PDL_MCU_OFS_WDT_TIMEOUT_4096	BIT_18
#define PDL_MCU_OFS_WDT_TIMEOUT_8192	BIT_19
#define PDL_MCU_OFS_WDT_TIMEOUT_16384	(BIT_19 | BIT_18)

/* WDT clock division */
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_4	BIT_20
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_64	BIT_22
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_128	(BIT_23 | BIT_22 | BIT_21 | BIT_20)
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_512	(BIT_22 | BIT_21)
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_2048	(BIT_22 | BIT_21 | BIT_20)
#define PDL_MCU_OFS_WDT_CLOCK_PCLK_8192	BIT_23

/* WDT window end position */
#define PDL_MCU_OFS_WDT_WIN_END_75		0
#define PDL_MCU_OFS_WDT_WIN_END_50		BIT_24
#define PDL_MCU_OFS_WDT_WIN_END_25		BIT_25
#define PDL_MCU_OFS_WDT_WIN_END_0		(BIT_25 | BIT_24)

/* WDT window start position */
#define PDL_MCU_OFS_WDT_WIN_START_25	0
#define PDL_MCU_OFS_WDT_WIN_START_50	BIT_26
#define PDL_MCU_OFS_WDT_WIN_START_75	BIT_27
#define PDL_MCU_OFS_WDT_WIN_START_100	(BIT_27 | BIT_26)

/* WDT reset type */
#define PDL_MCU_OFS_WDT_NMI				0
#define PDL_MCU_OFS_WDT_RESET			BIT_28

/* LVD monitor 0 control */
#define PDL_MCU_OFS_LVD_0_DISABLE	0x000000FFul
#define PDL_MCU_OFS_LVD_0_ENABLE	0x000000F8ul

/* LVD monitor 0 voltage levels */
#define PDL_MCU_OFS_LVD_0_380		0
#define PDL_MCU_OFS_LVD_0_285		BIT_0
#define PDL_MCU_OFS_LVD_0_190		BIT_1
#define PDL_MCU_OFS_LVD_0_172		(BIT_1 | BIT_0)

/* CGC HOCO control */
#define PDL_MCU_OFS_CGC_HOCO_ENABLE		0x0000FE00ul
#define PDL_MCU_OFS_CGC_HOCO_DISABLE	0x0000FF00ul

#endif
/* End of file */
