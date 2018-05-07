#include <TimerOne.h>

int ledPin_1 = 6;
int ledPin_2 = 7;
int ledPin_3 = 8;
int buzzerPin = 13;
int i = 440;

volatile unsigned long buzzerCounter = 0;
volatile unsigned long ledCounter = 0;
volatile boolean soundState = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  Timer1.initialize(6000);
  Timer1.attachInterrupt(counters);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(ledCounter == 0) {
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, HIGH);
    digitalWrite(ledPin_3, LOW);
  }
  if(ledCounter == 17) {
    digitalWrite(ledPin_2, LOW);
  }
  if(ledCounter == 26) {
    digitalWrite(ledPin_2, HIGH);
  }
  if(ledCounter == 43) {
    digitalWrite(ledPin_1, HIGH);    
    digitalWrite(ledPin_2, LOW);
    digitalWrite(ledPin_3, HIGH); 
  }
  if(ledCounter == 60) {
    digitalWrite(ledPin_1, LOW);
  }
  if(ledCounter == 69) {
    digitalWrite(ledPin_1, HIGH);
  }
  if(ledCounter == 86) {
    ledCounter = 0;
  }
  
  if(buzzerCounter >= 1 && soundState == true) {
    tone(buzzerPin, i);
    i += 24;
    buzzerCounter = 0;
    if(i >= 1256) {
      soundState = !soundState;
    }
  }

  if(buzzerCounter >= 1 && soundState == false) {
    tone(buzzerPin, i);
    i -= 24;
    buzzerCounter = 0;
    if(i <= 440) {
      soundState = !soundState;
    }
  }
}

int counters() {  
  ledCounter++;
  buzzerCounter++;
  return ledCounter, buzzerCounter;
}

