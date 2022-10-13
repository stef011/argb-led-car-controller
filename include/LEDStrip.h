#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <FastLED.h>
#include <Effect.h>
#include <EffectsEnum.h>

class Effect;     // TOFIX: circular dependency
class Parameters; // TOFIX: circular dependency

class LEDStrip
{
private:
  int _pin;                  // The _pin the LED strip is connected to
  int maxBrightness;         // The maximum brightness of the LED strip
  int maxCurrentInMilliamps; // The maximum current the LED strip can draw
  Effect *_currentEffect;    // The effect that is currently running
  int numLeds;               // The number of LEDs in the strip
  Parameters *parameters;    // The parameters of the effects, like brightness, color, speed, etc. Every parameter is retrieved on the potentiometers

  void init();
  void readValues();

public:
  CRGB *leds; // The array of LEDs
  LEDStrip(uint8_t, uint16_t, uint8_t);
  ~LEDStrip();

  void show(); // Show the current effect

  void setEffect(Effect *); // Set the effect that is currently running

  int getNumLeds(); // Get the number of LEDs in the strip
};

#endif
