#pragma once

template <typename T> class IController {
public:
  virtual void ControlSignal(T &signalIO, T &error, T &timestep);
};
