#ifndef BACK_AND_FORTH_H
#define BACK_AND_FORTH_H

#include <LEDStrip.h>

class BackAndForth : public Effect
{
private:
  uint8_t _commetSize = 5;

public:
  void tick(LEDStrip &, Parameters *);
};

#endif
