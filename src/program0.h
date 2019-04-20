program0(){
  while(true){
      if(!floorSensors()){
           if(seeEnemie()){
              //here we have to put some code :v
           }else{
              go(optimal, optimal);
           }
      }else{
           togDirection();
           while (floorSensors) go(full, full);
      }
  }
}
