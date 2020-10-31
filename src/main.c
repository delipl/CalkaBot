#include "header.h"
#include "motor.h"
#include "programs/program0.h"
#include "programs/program1.h"
#include "programs/program2.h"
#include "programs/program3.h"
#include "programs/program4.h"
#include "programs/program5.h"
#include "programs/program6.h"
#include "programs/program7.h"

int main(void){
  pins();
  showStart();
  if(!status_but1) program |= (1<<0);
	if(!status_but2) program |= (1<<1);
	if(!status_but3) program |= (1<<2);

  while(true){
    
  }

  return 0;
}
