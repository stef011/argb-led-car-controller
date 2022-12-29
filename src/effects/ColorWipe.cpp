#include <effects/ColorWipe.h>

void ColorWipe::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  // uint8_t thisLed = map(beat88(parameters->getSpeed() * 255), , 255, 0, ledStrip.getNumLeds() - _commetSize);

  uint16_t thisLed = map(beat8(parameters->getSpeed()), 0, 255, 0, ledStrip.getNumLeds() - _commetSize);

  for (int i = thisLed; i < thisLed + _commetSize; i++)
  {
    ledStrip.leds[i] = CHSV(parameters->getColor().hue, 255, parameters->getBrightness());
  }

  // ledStrip.leds[thisLed] = CHSV(parameters->getColor().hue, 255, parameters->getBrightness());
  fadeToBlackBy(ledStrip.leds, ledStrip.getNumLeds(), max(1, parameters->getFade()));
}
