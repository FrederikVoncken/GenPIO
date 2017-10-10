/*
 * GenPIO.cpp
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#include "GenPIO.h"

GenPIO::GenPIO(int Pin, int Mode, FunctionalActive_t Active, FunctionalInvert_t Invert)
{
	GenPIO_Pin = Pin;
	GenPIO_Mode = Mode;
	GenPIO_Active = Active;
	GenPIO_Invert = Invert;

	if (GenPIO_Mode == OUTPUT) {
		pinMode(GenPIO_Pin, INPUT);
		Write(GenPIO_Active);
	}
	pinMode(GenPIO_Pin, GenPIO_Mode);
}

void GenPIO::Write(FunctionalActive_t Active)
{
	if (GenPIO_Mode == OUTPUT) {
		GenPIO_Active = Active;
		if (GenPIO_Active == OFF) {
			if (GenPIO_Invert == NORMAL) {
				digitalWrite(GenPIO_Pin, LOW);
			} else {
				digitalWrite(GenPIO_Pin, HIGH);
			}
		} else {
			if (GenPIO_Invert == NORMAL) {
				digitalWrite(GenPIO_Pin, HIGH);
			} else {
				digitalWrite(GenPIO_Pin, LOW);
			}
		}
	}
	// else do nothing because of write to input
}

FunctionalActive_t GenPIO::Read(void)
{
	int InputActive;

	if (GenPIO_Mode == OUTPUT) {
		return GenPIO_Active;
	} else {
		InputActive = digitalRead(GenPIO_Pin);
		if (GenPIO_Invert == NORMAL) {
			if (InputActive == LOW) {
				return OFF;
			} else {
				return ON;
			}
		} else {
			if (InputActive == LOW) {
				return ON;
			} else {
				return OFF;
			}
		}
	}
}
