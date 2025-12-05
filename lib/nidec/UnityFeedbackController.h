#pragma once
#include <IController.h>

template <typename U> class UnityFeedbackController : public IController<U> {
public:
  void ControlSignal(U &signalIO, U &error, unsigned long &timestep) {
    signalIO = signalIO * error;
  }
};
