#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <FastLED.h>
#include <LedStrip.h>
#include <EffectsEnum.h>
#include <Button.h>
#include <Effect.h>

#include <effects/Still.h>
#include <effects/ColorWipe.h>
#include <effects/BackAndForth.h>
#include <effects/Rainbow.h>
#include <effects/MovingRainbow.h>
#include <effects/Sinelon.h>

class BackAndForth; // mysterious forward declaration for this effect

#define BUTTON_PREV_PIN 5
#define BUTTON_NEXT_PIN 4
#define STRIPS_COUNT 2

class Controller
{
private:
  // LEDStrip *_ledStrip;
  LEDStrip *_ledStrips[STRIPS_COUNT];
  void SetEffect(Effects *effect);
  void NextEffect();
  void PreviousEffect();

  Button *_prevButton, *_nextButton;

  Effects _currentEffect = Effects::Still;
  Effect *_effectList[static_cast<int>(Effects::EnumCount)] = {
      new Still(),
      new ColorWipe(),
      new BackAndForth(),
      new Rainbow(),
      new MovingRainbow(),
      new Sinelon()};

public:
  Controller(LEDStrip *ledStrips[]);
  void tick();
};

#endif
