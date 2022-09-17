#ifndef Config_H
#define Config_H

#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 223
#define MAX_BRIGHTNESS 200
#define FRAMES_PER_SECOND 10

#define BUTTON_PLUS_PIN 5
#define BUTTON_MINUS_PIN 4

#define POT_BRIGHTNESS A1
#define POT_COLOR A2
#define POT_DELAY A3
#define POT_MISC A4

#define EFFECTS_NUM 6

extern CRGB leds[NUM_LEDS];
extern int tableState;
extern bool isInitialized;
extern int brightness;

#endif
