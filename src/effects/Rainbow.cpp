#include <effects/Rainbow.h>

void Rainbow::tick(LEDStrip *ledStrip, Parameters *parameters)
{
  fill_gradient(ledStrip->leds, 0, parameters->getColor(), ledStrip->getNumLeds(), CHSV(parameters->getColor().hue + parameters->getColor2().hue, 255, parameters->getBrightness()));
}
