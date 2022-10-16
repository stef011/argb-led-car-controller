#ifndef SINELON_H
#define SINELON_H

#include <LedStrip.h>

class Sinelon : public Effect
{
public:
  void tick(LEDStrip &, Parameters *);

private:
  CRGBPalette16 currentPalette;
  CRGBPalette16 targetPalette;
  TBlendType currentBlending;
  uint8_t maxChanges = 10;

  // Define variables used by the sinelon.
  // uint8_t thisbeat = 24; // Beats per minute for first part of dot.
  // uint8_t thatbeat = 28; // Combined the above with this one.
  uint8_t thisfade = 5;  // How quickly does it fade? Lower = slower fade rate.
  uint8_t thissat = 255; // The saturation, where 255 = brilliant colours.
  uint8_t thisbri = 255; // Brightness of a sequence.
};

#endif
