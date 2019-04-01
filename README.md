Pinout Atmega32u4:

| **Pin** | **Arduino**    | **Function**   | **Code** |
| :------:|:-------------: | :-------------:|:--------:|
|   1     | digital pin 7  | built in LED   | builtLed1|
|   2     | 	VCC 	   | voltage supply |   HIGH   |
|   3     | D-             | USB data   	|   ---    |
|   4     | D+             | USB data   	|   ---	   |
|   5     | 	GND  	   | ground			| 	LOW	   |
|   6     | 	Cap  	   | USB capacotor	| 	---	   |
|   7     | 	VCC 	   | voltage supply |   HIGH   |
|   8     | 	rxLed  	   | empty 1\0 pin	| 	---    |
|   9     | 	SCK  	   | ICSP			| 	SCK	   |
|   10    | 	MOSI 	   | ICSP		    | 	MOSI   |
|   11    | 	MISO 	   | ICSP		    | 	MISO   |
|   12    | digital pin 11 | unplugged	  	| 	---	   |
|   13    | 	RST	   	   | reset		    | 	RST    |
|   14    | 	VCC 	   | voltage supply |   HIGH   |
|   15    | 	GND  	   | ground			| 	LOW	   |
|   16    | 	XTAL1 	   | oscilator		| 	---    |
|   17    | 	XTAL2	   | oscilator		| 	---    |
|   18    | digital pin 3  | floor sensor  	| 	FaP	   |
|   19    | digital pin 2  | floor sensor  	| 	FaL	   |
|   20    | digital pin 0  | floor sensor  	| 	FbL	   |
|   21    | digital pin 1  | floor sensor  	| 	FbP	   |
|   22    | 	txLED 	   | distans sendor	|  (IRbR)  |  <- ???
|   23    | 	GND  	   | ground			| 	LOW	   |
|   24    |		VCC 	   | voltage supply |   HIGH   |
|   25    | digital pin 4  | distans sendor	| 	IRb    |
|   26    | digital pin 12 | distans sendor	| 	IRbL   |
|   27    | digital pin 6  | motor PWM   	| 	MaPWM  |
|   28    | digital pin 8  | motor control	| 	Ma2    |
|   29    | digital pin 9  | motor control	| 	Ma1    |
|   30    | digital pin 10 | motor control	| 	Mb1    |
|   31    | digital pin 5  | motor control	| 	Mb2    |
|   32    | digital pin 13 | distans sendor	| 	MbPWM  |
|   33    | 	HWB 	   | built in LED   |(builtLed2)| <- ???
|   34    | 	VCC 	   | voltage supply |   HIGH   |
|   35    | 	GND  	   | ground			| 	LOW	   |
|   36    |    analog 0    | distans sendor | 	IRaL   |
|   37    |    analog 1    | distans sendor	| 	IRa	   |
|   38    |    analog 2    | distans sendor	| 	IRaR   |
|   39    |    analog 3    | button      	| 	but1   |
|   40    |    analog 4    | button      	| 	but2   |
|   41    |    analog 5    | button      	| 	but3   |

--------------------------------------------------------------

Arduino Leonardo pinout:

| **Arduino**    | **Function**     | **Code** | **Pin** |
|:-------------: | :---------------:|:--------:| :------:|
| digital pin 0  | floor sensor  	|   FbL	   |	20   |
| digital pin 1  | floor sensor     |   FbP	   |    21   |
| digital pin 2  | floor sensor  	|   FaL	   |	19	 |
| digital pin 3  | floor sensor  	|   FaP	   |	18	 |
| digital pin 4  | distans sendor	| 	IRb    |    25   |
| digital pin 5  | motor control	| 	Mb2    |	31   |
| digital pin 6  | motor PWM   		| 	MaPWM  |    27   |
| digital pin 7  | built in LED  	| builtLed1|    1    |
| digital pin 8  | motor control	| 	Ma2    |    28   |
| digital pin 9  | motor control	| 	Ma1    |    29   |
| digital pin 10 | motor control	| 	Mb1    |    30   |
| digital pin 11 | unplugged	  	| 	---	   |    12   |
| digital pin 12 | distans sendor	| 	IRbL   |    26   |
|    analog 0    | distans sendor   | 	IRaL   |    32   |
|    analog 1    | distans sendor	| 	IRa	   |    33   |
|    analog 2    | distans sendor	| 	IRaR   |    34   |
|    analog 3    | button  		 	| 	but1   |    35   |
|    analog 4    | button       	| 	but2   |    36   |
|    analog 5    | button 			| 	but3   |    37   |
| 	 txLED 	     | distans sendor	|  (IRbR)  |    22   | <- ???
| 	   HWB 	     | built in LED     |(builtLed2)|   33   | <- ??? 

(luckly, 11 pin works...)

Code definitions:
| 	**Group** 	| **Code** |          **Definition**     	    |
|:-------------:|:--------:|									|
| Floor Sensors	|   FbL	   |									|
|				|   FbP	   |									|
|				|   FaL	   |									|
| 				|   FaP	   |									|
| 				| 	       |									|
|Distans Senstors| IRaL	   |									|
| 				|  IRa     |									|
| 				|  IRaR    |									|
| 				|  IRbL	   |									|
| 				|  IRb     |									|
| 				|  IRBR    |									|
| 				| 	       |									|
|Motors Control	| 	Ma1    |									|
|				| 	Ma2    |									|
|				|	MaPWM  | 									|
|				|	Mb1    |									|
|				|	Mb2	   | 									|
|				|	MbPWM  | 									|
|				|		   |									|
|	Output 		|builtLed1 |									|
|				|builtLed2 |									|











