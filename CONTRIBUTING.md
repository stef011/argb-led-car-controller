# How to contribute

You can contribute to the project if you see some bugs or if you want to add some features. I'll try to review your pull requests as soon as possible.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## Adding effects

If you want to add an effect, you'll need to create two new files in `include/effects` and `src/effects`. The name of these file will be the name of the effect. The file should contain a class that inherits from the `Effect` class. The class should have a method called `tick` that will be called every frame. The `tick` method should return nothing, but takes in parameters the `ledStrip` object and a `parameter` object.

To change the ledstrip color, you need to change the values in the table `ledStrip->leds[]`. The table contains the color of each led in a CHSV or CRGB object. You can change the color of a led by doing `ledStrip->leds[ledNumber] = CHSV(0, 255, 255);` for example.

The `parameter` object contains the values of the potentiometers. You can access them by doing `parameter->getBrightness()`, `parameter->getColor()` or `parameter->getSpeed()`. You can even directly access the potentiometer by doing `parameter->getPot1()`, `parameter->getPot2()`, `parameter->getPot3()` or `parameter->getPot4()`. And then calling a method on the potentiometer object, either `getValue()`, `getValue8()`, getValueHSV()`or`getLength()`.

`MyEffect.h`

```cpp
#include "Effect.h"

class MyEffect : public Effect
{
public:
  void tick(LedStrip *ledStrip, Parameter *parameter);
};
```

`MyEffect.cpp`

```cpp
#include "MyEffect.h"

void MyEffect::tick(LedStrip *ledStrip, Parameter *parameter)
{
  // Get the value of the potentiometer
  int potValue = parameter->getPot1()->getValueHSV();

  // Change the color of the led strip
  for (int i = 0; i < ledStrip->getLength(); i++)
  {
    ledStrip->leds[i] = CHSV(potValue.hue(), 255, 255);
  }
}
```

Once you have created these files, you need to add the effect name to the `EffectsEnum` in `include/EffectsEnum.h`.

```cpp
...
enum class Effects : int
{
  Still,
  ColorWipe,
  BackAndForth,
  Rainbow,
  MovingRainbow,
  Sinelon,
  MyEffect, // Add this line

  EnumCount
};
...
```

Then include `effects/MyEffect.h` in `Controller.h` and add the effect to the `effects` array in the same file.

```cpp
...
  Effect _effectList[static_cast<int>(Effects::EnumCount)] = {
      Still(),
      ColorWipe(),
      BackAndForth(),
      Rainbow(),
      MovingRainbow(),
      Sinelon(),
      MyEffect() // Add this line
      };
...
```

**NOTE: The order of the effects in the `EffectsEnum` and the `effects` array must be the same. If you want to add an effect in the middle of the list, you need to change the order of the effects in both files.**
