void program4(){
  while(true){
      if(!edgeAL && !edgeBL){
        while(!edgeAL && !edgeBL){
          slowSpin();
        }
      }else{
        go(0);
      }

    }
}
