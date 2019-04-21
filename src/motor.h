
bool seeEnemy(){
  //also here we have to put some code :P

  //this is true when CalkaBot sees the enemy just straight ahead
  return !disA || !disB;
}

//control motors
void goForward(uint8_t x, uint8_t y){
  if(x==y && (x!=0 || x!=255)) y --;
  analogWrite(6, x);
  analogWrite(13, y);
  Ma1_OFF;
  Ma2_ON;
  Mb1_OFF;
  Mb2_ON;
}

void goBackward(uint8_t x, uint8_t y){
  if(x==y && (x!=0 || x!=255)) y --;
  analogWrite(6, x);
  analogWrite(13, y);
  Ma1_ON;
  Ma2_OFF;
  Mb1_ON;
  Mb2_OFF;
}

void go(uint8_t x, uint8_t y){
  direction?goForward(x, y):goBackward(x, y);
}

void hardStop(){
  Ma1_ON;
  Ma2_ON;
  Mb1_ON;
  Mb2_ON;
}

void slowStop(){
  Ma1_OFF;
  Ma2_OFF;
  Mb1_OFF;
  Mb2_OFF;
}
