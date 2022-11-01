#include <Potentiometer.h>

Potentiometer::Potentiometer(uint8_t pin, uint16_t numLeds) : Input(pin)
{
  // pinMode(pin, INPUT);
  // this->_pin = pin;
  this->_numLeds = numLeds;

  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    readings[thisReading] = 0;
  }

  update();
}

uint16_t Potentiometer::getValue()
{
  update();
  return this->_value;
}

uint8_t Potentiometer::getValue8()
{
  update();
  return map(this->_value, 0, 1023, 0, 255);
}

CHSV Potentiometer::getValueHSV()
{
  update();
  return CHSV(getValue8(), 255, 255);
}

uint16_t Potentiometer::getLength()
{
  update();
  return map(this->_value, 0, 1023, 1, this->_numLeds);
}

void Potentiometer::update()
{
  this->_value = smoothedValue(); // 0 - 1023
}

int Potentiometer::smoothedValue()
{
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(this->_pin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings)
  {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // return the average value for last n readings:
  return average;
}
