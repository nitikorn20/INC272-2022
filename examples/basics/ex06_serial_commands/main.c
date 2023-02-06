
#include <bsp.h>
#include <rtl.h>

/**
 * MCU Note:
 * 	UART1 is used as communication port
 * 	UART2 is used as debugging port
*/

/**
 * Proteus Note:
 *  Exclude the UART1
 *  Include the UART2
*/

/**
 * VSPD Note:
 *  COM4 is connected to Proteus
 *  COM5 is connected to Rust
*/

void uart1_line_received(void* evt) {

	/**
	 * Get line data from the event
	*/
	uart_line_t * ue = (uart_line_t *)evt;
	const char* line = ue->buffer;
	
	/**
	 * Note: `line` variable contains `\r\n`
	*/

	Uart2_Printf("Received: %s", line);

	/**
	 * Control logic
	*/
	if( !strcmp(line, "led-on\r\n")) {
		Led0_Set();
	}
	else if( !strcmp(line, "led-off\r\n")) {
		Led0_Clr();
	}
	else if( !strcmp(line, "led-inv\r\n")) {
		Led0_Inv();
	}
	else {
		Uart2_Printf("Cmd Err: %s", line);	
	}
}

int main()
{
	System_Init();
	Uart1_Init(115200, 64, 64);
	Uart2_Init(115200, 64, 64);
	Uart1_SetRxLineCallback(uart1_line_received, 128);
	System_Start();
}