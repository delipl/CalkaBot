program0(){
  while(true){
      if(!floorSensors()){
           if(seeEnemy()){
              //here we have to put some code :v
           }else{
              go(optimal, optimal);
           }
      }else{
           direction_TOG;
           while (floorSensors) go(full, full);
      }
  }
}
