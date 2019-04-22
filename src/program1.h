/*
After start CalkaBot does't move for 4500ms
but looks for the enemy
After 4500 begins spinning and looking for the enemy
when it find the program0 will work
*/
int startTime;
program1(){
  while (true) {
    if(first){
      startTime = millis(); //does it work w\like that?
      while(!seeEnemy && disA && disB){
        if(millis() - startTime >= 4500){
          if(!disA)
            go(full, full);
          else if(!disB){
            direction_TOG;
            go(full, full);
          }
          else
            spin();
        }
      }
      first = false;
    }
    if(seeEnemy)
      program0();
  }
}
