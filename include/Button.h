#ifndef BUTTON_H
#define BUTTON_H

#include <Input.h>

class Button : Input
{
private:
  uint8_t _pin;                   // The _pin the button is connected to
  bool _state;                    // The current state of the button
  bool _lastState;                // The last state of the button
  uint16_t _lastDebounceTime = 0; // The last time the button state changed
  uint16_t _debounceDelay = 50;   // The debounce time; the period of time (milliseconds) after the last button state change during which the button state will not be changed
  void update();                  // update the state of the button (debouncing)

public:
  uint16_t debounceMs;

  Button(uint8_t pin);
  bool isPressed(); // return true if the button is pressed (debounced)
  bool getState();  // return the state of the button (debounced)
};

#endif
