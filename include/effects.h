#pragma once

#ifndef Effects_H
#define Effects_H

#include "config.h"

void initializeEffects();


// Fixed color 
// @param color CRGB color to fill the LEDs with
void still(CHSV color, uint8_t saturation);

// A simple colorWipe animation 
// @param color CRGB color of the leds
// @param speed the speed of the animation
// @param length the speed at which lights fade
void colorWipe(CHSV color, int speed, int length);

// A simple back and forth animation
// @param color CRGB color of the leds
// @param speed the speed of the animation
// @param length the speed at which lights fade
void backAndForth(CHSV color, int speed, int length);

// A still rainbow effect
// @param color The starting color of the rainbow
// @param secondaryColor the ending color of the rainbow
void rainbow(CHSV color, CHSV secondaryColor);

// A moving Rainbow animation
// @param color the color of the leds
// @param gradient the color of the gradient
// @param delayTime Teh speed of the rainbow effect
void movingRainbow(int delayTime, int length);

// A moving worm called sinelon
// @param color the color of the leds
// @param delayTime the speed of the sinelon effect
void sinelon(CHSV color, int delayTime);

#endif
