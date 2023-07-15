#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUESIZE 100
typedef struct
{
	int front;
	int rear;
	char items[QUEUESIZE][200];
} queue;
void enqueue(queue *q, char *msg)
{
	if ((q->rear + 1) % QUEUESIZE == q->front)
	{
		printf("\nOVERFLOW\n");
		exit(0);
	}
	q->rear = (q->rear + 1) % QUEUESIZE;
	strcpy(q->items[q->rear], msg);
}
void dequeue(queue *q, char *msg)
{
	if (q->rear == q->front)
	{
		printf("\nUNDERFLOW\n");
		exit(0);
	}
	q->front = (q->front + 1) % QUEUESIZE;
	strcpy(msg, q->items[q->front]);
}
void display(queue *q)
{
	int i, pos;
	if (q->rear == q->front)
	{
		printf("\nUNDERFLOW\n");
		return;
	}
	printf("Messages in the queue are \n");
	pos = (q->front + 1) % QUEUESIZE;
	for (i = 0; pos <= q->rear; i++)
	{
		printf("%s\n", q->items[pos]);
		pos = (pos + 1) % QUEUESIZE;
	}
	return;
}
int main()
{
	int choice;
	char x[200];
	queue msq = {QUEUESIZE - 1, QUEUESIZE - 1};
	printf("Welcome to circular message queue\n");
	while (1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the input message: ");
			scanf("%s", x);
			enqueue(&msq, x);
			break;
		case 2:
			dequeue(&msq, x);
			printf("Removed message : %s", x);
			break;
		case 3:
			display(&msq);
			break;
		case 4:
		default:
			printf("\nEXIT\n");
			exit(0);
		}
	}
}
