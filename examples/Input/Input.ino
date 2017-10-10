/*
 * Input example for GenPIO
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#include <GenPIO.h>

GenPIO Indicator(LED_BUILTIN, OUTPUT, OFF, INVERTED);
GenPIO Switch(D6, INPUT, OFF, INVERTED);

void setup (void)
{
}

void loop(void)
{
	delay(1000);
	Indicator.Write(ON);
	delay(100);
	Indicator.Write(OFF);
	if (Switch.Read() == ON) {
		delay(100);
		Indicator.Write(ON);
		delay(100);
		Indicator.Write(OFF);
	}
}
