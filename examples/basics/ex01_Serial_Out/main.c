
#include <bsp.h>
#include <rtl.h>

int main()
{
	System_Init();

	/*******************************************************
	 * Uart1_Printf
	 * Uart2_Printf
	 * Synchronously prints a formatted string to Uart1 or Uart2.
	 *
	 *
	 * Uart1_Printf(const char *format, ...);
	 * Uart2_Printf(const char *format, ...);
	 *
	 * Parameter:
	 * - format: The formatted string.
	 * - ...: Additional parameters used to create the string.
	 *******************************************************/

	Uart1_Printf("Hello, World!\r\n");

	int16_t Data_Int = 30;
	Uart1_Printf("Int Data: %d\r\n", Data_Int);

	float Data_Float = 12.223;
	Uart1_Printf("Float Data: %f\r\n", Data_Float);

	System_Start();
}
