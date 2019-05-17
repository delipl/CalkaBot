//podstawowyprogram z jezdzeniem
void program6(){
  unsigned long start = millis();
  while(true){

    //jak wszystkie czujniki widzą to znaczy ze jest na podłodze
    /*if((!edgeA && !edgeB)) error(5);
    else*/

    //nastawienie sie przodem i dzida
    if(toSeeFront()){
      start = millis();
      while (toSeeFront()){
        start = millis();
        go(0);
      }
    }

    //jak najedzesz na linie od boku to się przekręć
    else if((!edgeAL && !edgeBL) || (!edgeAR && !edgeBR)){
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
      delay(175);
      go(0);
      delay(25);
    }

    //jedz z optimalem przed siebie
    else{
       go(1);
       if((millis() - start) > 500){
         go(0);
       }
       if((millis() - start) > 1200){
         start = millis();
         hardStop();
         delay(25);
       }
     }
  }
}
