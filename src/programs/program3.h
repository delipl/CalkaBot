void program3(){
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
    //program6():
    if((!edgeAL && !edgeBL) || (!edgeAR && !edgeBR)){
       start = millis();
       goForward();
       Mb1_ON;
       Mb2_OFF;
       delay(100);
     }

     //jeżeli dotykasz lini jedz w druga strone
     else if(floorSensors()){
       start = millis();
       direction_TOG;
       hardStop();
       delay(150);
       go(0);
       delay(50);

     }

     //jedz z optimalem przed siebie
     else{
        go(1);

        if((millis() - start) > 1000){
          start = millis();
          hardStop();
          delay(25);
        }
      }

  }
}
