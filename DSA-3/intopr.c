#include<stdio.h>
#include<string.h>
#define STACKSIZE 10
typedef struct{
	int top;
	char item[STACKSIZE];
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
int Precedence(char op){
	switch(op){
		case '-':

		case '+': return 1;

		case '*':
		case '/': return 2;

		case '^': return 3;
		default: return 0;
	}
}
void INFIX_TO_PREFIX(char *in,char *px){
	int i,j=0;
	char topch;
	stack s;
	s.top=-1;
    i=strlen(in)-1;
	//printf("%s %d",in,s.top);

	while(i >= 0){
		if(in[i]>='a'&&in[i]<='z'){
			px[j]=in[i];
			j++;
		}
		//else if(Precedence(in[i])==3)
			//push(&s,in[i]);

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
		px[j]=topch;
		j++;
	}
	px[j]='\0';
    strrev(px);
	return;				
}
int main(){
	char in[STACKSIZE];
	char px[STACKSIZE];
	printf("Enter the expression to evaluate: ");
	scanf("%s",in);
	printf("Prefix expression: ");
	INFIX_TO_PREFIX(in,px);
	printf("%s",px);
	printf("\n");
	return 0;
}
