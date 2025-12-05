#pragma once
#include <IController.h>

template <typename U> class NidecController : IController<U> {
public:
  void ControlSignal(U &signalIO, U &error, U &timestep) {
    signalIO = signalIO * error;
  }
};
