
#include <bsp.h>
#include <rtl.h>

void read_analog_All()
{

	float adc0 = Adc_GetVoltage(0);
	float adc1 = Adc_GetVoltage(1);
	float adc2 = Adc_GetVoltage(2);
	float adc3 = Adc_GetVoltage(3);

	/*******************************************************
	 * Adc_GetVoltage
	 *
	 * ####################################
	 *
	 * Adc_Get(uint16_t id);
	 *
	 * ####################################
	 *
	 * Returns voltage of the target channel.
	 * Parameter:
	 * - id: Id of ADC (ADC_ID_0, ..., ADC_ID_3).
	 *******************************************************/
	Uart1_Printf("%f;%f;%f;%f;\r\n", adc0, adc1, adc2, adc3);
}

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
}

int main()
{
	System_Init();
	Adc_Init(); // Init ADC Function
	Uart1_Init(115200, 64, 64);
	Uart1_SetRxLineCallback(uart1_line_received, 128);
	Timer_Create(1000, read_analog_All);
	System_Start();
}