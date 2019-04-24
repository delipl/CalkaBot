void program1(){

  while(true){
  touch = false;
    if(!go(1)){
      hardStop();
      delay(2);
      direction_TOG;
      touch = true;
      builtLed1_TOG;
      while(touch){
        if(go(1)&&floorSensors(!direction)){
          builtLed2_TOG;
          touch = false;
        }
      }
    }else{
        if(!disAR || !disAL || !disBL || !disBR)
        if(toSeeFront()) go(0);
    }
  }
}
