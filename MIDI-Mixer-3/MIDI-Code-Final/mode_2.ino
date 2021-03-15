//button and potentiometer setup
boolean synLit = false;
boolean synB[] = {false, false, false, false, false, false, false, false};
int state1Pots[] = {0, 0, 0, 0};
int state1PotsTol = 5;

//checks button States
void mode3() {

  if (!synLit) {
    strip.setPixelColor(3, 0, 0, 255);
    strip.setPixelColor(7, 150, 0, 255);
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(4, 255, 0, 0);
    strip.setPixelColor(5, 255, 0, 0);
    strip.setPixelColor(6, 255, 0, 0);
    strip.show();
    synLit = true;
  }

  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      Serial.print(i);
      synB[i] = !synB[i];
      if (synB[i]) {
        usbMIDI.sendControlChange(i + 50, 127, 1);
      } else {
        usbMIDI.sendControlChange(i + 50, 0, 1);
      }
    }
    if (buttonStates[i] == 1 && i == 3 ) {
      mode = 1;
      synLit = false;
    }
    if (buttonStates[i] == 1 && i == 7 ) {
      mode = 2;
      synLit = false;
    }
  }

  //checks potentiometer States
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - state1Pots[i]) > state1PotsTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      state1Pots[i] = thisPot;
    }
  }
}
