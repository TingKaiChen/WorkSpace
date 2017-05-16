/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_INTC.c
* Version		: 0.20
* Contents		: Interrupt handlers for the external interrupts
* Customer		: 
* Model			:
* Order		 	:
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

#include "r_pdl_intc.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/* External functions */
extern void PowerON_Reset_PC(void);

/* CMT control register definition */
#define CMSTR_ADDRESS(a) ( (volatile uint16_t __evenaccess *)&CMT.CMSTR0 + ( (0x10u * (a >> 1)) / sizeof(uint16_t)) )

/*""FUNC COMMENT""***************************************************
* Module outline: External interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_XXXX(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for External interrupts
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_INTC_callback_func[n]()
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_ICU_IRQ0
#pragma interrupt Interrupt_IRQ0(vect=VECT_ICU_IRQ0, fint)
#else
#pragma interrupt Interrupt_IRQ0(vect=VECT_ICU_IRQ0)
#endif
void Interrupt_IRQ0(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ0] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ0]();
	}
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ1
#pragma interrupt Interrupt_IRQ1(vect=VECT_ICU_IRQ1, fint)
#else
#pragma interrupt Interrupt_IRQ1(vect=VECT_ICU_IRQ1)
#endif
void Interrupt_IRQ1(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ1] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ1]();
	}
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ2
#pragma interrupt Interrupt_IRQ2(vect=VECT_ICU_IRQ2, fint)
#else
#pragma interrupt Interrupt_IRQ2(vect=VECT_ICU_IRQ2)
#endif
void Interrupt_IRQ2(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ2] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ2]();
	}
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ3
#pragma interrupt Interrupt_IRQ3(vect=VECT_ICU_IRQ3, fint)
#else
#pragma interrupt Interrupt_IRQ3(vect=VECT_ICU_IRQ3)
#endif
void Interrupt_IRQ3(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ3] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ3]();
	}
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ4
#pragma interrupt Interrupt_IRQ4(vect=VECT_ICU_IRQ4, fint)
#else
#pragma interrupt Interrupt_IRQ4(vect=VECT_ICU_IRQ4)
#endif
void Interrupt_IRQ4(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ4] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ4]();
	}
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ5
#pragma interrupt Interrupt_IRQ5(vect=VECT_ICU_IRQ5, fint)
#else
#pragma interrupt Interrupt_IRQ5(vect=VECT_ICU_IRQ5)
#endif
void Interrupt_IRQ5(void)
{
#ifdef DEVICE_PACKAGE_TFLGA_85
	/* This pin is not available on the 85-pin package */
	nop();
#else
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ5] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ5]();
	}
#endif
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ6
#pragma interrupt Interrupt_IRQ6(vect=VECT_ICU_IRQ6, fint)
#else
#pragma interrupt Interrupt_IRQ6(vect=VECT_ICU_IRQ6)
#endif
void Interrupt_IRQ6(void)
{
#ifdef DEVICE_PACKAGE_TFLGA_85
	/* This pin is not available on the 85-pin package */
	nop();
#else
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ6] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ6]();
	}
#endif
}

#if FAST_INTC_VECTOR == VECT_ICU_IRQ7
#pragma interrupt Interrupt_IRQ7(vect=VECT_ICU_IRQ7, fint)
#else
#pragma interrupt Interrupt_IRQ7(vect=VECT_ICU_IRQ7)
#endif
void Interrupt_IRQ7(void)
{
#ifdef DEVICE_PACKAGE_TFLGA_85
	/* This pin is not available on the 85-pin package */
	nop();
#else
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_IRQ7] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_IRQ7]();
	}
#endif
}

