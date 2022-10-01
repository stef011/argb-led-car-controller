# 1 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\LEDController.ino"
# 2 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\LEDController.ino" 2
# 3 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\LEDController.ino" 2
# 4 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\LEDController.ino" 2

// #include <FastLED.h>

CRGB leds[223];

bool isInitialized = false;

int tableState = 0;
int state = 0;

int potBrightness;
int potColor;
int potDelay;
int potMisc;

int brightness;

bool currentUpState;
bool lastUpState;
bool upStateChange;
bool downStateChange;
bool currentDownState;
bool lastDownState;
int sequence;


CHSV color;
CHSV secondaryColor;

void setup() {
  // Init buttons and potentiometers
  pinMode(5, 0x0);
  pinMode(4, 0x0);
  pinMode(A1, 0x0);
  pinMode(A2, 0x0);
  pinMode(A3, 0x0);
  pinMode(A4, 0x0);

  // Init Modules
  initializeEffects();

  // Serial.begin(9600);

  // Setup FastLED
  FastLED.addLeds<WS2812, 2, GRB>(leds, 223);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.setBrightness(200);
  FastLED.clear();
  FastLED.show();
  delay(1000); // Sanity delay
}

void loop() {
  resetTableState();

  // Read potentiometers
  potBrightness = analogRead(A1);
  potColor = analogRead(A2);
  potDelay = analogRead(A3);
  potMisc = analogRead(A4);

  // Serial.print("Brightness: ");
  // Serial.println(potBrightness);
  // Serial.print("Color: ");
  // Serial.println(potColor);
  // Serial.print("Delay: ");
  // Serial.println(potDelay);
  // Serial.print("Misc: ");
  // Serial.println(potMisc);


  brightness = (int)(((float)potBrightness /1023) * 200);
  color = potToCHSV(potColor);
  secondaryColor = potToCHSV(potMisc);



  // Manage up button press
  currentUpState = readButton(5);
  upStateChange = checkForChange(currentUpState, lastUpState);
  if (upStateChange && currentUpState){
    sequence = cycleCounter(sequence, false);
    FastLED.clear();
    tableState = 0;
  }
  lastUpState = currentUpState;

  // Manage down button press
  currentDownState = readButton(4);
  downStateChange = checkForChange(currentDownState, lastDownState);
  if (downStateChange && currentDownState){
    sequence = cycleCounter(sequence, true);
    FastLED.clear();
    tableState = 0;
  }
  lastDownState = currentDownState;

  // Run effects
switch (sequence) {
  case 0: // Solid
    still(color);
    break;
  case 1: // Forth color light (sawblade effect)
    colorWipe(color, (int)(((float)potDelay /1023) * 20), (int)(((float)potMisc / 1023) * 20));
    break;
  case 2: // Back and forth color light (sinusoide effect)
    backAndForth(color, (int)(((float)potDelay /1023) * 20), (int)(((float)potMisc / 1023) * 20));
    break;
  case 3: // Rainbow
    rainbow(color, secondaryColor);
    break;
  case 4: // Moving Rainbow
    movingRainbow((int)(((float)potDelay /1023) * 50), (int)(((float)potColor /1023) * 255));
    break;
  case 5: // Random colors generated by sine waves
    sinelon(color, (int)(((float)potDelay / 1023) * 50)); // TODO: Control parameters (colors, speed and fading)
    break;
  // case 4: //
  //   bpm(color); 
  //   break;


}

  // FastLED.setBrightness((int)(((float)potBrightness /1023) * 255));
  FastLED.show();
}

void resetTableState() {
  if (tableState >= 223) {
    tableState = 0;
  }
}