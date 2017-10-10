/*
 * GenPIO.h
 *
 * Frederik Voncken 2017 - V0.1.0
 *
 */

#ifndef _GENPIO_H
#define _GENPIO_H

#include "arduino.h"
#include <stdint.h>

typedef enum {NORMAL = 0, INVERTED = !NORMAL} FunctionalInvert_t;
typedef enum {OFF = 0, ON = !OFF} FunctionalActive_t;

class GenPIO
{
	public:
		GenPIO(int Pin, int Mode, FunctionalActive_t Active, FunctionalInvert_t Invert);
		~GenPIO() {;}
		void Write(FunctionalActive_t Active);
		FunctionalActive_t Read(void);
	private:
		int GenPIO_Pin;
		int GenPIO_Mode;
		FunctionalInvert_t GenPIO_Invert;
		FunctionalActive_t GenPIO_Active;
};

#endif /* _GENPIO_H */
