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
        else
            tree_insert(&((*p)->rchild),item);
        return;
    }
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

int countnode(NODE* p){
	if(*p == NULL)
		return 0;
	
	return 1 + countnode(&((*p)->lchild)) + countnode(&((*p)->rchild));
}

int countleafnode(NODE *p){
    if(*p == NULL)
        return 0;
    if((*p)->lchild == NULL && (*p)->rchild == NULL)
        return 1;
    return countleafnode(&((*p)->lchild)) + countleafnode(&((*p)->rchild));  
}
int main(){
    int n,a[100],i,choice,x;
    NODE ROOT=NULL;
    printf("Welcome to Binary Search tree\n");
    while(1){
        printf("\n1.Insert\n2.Count Nodes\n3.Count Leaf Nodes\n4.Display\n5.EXIT\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the value:");
                    scanf("%d",&x);
                    tree_insert(&ROOT,x);
                    break;
            case 2: printf("\nThe number of nodes = %d\n", countnode(&ROOT) );
                    break;
            case 3: printf("\nThe number of leaf nodes = %d\n", countleafnode(&ROOT) );
                    break;
            case 4: tree_display(&ROOT);
                    printf("\n\n");
                    break;
            default: exit(0);
        }
    }
   
}