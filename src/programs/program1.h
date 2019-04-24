/*
After start CalkaBot does't move for 4500ms
but looks for the enemy
After 4500 begins spinning and looking for the enemy
when it find the program0 will work
*/

void program1(){

  while(true){
  touch = false;
    if(!go(1)){
      hardStop();
      delay(2);
      direction_TOG;
      touch = true;
      while(touch){
        builtLed1_TOG;
        if(go(1)&&floorSensors(!direction)){
          builtLed2_TOG;
          touch = false;
        }
      }
    }

    if(!disAR){
      direction = 1;
      if(go(0)){}
    }
}
}
