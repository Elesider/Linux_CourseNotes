// This example shows the Operation of the call functions
// turn char []='-12.06'to int -12.06;
#include <ctype.h> 
double atof(char s[])
{
  double val, power;
  int i, sign;
  for(i=1; isspace(s[i]); i++){
    ;
  }
  sign=(s[i]=='-')?-1:1;
  for (val=0.0; isdigit(s[i]);i++)
  {
    val=10*val+s[i]-'0' //do not consider data rounding loss. 

  }
   if (s[i]=='.') {i++}
   for (power=1.0; isdigit(s[i]);i++)
  {
    val=10*val+s[i]-'0'; //do not consider data rounding loss. 
      power*=10;

  }

  return sign*val/(power);
    
}

//This check the main line[] and s[]. They duplicate or just alias? 
//
int getline(char s[], int max)
{
  int c, i;
  i=0;
  while(--max>0&&(c=getchar()!=EOF)&&c!='\n')
    s[i++]=c;
  if(c=='\n') s[i++]='\0';
  return i;
  
}

#include <stdio.h>
#define MAXLINE 100

int main ( )
{
double sum,atof(char[]);
char line[MAXLINE];
int getline(char line[], int max);
sum=0;
while (getline(line, MAXLINE)>0)
  printf("\t%g\n",sum+=atof(line));
return 0;
}

