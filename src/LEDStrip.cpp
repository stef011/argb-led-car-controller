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
  this->_maxCurrentInMilliamps = 1000;
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

  FastLED.addLeds<LED_TYPE, 2, COLOR_ORDER>(this->leds, this->_numLeds);

  FastLED.setMaxPowerInVoltsAndMilliamps(5, this->_maxCurrentInMilliamps);
  FastLED.setBrightness(this->_maxBrightness);
  FastLED.clear();
  FastLED.show();
  delay(1000);
}

void LEDStrip::show()
{
  _currentEffect->tick(*this, _parameters);

  FastLED.show();
}

void LEDStrip::setEffect(Effect &effect)
{

  this->_currentEffect = &effect;
}

int LEDStrip::getNumLeds()
{
  return this->_numLeds;
}
