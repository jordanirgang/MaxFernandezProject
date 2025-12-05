#include <Arduino.h>
#include <Nidec24Motor.h>

void Nidec24Motor::Drive(float speed )
{
  speedVirtualOut = speed;
  this->_direction = speed >= 0;
  digitalWrite(_directionPin,this->_direction);
  digitalWrite(_brakePin,LOW);

  float frequency = map(abs(speed),VOLTAGE_MIN,VOLTAGE_MAX,DUTYCYCLE_MIN,DUTYCYCLE_MAX);
  if(isPWM)
  {
    float dutyCycle = 1/frequency;
    Serial.println("dutyCycle");
    Serial.println(dutyCycle);
    analogWrite(_ctlPin, dutyCycle); // Write the PWM value
  }else
  {
    Serial.println("freq");
    Serial.println(frequency);
    tone(_ctlPin,frequency);
  }

}


Nidec24Motor::Nidec24Motor(const int& ctl,const int& brake,const int& direction,const int& enable)
{
  this->_brakePin = brake;
  this->_directionPin = direction;
  this->_enablePin = enable;
  this->_ctlPin = ctl;

  digitalWrite(_enablePin,HIGH);
}
    
Nidec24Motor::Nidec24Motor(){}

