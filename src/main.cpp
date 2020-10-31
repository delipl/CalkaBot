#include "header.h"

void setup(){

	irrecv.enableIRIn();
	//czujniki odległości
	pinMode(sensorF, INPUT);
	pinMode(sensorFL, INPUT);
	pinMode(sensorFR, INPUT);
	pinMode(sensorB, INPUT);
	pinMode(sensorBR, INPUT);
	pinMode(sensorBL, INPUT);

	//silnik
	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);

	//Led
	pinMode(9, OUTPUT);
	digitalWrite(9,HIGH);

	for(int i = 0; i < 5; i++){
		digitalWrite(9, 0);
		delay(100);
		digitalWrite(9, 1);
		delay(100);
	}
}



void loop(){
bool play=1;
byte check = irRemoute();
 if (check != 0)
{
	play=1;
  // Tutaj podajemy co ma wykonać dalej z zmienną check jeżeli nie jest ona zerem
}
//play=1;
while(play){//nzfs
		while (true){
			if(!floor()){
				while(digitalRead(sensorB)==0) go(0, 0);
				while(digitalRead(sensorF)==0) go(0, 1);
				if(digitalRead(sensorFR)==0) go(3, 1);
				else if(digitalRead(sensorFL)==0) go(2, 1);
				else if(digitalRead(sensorBR)==0) go(3, 0);
				else if(digitalRead(sensorBL)==0) go(2, 0);
				else spin();
			}else if(floorFront()){
				go(0, 0);
				delay(100);
			}else if(floorBack()){
				go(0, 1);
				delay(100);
			}
		}
 	}

}
