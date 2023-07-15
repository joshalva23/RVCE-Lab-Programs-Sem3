#include<stdio.h>
#define STACKSIZE 100

typedef struct{
    int top;
    int item[STACKSIZE];
}stack;

void push(stack *s,int ele){
    if(s->top==STACKSIZE-1){
        printf("STACK OVERFLOW\n");
        return;
    }
    s->item[++(s->top)]=ele;
    return;
}

int pop(stack *s){
    if(s->top==-1){
        printf("STACK UNDERFLOW\n");
        return -999;
    }
    return s->item[(s->top)--];
}

int* popn(stack *s,int n){
    int a[STACKSIZE];
    if(n>s->top+1){
        printf("INSUFFICIENT ELEMENTS\n");
        return NULL;
    }
    for(int i=0;i<n;i++){
        a[i]=pop(s);
    }
    return a;
}