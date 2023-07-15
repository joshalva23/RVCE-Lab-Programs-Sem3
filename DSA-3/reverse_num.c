#include<stdio.h>
#include<math.h>
int rev_num(int num1,int num2,int n){
	static int count=0;
	int rem=num1%10;
	num1=num1/10;
	num2+=rem*pow(10,n-count-1);
	if(count==n-1)
		return num2;
	count++;
	return rev_num(num1,num2,n);
}
int len(int num){
	static int count=0;
	int rem=num%10;
	num=num/10;
	if(rem==0)
		return count;
	count++;
	return len(num);
}
int mod_rev(int rev,int num){
	if(num>0){
		int digit=num%10;
		rev=rev*10+digit;
		return mod_rev(rev,num/10);
	}
	else
		return rev;
}
int main(){
	int num;
	printf("Enter number\n");
	scanf("%d",&num);
	printf("Reversed Number is %d\n",rev_num(num,0,len(num)));
	printf("Reversed Number is %d\n",mod_rev(0,num));
	return 0;
}

