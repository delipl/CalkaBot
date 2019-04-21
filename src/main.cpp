#include "header.h"
#include "program0.h"

void setup(){
	//pin mode
	pins();

	//turning on boarD
	builtLed1_ON;
	for (int i = 0; i < 5; ++i){
		delay(100);
		builtLed1_TOG;
    builtLed2_TOG;
	}
	builtLed1_OFF;
	builtLed2_OFF;
	delay(1000);


	//====================switch checking===================\\

	if(PINF & but1) program++;
	if(PINF & but2) program+=2;
	if(PINF & but3) program+=4;   //not sure if it work like this (propably not deli do sth with this XD)

	//========================================================\\

//start
//!(PINF & but1) ? full=255 : full=200;
	goBackward(full, full);
}


void loop(){

	switch(program){
		case 0:
			program0();
			break;
		case 1:
			program0();
			break;
		case 2:
			program0();
			break;
		case 3:
			program0();
			break;
		case 4:
			program0();
			break;
		case 5:
			program0();
			break;
		case 6:
			program0();
			break;
		case 7:
			program0();
			break;
		default:
			error(1);
			break;
	}

}

	/*//edge checker
	if(!edgeA){
		goBack(full, full);
	p++;
	}
	else if(!edgeAL){
		goBack(full, full);
		//delay(500);
			p++;
	}
	else if(!edgeAR){
		goBack(full, full);
		//delay(500);
		p++;
	}
	else if(!edgeB){
		go(full,full);
		p++;
	}
	else if(!edgeBL){
		go(full, full);
		//delay(500);
			p++;
	}
	else if(!edgeBR){
		go(full, full);
		//delay(500);
			p++;
	}
	/*if(p > 2){
		hardStop();
	}*/
	/*
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
	}*/
	//else 										go(full, full);*/
