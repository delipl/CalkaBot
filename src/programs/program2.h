void program2(){
    int toBeMiddle=100;
    go(0);
    delay(toBeMiddle);
    hardStop();

    while(true){
      if(!seeEnemy)spin(1);
      else if(floorSensors(direction)){
        direction_TOG;
        if(go(0));
        delay(toBeMiddle);
      }
      if(!disA){
        direction=1;
        go(0);
      }
      if(!disB){
        direction=0;
        go(0);
      }
      if(!disAR || !disAL || !disBL || !disBR) if(toSeeFront()) go(0);
    }
}
