#include <stdio.h>
volatile int a =2; //check where it is initilze
static void staticFunc(void)
{
     volatile int b=3;  //remove the static 
   printf("Inside the static function staticFunc()\n");
}


// integer a is defined before entering main during processing. 
