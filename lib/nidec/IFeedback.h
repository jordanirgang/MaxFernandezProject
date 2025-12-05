#pragma once

template <typename T> class IFeedbackAngle {
public:
  IFeedbackAngle() {}
  virtual T GetAngle();
  virtual void SetAngle(T);
};
