#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 100
/* Linked list node */

struct node
{
	char data;
	struct node *lc;
	struct node *rc;
};

typedef struct node *NODE;
struct stack
{
	NODE items[STACKSIZE];
	int top;
};
/* Function to create a newnode */
struct node *GetNode()
{
	struct node *p;
	p = (NODE)malloc(sizeof(struct node));
	if (p == NULL)
	{
		printf("Insufficient Memory");
		exit(0);
	}
	p->lc = NULL;
	p->rc = NULL;
	return p;
}

void push(struct stack *s, NODE p)
{
	if (s->top == STACKSIZE)
	{
		printf("STACK FULL!!!!!!!!");
		exit(0);
	}
	s->top++;
	s->items[s->top] = p;
}

NODE pop(struct stack *s)
{
	NODE p;
	if (s->top == -1)
	{
		printf("STACK EMPTY!!!!!!!!");
		exit(0);
	}
	p = s->items[s->top];
	s->top--;
	return p;
}
int isPrecedence(char x)
{
	switch (x)
	{
	case '+':
	case '-':
		return 1;
	case '/':
	case '*':
		return 2;
	case '^':
		return 3;
	case '(':
		return 0;
	}
}

NODE CreateExpTree(char a[])
{
	struct stack opers, opnds;
	opers.top = -1;
	opnds.top = -1;
	// printf("%s",a);
	int i = 0;
	char symb;
	NODE p, q, r, r1, r2;

	while (a[i] != '\0')
	{
		symb = a[i++];
		// printf("%c",symb);
		p = GetNode();
		p->data = symb;
		if (symb == '(')
		{
			push(&opers, p);
		}
		else if (symb == ')')
		{
			q = pop(&opers);
			free(p);
			while (q->data != '(')
			{
				r2 = pop(&opnds);
				r1 = pop(&opnds);
				q->lc = r1;
				q->rc = r2;
				push(&opnds, q);
				q = pop(&opers);
			}
		}
		else if (isalpha(symb))
			push(&opnds, p);
		else if (symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '^')
		{
			if (isPrecedence(symb) == 3)
				push(&opers, p);
			else
			{
				while (opers.top!=-1 && isPrecedence((opers.items[opers.top])->data) >= isPrecedence(symb))
				{
					q = opers.items[opers.top];
					if (isPrecedence(q->data) >= isPrecedence(symb))
					{
						r2 = pop(&opnds);
						q = pop(&opers);
						r1 = pop(&opnds);
						q->lc = r1;
						q->rc = r2;
						push(&opnds, q);
					}
					else
						break;
				}
				push(&opers, p);
			}
		}
		else{
			printf("\nInvalid entry %c\n",symb);
			exit(0);
		}
	}

	while (opers.top != -1)
	{
		q = pop(&opers);
		r2 = pop(&opnds);
		r1 = pop(&opnds);
		q->lc = r1;
		q->rc = r2;
		push(&opnds, q);
	}

	return (pop(&opnds));
}

void pretrav(NODE p)
{
	if (p != NULL)
	{
		printf("%c", p->data);
		pretrav(p->lc);
		pretrav(p->rc);
	}
}

void intrav(NODE p)
{
	if (p != NULL)
	{
		if (p->lc != NULL)
			printf("(");
		intrav(p->lc);
		printf("%c", p->data);
		intrav(p->rc);
		if (p->rc != NULL)
			printf(")");
	}
}

void postrav(NODE p)
{
	if (p != NULL)
	{
		postrav(p->lc);
		postrav(p->rc);
		printf("%c", p->data);
	}
}

int main()
{
	NODE tree = NULL;
	char ch;
	int i = 0;
	char a[50];
	printf("Enter infix expression\n");
	scanf("%s", a);
	tree = CreateExpTree(a);
	printf("\nInfix Expression\n");
	intrav(tree);
	printf("\nPostfix Expression\n");
	postrav(tree);
	printf("\nPrefix Expression\n");
	pretrav(tree);
	printf("\n");
}