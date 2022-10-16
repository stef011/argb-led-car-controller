#include <effects/MovingRainbow.h>

void MovingRainbow::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  uint8_t thisHue = beat8(parameters->getSpeed(), 255);
  fill_gradient(ledStrip.leds, 0, CHSV(thisHue, 255, parameters->getBrightness()), ledStrip.getNumLeds(), CHSV(thisHue + parameters->getLength(), 255, parameters->getBrightness()), FORWARD_HUES);
}
