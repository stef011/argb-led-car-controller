#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <FastLED.h>
#include <Potentiometer.h>

class Potentiometer; // TOFIX: circular dependency

class Parameters
{
private:
  uint16_t _numLeds;

  Potentiometer *_pot1,
      *_pot2, *_pot3, *_pot4;

public:
  Parameters(uint16_t);

  uint8_t getBrightness();
  CHSV getColor();
  CHSV getColor2();
  uint8_t getSaturation();
  uint8_t getSpeed();
  uint16_t getLength();
  uint8_t getFade();

  // TODO: there must be a better way to do this than having a getter for each pot (Design pattern ?)
  Potentiometer *getPot1();
  Potentiometer *getPot2();
  Potentiometer *getPot3();
  Potentiometer *getPot4();
};

#endif
