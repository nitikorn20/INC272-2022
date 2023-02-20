
#include <bsp.h>
#include <rtl.h>

void uart1_line_received(void *evt)
{

	/**
	 * Get line data from the event
	 */
	uart_line_t *ue = (uart_line_t *)evt;
	const char *line = ue->buffer;

	/**
	 * Note: `line` variable contains `\r\n`
	 */

	Uart2_Printf("Received: %s", line);

	/**
	 * Control logic
	 */
	if (!strcmp(line, "led,0,1\r\n"))
	{
		Uart2_Printf("LED1 ON");
		Led0_Set();
	}
	else if (!strcmp(line, "led,0,0\r\n"))
	{
		Uart2_Printf("LED1 OFF");
		Led0_Clr();
	}
	else if (!strcmp(line, "led,3,2\r\n"))
	{
		Uart2_Printf("LED3 INV");
		Led3_Inv();
	}
}

int main()
{

	/**
	 * Uart 1 Printf for Send and Recive Data to Node-Red
	 * Uart 2 Printf for Debug in Proteus
	 */

	System_Init();
	Uart1_Init(115200, 64, 64);
	Uart2_Init(115200, 64, 64);
	Uart1_SetRxLineCallback(uart1_line_received, 128);
	System_Start();
}