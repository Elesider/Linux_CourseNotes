# include<stdio.h>
void Strfun(char a[])
{
    printf("The String is : %s",a);
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


// Be carefull, in this case, the address of buff array is passed
// a[]. In this case, a and buff are pointing to the same address!
//gdb shows that a is an alias of buff with the same address.