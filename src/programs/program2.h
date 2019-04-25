void program2(){
    int toBeMiddle=300;
    go(0);
    delay(toBeMiddle);
    hardStop();

    while(true){

      if(!floorSensors(direction)){
        if(!disA||!disB){
            if(!disA)direction=1;
            else if(!disB) direction=0;
            go(0);
        }else if(!disAR || !disAL || !disBL || !disBR){
            if(!toSeeFront()){
              hardStop();
              direction_TOG;
              go(0);
              delay(100);
            }
        }else{
          spin();
        }
    }else{
      hardStop();
      direction_TOG;
      go(0);
      delay(400);
    }
}
}
