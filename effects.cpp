#include "effects.h"

bool darkening = false;
uint8_t offset = 0;

// Led status table, that way we can change the color on the fly
uint8_t ledStatus[NUM_LEDS];

// Moving Rainbow
CRGBPalette16 gradientPalette;
uint8_t gradientProgression = 0;

// Define variables used by the sinelon.
uint8_t thisbeat =  24;                                 // Beats per minute for first part of dot.
uint8_t thatbeat =  28;                                 // Combined the above with this one.
uint8_t thisfade =   5;                                // How quickly does it fade? Lower = slower fade rate.
uint8_t  thissat = 255;                                 // The saturation, where 255 = brilliant colours.
uint8_t  thisbri = 255;                                 // Brightness of a sequence.
int        myhue =   0;
CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType    currentBlending;                          // NOBLEND or LINEARBLEND

void initializeEffects() {
  // nothing to do
}


void still(CHSV color) {
  fill_solid(leds, NUM_LEDS, color);
}


void colorWipe(CHSV color, int speed, int length) {
  uint8_t thisLed = map(beat8(speed, 0), 0, 255, 0, NUM_LEDS - 1);
  leds[thisLed] = color;
  fadeToBlackBy(leds, NUM_LEDS, max( 1, length));
}

void backAndForth(CHSV color, int speed, int length){
  uint8_t thisLed = beatsin16(speed, 0, NUM_LEDS - 1);
  leds[thisLed] = color;
  fadeToBlackBy(leds, NUM_LEDS, max( 1, length));
}


void rainbow(CHSV color, CHSV secondaryColor){
  fill_gradient(leds, 0, color, NUM_LEDS, CHSV(color.hue + secondaryColor.hue, 255, brightness), FORWARD_HUES);
}

void movingRainbow(int delayTime, int length) {
  // gradientPalette = CRGBPalette16(
  //   color,
  //   secondaryColor
  // );
  // EVERY_N_MILLISECONDS(delayTime) {
  //   fill_palette(leds, NUM_LEDS, gradientProgression, 16 / NUM_LEDS, gradientPalette, MAX_BRIGHTNESS, LINEARBLEND);
  // }

  uint8_t thisHue = beat8(max(delayTime, 2), 255);
  fill_gradient(leds, 0, CHSV(thisHue, 255, brightness), NUM_LEDS, CHSV(thisHue + length, 255, brightness), FORWARD_HUES);
  // fill_rainbow(leds, NUM_LEDS, thisHue, hueOffset.hue / 10);

}

void sinelon(CHSV color, int delayTime) {

  EVERY_N_MILLISECONDS(100) {
    uint8_t maxChanges = 10;
    nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);   // AWESOME palette blending capability.
  }

  EVERY_N_SECONDS(5) {                                        // Change the target palette to a random one every 5 seconds.
    static uint8_t baseC = color.hue;                         // You can use this as a baseline colour if you want similar hues in the next line.
    targetPalette = CRGBPalette16(CHSV(random8(), 255, random8(128,255)), CHSV(random8(), 255, random8(128,255)), CHSV(random8(), 192, random8(128,255)), CHSV(random8(), 255, random8(128,255)));
  }

  fadeToBlackBy(leds, NUM_LEDS, 10);
  int pos1 = beatsin16(thisbeat,0,NUM_LEDS);
  int pos2 = beatsin16(thatbeat,0,NUM_LEDS);

  leds[(pos1+pos2)/2] += ColorFromPalette(currentPalette, myhue++, thisbri, currentBlending);
}
  