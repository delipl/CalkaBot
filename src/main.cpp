#include "header.h"

void setup(){
	//turning on boarD
	for (int i = 0; i < 5; ++i){
		delay(100);
		builtLed1_TOG;
    builtLed2_TOG;
	}

//pin mode
pins();

//start
go(full, full);
}

void loop(){
	//edge checker
	if(!edgeA)							goBack(full, full);
	else if(!edgeAL) 				goBack(full, half);
	else if(!edgeAR)				goBack(half, full);
	else if(!edgeB)					go(full, full);
	else if(!edgeBL) 				go(full, half);
	else if(!edgeBR)				go(half, full);

	//straight attack
	else if(!IRa)						go(full, full);
	else if(!IRb)						goBack(full, full);

	//take a enemy
	else if(!IRaR){
		while(IRa || floorSensors())	go(full, 0);
	}
	else if(!IRaL){
		while(IRa || floorSensors())	go(0, full);
	}
	else if(!IRbR){
		while(IRb || floorSensors())	goBack(full, 0);
	}
	else if(!IRbL){
		while(IRb || floorSensors())	goBack(0, full);
	}
	else 										go(full, full);
}
