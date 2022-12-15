#include <stdio.h>
int foo(int x, int y) {
    x >>= (sizeof(int) << y);
    return x;
}
int main () {
    printf("%d\n", foo(1000, 3));
    char a=1;
    a++;
    int b=-2;
    float c =1.1;
    int d;
    char  a1[4]="abc";// '\0'is the last one.
    char  b1[4];
//    b1=a1; THis is wrong. copy one string to another. while(b1[i++]=a1[i++])
 
    while ((d = getchar()) != EOF)
    putchar(d);
   return 0;
 }
