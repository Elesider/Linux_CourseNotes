// Bit shift Operation 
#include <stdio.h>
int foo(int x, int y) {
    x >>= (sizeof(int) << y);
    return x;
}
int main () {
    printf("%d\n", foo(1000, 3));
    int a=1;
    int *ptr=0; // This *ptr cannot be accessed. The ptr address is 0;
    ptr=&a;
    (*ptr)++;
    int b[2]={3,4};
    ptr=b;  //This is valid.
    *ptr++; // this result is 3, and ptr to next cell.
    return 0;
 }