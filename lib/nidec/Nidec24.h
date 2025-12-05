#pragma once
#include <IController.h>
#include <IFeedback.h>
#include <Nidec24Motor.h>
class Nidec24 {
private:
  IController<float> *_controlK;        // digital ctl system
  IFeedbackAngle<float> *_measurementK; // a2d converted feedback system
  Nidec24Motor *_outputK;               // output to motor
  float _motorSpeed = 0;                // dont rotate
  unsigned long _timeCurrent = 0;
  unsigned long _timeOld = 0;

public:
public:
  Nidec24();
  //~Nidec24();
  Nidec24(Nidec24Motor *motor, IFeedbackAngle<float> *feedback,
          IController<float> *ctlSys);
  void MatchSetPoint(float &setPoint, unsigned long &deltaT);
  void MatchSetPoint(float &setPoint);
};
