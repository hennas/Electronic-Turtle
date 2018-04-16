#include "pitches.h"
int a;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() { 
  while(a < 16) {
    //1244
    for(int i = 440; i <= 1244; i=i+12) {
      tone(3, i);
      delay(3); 
    }
    //1243
    for(int i = 1245; i > 440; i=i-12) {
      tone(3, i);
      delay(3);
    }
    a++;
  }
  a = 4;
  while(a > 0) {
    tone(3, 622);
    delay(765);
    tone(3, 440);
    delay(765);
    a--; 
  }
}
