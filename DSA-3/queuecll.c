#include<stdio.h>
#include<stdlib.h>
struct node {
	int item;
	struct node *next;
}*REAR=NULL;

typedef struct node* NODE;
NODE getnode(){
	NODE p=(NODE) malloc( sizeof(struct node) );
	if(p == NULL){
		printf("Insufficient Memory\n");
		exit(0);
	}
	p->next=p;
	return p;
}
void insertlast(int x){
	NODE p = getnode();
	p->item=x;
	if(REAR==NULL){
		REAR=p;
		return;
	}
	/*
	 if(q->next=q){
	 	p->next=q;
		q->next=p;
		return;
	}*/
	p->next=REAR->next;
	REAR->next=p;
	REAR=p;
	return;
}
int deletefirst(){
	if(REAR==NULL){
		printf("QUEUE UNDERFLOW\n");
		exit(0);
	}
	if(REAR->next==REAR){
		int x=REAR->item;
		free(REAR);
		REAR=NULL;
		return x;
	}
	NODE p = REAR->next;
	REAR->next=p->next;
	int x=p->item;
	free(p);
	return x;
}
void display(){
	if(REAR==NULL){
                printf("QUEUE UNDERFLOW\n");
                return;
        }
	NODE p=REAR->next;
	printf("The elements in the queue:\n");
	do{
		printf("%d ",p->item);
		p=p->next;
	}while(p!=REAR->next);
	printf("\n");
}
int main(){
	int choice,x;
	printf("Welcome to the queue \n");
	while(1){
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the element:");
				scanf("%d",&x);
				insertlast(x);
				break;
			case 2: x=deletefirst();
				printf("Deleted element %d\n",x);
				break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}
