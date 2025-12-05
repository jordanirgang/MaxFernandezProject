#pragma once
#include <Arduino.h>

#define FORWARD false
#define BACKWARD true
#define DUTYCYCLE_MAX 26000
#define DUTYCYCLE_MIN 1000
#define VOLTAGE_MAX 255
#define VOLTAGE_MIN 0

class Nidec24Motor
{
  private:
    bool _direction = FORWARD;
    int _brakePin;
    int _directionPin;
    int _enablePin;
    int _ctlPin; 
  public:
    float speedVirtualOut = 0;
    bool isPWM = false;//implies PFM/tone function
                       //CON

    Nidec24Motor(const int& ctl,const int& brake,const int& direction,const int& enable);
    Nidec24Motor();
    void Drive(float speed);
    

};
