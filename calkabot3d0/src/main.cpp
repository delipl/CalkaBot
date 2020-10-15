#include "header.h"
void setup(){
  Serial.begin(115200);
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      //to read me in variant.h change i2c pins
      Wire.begin();
      Wire.setClock(400000); 
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
  #endif

  //wait for Serial connection
  while(Serial.available()){
    Serial.println("");
  }
  delay(2200);
  Serial.println("Połączono...");
  initGyro();
}
void loop(){
  printGyro();
  
  delay(100);
}