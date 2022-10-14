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

class Controller
{
private:
  LEDStrip *_ledStrip;
  void SetEffect(Effects *effect);
  void NextEffect();
  void PreviousEffect();

  Button *_prevButton, *_nextButton;

  Effects _currentEffect = Effects::Still;
  Effect _effectList[static_cast<int>(Effects::EnumCount)] = {
      Still(),
      ColorWipe(),
      BackAndForth(),
      Rainbow(),
      MovingRainbow(),
      Sinelon()};

public:
  Controller(LEDStrip *ledStrip);
  void tick();
};

#endif
