
#include<stdio.h>
int main(){
	float sum=0.0f;
	int sum1=0;
	for (int i=0;i<10000;i++) {
	sum +=i+1;
	sum1 +=i+1;
	}
	printf("Sum:%f\n",sum);
	printf("Sum1:%d\n",sum1);
	printf("Sum of 1.3+50005000.0:%f\n",1.3f+50005000.0f);
	return 0;

} 
