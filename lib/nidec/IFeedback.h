#pragma once

template <typename T> class IFeedbackAngle {
public:
  T value;
  IFeedbackAngle() {}
  virtual T GetAngle() { return value; }
  virtual void SetAngle(T) {}
};
