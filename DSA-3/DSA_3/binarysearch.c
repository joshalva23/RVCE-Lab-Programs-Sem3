#include<stdio.h>
int binsearch(int *a,int ele,int first,int last){
	int mid=(first+last)/2;
	if(first<=last){
        
		if(a[mid]>ele)
			last=mid-1;
		else if(a[mid]<ele)
			first=mid+1;
		else if(a[mid]==ele)
			return mid;
        if(first==last)
            return -1;
	}
	return binsearch(a,ele,first,last);
}
int main(){
	int a[10],n,ele,pos,i;
	printf("Number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter search element\n");
	scanf("%d",&ele);
	pos=binsearch(a,ele,0,n-1);
	if(pos==-1)
		printf("Element does not exist\n");
	else
		printf("Element is at %d position\n",pos);
	return 0;
}
