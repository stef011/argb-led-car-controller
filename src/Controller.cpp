#include "Controller.h"

/**
 * @brief Construct a new Controller:: Controller object
 *
 * @param ledStrip The LED strip to control
 */
Controller::Controller(LEDStrip *ledStrip)
{
  this->_ledStrip = ledStrip;
  this->_prevButton = new Button(2);
  this->_nextButton = new Button(3);
};

/**
 * @brief The main loop of the controller
 *
 * This function is called in the main loop of the program, it handles the button presses and the effect tick
 */
void Controller::tick()
{
  if (this->_prevButton->isPressed())
  {
    this->PreviousEffect();
  }

  if (this->_nextButton->isPressed())
  {
    this->NextEffect();
  }

  this->_ledStrip->show();
}

void Controller::SetEffect(Effects *effect)
{
  this->_ledStrip->setEffect(&_effectList[static_cast<int>(*effect)]);
}

void Controller::NextEffect()
{
  this->_currentEffect = ++_currentEffect;
  this->SetEffect(&this->_currentEffect);
}

void Controller::PreviousEffect()
{
  this->_currentEffect = --_currentEffect;
  this->SetEffect(&this->_currentEffect);
}
