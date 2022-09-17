#line 1 "c:\\Users\\Stephane\\Documents\\Arduino\\LEDController\\inputs.cpp"
#include "inputs.h"

unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 30;

bool oldDidState = false;
bool didState = false;

CHSV potToCHSV(int pot) {
  CHSV color;

  // Useless, we will now use HSV colors
  // if (pot < 1023/3 ) {
  //   R = 255 - (int)(((float) pot / (1023/3)) * 255);
  //   G = (int)(((float) pot / (1023/3)) * 255);
  //   B = 0;
  // }
  // if (pot >= 1023/3 && pot < 2*1023/3) {
  //   R = 0;
  //   G = 255 - (int)(((float) (pot - (1023/3)) / (1023/3)) * 255);
  //   B = (int)(((float) (pot - (1023/3)) / (1023/3)) * 255);
  // }
  // if (pot >= 2*1023/3) {
  //   R = (int) (int)(((float) (pot - (1023/3) * 2) / (1023/3)) * 255);
  //   G = 0;
  //   B = 255 - (int) (int)(((float) (pot - (1023/3) * 2) / (1023/3)) * 255);
  // }

  color = CHSV((int)(((float)pot /1023) * 255), 255, brightness);

  return color;
}


bool readButton(int pin) {
  bool state = digitalRead(pin);
  if (state != oldDidState){
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) >= debounceDelay){
    didState = state;
    return state;
  }
  oldDidState = state;
}

bool checkForChange(bool current, bool last) {
  bool change;
  if (current != last) {
    change = true;
  }
  else {
    change = false;
  }
  return change;
}

int cycleCounter(int sequence, bool reverse) {
  isInitialized = false;
  if (reverse == true)
  {
    sequence--;
  }
  else{
    sequence++;
  }
  if (sequence > (EFFECTS_NUM - 1)) {
    sequence = 0;
  }
  if (sequence < 0) {
    sequence = EFFECTS_NUM - 1;
  }
  return sequence;
}
