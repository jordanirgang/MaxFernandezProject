#pragma once
#include <Arduino.h>
#include <IFeedback.h>
#define MIN_ANGLE 0
#define MAX_ANGLE 180

template <typename U> class PotFeedback : public IFeedbackAngle<U> {
private:
public:
  U _angle;
  int _readPin;

  int minVoltage = 0;
  int maxVoltage = 255;

  PotFeedback() : IFeedbackAngle<U>() {}
  PotFeedback(const int &wiperPin) : IFeedbackAngle<U>() {
    _readPin = wiperPin;
  }

  void SetUp(const int wiperPin) { _readPin = wiperPin; }

  void SetAngle(U angle) {
    // update pot value map
    _angle = map(angle, minVoltage, maxVoltage, MIN_ANGLE, MAX_ANGLE);
  }
  void SetAngle() {
    // update pot value map
    _angle = analogRead(_readPin);
    SetAngle(_angle);
  }

  U GetAngle() { return _angle; }
};
