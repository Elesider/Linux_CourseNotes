#include <stdio.h>
//#include "L5_3_F1.c"   
//gcc should include this .c file without it.
int main()
{
   static void staticFunc(void); //remove static 
   extern volatile int a; 
   staticFunc();
   a++;
   return 0;
}


//remove in fucntion and main static specifier will work. 