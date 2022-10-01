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

Open the `LEDController.ino` file with the Arduino IDE and upload it to your board.

You'll need 4 potentiometers and 2 buttons, connect them to the Arduino board as shown in the following table:

| Potentiometer | Arduino Pin |
| ------------- | ----------- |
| Brightness    | A1          |
| Color         | A2          |
| Speed         | A3          |
| Misc          | A4          |

| Button | Arduino Pin |
| ------ | ----------- |
| Next   | 4           |
| Prev   | 5           |

Connect the LED strip to the pin 2 on the board.

If you don't want to use these specific pins, you can change them in the `config.h` file.

In the `config.h` file, you will also need to configure:

- The number of the LEDs connected to the controller (Be sure to have a consequent alimentation for the LED strip)
- The maximum Brightness of the led strip (WIP)
- The frames per second (fluidity of the effects)

## Disclaimer

This is a work in progress, so it may not work as expected. If you find any bugs, please open an issue.
This software is licensed under the [MIT License](LICENSE), so you can use it for whatever you want.
The software is provided as is, without any warranty of any kind.
