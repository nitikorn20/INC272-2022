
#include <bsp.h>
#include <rtl.h>


void led0_on()
{
	Uart1_Printf("LED0 ON\r\n");
	Led0_Set();
}

void led0_off()
{
	Uart1_Printf("LED1 OFF\r\n");
	Led0_Clr();
}

int main()
{
	System_Init();

	Uart1_Printf("INFO:\r\n");
	Uart1_Printf(" - SW0: LED0 ON\r\n");
	Uart1_Printf(" - SW3: LED0 OFF\r\n");

	Psw_SetKeyDownCallback(PSW_ID_0, led0_on);
	Psw_SetKeyDownCallback(PSW_ID_3, led0_off);

	System_Start();
}
