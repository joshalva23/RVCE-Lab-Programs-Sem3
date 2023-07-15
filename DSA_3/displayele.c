#include<stdio.h>
void display(int *a,int n){
	static int count=0;
	printf("%d ",a[count]);
	count++;
	if(count==n)
		return;
	display(a,n);
}
int main(){
	int a[10],n,i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The array elements are ");
	display(a,n);
	printf("\n");
	return 0;
}