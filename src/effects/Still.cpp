#include <effects/Still.h>

void Still::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  fill_solid(
      ledStrip.leds,
      ledStrip.getNumLeds(),
      CHSV(
          parameters->getColor().hue,
          parameters->getSaturation(),
          parameters->getBrightness()));
}
