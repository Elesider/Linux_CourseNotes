// Bit shift Operation 
#include <stdio.h>
int foo(int x, int y) {
    x >>= (sizeof(int) << y);
    return x;
}
int main () {
    printf("%d\n", foo(1000, 3));
    return 0;
 }

 //1. size of return type is unsign int or unsign long int depends
 //2.gcc -O2 t.c -fsanitize=undefined. To show up the defined action 