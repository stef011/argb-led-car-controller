#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Input.h>
#include <LEDStrip.h>

class Potentiometer : Input
{
private:
  uint16_t _value;   // 0 - 1023 (10 bit) The value of the potentiometer
  uint16_t _numLeds; // 0 - 1023 (10 bit) The number of LEDs in the strip

  void update();

public:
  Potentiometer(uint8_t pin, uint16_t numLeds);
  uint16_t getValue();
  uint8_t getValue8();
  CHSV getValueHSV();
  uint16_t getLength();
};

#endif
