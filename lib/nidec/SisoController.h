#pragma once
#include <IController.h>
template <typename U> class SisoController : public IController<U> {
private:
  U _errorHistory[4] = {0, 0, 0, 0};     // k-1,k-2,k-3,k-4
  U _signalOutHistory[4] = {0, 0, 0, 0}; // k-1,k-2,k-3,k-4

public:
  SisoController() : IController<U>() {}

  void ControlSignal(U &signalIO, U &error, unsigned long timestep) {
    signalIO = 79.704596889501 * _signalOutHistory[2] +
               4.79046574041161044 * _signalOutHistory[1] +
               78.488404271079673 * _signalOutHistory[0] +
               44.64437764121889 * _signalOutHistory[3] -
               .5888626843152447998 * _errorHistory[3] +
               .0894139572582 * _errorHistory[2] -
               1.5761261928506509 * _errorHistory[1] -
               .102150448722832 * _errorHistory[0] + error * 1;

    signalIO = signalIO / 58.06097540616;
  }
};
