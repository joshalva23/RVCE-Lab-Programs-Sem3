#include<stdio.h>
int mul(int a, int b)
{
    return a*b;
}
float divide(float a, float b)
{
    float q = a/b;
    printf("\n%d %d\n",a,b);
    return q;
}