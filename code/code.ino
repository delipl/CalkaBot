
//control motor 2 PB
	#define goFowardA  		0b010000;
	#define goBackwardA  	0b100000;
	#define slowStopA		0b000000;
	#define hardStopA		0b110000;




void setup(){
 
	//===[pinMode]=====
  	//       76543210
	DDRB = 0b01110000;
	DDRC = 0b11000000;
	DDRD = 0b10000000;
	DDRE = 0b01000100;
	DDRF = 0b00000000;
	//=================

	

	//informacja włączenia płytki
  	PINE |= (1<<6) | (1<<2);		//wstaw bity
	for (int i = 0; i < 5; ++i){
		delay(100);
		PINE = ~(0<<0);
	}
	//===========================

}



  
void loop(){
  
  
	 
  
}