#pragma once

template <typename T> class IController {
public:
  IController() {}
  virtual void ControlSignal(T &signalIO, T &error, unsigned long timestep) {}
};
