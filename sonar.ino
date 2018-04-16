#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 9;
const int echoPin = 10;
int distanceCm, distanceInch;
void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
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
  float v = (distance2 - distance1) * 1.0 / (t2 - t1) * 10000;
   
  Serial.println(v);
  delay(100);
    
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distance1); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(v);
  lcd.print(" ");
  delay(10); 
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
