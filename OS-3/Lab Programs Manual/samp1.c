#include<stdio.h>
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    printf("\nSum is %d",add(a,b));
    printf("\nDifference is %d",sub(a,b));
    printf("\nThe product is %d",mul(a,b));
    float q = divide(a,b);
    printf("\nThe quotient is %f\n",q);
}