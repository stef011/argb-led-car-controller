#include <Arduino.h>

#include <Controller.h>
#include <LEDStrip.h>

#define LED_PIN 2
#define LED_COUNT 223
#define MAX_BRIGHTNESS 255

LEDStrip *ledStrip;
Controller *controller;
// Controller controller(&ledStrip);

void setup()
{
  ledStrip = new LEDStrip(LED_PIN, LED_COUNT, MAX_BRIGHTNESS);
  controller = new Controller(*ledStrip);
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
