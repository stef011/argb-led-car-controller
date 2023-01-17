#include <Arduino.h>

#include <Controller.h>
#include <LEDStrip.h>

#define LED_PIN 2
#define LED_COUNT 88
#define MAX_BRIGHTNESS 255

LEDStrip *ledStrip;
LEDStrip *insideLedStrip;
Controller *controller;
// Controller controller(&ledStrip);

void setup()
{
  ledStrip = new LEDStrip(LED_PIN, LED_COUNT, MAX_BRIGHTNESS);
  insideLedStrip = new LEDStrip(3, 23, MAX_BRIGHTNESS);
  // controller = new Controller(*ledStrip);
  LEDStrip *strips[] = {ledStrip, insideLedStrip};
  controller = new Controller(strips);
}

void loop()
{
  controller->tick();
}

int main()
{
  init();
  setup();
  while (true)
  {
    loop();
  }
  return 0;
}
