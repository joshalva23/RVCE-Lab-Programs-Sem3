#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 100
typedef struct{
	int top;
	float item[STACKSIZE];
}stack;
void push(stack *s, float num){
	if(s->top==STACKSIZE-1){
		printf("\nOVERFLOW\n");
		exit(0);
	}
	s->top++;
	s->item[s->top]=num;
	return;
}
float pop(stack *s){
	if(s->top==-1){
		printf("\nUNDERFLOW\n");
		exit(0);
	}
	float num;
	num=s->item[s->top];
	s->top--;
	return num;
}
float TOP(stack *s){
	if(s->top==-1){
		return '\0';
	}

	return (s->item[s->top]);
}
float calc(char op,float op1,float op2){
	switch(op){
		case '+': return (op1+op2);
		case '-': return (op1-op2);
		case '*': return (op1*op2);
		case '/': return (op1/op2);
		case '^': return pow(op1,op2);
		default:exit(0);
	}
}
void PREFIX_TO_OUTPUT(char* px,float* val){
	int i;
	stack s={-1};
	float opnd1,opnd2;
	char symb;
	i=strlen(px)-1;
	//printf("%s",px);
	while(px[i]!='\0'){
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
	printf("The output is %lf\n",pop(&s));
}
int main(){
	float val[STACKSIZE];
	int i,j=0;
	char px[STACKSIZE];
	printf("Enter the prefix expression: ");
	scanf("%s",px);
	for(i=0;px[i]!='\0';i++)
		if(isalpha(px[i])){
			printf("Enter value for %c: ",px[i]);
			scanf("%f",&val[j]);
			j++;
		}
    
        PREFIX_TO_OUTPUT(px,val);
}
