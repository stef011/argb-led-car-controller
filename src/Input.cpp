#include <Input.h>

Input::Input(uint8_t pin)
{
  this->_pin = pin;
  pinMode(pin, INPUT);
}

Input::~Input()
{
}

void Input::update()
{
}
