#include<stdio.h>

int* rev(int a[], int i,int n)
{
    if(i>=n/2)
        goto out;
    a = rev(a, ++i, n);
    a[i] = a[n-i-2];
out:
    return a;
}
void main()
{
    int a[8]={1,2,3,4,5,6,7,8}, n =8, *p;
    p = rev(a, 0, 8);
    for(int i = 0; i < n; i++)
        printf("%d\n",p[i]);
}