**C_Languge_Review**
> Guts to start. This is a rethinking learning for the C language based on the material provided by the [josephy](https://hackmd.io/@sysprog/c-prog/%2F%40sysprog%2Fc-programming). The book is also referened inside. It is not about programming skill. It is about the understanding the C programming now.
```
C is an artisanal language for programmers obsessed with hand-crafting the smallest details of their programs.
```
- [1. Developing Tool and Standards.](#1-developing-tool-and-standards)
  - [1.1. Undefined Behavior](#11-undefined-behavior)
- [2. Pointer and Matrix](#2-pointer-and-matrix)
  - [2.1. Declare and Definition for pointer](#21-declare-and-definition-for-pointer)
  - [2.2. Void pionter type](#22-void-pionter-type)
  - [2.3. Arithmatic of Pointer and Matrix](#23-arithmatic-of-pointer-and-matrix)
  - [2.4. Multiple dimension array and pointer to pointer](#24-multiple-dimension-array-and-pointer-to-pointer)
  - [2.5. Pionter to function](#25-pionter-to-function)
- [3. Data Type Explore](#3-data-type-explore)
  - [3.1. Int](#31-int)
  - [3.2. float double](#32-float-double)
  - [3.3.  Char String ASCII and Unicode](#33--char-string-ascii-and-unicode)
  - [3.4. boolen  bitwise operation](#34-boolen--bitwise-operation)
  - [3.5. Data Type Cast](#35-data-type-cast)
  - [3.6. Enumerations Union Struct Bit Field](#36-enumerations-union-struct-bit-field)
  - [3.7. Data Storage Specifier](#37-data-storage-specifier)
- [4. Operation and Loop Control State](#4-operation-and-loop-control-state)
- [5. Function](#5-function)
  - [5.1. Declare and Definition](#51-declare-and-definition)
  - [5.2. Arguments and shared memory](#52-arguments-and-shared-memory)
  - [5.3. Scope of shared memory, Header, and linker](#53-scope-of-shared-memory-header-and-linker)
  - [5.4. Static Function](#54-static-function)
  - [5.5. Recurrsion and pop()-pop()](#55-recurrsion-and-pop-pop)
  - [5.6. Exception Handling](#56-exception-handling)
- [6. IO Stream , File Handler and Linux System](#6-io-stream--file-handler-and-linux-system)
  - [IO STREAM](#io-stream)
  - [File Handle](#file-handle)


# 1. Developing Tool and Standards.
> Tools for us to `measure` what it is inside of the code. You can't under it until you know how to `measure` it and express it in math. A good tool will give us an important opportunity to `see` it. 
> 
> Tools: 
> - [ ] 1. CDECL 
> - [ ] 2. GDB & rr 
> - [ ] 3. [GCC](https://gcc.godbolt.org/) Both GCC and GDB provide us a way to measure it and to see it. 
> - [ ] 4. [C89 C99 online Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
> - [ ] 4. git. other interactive tools is `jupyter`. 

> Standards not the other Internet or google to turn to. There are a lot of explaination or notes on the internet. But they are not necessary right. The first hand information can only be found in the first hand material: Standards. 
> - [ ] What is ` C99 C11 C20 `?  Dictionary. [C99]() is the **agreement**
> - [ ] What is `ANSI` or `ISO`, `MISRA`? Organization make Dictionary.

## 1.1. Undefined Behavior
> There is no so-called `undefined behavior`. Different compiler with different optimization level can result in different results. Especially nowadays, the `compiler` is too smart to optimize our code to an unexpected level.
- [ ] Optimizer in the Compiler. [Overflow L1_1.c](L1_1.c) file for more detail. The optimizer remove the if statement judegment, which can cause problem. check gcc manual. fsanitize to find out different undefined behavior and show them. 
   ![Fig1_1](Fig/Fig1_1) 
- [ ] [Bit shift underfined behavior](L1_2.c). 

# 2. Pointer and Matrix 
> Read the book and then to the note from Josephy.
## 2.1. Declare and Definition for pointer
> If you cannot express it in math, you don't understand it. Use `cdecl` to check whether you understand the define and declaration

  1. char s[] and char *s are equivalent.
     > This is only for one dimension array. For high dimension is not.  
  2. [Declare of a pointer.c file.](L2_1.c) 
   ```C
   int *p=&a; // p point to a.
   int *p=a;  // p address is a. Cannot access if a constant number is given. Check L2_1.c.
   int *p; p=&a;
   int *p; int a[2]]; p=a; p=&a[0];
   double atof(*char);
   int *p; int *q; p=q;
   void *p; char* q; p=q;//this is special case. Usually not ok.
   char *p="Hello, world";
   char s[]="Hello, world";
   p=s;
   ``` 
  3. Advanced Example Understanding.
```C
// Advanced Example
struct tag (*var[])()
/* Arrary of pionters to function. Return type of func is struct tag object. */

char *(*fptab[])(int)
//Declare array of pointers to function, whose return is pointer to char. */

Const void * src;// src is a pointer to const void type.
void * const src; //src is a const pointer to void type

void **(*d) (int &, char **(*)(char *, char **));
//reference is not supported in C.

*(int32_t * const) (0x67a9) = 0xaa6;
// put the absolute address Ox67a9 32 bit int to Oxaa6.

int main (int argc char * argv[])

int main (int argc char ** argv)
```

## 2.2. Void pionter type
> Void * ptr is 





## 2.3. Arithmatic of Pointer and Matrix
  1. Basic Arithmatic for pointer
```C
a+=b;   //a=a+b;
a=+b;   //a = (+b);
int a = 15;
int b = -5;

a += b; // a is now 10
a =+ b; // a is now -5

++*ptr;  
(*ip)++ ;  *ip++; //These two are different

```
2. alloc [malloc](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm) [calloc](https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm)  free.
   > malloc is to avoid small stack storage. For example, if use a[100000]. It may not work due to the limiation of the continuous memory for the stack. To get very large `vector`. Have to use malloc to use `heap` section. This is also called dynamic memory allocation.
   > calloc is the same with malloc.But initialize memory to o. 
   > malloc and calloc is to define `large` matrix. 

3. strcpy use arithmatic of pointers. *p++
```C
 void strcpy(char *p, char *s)
 {
  while ((*p++=*s++)!='\0'){
    ;
    } 
 }
```



## 2.4. Multiple dimension array and pointer to pointer
  1. Two dimentional Array Declare
   > Row is not important. Column is important!
```C
  int a[row][column];
  int a[][column];  //declare two demension array
  int (*a)[column]; //Two dimension array
  int *a[column]; //pointer array
  int **a;//pointer array (pointer to pointer)
  //precedence of [] is higher than *

  //Initialization of the two dimentinal matrix
  int a[2][2]={{1,1},{2 2}};
```

  2. Two dimensional array initilization. Two dimensional arrary is not the same with pointer arrary. Two dimensional arrary has one more feature:  data byte alignment, which pointer array don't have it.
```C
static char monthname[][15]={"illegal","Jan","Feb",...}
//The memory of the arrary is connected together.

```


  3. Pointer to pointer/ Pointer array initializtion. This is frequency seen in int main (int argc, char * argv[]) or int main (int argc, char **argv).
``` C
char *monthname(int n){
  static char *name[]={
    "illegal","jan","Feb",...,"Dec"
  }
  char * outp;
  if (n<=12 && n>=1)
  {
   outp=name[n] 
  }
  else 
  outp=name[0];
  return outp;
// or return (n<=12 && n>=1)? name[n]:name[0];
}
```


## 2.5. Pionter to function
> alias to a function. Pointer to function.
> Understanding of char (*(*x())[])()
```C
//declare
int (*comp)(void *, void *)
{}
```

```C
//Definition
void fun(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = &fun;
  
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
  
    return 0;
}
```



# 3. Data Type Explore
> Data Data Data. All services are creates for the Data.

## 3.1. Int 
1. With the development of the hardware, int can be 16 bits, 32 bits and 64 bits. As a result, many OS will use int_16 int_32 int_64. Anyway, they are not standardized datatype. Use them after define. 


2. Char is also a int type. For C99 in Linux 64, int is 4 bytes, char is 1 byte, short int, long int, unsign int, unsigned char. C99 support long long int.

3. Declare and Define Regulation
  ```C
  unsign long int x;
  char x;
  x=65;
  char y='a';
  0x2f; //hex
  057; //octal. start from zero. 
  56; //default decimal
  45UL;  45ul; //the same
  ```


4. Int in the memory. Very very careful with negative number. Especially doing bit shift and calculation. They may enters the undefined state. 
   > Bit shift over 32 for a int. What will happen.

   > what to do with overflaw in int. Be careful! In the `digital system` course, we learnt how to set the overflow flag for plus and minus, also bit shifting flags. There are a lot to play for these. However, all those do not mean to be true here. In the `digital system` or `computer architecture` course, they are very bottom level. In the real world, gcc will determined what to do with it sometimes without even warning. Do not take all to granted. To make gcc more efficient, they set a lot of option by default without warning. But it do not work as you imagine ! Use gcc option and gdb to find out how it works in the bottom level.

   > Always remeber 2's complement in the memory when operate with int type. 
    - FOr integer (both positive and negative), `<<1` is to muliple 2.

   > Always remember you have a very `high-level`gcc. Especially in gcc ,there is a `high end` optimizer. The code can optimized to a different code. Also the same code can behavior different than you think. 


## 3.2. float double
 > We thought we understand float by mistake. What is the float in memory??? How operate in the add/minus? multiple is more difficult.

 > bit shift operation is not supported float. This makes us to forget its shape in memory.


1. Float in Memory.Then think in memory.
   [Float in memory calculator](https://babbage.cs.qc.cuny.edu/IEEE-754.old/Decimal.html).  

2. Due to its data stored type, it is a relative expression. It means two near float operation is more accurate. However, when two float are different scale, they will put them into the same exponent field level for operation. Then it will cause rounding data loss for this conversion. In this sense, `floating type is also fix-point data type.` When the exponent field is fixed when operation.
  - `Rounding data loss Issue, we cannot created a pure 60 Hz using integral software`. Check [L3_1.c](L3_1.c) for the code. This is a very very important example widely used in the real-time operating system. Consider we are create a 60 Hz output sine wave or any PI controller. In each step, the integrated value in each sampling time is very very small. A good way to alleviate this data conversion loss problem is to nominaize all the input for the controller to 1.  Or a better way is to directly use the fixed piont data. Or reduce the rounding loss: only math operation between two number with similar level. 
  ```C
  float kahan_sum(float* val_arr, int nval) {
    int i;
    float acc = 0.0f, y, t;
    float corr = 0.0f; /* running corrective value for rounding error*/
    for (i = 0; i < nval; i++) {
        y = val_arr[i] - corr; /* add the correction to the item */
        t = acc + y;           /* increase the sum, bits may be lost */
        corr = (t - acc) - y;  /* recover the lost bits*/
        acc = t;
    }
    return acc;
}

  ```

3. 0.1+0.2!=0.3. Floating point comparison should be used within  range. 
   
4. There is no guarantee the same code will generate the same data.It depends on the rounding/exception method. This is very dangerous for nondeterminstic!
  
5. Most commona mistake float constant. 1!=1.0.   1.0 is float. 1 is not.
  ```C
  //define real constant double 
  double x; x=5e2; x=5e-2;
  
  ```


6.  A better understanding of float. [Quake III algorithm](https://attackofthefanboy.com/articles/the-quake-iii-algorithm-that-defies-math-explained/)
   
   ```C++
  float Q_rsqrt(float number)
  {
    long i;
    float x2,y;
    const float threehalfs=1.5F;
    x2=number*0.5F;
    y=number;
    i=*(long*)&y;  /* change point to y to long *; then use i to contain it.*/
    i=Ox5f3759df-(i>>1); // bit hacking
    y=*(float *) &i;
    y=y*(threehalfs-x2*y*y);
    return y;
  }
  // Memory, Memory! and Memory!!!. 1/sqrt(number)
  ```


## 3.3.  Char String ASCII and Unicode 
> Without char, C is only for a calculator.

  1. Char constant demonstration
   ```C
  \\
  \?
  \n
  \b
  \v
  \t
  \e     escape
  \ooo   octal number
  \xhhh  hexadecimal number
   ```
2. ASCII Symbol




3. EOF is not a ASCII symbol. That's why putchar, getchar return is a int type not a char type. EOF is defined as -1. getchar is similar to serialread or its like. It opens a stream of file. So one can input a whole sentence not only a char.
```C
#include <stdio.h>
/* copy input to output; 1st version */
main()
{
int c;  // use int ot char
c = getchar();
while (c != EOF) {   
putchar(c);
c = getchar();
}
}

#include <stdio.h>
/* copy input to output; 2nd version */
main()
{
int c;
while ((c = getchar()) != EOF)
putchar(c);

// getchar() function. We can input a string into a file. But each time, it will only return back to one char to c. Then output c until EOF(end of the file).
```
>**We can use this method to tunning the Uart Communicatino. Real time show the waveform in the screen. Use recurrension. A function call itself**  Check writeline data empty or not, if y, readline and disp, if n, writeline data and call the function itself. Then we can achieve to both sending and receiving data at the same time without using the help of the operating system.   


## 3.4. boolen  bitwise operation
  


## 3.5. Data Type Cast
> This is the most widely used and important thing. Before dealing with data, imagine the data in the memory and make sure they are the same type. Use data type cast when necessary. 



## 3.6. Enumerations Union Struct Bit Field
1. Enumerations is a custom data type used for storing `signed integer values` and refereing to them by names. By default, these values aare of type f signed int. use `comma` between like array.
```C
   emum fruit {grape=-5, cherry,lemon, kiwi };
   // defined four int number for four fruit:-5 -4 -3 -2.(incremented by 1, defaut first value is 0)

#include <stdio.h>
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20, // use comma. For union and struct all use semicolon.
    spades = 3  // there is no comma
} card;
enum suit card1;
int main() 
{
  card = club;
	printf("Size of enum variable = %d bytes", sizeof(card));	
	return 0;
}
   

#include <stdio.h>

enum designFlags {
	BOLD = 1,
	ITALICS = 2,
	UNDERLINE = 4
};

int main() {
	int myDesign = BOLD | UNDERLINE; 

        //    00000001
        //  | 00000100
        //  ___________
        //    00000101

	printf("%d", myDesign);

	return 0;
}

```
>However, you cannot change the values in an enumeration once it has been defined; they are constant values!
```C
enum fruit {banana, apple, blueberry, mango};
banana = 15;  /* You can’t do this! */

```

2. Union:A union is a custom data type used for storing several variables in the same memory space. Assigning a value to one of them overwrites the values in the others. Use `semicolon` between. The size of union is equal to the size o fits largest number. 
```C
//Define and declarasion
union numbers
  {
    int i;
    float f;
  };
union numbers first_number = { 5 };

union numbers
  {
    int i;
    float f;
  } first_number = { 5 };

union numbers first_number = { .f = 3.14159 };
union numbers first_number = { f: 3.14159 };
first_number.i = 5;
first_number.f = 3.9; //This will overrides the value in i.  
```

3. A structure is a programmer-defined data type made up of variables of other data types (possibly including other structure types).
```C
//Define and declaration
struct point
  {
    int x, y;
  };
struct point first_point, second_point;


struct point
  {
    int x, y;
  };
struct point first_point = { 5, 10 };

struct point
  {
    int x, y;
  } first_point = { 5, 10 };

struct point first_point = { .y = 10, .x = 5 };
struct point first_point = { y: 10, x: 5 };

struct point
  {
    int x, y;
  };

struct point first_point;

first_point.x = 0;
first_point.y = 5;

```
Example:  pointer to the struct. ptr-> is *ptr.
```C
#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;   

    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);
//personPtr->age is equivalent to (*personPtr).age
    return 0;
}
```


4. Bit Fields are struct of `integer members` of nonstandard sizes, called bit fields. You do this by specifying an integer (int, char, long int, etc.) member as usual
  ```C
struct card
  {
    unsigned int suit : 2;
    unsigned int face_value : 4;
  };


struct {
   unsigned int age : 3;
} Age;

int main( ) {

   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );

   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );

   Age.age = 8;
   printf( "Age.age : %d\n", Age.age );

   return 0;
}
  
  ```
  > That example defines a structure type with two bit fields, suit and face_value, which take up 2 bits and 4 bits, respectively. suit can hold values from 0 to 3, and face_value can hold values from 0 to 15. Notice that these bit fields were declared as unsigned int; had they been signed integers, then their ranges would have been from -2 to 1, and from -8 to 7, respectively.

  > Cannot take the address opertor & for the bit field.



## 3.7. Data Storage Specifier
> The coverage of the data and property of the data. const volatile auto static globle extern 
 - const: Read only after initilization. Tell the compiler that it is good for optimization.
 - volatile: The data is explicitly changeable. Tell the compiler that do not optimizer the `seemingly useless access to this data`. Consider the same code in L1_2.c. 
  
```C
// L1_2.c  Example to solve the undefined problem.
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
int main () { foo(100); foo(0x7fffffff); return 0; }   if (a + 100 > a)
        printf("%d GT %d\n", a + 100, a);
    else
        printf("%d LT %d\n", a + 100, a);
// use volatile, the optimization is disable. Overflow will taken into account. The positive number will become negative number. 
```
    > Another example for volatile is for the embedded system control. A lot of subfunctions and a lot of interrupt can happen. Do not optimize the data.  
- auto , register: Register is the same with auto but will be heavily used. perish when the function or block is finished.
  
- static: opposite to auto, when applied to variables within a function
or block, retain their value even when the function or block is finished.
 > You can also declare variables (or functions) at the top level (that is, not inside a function) to be static; such variables are visible (global) to the current source file (but not other source files). 

- extern: globle to different source files.

 > Atomic is a new data specifier in new c language. 

# 4. Operation and Loop Control State


# 5. Function
> Function is used as a independent subroutine. With the increasing of the code, different subroutine may interfere with each other. Problems comes: 
> - How to make functions to be independent without each others since they work on the same piece of hardware.
> - How to make the function to be determinstic? Several interrupt or function deal with the same piece of memory. Change or not change?
> - We don't want too many data connection between the functions. And also we would like to have a way to share the same data between functions.  

## 5.1. Declare and Definition
    - Data type should be in consistancy. check [Code L5_1](L5_1.c). 



## 5.2. Arguments and shared memory
   > Arguments are used to avoid data connection between the functions. 
   - [ ] [Passing Reference or duplicate the data. THis is a problem](http://www.trytoprogram.com/c-programming/c-programming-function-arguments/#:~:text=C%20programming%20function%20arguments%20also,carry%20out%20the%20specified%20task.) 

```C
void Strfun(char *ptr)// change this to char a[], it is the same 
{
    printf("The String is : %s",ptr);
}

// main function
int main()
{
	// Declare a buffer of type "char"
	char buff[20]="Hello Function";
	
	// Passing string to Function
	Strfun(buff);
	
	return 0;
}

```
- [ ] For the int number, the passing to function is to dumplicate the data. However, if used the string/array/pionter, only reference address is is passing to the function. In this way, it can allow the control the access to the data.  Please check [Code L5_2](L5_2.c). This is very different from passing an int data.

## 5.3. Scope of shared memory, Header, and linker
> The arguments is a good way to share data between functions using duplicating the data or sending the reference. However, when the code becomes toooo large and requires a lot of datas connections, then we need to use headers to holder all the external datas for the functions. Using a file to for sharing the data. In this sense,`headers for external variable has no difference for passing a huge number of arguments instead of declaration all of the variables.`

   1. Headers will declare the functions and datas. gcc Linker will try to find out the definition of these function in the preprocessing stage using make file. 
   ```Makefile
    gcc main.c getline.c strindex.c
   ```
   This can be greate helpful to reduce the compiler time. With getline.out and strindex.out. There is not need to compile these file again when the other functions use them. That's the power of the make file. We don't need to include "getline.c" in the main function file since the linker will later find them out. 


  2. <>  and ""
   > <stdio.h>  Lookinto it. It only declare the functions. Definition of the functions are inside the system default trajectory. So we don't include them in the compiler. However, " " means the user defined header for declaration using the directory. The user should also define the functions declared. 


  3. Same function Name problem
   This is not supported by the C language. C++ support it with function reloading.  std::printf.   using namespace std; std::



   ## 5.4. Static Function

1. Static function. The static function can only be used in the files it `defines`. It cannot be used with delcaration. Check the [L5_3 example](L5_3_M.c).
   



2. Preprocessing of the functions. The integer a defined in the function will defined before entering the main function. The variable a will be defined at the preprocessing stage of the gcc compiler when you use include "func.c". 
  
 ```C
#include <stdio.h>
volatile int a =2; //check where it is initilze
 void staticFunc(void)
{
     volatile int b=3;  //remove the static 
   printf("Inside the static function staticFunc()\n");
}
//subfunction
 ```

```C
#include <stdio.h>
#include "L5_3_F1.c" 
int main()
{
  staticFunc(); //Don't need to declare it.
   a++;
   return 0;
}
// #include "L5_3_F1.c" will directly copy the this file in this place in the main file. So we don't need to delcare variable a again in the main file. It will find out a.
```

> However, When you use gcc file1.c file2.c. It will cause **problems**
 ```C
#include <stdio.h>
volatile int a =2; //check where it is initilze
 void staticFunc(void)
{
     volatile int b=3;  //remove the static 
   printf("Inside the static function staticFunc()\n");
}
//subfunction
 ```

```C
#include <stdio.h>
// #include "L5_3_F1.c"  
int main()
{
   void staticFunc(void); // Have to declare it
   extern volatile int a; // Have to declare variable a. 
   staticFunc();
   a++;
   return 0;
}
// use gcc fi1e1.c file2.c. It will lead to failure since variable a is not defined in the main.
```
## 5.5. Recurrsion and pop()-pop()
> Writing recurrsion requires to avoid infinitely loop. Recurrsion is extensively used in the interview. Less is more. Recurrsion makes computer to be powerful. It is not a calculator with it with numerical element calculation. This makes computer good at numerical computation.Reading the joserph documents. 

```C
int factorial (int x)
{
  if (x < 1)
    return 1;
  else
    return (x * factorial (x - 1));
}
```
> For a stack , pop()-pop() will cause error since we didn't know which pop out will calculte first. underfined state. 

1. Tail Recursion to find a maximum value in a array a[n].
```C
  int n;
  double max_value( double a [])
  {
    double temp;
      for (i=0; i<=n-2; i++) 
    {
      if(a[i]>a[i+1]) {temp=a[i]; a[i]=a[i+1];a[i+1]=temp; }
      return a[n-1];

    }
  }
// when using tail recursion.
int n;
double a[n];
double max(double a, double b) {a-b>0? a:b;}
double max_value (int n)
{
  if(n==1) 
    return a[0];
  else  
    return (max_value(n-2)-a[n-1]>0)? max_value(n-2):a[n-1];
}
  ```


2. Numerical Element parallel R resistor value
```C
double SR(int n, double r)
   if n==1; return r;
   else return 1/(1/SR(n-1,r)+1/r);

```


## 5.6. Exception Handling 










# 6. IO Stream , File Handler and Linux System

## IO STREAM
> LIke the fprintf(), fscanf(), fread(), fwrite() command. Serialread() and so on command. The input and output data are streamed into a file. That's why we can later dump all the data out. We can read when each data comes in. Or we can read when trigger is hitted. In this way, the cpu (extremely high speed) don't need to waste too much effort to to fetch read and write IO. It will deal with the stream file in frame after another frame. 

> Compare delay() function and minilus(). And the introduction of the `southbridge` hardware in the computer to contrl the slow IOs using interrupts. 

> The introduction of stream and file can continously dump out the file without losing the data. In normal situation, after fopen(s1) function ran, the data accepted in this function is `terminated.` This problem is solve using another layer of indirection.  `sourthbridge IC` and hardware interrupts. The data is streamed into the file. The `southbridge ic ` wil l interrputs the CPU when necessary. Understanding `Stream`

```Matlab
% This is the code written in matlab for serial comm. in C is similar
clc; clear; close all;
s1=serial("COM6",'BaudRate', 230400,'DataBits',8);
s1.Terminator='CR/LF';
s1.InputBufferSize=400*3*2*2;  %hit the maximum buffer. It will stop.
fopen(s1);
while(1) {
  a=fscanf(s1); % dump out the buffer in the file when hit maximum buffer or when terminator is hit. The stream is always on!!! until fclose
% decode and plot data
  pause(0.1); % CPU don't deal with this code. But `southbridge ic` is still streaming. This is so-called stream.

}
fclose(s1)  %stream never stops
```


## File Handle
> File pointer points to a **structure** that contains information about file such as buffer, baudrate, terminator and so on. User don't need to know the details.

```C
FILE *fp; // a pointer to FILE
FILE *fopen(char *name, char *mode); // Function return type is a pointer to FILE

fp=fopen(name, mode);

//The definition is shown in stdio.h

```