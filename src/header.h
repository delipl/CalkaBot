#include <Arduino.h>

#define disL PB11
#define disR PB10
#include "distance.h"
#include "accelerometer.h"

#define PWMA    PA1
#define Ma2     PA2
#define Ma1     PA3
#define STBY    PA4
#define Mb1     PA5
#define Mb2     PA6
#define PWMB    PA7
void initMotor();

#include "motor.h"

#define LED PC13
#define encoder A0