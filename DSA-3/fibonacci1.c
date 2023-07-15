#include<stdio.h>
#include<math.h>
#include<time.h>
unsigned long long int fibonacci(unsigned long long int f1,unsigned long long int f2,unsigned long long int count){
	static int n=1;
	//printf("%lld \n",f3);
	if(n==count)	
		return f1;
	unsigned long long int f3=f1+f2;
	n++;
	return fibonacci(f2,f3,count);
}
int fib(int n){
    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
/*
int main(){
	int count;
	printf("Enter the number of terms required\n");
	scanf("%d",&count);
	printf("Fibonacci numbers:\n");
	fibonacci(0,1,count);
	return 0;
}*/

int main(){
    //printf("%lld",fibonacci(0,1,1000));
	clock_t start, end;
	int n = 10;
	start = clock();
	printf("%lld",fibonacci(0,1,n));
	//printf("%lld",fib(50));
	end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime Taken by program = %lfs",cpu_time_used);
	printf("\n");
	start = clock();
	//printf("%lld",fibonacci(0,1,50));
	printf("%d",fib(n));
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime Taken by program = %lfs",cpu_time_used);
	printf("\n");
	
    return 0;
}