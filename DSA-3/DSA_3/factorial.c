#include<stdio.h>
int fact(int num){
	if(num==1)
		return num;
	return num*fact(num-1);
}
int main(){
	int num,numfact;
	printf("Enter the number:\n");
	scanf("%d",&num);
	numfact=fact(num);
	printf("The factorial of %d is %d\n",num,numfact);
	return 0;
}