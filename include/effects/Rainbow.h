#ifndef RAINBOW_H
#define RAINBOW_H

#include <LEDStrip.h>

class Rainbow : public Effect
{
public:
  void tick(LEDStrip *, Parameters *);
};

#endif
