#include <Arduino.h>
#include <NIDEC_24.h>
#define ENABLE_MOTOR 1
#define BRAKE 3
#define DIRECTION 2
#define CTL 0


 Nidec24Motor myNidec;
void setup()
{
  pinMode(ENABLE_MOTOR,OUTPUT);
  pinMode(BRAKE,OUTPUT);
  pinMode(DIRECTION,OUTPUT);
  pinMode(CTL,OUTPUT);
  myNidec = Nidec24Motor(CTL,BRAKE,DIRECTION,ENABLE_MOTOR);
  myNidec.isPWM = false;
  myNidec.Drive(255);
  Serial.begin(115200);

}

void loop()
{
  for(int i = 0; i <= 255; i+=5)
  {
    Serial.println(i);
    myNidec.Drive(i);
    delay(500);
  }

}

