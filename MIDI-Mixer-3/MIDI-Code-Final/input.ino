//button and potentiometer setup
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
int potStates[] = {0, 0, 0, 0};

//given function, initializes buttons and potentiometers
void initializeButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(25);  
  }
}
void updateButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].update();
    if(buttons[i].rose()){buttonStates[i] = 1;}
    else{buttonStates[i] = 0;}
  }
}
void printButtons(){
  for (int i = 0; i < 8; i++){
    int thisButton = buttonStates[i];
    Serial.print(thisButton);
    Serial.print("\t");
  }  
  //Serial.println();
}
void updatePots(){
  for (int i = 0; i < 4; i++){
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}
void printPots(){
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    Serial.print(thisPot);
    Serial.print("\t");
  }  
  Serial.println();
}
