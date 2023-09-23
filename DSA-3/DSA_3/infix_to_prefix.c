#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 100
typedef struct{
	int top;
	char item[STACKSIZE];
}stack;
void str_rev(char *s){
	int i,n=strlen(s);
	char ch;
	for(i=0;i<n/2;i++){
		ch=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=ch;
	}
	return;
}

void push(stack *s, char num){
	if(s->top==STACKSIZE-1){
		printf("\nOVERFLOW\n");
		exit(0);
	}
	s->top++;
	s->item[s->top]=num;
	return;
}
char pop(stack *s){
	if(s->top==-1){
		printf("\nUNDERFLOW\n");
		exit(0);
	}
	char num;
	num=s->item[s->top];
	s->top--;
	return num;
}
char TOP(stack *s){
	if(s->top==-1){
		return '\0';
	}
	return (s->item[s->top]);
}
int Precedence(char op){
	switch(op){
		case '-':

		case '+': return 1;

		case '*':
		case '/': return 2;

		case '^': return 3;
		case ')':
		case '(':
		case '\0': return 0;
		default: printf("INVALID OPERATOR %c\n",op);
			 exit(0);
	}
}
void INFIX_TO_PREFIX(char *in,char *px){
	int i=0,j=0;
	char topch;
	stack s;
	s.top=-1;
    	i=strlen(in)-1;
	//printf("%s %d",in,s.top);

	while(i!=-1){
		if(in[i]>='a'&&in[i]<='z'){
			px[j]=in[i];
			j++;
		}
		else if(Precedence(in[i])==3)
			push(&s,in[i]);

		else if(Precedence(TOP(&s))<Precedence(in[i])||in[i]==')')
			push(&s,in[i]);

		else if(in[i]=='('){
			topch=pop(&s);
			while(topch!=')'){
				px[j]=topch;
				j++;
				topch=pop(&s);
			}
		}

		else if(Precedence(TOP(&s))>=Precedence(in[i])){
			while(Precedence(TOP(&s))>=Precedence(in[i])){
				topch=pop(&s);
				px[j]=topch;
				j++;
			}
			push(&s,in[i]);
		}
		i--;
	}
	while(s.top!=-1){
		topch=pop(&s);
		if(topch!=')'){
			px[j]=topch;
			j++;
		}
	}
	px[j]='\0';
	str_rev(px);
	return;				
}
int main(){
	char in[STACKSIZE];
	char px[STACKSIZE];
	printf("Enter the expression to evaluate: ");
	scanf("%s",in);
	INFIX_TO_PREFIX(in,px);
	printf("Prefix expression: ");
	printf("%s",px);
	printf("\n");
	return 0;
}
