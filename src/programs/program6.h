void program6(){
  while(true){

    if(toSeeFront()){
      if(!go(0)){
        hardStop();
        direction_TOG;
        go(0);
        delay(100);
      }
    }
    if(!go(1)){
      hardStop();
      direction_TOG;
      go(0);
      delay(100);
    }
  }
}
