#include <Parameters.h>

Parameters::Parameters(uint16_t numLeds)
{
  this->_pot1 = new Potentiometer(A1, numLeds);
  this->_pot2 = new Potentiometer(A2, numLeds);
  this->_pot3 = new Potentiometer(A3, numLeds);
  this->_pot4 = new Potentiometer(A4, numLeds);

  this->_numLeds = numLeds;
}

uint8_t Parameters::getBrightness()
{
  return this->_pot1->getValue8();
}

CHSV Parameters::getColor()
{
  return this->_pot2->getValueHSV();
}

CHSV Parameters::getColor2()
{
  return this->_pot3->getValueHSV();
}

uint8_t Parameters::getSaturation()
{
  return this->_pot3->getValue8();
}

uint8_t Parameters::getSpeed()
{
  return map(this->_pot4->getValue(), 0, 1023, 1, 20);
}

uint16_t Parameters::getLength()
{
  return this->_pot4->getLength();
}

uint8_t Parameters::getFade()
{
  return map(this->_pot3->getValue(), 0, 1023, 1, 20);
}

Potentiometer *Parameters::getPot1()
{
  return this->_pot1;
}

Potentiometer *Parameters::getPot2()
{
  return this->_pot2;
}

Potentiometer *Parameters::getPot3()
{
  return this->_pot3;
}

Potentiometer *Parameters::getPot4()
{
  return this->_pot4;
}
