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

//hard stop
void hardStop(){
  Ma1_ON;
  Ma2_ON;
  Mb1_ON;
  Mb2_ON;
}
//slow stop, cutting voltage supply for motors
void slowStop(){
  Ma1_OFF;
  Ma2_OFF;
  Mb1_OFF;
  Mb2_OFF;
}

//floor sensors
bool floorSensors(){
  return  !edgeA  ||
          !edgeAL ||
          !edgeAR ||
          !edgeB  ||
          !edgeBR ||
          !edgeBL;
}

//when CalkaBot sees the enemyy not straight ahead
bool seeEnemy(){
  return  !disAR  ||
          !disAL  ||
          !disBR  ||
          !disBL;
}

//turn one of side until you don't touch floor and you don't see enemy
bool toSeeFront(){
  if(!disAR || !disBR){
    go(optimal, half);
    while(true){
      if(!floorSensors)   return false;
      if(!disA || !disB)  return true;
    }
  }
  if(!disAL || !disBL){
    go(half, optimal);
    while(true){
      if(!floorSensors)   return false;
      if(!disA || !disB)  return true;
    }
  }
  error(2);
  return 0;
}

//to spin
void spin(){
  analogWrite(6, full);
  analogWrite(13,full);
  Ma1_OFF;
  Ma2_ON;
  Mb1_ON;
  Mb2_OFF;
}
