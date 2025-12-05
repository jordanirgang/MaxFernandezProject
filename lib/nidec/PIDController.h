#pragma once
#include <IController.h>

template <typename U> class PIDController : public IController<U> {
private:
  U _error[1] = {0};

public:
  // set gains
  U kp = 0;
  U ki = 0;
  U kd = 0;
  PIDController() : IController<U>() {}

  void ControlSignal(U &signalIO, U &error, unsigned long timestep) {
    signalIO = kp * error +
               ki * (error + this->_error[0]) * static_cast<U>(timestep) -
               kd * (error - this->_error[0]) / static_cast<U>(timestep);
    _error[0] = signalIO;
  }
};
