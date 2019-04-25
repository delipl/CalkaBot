void program1(){

  while(true){
  touch = false;

  if(!disA || !disB){
    !disA?direction=1:direction=0;
    if(!go(0)){
      hardStop();
      delay(2);
      direction_TOG;
      touch=1;
      while(touch){
        if(go(0)&&floorSensors(!direction)){
          builtLed1_TOG;
          touch = false;
        }
      }
    }
  }
  else if(!disAR || !disAL || !disBL || !disBR){
    if(toSeeFront()){
      if(!go(0)){
        hardStop();
        delay(2);
        direction_TOG;
        touch=1;
        while(touch){
          if(go(0)&&floorSensors(!direction)){
            builtLed1_TOG;
            touch = false;
          }
        }
      }
    }
  }else if(!go(1)){
    hardStop();
    delay(2);
    direction_TOG;
    touch=1;
    while(touch){
      if(go(0)&&floorSensors(!direction)){
        builtLed1_TOG;
        touch = false;
      }
    }
  }
}
}


    /*if(!go(1)){
      hardStop();
      delay(2);
      direction_TOG;
      touch = true;
      builtLed1_TOG;
      while(touch){
        if(go(1)&&floorSensors(!direction)){
          builtLed1_TOG;
          touch = false;
        }
      }
    }else{
        if(!disA){
          direction=1;
          go(0);
        }
        if(!disB){
          direction=0;
          go(0);
        }
        if(!disAR || !disAL || !disBL || !disBR) if(toSeeFront()) go(0);

    }*/
