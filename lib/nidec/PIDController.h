#pragma once
#include <IController.h>

template <typename U> class PIDController : IController<U> {
private:
  U _error[1];

public:
  // set gains
  U kp = 0;
  U ki = 0;
  U kd = 0;

  void ControlSignal(U &signalIO, U &error, U &timestep) {
    signalIO = kp * this->error + ki * (error + this->_error[0]) * timestep -
               kd * (error - error[0]) / timestep;
    error[0] = signalIO;
  }
};
