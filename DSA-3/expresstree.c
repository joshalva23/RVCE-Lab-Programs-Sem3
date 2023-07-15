#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 100
/* Linked list node */

struct node
{
    int data;
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
int icp(char x)
{
    switch (x)
    {

    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 3;
    case '^':
        return 6;
    }
}
int isp(char x)
{
    switch (x)
    {

    case '+':
    case '-':
        return 2;
    case '/':
    case '*':
        return 4;
    case '^':
        return 5;
    }
}
NODE CreateExpTree(char a[])
{
    struct stack opers, opnds;
    opers.top = -1;
    opnds.top = -1;

    int i = 0;
    char symb;
    NODE p, q, r, r1, r2;

    while (a[i] != '\0')
    {
        symb = a[i++];
        // printf("%c",symb);
        p = GetNode();
        p->data = symb;
        if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z'))
            push(&opnds, p);
        else if (symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '^')
        {

            while (opers.top != -1)
            {
                q = opers.items[opers.top];
                if (isp(q->data) >= icp(symb))
                {
                    q = pop(&opers);
                    r2 = pop(&opnds);
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
        intrav(p->lc);
        printf("%c", p->data);
        intrav(p->rc);
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
    printf("Eter infix expression\n");
    scanf("%s", a);
    tree = CreateExpTree(a);
    printf("\nInfix Expression\n");
    intrav(tree);
    printf("\npostfix Expression\n");
    postrav(tree);
    printf("\nprefix Expression\n");
    pretrav(tree);
}
ijece @iaesjournal.com >