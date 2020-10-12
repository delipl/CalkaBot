#include <VL53L0X.h>
int quan = 2;
VL53L0X sensor[2];

void distanceInit(int index) {
    if (!sensor[index].init())
    {
        //print("Failed to detect and initialize sensor!");
        while (1) {}
    } 
    sensor[index].startContinuous();
}
int getDistance(int index){
    return sensor[index].readRangeContinuousMillimeters();
}