#include <Servo.h>     
Servo myservo;          
 
      
int servoPin = 8;       
int i = 0;
int Status = 0;

void setup ()
{
    myservo.attach(servoPin); 
    Serial.begin(9600); 
}
void loop() {

  
    if(Status == 0)
    {
      myservo.write(i);
      if(i == 180)
          Status = 1;
      i = i + 1;
    }
    else
    {
     myservo.write(i);
      if(i == 0)
          Status = 0;
      i = i - 1;
    }
    
    Serial.println(i);
    delay(100);
}
