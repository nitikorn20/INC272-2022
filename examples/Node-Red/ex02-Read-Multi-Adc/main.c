
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

int main()
{
	System_Init();
	Adc_Init(); // Init ADC Function
	Timer_Create(1000, read_analog_All);
	System_Start();
}