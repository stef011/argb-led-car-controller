#include <Potentiometer.h>

Potentiometer::Potentiometer(uint8_t pin, uint16_t numLeds) : Input(pin)
{
  pinMode(pin, INPUT_PULLUP);
  this->_numLeds = numLeds;
  update();
}

uint16_t Potentiometer::getValue()
{
  update();
  return this->_value;
}

uint8_t Potentiometer::getValue8()
{
  update();
  return map(this->_value, 0, 1023, 0, 255);
}

CHSV Potentiometer::getValueHSV()
{
  update();
  return CHSV(getValue8(), 255, 255);
}

uint16_t Potentiometer::getLength()
{
  update();
  return map(this->_value, 0, 1023, 1, this->_numLeds);
}

void Potentiometer::update()
{
  this->_value = analogRead(this->_pin); // 0 - 1023
}
