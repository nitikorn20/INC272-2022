
#include "BSP_Main.h"
#include "BSP_SysTick.h"
#include "BSP_Uart.h"
#include "rtl.h"

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{

	IFS0bits.T1IF = 0;

	/*********************************
	 * System_IsrPerformTick
	 *********************************/
	Sys_IsrPerformTick();

	/*********************************
	 * BSP_TickIsrExecutor
	 *********************************/
	BSP_TickIsrExecutor();

	/*********************************
	 * RTL_TickIsrExecutor
	 *********************************/
	RTL_TickIsrExecutor();
}

#define System_Init() {			\
	Mcu_Init();					\
	Uart1_Init(115200, 64, 128);\
}

#define System_Start() {	\
	Sys_Start();			\
	while(1) {				\
		BSP_Executor(); 	\
		RTL_Executor();		\
	}						\
}
