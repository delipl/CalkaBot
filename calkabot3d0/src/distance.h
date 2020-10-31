#include <VL53L0X.h>
int quan = 2;
VL53L0X sensor[2];

void initDistance(int index) {
    if (!sensor[index].init())
    {
        //print("Failed to detect and initialize sensor!");
        while (1) {}
    } 
    sensor[index].startContinuous();\

    pinMode(disL, INPUT);
    pinMode(disR, INPUT);
}
int getDistance(int index){
    return sensor[index].readRangeContinuousMillimeters();
}

