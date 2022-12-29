#include "Controller.h"

/**
 * @brief Construct a new Controller:: Controller object
 *
 * @param ledStrip The LED strip to control
 */
Controller::Controller(LEDStrip *ledStrips[])
{
  for (int i = 0; i < STRIPS_COUNT; i++)
  {
    this->_ledStrips[i] = ledStrips[i];
  }
  this->_prevButton = new Button(BUTTON_PREV_PIN);
  this->_nextButton = new Button(BUTTON_NEXT_PIN);
  this->SetEffect(&this->_currentEffect);
};

/**
 * @brief The main loop of the controller
 *
 * This function is called in the main loop of the program, it handles the button presses and the effect tick
 */
void Controller::tick()
{
  if (this->_prevButton->latchState())
  {
    this->PreviousEffect();
  }

  if (this->_nextButton->latchState())
  {
    this->NextEffect();
  }

  for (size_t i = 0; i < STRIPS_COUNT; i++)
  {
    this->_ledStrips[i]->show();
  }
}

void Controller::SetEffect(Effects *effect)
{
  for (size_t i = 0; i < STRIPS_COUNT; i++)
  {
    this->_ledStrips[i]->setEffect(_effectList[static_cast<int>(*effect)]);
    this->_ledStrips[i]->show();
  }
}

void Controller::NextEffect()
{
  this->_currentEffect = ++_currentEffect;
  this->SetEffect(&_currentEffect);
}

void Controller::PreviousEffect()
{
  this->_currentEffect = --_currentEffect;
  this->SetEffect(&_currentEffect);
}
