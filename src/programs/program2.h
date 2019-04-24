void program2(){
    int toBeMiddle=100;
    go(0);
    delay(toBeMiddle);
    hardStop();

    while(true){
      if(floorSensors(direction)){
        direction_TOG;
        if(go(0));
        delay(toBeMiddle);
      }
      else if(!disA){
        direction=1;
        go(0);
      }
      else if(!disB){
        direction=0;
        go(0);
      }
      else if(!disAR || !disAL || !disBL || !disBR) if(toSeeFront()) go(0);
      else spin(1);
    }
}
