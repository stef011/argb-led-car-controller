#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Input.h>
#include <LEDStrip.h>

class Potentiometer : Input
{
private:
  uint8_t _pin;
  uint16_t _value;
  uint16_t _numLeds;

  void update();

public:
  Potentiometer(uint8_t pin, uint16_t numLeds);
  uint16_t getValue();
  uint8_t getValue8();
  CHSV getValueHSV();
  uint16_t getLength();
};

#endif
