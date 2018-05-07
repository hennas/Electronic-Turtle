#include <LiquidCrystal.h>

const int pins[] = {6, 7, 8};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;
const int echoPin = 10;
int distanceCm, distanceInch;

void setup() {
  for(int i = 0; i <= 2; i++) {
    pinMode(pins[i], OUTPUT);
  }
  
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  float distance1 = sonicRead();
  unsigned long t1 = micros();
  delay(100);
  float distance2 = sonicRead();
  unsigned long t2 = micros();
  float v = ((distance2 - distance1) * 1.0 / (t2 - t1) * 10000) * 3.6;
    
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance2);
  lcd.print("       ");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(v);
  lcd.print("          ");
  delay(10); 

  if(abs(v) > 10 ) {
     flash();
     buzzer();
  }
}

float sonicRead ()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  unsigned long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void flash(void) {
  for(int i = 0; i <= 7; i++) {
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[2], LOW);
    delay(100);
  
    digitalWrite(pins[1], LOW);
    delay(50);
    digitalWrite(pins[1], HIGH);
    delay(100);
    
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], LOW);
    digitalWrite(pins[2], HIGH);
    delay(100);
  
    digitalWrite(pins[2], LOW);
    delay(50);
    digitalWrite(pins[2], HIGH);
    delay(100);
  }
  for(int i = 0; i <= 2; i++) {
    digitalWrite(pins[i], LOW);
  }  
}

void buzzer(void) {
  int a;

  while(a < 16) {
    for(int i = 440; i <= 1244; i=i+12) {
      tone(13, i);
      delay(3); 
    }
    for(int i = 1245; i > 440; i=i-12) {
      tone(13, i);
      delay(3);
    }
    a++;
  }
  a = 4;
  while(a > 0) {
    tone(13, 622);
    delay(765);
    tone(13, 440);
    delay(765);
    a--; 
  }
  noTone(13);
}

