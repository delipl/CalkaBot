/*
jest tutaj dzialajacy seefront tylko ze z tylu
*/
void program2(){
  while(!disB){
     goBackward();
  }
  while(!disA){
    goForward();
  }
  if(!disBR){
    Ma1_ON;
    Ma2_OFF;
    Mb1_OFF;
    Mb2_OFF;
  }
  else if(!disBL){
    Ma1_OFF;
    Ma2_OFF;
    Mb1_ON;
    Mb2_OFF;
  }
  else if(!disAL){
    Ma1_OFF;
    Ma2_OFF;
    Mb1_OFF;
    Mb2_ON;
  }
  else if(){
    Ma1_OFF;
    Ma2_ON;
    Mb1_OFF;
    Mb2_OFF;
  }
  else slowStop();
}
