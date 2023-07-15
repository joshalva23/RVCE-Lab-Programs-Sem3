#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Linked list node */
struct node
{
   int r, c, data;
   struct node *next;
   struct node *prev;
};

typedef struct node *NODE;

/* Function to create a newnode */
struct node *getnode()
{
   struct node *p;
   p = (NODE)malloc(sizeof(struct node));
   if (p == NULL)
   {
      printf("Insufficient Memory");
      exit(0);
   }
   p->next = NULL;
   p->prev = NULL;
   return p;
}

/* Function to insert a node at last*/
void SaerchAndInsert(NODE list, int x, int i, int j)
{
   struct node *p, *q;

   p = getnode();

   p->data = x;
   p->r = i;
   p->c = j;
   if (list == NULL)
      return p;
   q = list;
   while (1)
   {
      if ((q->r > i) || (q->r == i && q->c > j))
      {
         p->next = q;
         p->prev = q->prev;
         if (q->prev != NULL)
            q->prev->next = p;
         else
            list = p;
         q->prev = p;
         break;
      }

      if (q->next == NULL)
      {
         q->next = p;
         p->prev = q;
         break;
      }
      q = q->next;
   }
}

NODE InserLast(NODE list, int x, int i, int j)
{

   NODE q, p;

   p = getnode();
   p->data = x;
   p->r = i;
   p->c = j;
   if (list == NULL)
      return p;
   q = list;
   while (q->next != NULL)
      q = q->next;
   q->next = p;
   p->prev = q;
   return list;
}

int main()
{
   NODE list = NULL, p;
   int m, n, i, j, element, zero = 0;
   printf("Enter the Order of the Matrix");
   scanf("%d%d", &m, &n);
   printf("Enter the elements");

   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &element);
         if (element != 0)
            list = InserLast(list, element, i, j);
      }
   }
   printf(" The matrix is \n");
   p = list;
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (p != NULL && p->r == i && p->c == j)
         {
            printf("%4d ", p->data);
            p = p->next;
         }
         else
            printf("%4d", zero);
      }
      printf("\n");
   }
   return 0;
}