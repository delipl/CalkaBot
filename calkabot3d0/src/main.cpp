#include "header.h"
void setup(){
  Serial.begin(9600);
  while(!Serial.available()){
    Serial.println();
  }
  Serial.println("Połączono...");
  delay(500);
}
void loop(){

}