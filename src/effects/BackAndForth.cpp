#include <effects/BackAndForth.h>

void BackAndForth::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  uint8_t thisLed = beatsin16(parameters->getSpeed(), 0, ledStrip.getNumLeds() - 1);
  ledStrip.leds[thisLed] = CHSV(parameters->getColor().hue, 255, parameters->getBrightness());
  fadeToBlackBy(ledStrip.leds, ledStrip.getNumLeds(), max(1, parameters->getFade()));
};
