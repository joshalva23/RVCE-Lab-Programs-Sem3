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
void insertfirst(int x){
    NODE p;
    p=getnode();
    p->item=x;
    if(REAR == NULL){
        REAR=p;
        return;
    }
    p->next = REAR->next;
    REAR->next=p;
    return;
}
void insertlast(int x){
	NODE p = getnode();
	p->item=x;
	if(REAR==NULL){
		REAR=p;
		return;
	}
	p->next=REAR->next;
	REAR->next=p;
	REAR=p;
	return;
}
int deletefirst(){
	if(REAR==NULL){
		printf(" UNDERFLOW\n");
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
int deletelast(){
    NODE p;
    if(REAR == NULL){
        printf(" UNDERFLOW\n");
        return -1;
    }
    NODE p = REAR->next;
    while(p->next!=REAR)
        p=p->next;
	int x=REAR->item;
    p->next=REAR->next;
    if(p==REAR){
        p=NULL;
    }
	free(REAR);
    REAR=p;
	return x;
}
void display(){
	if(REAR==NULL){
                printf(" UNDERFLOW\n");
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
