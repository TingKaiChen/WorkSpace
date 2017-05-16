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
* File Name		: main_uart.c
* Version 		: 1.00
* Device 		: R5F52108DFP
* Tool Chain 	: RX Family C Compiler, v1.01
* H/W Platform	: RSKRX210
* Description   : Demonstration of SCI in asynchronous mode. The program 
*			  	  communicates from the RX210 to a terminal program via SCI and
*			  	  RS-232.	  
* Instructions  : 1. Connect the RSK to a PC via a 9-way, straight through
*					 serial cable. Open a terminal program (e.g Hyper Terminal).
*					 
*				  2. Ensure the terminal program connection settings are as
*				  	 follows:
*					 
*					 Baud Rate.............19200
*					 Data Bits.................8
*					 Parity.................None
*					 Stop Bits.................1
*					 Flow Control...........None
*
*				  3. Compile and download the sample code to the target. click  
*					 'Reset Go' icon on the 'Debug Run' toolbar to start the 
*					  software.
*					 
*				  4. Observe the output on the terminal window. The numbers 0
*					 to 9 will appear repeatedly. Type 'z' (lowercase) into the
*					 terminal to pause the UART writes, and any other key to
*					 resume.	
*
*				  5. While data is being transmitted, LED0 will be on and LED1
*				  	 will be off. When transmission is inactive, LED1 will be
*					 on and LED0 will be off. 
*******************************************************************************/
/*******************************************************************************
* History 		: 05.08.2011  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* LCD controlling function prototypes & macro defines */
#include "lcd.h"
/* Async UART function definitions */
#include "async.h"

/*******************************************************************************
* Outline 		: main
* Description 	: The main program function. This function calls the UART 
*				  initialisation routine, displays instructions on the LCD, then 
*				  initializes the timer to generate an interrupt every 100 ms.
*				  The callback function for timer calls the function
*				  'Transmit_Async'. 
*				  If the 'gSCI_Flag' is 1, the 'Transmit_Async' function 
*				  transmits the characters '0' to '9' & also turns ON the LED0. 
*				  If the 'gSCI_Flag' is 0 (from a 'z' press on
*				  terminal) the function turns on LED1 and waits for another 
*				  key press.
* Argument  	: none
* Return value  : none
*******************************************************************************/
void main(void)
{
	/* Initialise the LCD Display */
	Init_LCD();
	
	/* Displays the application name on the debug LCD */
	Display_LCD(LCD_LINE1, " Async  ");
	Display_LCD(LCD_LINE2, " Serial ");
	
	/* Initialises the UART interface */
	Init_Async();

	/* Infinite while loop */
	while(1);
}
/*******************************************************************************
End of main
*******************************************************************************/
