#ifndef BACK_AND_FORTH_H
#define BACK_AND_FORTH_H

#include <LEDStrip.h>

class BackAndForth : public Effect
{
public:
  void tick(LEDStrip &, Parameters *);
};

#endif
