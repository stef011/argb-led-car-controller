#include <Button.h>

Button::Button(uint8_t pin) : Input(pin)
{
  this->_pin = pin;
  this->_lastState = LOW;

  pinMode(pin, INPUT);
  update();
}

bool Button::isPressed()
{
  return (getState() == HIGH);
}

bool Button::getState()
{
  update();
  return this->_state;
}

void Button::update()
{
  bool reading = digitalRead(this->_pin);

  if (reading != this->_lastState)
  {
    this->_lastDebounceTime = millis();
  }

  if (((millis() - this->_lastDebounceTime) > this->_debounceDelay) && reading != this->_state)
  {
    this->_state = reading;
  }

  this->_lastState = reading;
}
