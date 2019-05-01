#include "Keyboard.h"

int key1 = 3;
int key2 = 4;
int key3 = 2;
int key4 = 7;
int key5 = 6;
int key6 = 10;

bool pressed1 = false;
bool pressed2 = false;
bool pressed3 = false;
bool pressed4 = false;
bool pressed5 = false;
bool pressed6 = false;

int deBounceDelay = 0;
int deBounceCount = 50;


// keys config
int getKeyToPrint(int key) {
  if(key == key1){
    return KEY_F7;
  }
  if(key == key2){
    return KEY_F8;
  }
  if(key == key3){
    return KEY_F9;
  }
  if(key == key4){
    return KEY_F10;
  }
  if(key == key5){
    return KEY_F11;
  }
  if(key == key6){
    return KEY_F12;
  }
}


void setup() {
  // set up keys
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
  pinMode(key5, INPUT_PULLUP);
  pinMode(key6, INPUT_PULLUP);

  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}


bool getKeyPressed(int key) {
  if(key == key1){
    return pressed1;
  }
  if(key == key2){
    return pressed2;
  }
  if(key == key3){
    return pressed3;
  }
  if(key == key4){
    return pressed4;
  }
  if(key == key5){
    return pressed5;
  }
  if(key == key6){
    return pressed6;
  }
}

void setKeyPressed(int key, bool val) {
  if(key == key1){
    pressed1 = val;
  }
  if(key == key2){
    pressed2 = val;
  }
  if(key == key3){
    pressed3 = val;
  }
  if(key == key4){
    pressed4 = val;
  }
  if(key == key5){
    pressed5 = val;
  }
  if(key == key6){
    pressed6 = val;
  }
}


bool checkKey(int key) {
  int  val = digitalRead(key);

  if(val == LOW){
    if(getKeyPressed(key) == false){
      deBounceDelay = deBounceCount;
      String str = String(key);
      Keyboard.press(getKeyToPrint(key));
      setKeyPressed(key, true);
    }
  } else {
    if(deBounceDelay == 0){
      setKeyPressed(key, false);
    }
  }
}

void loop() {

  checkKey(key1);
  checkKey(key2);
  checkKey(key3);
  checkKey(key4);
  checkKey(key5);
  checkKey(key6);


  if(deBounceDelay > 0){
    deBounceDelay -= 1;
  }

//  delay(5);
  Keyboard.releaseAll();
}


