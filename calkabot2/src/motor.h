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
              if(floorSensors() && checkFloor) return 0;
              _delay_us(p);
              slowStop();
              if(floorSensors() && checkFloor) return 0;
              _delay_us(100-p);

        }else if(!direction){

              goBackward();
              if(floorSensors() && checkFloor) return 0;
              _delay_us(p);
              slowStop();
              if(floorSensors() && checkFloor) return 0;
              _delay_us(100-p);

        }else error(9);

  }else if(x==2){

        if(direction){
            goForward();
            Ma1_OFF;
            Ma2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else if(!direction){
            goBackward();
            Ma1_OFF;
            Ma2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else error(11);

  }else if (x==3){

        if(direction){
            goForward();
            Mb1_OFF;
            Mb2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else if(!direction){
            goBackward();
            Mb1_OFF;
            Mb2_OFF;
            if(floorSensors() && checkFloor) return 0;
        }else error(12);
    }
  else error(13);
  return 1;
}

//to spin
void spin(){
    Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;
    _delay_ms(3);
    slowStop();
    _delay_ms(5);
}

//to slowly spin
void slowSpin(){
    Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;
    _delay_ms(5);
    slowStop();
    _delay_ms(10);
}
