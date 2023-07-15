#include<stdio.h>
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
	printf("Reversed Number is %d\n",mod_rev(0,num));
	return 0;
}

