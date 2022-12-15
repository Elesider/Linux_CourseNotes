// Undefine Behavior cause by compiler(optimizer)
//Data Sign problem.
#include <stdio.h>
int foo (int a) {
    if (a + 100 > a)
        printf("%d GT %d\n", a + 100, a);
    else
        printf("%d LT %d\n", a + 100, a);
    
   volatile int b=a;
       if (b + 100 > b)
        printf("%d GT %d\n", b + 100, b);
    else
        printf("%d LT %d\n", b + 100, b);
    
    return 0;
}
int main () { foo(100); foo(0x7fffffff); return 0; }


//gcc version is 9.3.0. gcc -Og still can't dsiable the optimizatin.
// It is noted that the optimizer donot even calculate the if statement.
