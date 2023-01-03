
#include <bsp.h>
#include <rtl.h>

void timer_tick()
{
	Uart1_Printf("ticks\r\n");
}

void led0_toggle()
{
	Led0_Inv();
}

void led3_toggle()
{
	Led3_Inv();
}

int main()
{
	System_Init();

	/*******************************************************
	 * Timer_Create
	 * Creates and returns a timer object.
	 * Parameters:
	 * - interval: Sleeping interval in milliseconds.
	 * - callback: Callback function, performed when the timer ready.
	 *
	 * #####################################################
	 *
	 * Timer_Create(uint16_t interval, callback_t callback);
	 *
	 * #####################################################
	 *
	 *******************************************************/

	Timer_Create(10000, timer_tick);

	Timer_Create(500, led0_toggle);

	Timer_Create(800, led3_toggle);

	System_Start();
}
