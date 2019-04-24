//control motors
void goForward(){
  Ma1_OFF;
  Ma2_ON;
  Mb1_OFF;
  Mb2_ON;
}

void goBackward(){
  Ma1_ON;
  Ma2_OFF;
  Mb1_ON;
  Mb2_OFF;
}

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

bool go(int x){   //0 - full   1 - optimal 2 -  left 3 -right
  if(x==0){
        direction?goForward():goBackward();
  }else if(x==1){

        if(direction){

              goForward();
              if(floorSensors(direction)) return 0;
              delayMicroseconds(p);
              slowStop();
              if(floorSensors(direction)) return 0;
              delayMicroseconds(100-p);

        }else if(!direction){

              goBackward();
              if(floorSensors(direction)) return 0;
              delayMicroseconds(p);
              slowStop();
              if(floorSensors(direction)) return 0;
              delayMicroseconds(100-p);

        }else error(9);

  }else if(x==2){

        if(direction){
            goForward();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();
            Mb2_ON;
            if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);

        }else if(!direction){
          goBackward();
          if(floorSensors(direction)) return 0;
          delayMicroseconds(100);
          slowStop();
          Ma1_ON;
          if(floorSensors(direction)) return 0;
          delay(1);
          slowStop();
          if(floorSensors(direction)) return 0;
          delayMicroseconds(100);
        }else error(11);

  }else if (x==3){

        if(direction){
            goForward();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();
            Ma2_ON;
            if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
        }else if(!direction){
            goBackward();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();
            Mb1_ON;
            if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
            if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
        }else error(12);

  }
  else if(x==4){
    if(direction){
      for(int i = p; i < 101; i++){
        goForward();
        if(floorSensors(direction)) return 0;
        delayMicroseconds(p);
        slowStop();
        if(floorSensors(direction)) return 0;
        delayMicroseconds(100-p);
      }
    }
    else if(!direction){
      for(int i = p; i < 101; i++){
        goBackward();
        if(floorSensors(direction)) return 0;
        delayMicroseconds(p);
        slowStop();
        if(floorSensors(direction)) return 0;
        delayMicroseconds(100-p);
      }
    }
    else error(15);

  }
  else error(13);
  return 1;
}


//floor sensors


//turn one of side until you don't touch floor and you don't see enemy
bool toSeeFront(){
  /*if(!disAR || !disBR){
    go(optimal, false);
    while(true){
      if(!floorSensors)   return false;
      //if(!disAR || !disBR)  return true;
      if(disAR)  return true;
    }
  }
  if(!disAL || !disBL){
    go(0, optimal);
    while(true){
      if(!floorSensors)   return false;
      if(disAL)           return true;
    }
  }*/

  //error(2);
  return 0;
}

//to spin
void spin(bool x){
  analogWrite(6, full);
  analogWrite(13,full);
  if(x){
    Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;
  }else{
    Ma1_ON;
    Ma2_OFF;
    Mb1_OFF;
    Mb2_ON;
  }
}
