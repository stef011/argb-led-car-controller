# ARGB Led Car Controller

This is a simple controller for an **addressable** RGB LED strip. It uses an Arduino board, at least one button and a few potentiometers to control the color of the LED strip.
This can be useful if you want to have a controller for **addressable** RGB LED strips in your car, but don't want to spend a lot of money on a controller with a lot of features you don't need like WiFi or Bluetooth.

![Controller prototype](/img/PXL_20221001_072746806.MP.jpg)
The prototype of this controller.

## Features

- Cycle through the different pre-programmed effects with a button
- Control the led strip with few potentiometers, for now, you can control:
  - Brightness
  - Color
  - Speed of the effect
  - A miscellaneous value that can be used to control the effect in different ways

## How to use

Clone this repository

```bash
git clone https://github.com/stef011/argb-led-car-controller.git
```

Open the project in your favorite IDE, I use [PlatformIO](https://platformio.org/) with [Visual Studio Code](https://code.visualstudio.com/).

You'll need to setup few things before uploading the code on your arduino board:

|  Parameter      | File         | Description                                                                 |
| --------------- | ------------ | --------------------------------------------------------------------------- |
| LED_PIN         | main.cpp     | The pin of the led strip                                                    |
| LED_COUNT       | main.cpp     | The number of leds in the led strip                                         |
| MAX_BRIGHTNESS  | main.cpp     | The maximum brightness of the led strip                                     |
| MAX_CURRENT     | LEDStrip.h   | The maximum current the ledStrip is allowed to draw                         |
| POT1_PIN        | Parameters.h | Pin of the Brightness potentiometer                                         |
| POT2_PIN        | Parameters.h | Pin of the Color potentiometer                                              |
| POT3_PIN        | Parameters.h | Pin of the Speed or secondary color, saturation or fade speed potentiometer |
| POT4_PIN        | Parameters.h | Pin of the effect speed or length potentiometer                             |
| BUTTON_PREV_PIN | Controller.h | The pin of the "previous" button                                            |
| BUTTON_NEXT_PIN | Controller.h | The pin of the "next" button                                                |
| LED_TYPE        | LEDStrip.h   | The type of the leds you're using                                           |
| COLOR_ORDER     | LEDStrip.h   | The color order of the leds you're using                                    |

If you want to change the type of Leds you're using, you'll need to change the `LED_TYPE` parameter in the `LEDStrip.h` file.

Some types of leds have a different order of the RGB values, for instance the WS2812B leds have the order GRB, so you'll need to change the `COLOR_ORDER` parameter in the `LEDStrip.h` file.

## Contributing

Please check the [Contribution guide](CONTRIBUTING.md) file for more information.

## Disclaimer

This is a work in progress, so it may not work as expected. If you find any bugs, please open an issue.
This software is licensed under the [MIT License](LICENSE), so you can use it for whatever you want.
The software is provided as is, without any warranty of any kind.