/*""FUNC COMMENT""***************************************************
* Module outline: Software interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SWINT(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for the software interrupt
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_INTC_callback_func[PDL_INTC_SWINT]()
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/
#if FAST_INTC_VECTOR == VECT_ICU_SWINT
#pragma interrupt Interrupt_SWINT(vect=VECT_ICU_SWINT, fint)
#else
#pragma interrupt Interrupt_SWINT(vect=VECT_ICU_SWINT)
#endif
void Interrupt_SWINT(void)
{
	/* Call the user function */
	if (rpdl_INTC_callback_func[PDL_INTC_SWINT] != PDL_NO_FUNC)
	{
		rpdl_INTC_callback_func[PDL_INTC_SWINT]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Break interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_BRK(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for the break interrupt
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: 
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#pragma interrupt Interrupt_BRK(vect=0)
void Interrupt_BRK(void)
{
	uint32_t * vector_location;
	volatile uint32_t * stacked_psw_ptr;
	uint32_t psw_copy;

	/* Enable writing to the registers */
	rpdl_register_protection(REG_ENABLE_MODE_RESET_WRITE);
	
	switch (rpdl_INTC_brk_command)
	{
		case BRK_SLEEP:
			/* Prevent all-module clock stop */
			SYSTEM.MSTPCRA.BIT.ACSE = 0;
			/* Select sleep or all-module clock stop */
			SYSTEM.SBYCR.BIT.SSBY = 0;
			/* Prevent out-of-order execution */
			while (SYSTEM.SBYCR.BIT.SSBY != 0);
			wait();
			break;
		case BRK_ALL_MODULE_CLOCK_STOP:
			/* Select sleep or all-module clock stop */
			SYSTEM.SBYCR.BIT.SSBY = 0;
			/* Prevent out-of-order execution */
			while (SYSTEM.SBYCR.BIT.SSBY != 0);
			wait();
			break;
		case BRK_STANDBY:
			/* Prevent deep standby mode */
			SYSTEM.DPSBYCR.BIT.DPSBY = 0;
			/* Select standby mode */
			SYSTEM.SBYCR.BIT.SSBY = 1;
			/* Prevent out-of-order execution */
			while (SYSTEM.SBYCR.BIT.SSBY != 1);
			wait();
			break;
		case BRK_DEEP_STANDBY:
			/* Stop the RAM clock */
			SYSTEM.MSTPCRC.BIT.MSTPC0 = 1;
			/* Select deep standby mode */
			SYSTEM.DPSBYCR.BIT.DPSBY = 1;
			/* Select standby mode */
			SYSTEM.SBYCR.BIT.SSBY = 1;
			/* Prevent out-of-order execution */
			while (SYSTEM.SBYCR.BIT.SSBY != 1);
			wait();
			break;
		case BRK_LOAD_FINTV_REGISTER:
			/* Find the start of the maskable interrupt vector table */
			vector_location = (uint32_t *)get_intb();
			/* Move to the location of the address of the selected interrupt */
			vector_location += ICU.FIR.BIT.FVCT;
			/* Store the address of this vector in the FINTV register */
			set_fintv((void *)vector_location);
			break;
		case BRK_WRITE_IPL:
			/* Find the stacked PSW */
			stacked_psw_ptr = (uint32_t *)(rpdl_INTC_saved_isp) - 1;
			/* Read the stacked PSW */
			psw_copy = *stacked_psw_ptr;
			/* Clear the IPL bits */
			psw_copy &= (uint32_t)(INV_BIT_27 & INV_BIT_26 & INV_BIT_25 & INV_BIT_24);
			/* Modify the IPL bits */
			psw_copy |= (uint32_t)(rpdl_INTC_brk_data8 << 24);
			/* Modify the saved IPL */
			*stacked_psw_ptr = psw_copy;
			break;
		case BRK_CMT_START:
			/* Set STRn to 1 */
			*(CMSTR_ADDRESS(rpdl_INTC_brk_data8)) |= (uint16_t)((rpdl_INTC_brk_data8 & 0x01u) + 1);
			break;
		case BRK_CMT_STOP:
			/* Set STRn to 0 */
			*(CMSTR_ADDRESS(rpdl_INTC_brk_data8)) &= (uint16_t)(0x2u >> (rpdl_INTC_brk_data8 & 0x01u));
			break;
		case BRK_MODIFY_PROTECTION:
			/* Call the modification function */
			rpdl_modify_protection(rpdl_INTC_brk_data8);
			break;
		default:
			/* This must never occur */
			break;
	}
	
	/* Disable writing to the registers */
	rpdl_register_protection(REG_DISABLE_MODE_RESET_WRITE);
	
	rpdl_INTC_brk_command = BRK_NO_COMMAND;
}

/* Exception (Privileged Instruction) */
#pragma interrupt Excep_PrivilegedInst
void Excep_PrivilegedInst(void)
{
	if (rpdl_INTC_callback_func[PDL_INTC_PRIVILEGED] != PDL_NO_FUNC)
	{
		/* Call the user function */
		rpdl_INTC_callback_func[PDL_INTC_PRIVILEGED]();
	}
}

/* Exception (Undefined Instruction) */
#pragma interrupt Excep_UndefinedInst
void Excep_UndefinedInst(void)
{
	if (rpdl_INTC_callback_func[PDL_INTC_UNDEFINED] != PDL_NO_FUNC)
	{
		/* Call the user function */
		rpdl_INTC_callback_func[PDL_INTC_UNDEFINED]();
	}
}

#pragma interrupt Interrupt_NMI
void Interrupt_NMI(void)
{
	if (rpdl_INTC_callback_func[PDL_INTC_NMI] != PDL_NO_FUNC)
	{
		/* Call the user function */
		rpdl_INTC_callback_func[PDL_INTC_NMI]();
	}
}

/* Padding function for the fixed-vector table */
void Dummy(void){}

#pragma section C FIXEDVECT

void (* const Fixed_Vectors[12])(void) = {
/* 0xFFFFFFD0	Privileged Instruction */
	Excep_PrivilegedInst,
/* 0xFFFFFFD4	Reserved */
	Dummy,
/* 0xFFFFFFD8	Reserved */
	Dummy,
/* 0xFFFFFFDC	Undefined Instruction */
	Excep_UndefinedInst,
/* 0xFFFFFFE0	Reserved */
	Dummy,
/* 0xFFFFFFE4	Reserved */
	Dummy,
/* 0xFFFFFFE8	Reserved */
	Dummy,
/* 0xFFFFFFEC	Reserved */
	Dummy,
/* 0xFFFFFFF0	Reserved */
	Dummy,
/* 0xFFFFFFF4	Reserved */
	Dummy,
/* 0xFFFFFFF8	NMI */
	Interrupt_NMI,
/* 0xFFFFFFFC	RESET */
	PowerON_Reset_PC
};
/* End of file */
