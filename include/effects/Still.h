#ifndef STILL_H
#define STILL_H

// #include <FastLED.h>
#include <LEDStrip.h>

class Still : public Effect
{
public:
  void tick(LEDStrip &, Parameters *);
};

#endif
