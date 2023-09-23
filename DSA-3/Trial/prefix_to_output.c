#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 10
typedef struct{
	int top;
	int item[STACKSIZE];
}stack;
void push(stack *s, char num){
	if(s->top==STACKSIZE-1){
		//printf("\nOVERFLOW\n");
		return;
	}
	s->top++;
	s->item[s->top]=num;
	return;
}
char pop(stack *s){
	if(s->top==-1){
		//printf("\nUNDERFLOW\n");
		return '\0';
	}
	char num;
	num=s->item[s->top];
	s->top--;
	return num;
}
int ISFULL(stack *s){
	if(s->top==STACKSIZE-1){
		return 0;
	}
	return 1;
}
int ISEMPTY(stack *s){
	if(s->top==-1){
		return 0;
	}
	return 1;
}
char TOP(stack *s){
	if(s->top==-1){
		return '\0';
	}

	return (s->item[s->top]);
}
int calc(char op,int op1,int op2){
    switch(op){
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '^': return pow(op1,op2);
        default:exit(0);
    }
}
void PREFIX_TO_OUTPUT(char* px,int* val){
    int i;
    stack s={-1};
    int opnd1,opnd2;
    char symb;
    i=strlen(px)-1;
    //printf("%s",px);
    while(i>=0){
        
        if( px[i]>='a' && px[i]<='z'){
            opnd1=val[((int)px[i]-97)];
            push(&s,opnd1);
            //printf("%d",opnd1);
        }
        else{
            symb=px[i];
            opnd1=pop(&s);
            opnd2=pop(&s);
            opnd2=calc(symb,opnd1,opnd2);
            push(&s,opnd2);
        }
        i--;
    }
    printf("The output is %d",pop(&s));
}
int main(){
    int val[]={1,2,3};
    PREFIX_TO_OUTPUT("*+abc",val);
}
