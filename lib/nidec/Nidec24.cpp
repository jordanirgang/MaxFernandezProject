#include <IController.h>
#include <IFeedback.h>
#include <Nidec24.h>
IController<float> _controlK;        // digital ctl system
IFeedbackAngle<float> _measurementK; // a2d converted feedback system
Nidec24Motor _outputK;               // output to motor
Nidec24::Nidec24() {}

Nidec24::Nidec24(Nidec24Motor *motor, IFeedbackAngle<float> *feedback,
                 IController<float> *ctlSys) {
  _controlK = ctlSys;
  _measurementK = feedback;
  _outputK = motor;
}
// this should run in loop
void Nidec24::MatchSetPoint(float &setPoint, unsigned long &deltaT) {
  float angleError = setPoint - _measurementK->GetAngle();
  _controlK->ControlSignal(_motorSpeed, angleError, deltaT);
  _outputK->Drive(_motorSpeed);
}

void Nidec24::MatchSetPoint(float &setPoint) {
  _timeCurrent = millis();
  float angleError = setPoint - _measurementK->GetAngle();
  _controlK->ControlSignal(_motorSpeed, angleError, _timeCurrent - _timeOld);
  _outputK->Drive(_motorSpeed);
  _timeOld = _timeCurrent;
};
