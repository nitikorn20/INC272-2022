
#include <bsp.h>
#include <rtl.h>

int main()
{
	System_Init();

	/*******************************************************
	 * Turn LEDs
	 *******************************************************/
	Led0_Set(); // Turn LED0 ON.
	Led1_Set(); // Turn LED1 ON.
	Led2_Set(); // Turn LED2 ON.
	Led3_Set(); // Turn LED3 ON.

	/*******************************************************
	 * Turn LEDs
	 *******************************************************/
	Led0_Clr(); // Turn LED0 OFF.
	Led1_Clr(); // Turn LED1 OFF.
	Led2_Clr(); // Turn LED2 OFF.
	Led3_Clr(); // Turn LED3 OFF.

	/*******************************************************
	 * Invert LEDs
	 *******************************************************/
	Led0_Inv(); // Invert/Toggle status of LED0.
	Led1_Inv(); // Invert/Toggle status of LED1.
	Led2_Inv(); // Invert/Toggle status of LED2.
	Led3_Inv(); // Invert/Toggle status of LED3.

	System_Start();
	
}
