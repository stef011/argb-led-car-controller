#include <Effect.h>

class BackAndForth : Effect
{
public:
  void tick(LEDStrip *ledStrip, Parameters *parameters)
  {
    uint8_t thisLed = map(beat8(parameters->getSpeed()), 0, 255, 0, ledStrip->getNumLeds() - 1);
    ledStrip->leds[thisLed] = parameters->getColor();
    fadeToBlackBy(ledStrip->leds, ledStrip->getNumLeds(), max(1, parameters->getFade()));
  }
};
