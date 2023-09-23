#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* NODE;
int IsEmpty(NODE *START){
    if(*START==NULL)
        return 1;
    return 0;
}
struct node* GetNode(NODE *START){
    NODE p;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("INSUFFICIENT MEMORY\n");
        exit(0);
    }
    p->next=NULL;
    return p;
}
void InsertFirst(NODE *START,int x){
    NODE p;
    p=GetNode(START);
    p->data=x;
    p->next=*START;
    *START=p;
    return;
}
int DeleteFirst(NODE *START){
    NODE p;
    int x;
    if(IsEmpty(START)){
        printf("UNDERFLOW\n");
        return;
    }
    p=*START;
    *START=(*START)->next;
    printf("Deleted Element is %d\n",p->data);
    x=p->data;
    free(p);
    return x;
}
int Search(NODE *START,int x){
    NODE p;
    if(IsEmpty(START)){
        printf("UNDERFLOW\n");
        return 0;
    }
    p=*START;
    while(p!=NULL){
        if( p->data == x ){
            printf("Successful Search\n");
            return 1;
        }
        p=p->next;
    }
    printf("Unsuccessful Search\n");
    return 0;
}
void InsertLast(NODE *START,int x){
    NODE p;
    NODE q;
    p=*START;
    if(IsEmpty(START)){
        p=GetNode(START);
        p->data=x;
        p->next=NULL;
        *START=p;
        return;
    }
    while(p->next!=NULL)
        p=p->next;
    q=GetNode(START);
    q->data=x;
    q->next=NULL;
    p->next=q;
    return;
}
void InsertBefore(NODE *START,int x,int y){
    if(IsEmpty(START)){
        printf("Empty List\n");
        return;
    }
    NODE p=*START,prev,q;
    while(p!=NULL){
        if(p->data==x){
            q=GetNode(START);
            q->data=y;
            if(p==*START){
                q->next=*START;
                *START=q;
                return;
            }
            prev->next=q;
            q->next=p;
            return;
        }
        prev=p;
        p=p->next;
    }
    printf("Element %d isn't present\n",x);
    return;
}
void InsertAfter(NODE *START,int x,int y){
    if(IsEmpty(START)){
        printf("Empty Lits\n");
        return;
    }
    NODE p=*START,q;
    while(p!=NULL){
        if(p->data==x){
            q=GetNode(START);
            q->data=y;
            q->next=p->next;
            p->next=q;
            return;
        }
        p=p->next;
    }
    printf("Element %d isn't present\n",x);
    return;
}
int DeleteLast(NODE *START){
    NODE p;
    NODE q;
    p=*START;
    if(IsEmpty(START)){
        printf("Empty List\n");
        return;
    }
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    if(p==*START)
        START=NULL;
    q->next=NULL;
    int x=p->data;
    free(p);
    return x;
}
int DeleteBefore(NODE *START,int x){
    if(IsEmpty(START)){
        printf("Empty List\n");
        return;
    }
    NODE p=*START,prev=NULL,pprev=NULL;
    while(p!=NULL){
        if(p->data==x){
            pprev->next=p;
            if(p==*START){
                printf("No element before %d\n",x);
                return;
            }
            x=prev->data;
            free(prev);
            return x;        
            }
        pprev=prev;
        prev=p;
        p=p->next;
    }
    printf("Element %d isn't present\n",x);
    return;
}
int DeleteAfter(NODE *START,int x){
    if(IsEmpty(START)){
        printf("Empty List\n");
        return;
    }
    NODE p=*START,ahead=NULL;
    while(p!=NULL){
        if(p->data==x){
            p->next=(ahead)->next;
            if(p==*START){
                printf("No element after %d\n",x);
                return;
            }
            x=ahead->data;
            free(ahead);
            return x;
        }
        p=p->next;
        ahead=p->next;
    }
    printf("Element %d isn't present\n",x);
    return;
}
void display(NODE *START){
    NODE p;
    p=*START;
    if(p == NULL){
        printf("Empty list\n");
        return;
    }
    printf("\nThe elements in list: ");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return;
}
void reverse(NODE *START) {
    struct node* prev = NULL;
    struct node* current = *START;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *START = prev;
}



