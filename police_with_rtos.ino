#include <Arduino_FreeRTOS.h>

int a;

// define tasks
void TaskBlink1( void *pvParameters );
void TaskBlink2( void *pvParameters );
void TaskSiren( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskBlink1
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskBlink2
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskSiren
    ,  (const portCHAR *)"Siren"   // A name just for humans
    ,  256  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );  

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlink1(void *pvParameters) 
{
  (void) pvParameters;

  pinMode(2, OUTPUT);

  for (;;) 
  {
    digitalWrite(2, HIGH);   
    vTaskDelay( 100 / portTICK_PERIOD_MS ); 
    digitalWrite(2, LOW);    
    vTaskDelay( 50 / portTICK_PERIOD_MS ); 
    digitalWrite(2, HIGH);   
    vTaskDelay( 100 / portTICK_PERIOD_MS ); 
    digitalWrite(2, LOW);    
    vTaskDelay( 200 / portTICK_PERIOD_MS ); 
  }
}

void TaskBlink2(void *pvParameters) 
{
  (void) pvParameters;

  pinMode(5, OUTPUT);

  for (;;) 
  {
    digitalWrite(5, HIGH);   
    vTaskDelay( 200 / portTICK_PERIOD_MS ); 
    digitalWrite(5, LOW);    
    vTaskDelay( 200 / portTICK_PERIOD_MS ); 
  }
}

void TaskSiren(void *pvParameters)  
{
  (void) pvParameters;

  //pinMode(3, OUTPUT);

  for(;;) 
  {    
    while(a < 16) {
      
      for(int i = 440; i <= 1244; i=i+12) {
        tone(3, i);
        //delay(3);
        vTaskDelay( 1 ); 
      }
      //1243
      for(int i = 1245; i > 440; i=i-12) {
        tone(3, i);
        //delay(3);
        vTaskDelay( 16 / portTICK_PERIOD_MS );
      }
      a++;
    }
    
    a = 4;
    while(a > 0) {
      tone(3, 622);
      //delay(765);
      vTaskDelay( 765 / portTICK_PERIOD_MS );
      tone(3, 440);
      //delay(765);
      vTaskDelay( 765 / portTICK_PERIOD_MS );
      a--; 
    }
  }
}


