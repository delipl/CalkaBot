#include "Arduino.h"
#include "../lib/IRremote/IRremote.h"

IRrecv irrecv(8);
decode_results results;

//distance sensor front
#define sensorF 0
#define sensorFL 3
#define sensorFR 2
#define sensorB 7
#define sensorBL 1
#define sensorBR 4

#define floorBL 13
#define floorBR 12
#define floorFL 11
#define floorFR 10		//nie jestem pewny czy dobrze są lewy prawy ale to nieważne

//motor

#define AIN1 12
#define AIN2 13
#define BIN1 10
#define	BIN2 11

void error(int errorNr){
	digitalWrite(AIN1, 0);
	digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 0);

	while(true){
		for (int i = 0; i < errorNr; ++i){
			digitalWrite(9,LOW);
			delay(200);
			digitalWrite(9,HIGH);
			delay(200);
		}
		delay(2000);
	}
}

bool floorFront(){
//	if(analogRead(floorFL)>10||analogRead(floorFR)>10) retirn 1;
	return 0;
}

bool floorBack(){
//	if(analogRead(floorBL)>10||analogRead(floorBR)>10) retirn 1;
	return 0;
}

bool floor(){
	if(floorFront()||floorBack())return 1;
	return 0;
}

void slowStop(){
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 0);
}

void hardStop(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
}

void goForward(){
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
}

void goBackward(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
}

void go(int x, bool direction){ //0-full; 1-optimal; 2-left; 3-right
	if(x==0){
		direction?goForward():goBackward();
	}
	else if(x==1){
		if(direction){
			goForward();
			delay(1);
			slowStop();
			delay(3);
		}else{
			goBackward();
			delay(1);
			slowStop();
			delay(3);
		}
	}else if(x==2){
		if(direction){
			slowStop();
			digitalWrite(AIN2, 1);
			delay(1);
		}else{
			slowStop();
			digitalWrite(BIN1, 1);
			delay(1);
		}
	}else if(x==3){
		if(direction){
			slowStop();
			digitalWrite(BIN2, 1);
			delay(1);
		}else{
			slowStop();
			digitalWrite(AIN1, 1);
			delay(1);
		}
	}

}

void spin(){
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
    delay(1);
    slowStop();
    delay(1);
}

byte irRemoute ()
{
byte dane=0;
  while(dane==0)
{
   if (irrecv.decode(&results)) // sprawdza, czy otrzymano sygna� IR
{
       unsigned long odczyt = results.value; // sygnał zapisuje jako odczyt
switch (odczyt)
       {
case 1857: //power
  dane = 1;
break;
case 3905: //eneter
	dane = 1;
break;
case 16711935: //eneter
	dane = 1;
break;
case 3785549847:
	dane = 1;
break;

default:
         dane=0;
}
      irrecv.resume(); // reseruje czujnik
}
   else
{
    dane=0;
}
  }
return dane ;
}
