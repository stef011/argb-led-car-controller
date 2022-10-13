#include <Arduino.h>

#include <Controller.h>
#include <LEDStrip.h>

void setup()
{
}

void loop()
{
  LEDStrip *ledStrip = new LEDStrip(2, 60, 255);
  Controller controller = Controller(ledStrip);
  controller.tick();
}
