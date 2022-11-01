#include <Parameters.h>

Parameters::Parameters(uint16_t numLeds)
{
  _pot1 = new Potentiometer(PIN_POT1, numLeds);
  _pot2 = new Potentiometer(PIN_POT2, numLeds);
  _pot3 = new Potentiometer(PIN_POT3, numLeds);
  _pot4 = new Potentiometer(PIN_POT4, numLeds);

  _numLeds = numLeds;
}

uint8_t Parameters::getBrightness()
{
  return _pot1->getValue8();
}

CHSV Parameters::getColor()
{
  return _pot2->getValueHSV();
}

CHSV Parameters::getColor2()
{
  return _pot3->getValueHSV();
}

uint8_t Parameters::getSaturation()
{
  return _pot3->getValue8();
}

uint8_t Parameters::getFade()
{
  return map(_pot3->getValue(), 0, 1023, 1, 20);
}

uint8_t Parameters::getSpeed()
{
  return map(_pot4->getValue(), 0, 1023, 1, 120);
}

uint16_t Parameters::getLength()
{
  return _pot2->getLength();
}

Potentiometer *Parameters::getPot1()
{
  return _pot1;
}

Potentiometer *Parameters::getPot2()
{
  return _pot2;
}

Potentiometer *Parameters::getPot3()
{
  return _pot3;
}

Potentiometer *Parameters::getPot4()
{
  return _pot4;
}
