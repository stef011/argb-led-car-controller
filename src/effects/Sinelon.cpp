#include <effects/Sinelon.h>

void Sinelon::tick(LEDStrip &ledStrip, Parameters *parameters)
{
  EVERY_N_MILLISECONDS(100)
  {
    nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
  }

  EVERY_N_SECONDS(5)
  {
    targetPalette = CRGBPalette16(CHSV(random8(), 255, random8(128, 255)), CHSV(random8(), 255, random8(128, 255)), CHSV(random8(), 192, random8(128, 255)), CHSV(random8(), 255, random8(128, 255)));
  }

  fadeToBlackBy(ledStrip.leds, ledStrip.getNumLeds(), 10);
  int pos1 = beatsin16(map(parameters->getPot3()->getValue(), 0, 255, 1, 20), 0, ledStrip.getNumLeds());
  int pos2 = beatsin16(map(parameters->getPot4()->getValue(), 0, 255, 1, 20), 0, ledStrip.getNumLeds());

  ledStrip.leds[(pos1 + pos2) / 2] += ColorFromPalette(currentPalette, parameters->getColor().hue, parameters->getBrightness(), currentBlending);
}
