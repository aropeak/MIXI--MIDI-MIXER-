//button setup
#include <Bounce2.h>
int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
Bounce * buttons = new Bounce[8];

//potentiometer setup
int potPins[] = {A0, A1, A2, A3};

//neopixel setup
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);

int mode = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  delay(2000);
  Serial.println("Ready!");
}



void loop() {
  //updates buttons and displays them in the serial monitor
  updateButtons();
  printButtons();
  updatePots();
  printPots();
  delay(100);

  switch(mode) {
    case 0: startUp(); break;
    case 1: mode1(); break;
    case 2: mode2(); break;
    case 3: mode3(); break;
  }

}
