#include <Arduino.h>

#include <Controller.h>
#include <LEDStrip.h>

#define LED_PIN 2
#define LED_COUNT 60
#define MAX_BRIGHTNESS 255

void setup()
{
}

void loop()
{
  LEDStrip *ledStrip = new LEDStrip(LED_PIN, LED_COUNT, MAX_BRIGHTNESS);
  Controller controller = Controller(ledStrip);
  controller.tick();
}
