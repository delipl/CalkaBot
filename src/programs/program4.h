void program4(){
  while(true){
      if(floorSensors(direction)){
        go(3);
      }else{
          if(!disA){
          direction=1;
          go(0);
          }
          else if(!disB){
            direction=0;
            go(0);
          }
          else if(!disAR || !disAL || !disBL || !disBR) if(toSeeFront()) go(0);
          else go(1);
      }
  }
}
