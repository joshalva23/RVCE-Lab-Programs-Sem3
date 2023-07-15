#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node* NODE;

NODE getnode(){
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p == NULL){
		printf("INSUFFICIENT MEMORY\n");
		exit(0);
	}
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
void tree_insert(NODE* p,int item){
    if(*p == NULL){
        *p=getnode();
        (*p)->data=item;
        return;
    }    
    else{
        if((*p)->data > item)
            tree_insert(&((*p)->lchild),item);
        else if((*p)->data < item)
            tree_insert(&((*p)->rchild),item);
        else{
            printf("Duplicate element\n");
        }
        return;
    }
}
int InOrderSucc(NODE *p)
{
    NODE q;
    if(*p == NULL)
    {
        printf("ERROR!!!!!!!!!!!!");
        exit(0);
    }
    q= (*p)->rchild; // one step right
    // travrse left
    while(q->lchild != NULL) 
         q=q->lchild;
    return q->data;
}     
void BSTDelete(NODE *tp, int x)
{
    int y;
    NODE r; 
    if (*tp == NULL)
    {
        printf(" Element %d Not Present",x);  
        return;//tp
    } 
    if(x == (*tp)->data  )
    {
        //Case 1
        if( (*tp)->lchild == NULL &&  (*tp)->rchild==NULL)
        {   
            free(*tp);
            *tp=NULL;
            return;
        }
        //Case 2 : left subtree  is NULL
        if((*tp)->lchild == NULL)
        {
            r = (*tp)->rchild;
            free(*tp);
            *tp=r;
            return;
        }
        //Case 2 : right subtree  is NULL
        if((*tp)->rchild == NULL)
        {
            r=(*tp)->lchild;
            free(*tp);
            *tp=r;
            return;
        }
        // Case 3: both left && right NOT NULL
        y = InOrderSucc(tp);
        (*tp)->data= y;
        BSTDelete(&((*tp)->rchild),y); 
        return;
    }
    if( x < (*tp)->data)
        BSTDelete(&((*tp)->lchild),x);
    else
        BSTDelete(&((*tp)->rchild),x);
}
void displaytree(NODE *p){
	if(*p==NULL)
		return;
	displaytree(&((*p)->lchild));

    printf("%d ",(*p)->data);

	displaytree(&((*p)->rchild));
	return;
}
	
void tree_display(NODE *ROOT){
	if(*ROOT == NULL){
		printf("Empty Tree\n");
		return;
	}
	printf("\nElements of the tree printed in order are: ");
	displaytree(ROOT);
	return;
}
int main(){
    int n,a[100],i,choice,x;
    NODE ROOT=NULL;
    printf("Welcome to Binary Search tree\n");
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.EXIT\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the value:");
                    scanf("%d",&x);
                    tree_insert(&ROOT,x);
                    break;
            case 2: printf("Enter element to be deleted: ");
                    scanf("%d",&x);
                    BSTDelete(&ROOT,x);
                    break;
            case 3: tree_display(&ROOT);
                    printf("\n\n");
                    break;
            default: exit(0);
        }
    }
   
}