#ifndef MOVING_RAINBOW_H
#define MOVING_RAINBOW_H

#include <LEDStrip.h>

class MovingRainbow : public Effect
{
public:
  void tick(LEDStrip *, Parameters *);
};

#endif
