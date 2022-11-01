#include <effects/Rainbow.h>

void Rainbow::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  fill_gradient(ledStrip.leds, 0, CHSV(parameters->getColor().hue, 255, parameters->getBrightness()), ledStrip.getNumLeds(), CHSV(parameters->getColor().hue + parameters->getColor2().hue - 1, 255, parameters->getBrightness()), FORWARD_HUES);
}
