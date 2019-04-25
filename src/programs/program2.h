void program2(){
    int toBeMiddle=300;
    go(0);
    delay(toBeMiddle);
    hardStop();

    while(true){

      if(floorSensors(direction)){

          hardStop();
          delay(2);
          direction_TOG;
          go(0);
          delay(50);
      }
      else if(!disA){
        direction=1;
        go(0);
      }
      else if(!disB){
        direction=0;
        go(0);
      }
      /*else if(!disAR || !disAL || !disBL || !disBR){
        if(toSeeFront())
          go(0);
        }*/
      else {
       spin();
      //hardStop();
      //go(1);
      }
    }
}
