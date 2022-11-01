#ifndef COLOR_WIPE_H
#define COLOR_WIPE_H

#include <LEDStrip.h>

class ColorWipe : public Effect
{
private:
  static const uint8_t _commetSize = 5;

public:
  void tick(LEDStrip &, Parameters *);
};

#endif
