/*
Default program in mini-sumo
just finding the enemy and attacking
it with whole power
*/


void program0(){
  while(true){
    //what do firstly
    if(first){
      delay(4500);
      go(optimal, optimal);
      first = false;
    }

    //when you don't see the enemy straight ahead change direction and go
    if(!floorSensors() && disA && disB){
      direction_TOG;
      go(optimal, optimal);
    }

    //when you are being pushed by the enemy
    else if(!floorSensors() && (!disA || !disB)){
      go(full, full);
    }

    //if you see enemy straight ahead
    else if(!seeEnemy()){
      //see him front
      if(toSeeFront()){
        go(full, full);
      }
      //when you touch a line
      else{
        direction_TOG;
        go(optimal, optimal);
      }
    }
  }
}
