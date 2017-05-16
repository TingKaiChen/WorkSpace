/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*******************************************************************************/
/* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.   */
/*******************************************************************************
* File Name		: async.c
* Version 		: 1.00
* Device 		: R5F52108DFP
* Tool Chain 	: RX Family C Compiler, v1.01
* H/W Platform	: RSKRX210
* Description   : Defines SCI functions used in this sample.
*******************************************************************************/
/*******************************************************************************
* History 		: 05.08.2011  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* IO Port RPDL function definitions */
#include "r_pdl_io_port.h"
/* SCI RPDL function definitions */
#include "r_pdl_sci.h"
/* CMT RPDL function definitions */
#include "r_pdl_cmt.h"
/* General RPDL function definitions */
#include "r_pdl_definitions.h"
/* Declares functions defined in this file */
#include "async.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/
/* Declaration of the SCI status flag global variable */
bool gSCI_Flag = true;
/* Declare transmit and receive buffer variables used in this file */
uint8_t gSCI_TXBuffer[2]={0x2F, 0x0};
/* Declare a receive buffer variable */
volatile uint8_t gSCI_RXBuffer;
/* Declaration of the command string to clear the terminal screen */
const uint8_t cmd_clr_scr[] = {27, 91, 50, 74, 0, 27, 91, 72, 0};

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
/* Text write function prototype */
static void Transmit_Async(void);
/* Declaration of timer callback function */
void CB_Timer_Async(void);
/* Declaration of SCI receive callback function */
void CB_SCIReceive_Async(void);

/*******************************************************************************
* Outline 	   : Init_Async
* Description  : This function initialises the SCI channel connected to the 
*				 RS232 connector on the RSK. The channel is configured for 
*				 transmission and reception, and instructions are sent to the
*				 terminal.
* Argument     : none
* Return value : none
*******************************************************************************/
void Init_Async(void)
{
	/* Declare an error flag */
	bool err = true;

	/* Configure SCI channel 0 in UART mode */
	err &=	R_SCI_Create
			(
				0, 
				PDL_SCI_ASYNC | PDL_SCI_8N1, 
				19200, 
				6
			);
	
	/* Initialise UART receive interrupt */
	err &=	R_SCI_Receive
			(
				0, 
				PDL_NO_DATA, 
				&gSCI_RXBuffer, 
				1, 
				CB_SCIReceive_Async, 
				PDL_NO_FUNC
			);

	/* Clear the terminal screen */
	err &=	R_SCI_Send
			(
				0, 
				0, 
				cmd_clr_scr, 
				0, 
				PDL_NO_FUNC
			);

	/* Display splash screen on terminal window */
	err &=	R_SCI_Send
			(
				0, 
				0, 
				"Renesas RX210 UART Test \n\r", 
				0, 
				PDL_NO_FUNC
			);
				
	/* Inform user on how to stop transmission */						
	err &=	R_SCI_Send
			(
				0, 
				0, 
				"Press 'z' to stop and any key to resume\r\n\n", 
				0,
				PDL_NO_FUNC
			);

	/* Initialise the transmit buffer array to end in a NULL character */
	gSCI_TXBuffer[1] = 0x00;
	
	/* Configure CMT timer for SCI transmission intervals */
	err &=	R_CMT_Create
			(
				0,
				PDL_CMT_PERIOD,
				100E-3,
				CB_Timer_Async,
				3
			);

	/* Halt in while loop when RPDL errors detected */
	while(!err);
}
/*******************************************************************************
* End of function Init_Async
*******************************************************************************/

/*******************************************************************************
* Outline 		: Transmit_Async 
* Description 	: Sends incrementing numbers across the UART link to the 
*				  terminal window.
* Argument  	: none
* Return value  : none
*******************************************************************************/
static void Transmit_Async(void)
{	
	/* Declare error flag */
	bool err = true;

	/* Check SCI status flag */
	if(gSCI_Flag)
	{
		/* Increment number in transmit buffer */
		gSCI_TXBuffer[0]++;
		
		/* Check if hex value of transmit buffer is greater than 0x39 (9) */
		if(gSCI_TXBuffer[0] > 0x39)
		{
			/* Insert a new line and return the cursor left */
			err &=	R_SCI_Send
					(
						0,
						PDL_NO_DATA,
						"\r\n",
						0,
						PDL_NO_FUNC
					);
					
			/* Reset the ASCII character in the transmit buffer back to 0 */
			gSCI_TXBuffer[0] = 0x30;
		}
		
		/* Send the transmit buffer to the terminal */
		err &=	R_SCI_Send
				(
					0,
					PDL_NO_DATA,
					gSCI_TXBuffer,
					0,
					PDL_NO_FUNC
				);
				
		/* Turn on LED0 */
		err &= 	R_IO_PORT_Write
				(
					PDL_IO_PORT_1_4,
					0
				);	
	
		/* Turn off LED1 */
		err &= 	R_IO_PORT_Write
				(
					PDL_IO_PORT_1_5,
					1
				);		
	}
		
	/* Halt in while loop when RPDL errors detected */
	while(!err);
}
/*******************************************************************************
* End of function Transmit_Async
*******************************************************************************/

/*******************************************************************************
* Outline      : CB_Timer_Async
* Description  : This callback function is executed when a compare match occurs
*				 in the CMT timer (every 100ms). The function checks if a SCI
*				 transmission is in progress before executing the Transmit_Async
*				 function. If the SCI channel is busy, it postpones the trans-
*				 mission until the next CMT period.
* Argument     : none
* Return value : none
*******************************************************************************/
void CB_Timer_Async(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Declare SCI status container variable */
	uint8_t sci_status = 0x00;
	
	/* Check the status of SCI channel 0, and insert results into sci_status */
	err &=	R_SCI_GetStatus
			(
				0,
				&sci_status,
				PDL_NO_PTR,
				PDL_NO_PTR,
				PDL_NO_PTR
			);
	
	/* Check if SCI transmission is in progress */
	if(sci_status & 0x04)
	{
		/* SCI transmit not in progress, execute transmit function */
		Transmit_Async();
	}
	
	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/*******************************************************************************
* End of function CB_Timer_Async
*******************************************************************************/

/*******************************************************************************
* Outline 		: CB_SCIReceive_Async
* Description 	: Callback function, called when a character is received from
*				  the terminal program. Sets rx_flag if character is 'z'
* Argument  	: none
* Return value  : none
*******************************************************************************/
void CB_SCIReceive_Async(void)
{	
	/* Declare error flag */
	bool err = true;
	
	/* Check if last received character was 'z' */
	if(gSCI_RXBuffer == 'z')
	{
		/* Set SCI status flag to 0 */
		gSCI_Flag = false;
		
		/* Turn off LED0 */
		err &=  R_IO_PORT_Write
				(
					PDL_IO_PORT_1_4,
					1
				);
			
		/* Turn on LED1 */
		err &=  R_IO_PORT_Write
				(
					PDL_IO_PORT_1_5,
					0
				);
	}
	
	/* Check if the SCI status flag is 0, and the last received character
	   was not 'z' */
	else if(!gSCI_Flag)
	{
		/* Set SCI status flag to 1 */
		gSCI_Flag = true;
	}
	
	/* Re-configure the SCI receive interrupt */
	err &=	R_SCI_Receive
			(
				0,
				PDL_NO_DATA,
				&gSCI_RXBuffer,
				1,
				CB_SCIReceive_Async,
				PDL_NO_DATA
			);
	
	/* Halt in while loop when RPDL errors detected */
	while(!err);
}
/*******************************************************************************
* End of function CB_SCIReceive_Async
*******************************************************************************/
