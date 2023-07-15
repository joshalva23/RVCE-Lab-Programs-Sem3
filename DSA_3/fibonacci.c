#include<stdio.h>
void fibonacci(int f1,int f2,int count){
	static int n=0;
	
    int f3=f1+f2;
	printf("%d \n",f1);
	n++;
	if(n==count)	
		return;
	fibonacci(f2,f3,count);
}
int main(){
	int count;
	printf("Enter the number of terms required\n");
	scanf("%d",&count);
    if(count>0){
        printf("Fibonacci numbers:\n");
        fibonacci(0,1,count);
    }
	return 0;
}