/*
jest tutaj dzialajacy seefront tylko ze z tylu
*/
void program2(){
  if(!disB){
     goBackward();
  }
  else  if(!disBR){
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
  else slowStop();
}
