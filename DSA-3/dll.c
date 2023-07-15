#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
typedef struct node *NODE;

NODE getnode()
{
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\n\nINSUFFICIENT MEMORY\n\n");
        exit(0);
    }
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void InsertFirst(int x)
{
    NODE p;
    p = getnode();
    p->data = x;

    p->next = start;
    if (start != NULL)
        start->prev = p;
    start = p;
}
int DeleteFirst()
{
    struct node *p;
    if (start == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    p = start;
    int x = p->data;
    start = start->next;
    if (start != NULL)
        start->prev = NULL;
    printf("Deleted Element is %d\n", x);
    free(p);
    return x;
}
void InsertLast(int x)
{
    struct node *p, *last;
    p = getnode();
    p->data = x;
    if (start == NULL)
    {
        start = p;
        return;
    }
    last = start;
    while (last->next != NULL)
        last = last->next;
    last->next = p;
    p->prev = last;
}
int DeleteLast(int x)
{
    NODE last;
    if (start == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    last = start;
    while (last->next != NULL)
        last = last->next;
    int x = last->data;
    if (start == last)
        start = NULL;
    else
        (last->prev)->next = NULL;
    printf("Deleted Element is  %d", x);
    free(last);
    return x;
}
void InsertAfter(int x, int y)
{
    NODE r, p;
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            r = getnode();
            r->data = y;
            r->next = p->next;
            r->prev = p;
            if (r->next != NULL)
                (r->next)->prev = r;
            p->next = r;
            return;
        }
        p = p->next;
    }
    printf("Element %d not found. Failed!!\n,x");
    return;
}
void InsertBefore(int x, int y)
{
    NODE r, p;
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            r = getnode();
            r->data = y;
            r->next = p;
            r->prev = p->prev;
            (p->prev)->next = r;
            p->prev = r;
            return;
        }
        p = p->next;
    }
    printf("Element %d not found. Failed!!\n,x");
    return;
}
int DeleteAfter(int x)
{
    NODE p, r;
    if (start == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            r = p->next;
            if (r == NULL)
            {
                printf("Void Deletion\n");
                return -1;
            }
            int x = r->data;
            p->next = r->next;
            (r->next)->prev = p;
            free(r);
            return x;
        }
        p = p->next;
    }
    printf("Element %d not found. Failed!!\n,x");
    return -1;
}
int DeleteBefore(int x)
{
    NODE p, r;
    if (start == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            if (p == start)
            {
                printf("No element before %d\n", x);
                return -1;
            }
            r = p->prev;
            int x = r->data;
            if (r == start)
            {
                start = start->next;
                start->prev = NULL;
                free(r);
                return x;
            }
            (r->prev)->next = p;
            p->prev = r->prev;
            free(r);
            return x;
        }
        p = p->next;
    }
    printf("Element %d not found. Failed!!\n,x");
    return -1;
}
