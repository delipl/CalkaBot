void program4(){
  while(true){
      if(!edgeAL && !edgeBL){
        while(!edgeAL && !edgeBL){
          go(3);
        }
      }else{
        go(0);
      }

    }
}
