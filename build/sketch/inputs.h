#line 1 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\inputs.h"
#ifndef Inputs_H
#define Inputs_H

#include <Arduino.h>
#include <FastLED.h>
#include "config.h"


CHSV potToCHSV(int pot);

bool readButton(int pin);

bool checkForChange(bool current, bool last);

int cycleCounter(int cycle, bool reverse);

#endif
