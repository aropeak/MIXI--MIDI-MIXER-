void startUp() {

  int delayVal = 100;

  //clears neopixels
  strip.clear();
  strip.show();

  //startup animation;

  //sets pixels purple
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 150, 0, 255);
    strip.show();
    delay(delayVal);
  }
  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, 150, 0, 255);
    strip.show();
    delay(delayVal);
  }

  //sets pixels blue
    for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(delayVal);
  }
  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(delayVal);
  }

  //sets pixels red
    for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(delayVal);
  }
  for (int i = 4; i < 8; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(delayVal);
  }

  mode = 1;
}
