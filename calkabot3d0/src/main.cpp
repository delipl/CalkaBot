#include "header.h"
void setup(){
  Serial.begin(115200);
  while(!Serial.available()){
    Serial.println();
  }
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      Wire.begin();
      Wire.setClock(400000); 
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
  #endif

  Serial.println("Połączono...");
  initGyro();
}
void loop(){
  printGyro();
  delay(100);
}