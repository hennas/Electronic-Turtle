void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(50);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  delay(50);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
}
