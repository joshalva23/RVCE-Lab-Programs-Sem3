//Recursive Linear Search
#include<stdio.h> 
int linsearch(int *a,int ele,int n){
	static int count=0;
	if(a[count]==ele)
		return count;
	count++;
	if(count==n)
		return -1;
	return linsearch(a,ele,n);
}
int main(){
	int a[10],n,ele,pos,i;
	printf("Number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Search element??\n");
	scanf("%d",&ele);
	pos=linsearch(a,ele,n);
	if(pos==-1)
		printf("Element does not exist in array\n");
	else
		printf("Element is at %d position\n",pos);
	return 0;
}