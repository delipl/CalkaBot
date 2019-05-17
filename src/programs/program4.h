void program4(){
  if(first){
    while(!floorSensors()) {
      direction == true;
      go(1);
    }
    hardStop();
    delay(200);
  }

  if(!disB && disA){
    while((!disB && disA) && readButton()){
      goBackward();
    }
  }
  else if(!disA && disB){
    while((!disA && disB) && readButton()){
      goForward();
    }
  }
  if(!disBR){
    while(disB && readButton()){
      Ma1_ON;
      Ma2_OFF;
      Mb1_OFF;
      Mb2_OFF;
    }
  }
  else if(!disBL){
    while(disB && readButton()){
      Ma1_OFF;
      Ma2_OFF;
      Mb1_ON;
      Mb2_OFF;
    }
  }
  else if(!disAL){
    while(disA && readButton()){
      Ma1_OFF;
      Ma2_OFF;
      Mb1_OFF;
      Mb2_ON;
    }
  }
  else if(!disAR){
    while(disA && readButton()){
      Ma1_OFF;
      Ma2_ON;
      Mb1_OFF;
      Mb2_OFF;
    }
  }
  else{

    slowStop();
  }
}
