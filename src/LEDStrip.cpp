#include <LEDStrip.h>

/**
 * @brief Construct a new LEDStrip::LEDStrip object
 *
 * @param pin The pin to which the LED strip is connected
 * @param numLeds The number of LEDs in the strip
 * @param brightness The maximum brightness of the LED strip
 */
LEDStrip::LEDStrip(uint8_t _pin, uint16_t numLeds, uint8_t maxBrightness)
{
  this->_pin = _pin;
  this->numLeds = numLeds;
  this->maxBrightness = maxBrightness;
  this->leds = new CRGB[numLeds];
  this->parameters = new Parameters(numLeds);

  pinMode(_pin, OUTPUT);
  this->init();
}

LEDStrip::~LEDStrip()
{
  delete[] this->leds;
}

void LEDStrip::init()
{
  switch (this->_pin)
  {
  case 1:
    FastLED.addLeds<WS2812B, 1, GRB>(this->leds, this->numLeds);
    break;
  case 2:
    // The _pin initialisation need to be a const
    FastLED.addLeds<WS2812B, 2, GRB>(this->leds, this->numLeds);
    break;
  case 3:
    FastLED.addLeds<WS2812B, 3, GRB>(this->leds, this->numLeds);
    break;
  case 4:
    FastLED.addLeds<WS2812B, 4, GRB>(this->leds, this->numLeds);
    break;
  case 5:
    FastLED.addLeds<WS2812B, 5, GRB>(this->leds, this->numLeds);
    break;
  case 6:
    FastLED.addLeds<WS2812B, 6, GRB>(this->leds, this->numLeds);
    break;
  case 7:
    FastLED.addLeds<WS2812B, 7, GRB>(this->leds, this->numLeds);
    break;
  case 8:
    FastLED.addLeds<WS2812B, 8, GRB>(this->leds, this->numLeds);
    break;
  }

  FastLED.setMaxPowerInVoltsAndMilliamps(5, this->maxCurrentInMilliamps);
  FastLED.setBrightness(this->maxBrightness);
  FastLED.clear();
  FastLED.show();
  delay(1000);
}

void LEDStrip::show()
{
  this->readValues();
  this->_currentEffect->tick(this, parameters);
  FastLED.show();
}

void LEDStrip::readValues()
{

  // TODO: Read values from Potentiometers
}

void LEDStrip::setEffect(Effect *effect)
{
  this->_currentEffect = effect;
}

int LEDStrip::getNumLeds()
{
  return this->numLeds;
}
