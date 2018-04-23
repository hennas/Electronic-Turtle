
const long tickTime = 3;
unsigned long previousMillis = millis();
int i = 440;

boolean soundState = true;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= tickTime) {
    previousMillis = currentMillis;

    if(soundState == true) {
      tone(3, i);
      i = i + 12;

      if(i >= 1240) {
        soundState = !soundState;
      }
    }  
         
    if(soundState == false) {
      tone(3, i);
      i = i - 12;
      
      if(i <= 440) {
        soundState = !soundState;
      }
    }     
  }
 
}

