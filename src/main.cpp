#include <Arduino.h>
#include <Nidec24.h>
#include <Nidec24Motor.h>
#include <PIDController.h>
#include <PotentiometerFeedback.h>

#define ENABLE_MOTOR 1
#define BRAKE 3
#define DIRECTION 2
#define CTL 0

#define POT 4

Nidec24Motor myMotor;
PotFeedback<float> myPot(POT);
PIDController<float> myController;

Nidec24 myNidecMotorSys;

void setup() {
  pinMode(ENABLE_MOTOR, OUTPUT);
  pinMode(BRAKE, OUTPUT);
  pinMode(DIRECTION, OUTPUT);
  pinMode(CTL, OUTPUT);
  myMotor = Nidec24Motor(CTL, BRAKE, DIRECTION, ENABLE_MOTOR);
  myMotor.isPWM = false;
  // TODO: move to unit tests
  //  myNidec.Drive(255);
  Serial.begin(115200);

  myNidecMotorSys = Nidec24(&myMotor, &myPot, &myController);
}

void loop() {
  // TODO:move to unit tests
  /* for (int i = 0; i <= 255; i += 5) {
     Serial.println(i);
     myNidec.Drive(i);
     delay(500);
   }
   */
}
