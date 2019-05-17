/*    opis programu
robot bez zadnego zdarzenia kreci się


*/
void program5(){
  unsigned long start = millis();
  while(true){

    //jak wszystkie czujniki widzą to znaczy ze jest na podłodze
    /*if((!edgeA && !edgeB)) error(5);
    else*/

    //nastawienie sie przodem i dzida
    if(toSeeFront()){             //tutaj nie wejdzie za kazdym razem bo nie zdazy zatrzymac sie zkrecenia
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

    //skanowanie mapy
    else{
      //przez 500ms jedz do przodu
      if((millis() - start) < 500){
        go(0);
      }
      //w przeciwnym razie krec sie przez 2000ms
      else{
        spin();
        if((millis() - start) > 2000) start = millis();
      }
    }
  }
}
