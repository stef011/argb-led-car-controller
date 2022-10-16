#ifndef EFFECT_H
#define EFFECT_H

#include <FastLED.h>
#include <Parameters.h>
#include <LedStrip.h>

class LEDStrip;   // TOFIX: circular dependency
class Parameters; // TOFIX: circular dependency

class Effect
{
private:
public:
  Effect();
  virtual ~Effect();
  void virtual tick(LEDStrip &ledStrip, Parameters *parameters);
};

#endif
