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
  this->_numLeds = numLeds;
  this->_maxBrightness = maxBrightness;
  this->leds = new CRGB[numLeds];
  this->_parameters = new Parameters(numLeds);

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
    // The _pin initialisation need to be a const
  case 1:
    FastLED.addLeds<LED_TYPE, 1, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 2:
    FastLED.addLeds<LED_TYPE, 2, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 3:
    FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 4:
    FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 5:
    FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 6:
    FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 7:
    FastLED.addLeds<LED_TYPE, 7, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  case 8:
    FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(this->leds, this->_numLeds);
    break;
  }

  FastLED.setMaxPowerInVoltsAndMilliamps(5, this->_maxCurrentInMilliamps);
  FastLED.setBrightness(this->_maxBrightness);
  FastLED.clear();
  FastLED.show();
  delay(1000);
}

void LEDStrip::show()
{
  this->readValues();
  this->_currentEffect->tick(this, _parameters);
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
  return this->_numLeds;
}
