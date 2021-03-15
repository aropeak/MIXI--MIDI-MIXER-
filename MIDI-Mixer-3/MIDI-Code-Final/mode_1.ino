//button and potentiometer setup
boolean drumLit = false;
boolean drumB[] = {false, false, false, false, false, false, false, false};
int drumPots[] = {0, 0, 0, 0};
int drumPotsTol = 5;

//checks button States
void mode2() {

  if (!drumLit) {
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(0, 150, 0, 255);
    strip.setPixelColor(1, 150, 0, 255);
    strip.setPixelColor(2, 150, 0, 255);
    strip.setPixelColor(4, 150, 0, 255);
    strip.setPixelColor(5, 150, 0, 255);
    strip.setPixelColor(6, 150, 0, 255);
    strip.show();
    drumLit = true;
  }

  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      Serial.print(i);
      drumB[i] = !drumB[i];
      if (drumB[i]) {
        usbMIDI.sendControlChange(i + 20, 127, 1);
      } else {
        usbMIDI.sendControlChange(i + 20, 0, 1);
      }
    }
    if (buttonStates[i] == 1 && i == 3 ) {
      mode = 1;
      drumLit = false;
    }
    if (buttonStates[i] == 1 && i == 7 ) {
      mode = 3;
      drumLit = false;
    }
  }

  //checks potentiometer States
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - drumPots[i]) > drumPotsTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      drumPots[i] = thisPot;
    }
  }
}
