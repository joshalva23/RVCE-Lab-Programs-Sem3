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

void tree_init(NODE* ROOT,int count,char * side){
	if(*ROOT == NULL){
		*ROOT=getnode();
		printf("Enter the data %s %d: ",side,count);
		scanf("%d",&((*ROOT) -> data));

		if((*ROOT) -> data == -1){
            *ROOT= NULL;
            return;
        }
		
		tree_init(&((*ROOT)->lchild),count+1,"LEFT ");
		tree_init(&((*ROOT)->rchild),count+1,"RIGHT");
	}
	return;
}

void displaytree(NODE *p){
	if(*p==NULL)
		return;
	
	printf("%d ",(*p)->data);
	displaytree(&((*p)->lchild));
	displaytree(&((*p)->rchild));
	return;
}
	
void tree_display(NODE *ROOT){
	if(*ROOT == NULL){
		printf("Empty Tree\n");
		return;
	}
	printf("\nElements of the tree printed in pre order are: ");
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
	NODE ROOT=NULL;
    while( ROOT == NULL ){
	    tree_init(&ROOT,0,"ROOT ");
        if( ROOT == NULL )
            printf("\nERROR : ROOT not initialised\n\n");
    }
	printf("\nThe number of nodes = %d\n", countnode(&ROOT) );
    printf("\nThe number of leaf nodes = %d\n", countleafnode(&ROOT) );
    tree_display(&ROOT);
    printf("\n\n");
}