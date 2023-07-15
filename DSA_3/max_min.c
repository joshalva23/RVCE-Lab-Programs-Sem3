#include<stdio.h>
int max(int *a,int n,int l){
	if(a[n]>l)
		l=a[n];
	if(n==0)
		return l;
	n--;
	return max(a,n,l);
}
int min(int *a,int n, int s){
	if(a[n]<s)
		s=a[n];
	if(n==0)
		return s;
	n--;
	return min(a,n,s);
}
int main(){
	int a[10],n,i;
	printf("Number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The maximum is %d\n",max(a,n-1,0));
	printf("The minimum is %d\n",min(a,n-2,a[n-1]));
	return 0;
}