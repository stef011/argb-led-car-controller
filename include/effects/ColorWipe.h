#ifndef COLOR_WIPE_H
#define COLOR_WIPE_H

#include <LEDStrip.h>

class ColorWipe : public Effect
{
public:
  void tick(LEDStrip &, Parameters *);
};

#endif
