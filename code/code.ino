
//control motor 2 PB
	#define goFowardA  		0x10  //0b01 0000; 
	#define goBackwardA  	0x20  //0b10 0000; 
	#define slowStopA		  0x00  //0b00 0000; 
	#define hardStopA		  0x30  //0b11 0000; 




void setup(){
 
	//===[pinMode]=====
  	//       76543210
	DDRB = 0x70;      //0b0111 0000;
	DDRC = 0xC0;      //0b1100 0000;
	DDRD = 0x80;      //0b1000 0000;
	DDRE = 0x44;      //0b0100 0100;
	DDRF = 0x00;      //0b0000 0000;
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
