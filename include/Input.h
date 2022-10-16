#ifndef INPUT_H
#define INPUT_H

#include <FastLED.h>

class Input
{
protected:
  uint8_t _pin;

public:
  Input(uint8_t pin);
  virtual ~Input();
  virtual void update();
};

#endif
