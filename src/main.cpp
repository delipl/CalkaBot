#include "header.h"
#include "motor.h"
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

	//switch checking
	if(!status_but1) program++;
	if(!status_but2) program+=2;
	if(!status_but3) program+=4;
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
