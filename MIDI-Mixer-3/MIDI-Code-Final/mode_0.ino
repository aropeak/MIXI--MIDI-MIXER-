//button and potentiometer setup
boolean drumLit1 = false;
boolean drumB1[] = {false, false, false, false, false, false, false, false};
int drumPots1[] = {0, 0, 0, 0};
int drumPotsTol1 = 5;

//checks button States
void mode1() {

  if (!drumLit1) {
    strip.setPixelColor(3, 150, 0, 255);
    strip.setPixelColor(7, 255, 0, 0);
    strip.setPixelColor(0, 0, 0, 255);
    strip.setPixelColor(1, 0, 0, 255);
    strip.setPixelColor(2, 0, 0, 255);
    strip.setPixelColor(4, 0, 0, 255);
    strip.setPixelColor(5, 0, 0, 255);
    strip.setPixelColor(6, 0, 0, 255);
    strip.show();
    drumLit1 = true;
  }

  for (int i = 0; i < 8; i++) {
    if (buttonStates[i] == 1 && i != 3 && i != 7) {
      Serial.print(i);
      drumB1[i] = !drumB1[i];
      if (drumB1[i]) {
        usbMIDI.sendControlChange(i, 127, 1);
      } else {
        usbMIDI.sendControlChange(i, 0, 1);
      }
    }
    if (buttonStates[i] == 1 && i == 3 ) {
      mode = 2;
      drumLit1 = false;
    }
    if (buttonStates[i] == 1 && i == 7 ) {
      mode = 3;
      drumLit1 = false;
    }
  }

  //checks potentiometer States
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - drumPots1[i]) > drumPotsTol1) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      drumPots1[i] = thisPot;
    }
  }
}
