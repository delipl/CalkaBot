#include <Arduino.h>

uint8_t full 		= 255;
uint8_t optimal = 200; //max speed, not to fligh away from ring
uint8_t half 		= 180;
uint8_t program = 0x0;
bool first 			= 0b1;		//first loop after start
bool shown 			= false;
bool touch 			= false;
int p = 50;




	//direction
	bool direction = true;
	#define direction_TOG direction ^= true// 0 ^ 1 = 1 1

  //Leds on board
	#define builtLed1 		(1<<PE2)
	#define builtLed2		  (1<<PE6)
	#define builtLed1_ON	PORTE |= builtLed1  	// |0000| | 0001 = |0001|
	#define builtLed2_ON	PORTE |= builtLed2
	#define builtLed1_OFF	PORTE &= ~builtLed1 	// |0001| & ~0001 = 0001 & 1110 = |0000|
	#define builtLed2_OFF	PORTE &= ~builtLed2
	#define builtLed1_TOG	PORTE ^= builtLed1 		// |0000| ^ 0001 = |0001|
	#define builtLed2_TOG	PORTE ^= builtLed2 		// |1000| ^ 1000 = |0000|

  //floor sensors
  #define FaR 			(1<<PD0)
  #define FaL				(1<<PD1)
  #define FbR				(1<<PD3)
  #define FbL				(1<<PD2)

  #define edgeA     ((PIND & FaL) | (PIND & FaR))
  #define edgeB     ((PIND & FbL) | (PIND & FbR))
  #define edgeAL    (PIND & FaL)
  #define edgeAR    (PIND & FaR)
  #define edgeBL    (PIND & FbL)
  #define edgeBR    (PIND & FbR)

  //buttons
  #define but1      (1<<PF4)
  #define but2      (1<<PF1)
  #define but3      (1<<PF0)

	#define status_but1	(PINF & but1)
	#define status_but2	(PINF & but2)
	#define status_but3 (PINF & but3)

  //distans Sensors
  #define IRa       (1<<PF6)
  #define IRaR      (1<<PF5)
  #define IRaL      (1<<PF7)
  #define IRb       (1<<PD4)
  #define IRbR      (1<<PD5)
  #define IRbL      (1<<PD6)

  #define disA      (PINF & IRa)
  #define disAR     (PINF & IRaR)
  #define disAL     (PINF & IRaL)
  #define disB      (PIND & IRb)
  #define disBR     (PIND & IRbR)
  #define disBL     (PIND & IRbL)

  //control motor A PB
	#define Ma1				(1<<PB5)
	#define Ma2				(1<<PB4)
	#define MaPWM			(1<<PD7)

	#define Ma1_ON		PORTB |= Ma1
	#define Ma2_ON	 	PORTB |= Ma2
	#define Ma1_OFF		PORTB &= ~Ma1
	#define Ma2_OFF	 	PORTB &= ~Ma2
	#define	MaPWM_ON	PORTD |= MaPWM

  //control motor B
  #define Mb1				(1<<PB6)
  #define Mb2				(1<<PC6)
  #define MbPWM			(1<<PC7)

	#define Mb1_ON		  PORTB |= Mb1
	#define Mb2_ON	 		PORTC |= Mb2
	#define Mb1_OFF		  PORTB &= ~Mb1
	#define Mb2_OFF	 		PORTC &= ~Mb2
	#define	MbPWM_ON		PORTC |= MbPWM

	//show error function
	void error(int errorNr){
		Ma1_OFF;
		Ma2_OFF;
		Mb1_OFF;
		Mb2_OFF;
		while(true){
			for (int i = 0; i < 2*errorNr; ++i){
				delay(200);
				builtLed1_TOG;
			}
			delay(2000);

			//Serial.println(program);
		}
	}

	//if touch
	bool floorSensors(bool d){
		if(d) 			return !edgeAL || !edgeAR;
		else if(!d)  return !edgeBR || !edgeBL;
		else error(15);
	}

	//pins ins and outs
  void pins(){
    //output ports for motor A control
		pinMode(6, OUTPUT);
    DDRB |= Ma1 | Ma2;
		DDRD |= MaPWM;
		MaPWM_ON;
    //output ports for motor B control
  	DDRC |= Mb2;
    DDRB |= Mb1;
		DDRC |= MbPWM;
		MbPWM_ON;
		pinMode(13, OUTPUT);

		//output ports for leds
  	DDRE |= builtLed1 | builtLed2;

  	//input ports floor sensor
    DDRD 	&= ~FaR & ~FaL & ~FbR & ~FaL;
    //disconnect inside VCC
    PORTD &= ~FaR & ~FaL & ~FbR & ~FaL;

    //input ports for buttons
    DDRF  &= ~but1 & ~but2 & ~but3;
    //disconnect insice VCC
    PORTF &= ~but1 & ~but2 & ~but3;

    //input portys for distans sensors
    DDRF &= ~IRa & ~IRaR & ~IRaL;
    DDRD &= ~IRb & ~IRbR & ~IRbL;
    //disconect inside VCC
    PORTF &= ~IRa & ~IRaR & ~IRaL;
    PORTD &= ~IRb & ~IRbR & ~IRbL;
  }



	//diode start
	void showStart(){
		builtLed1_ON;
		for (int i = 0; i < 5; ++i){
			delay(100);
			builtLed1_TOG;
	    builtLed2_TOG;
		}
		builtLed1_OFF;
		builtLed2_OFF;
	}



	//when CalkaBot sees the enemyy not straight ahead
	bool seeEnemy(){
	  return  !disAR  ||
	          !disAL  ||
	          !disBR  ||
	          !disBL	||
						!disA		||
						!disB;
	}
