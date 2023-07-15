#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node* NODE;
struct stack{
	NODE loc[100];
	int top;
};
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

void tree_init(NODE* ROOT,int count,char side[],char* sub){
	if(*ROOT == NULL){
		int i;
		for(i=0;side[i]!='\0';i++);
		side[i]=sub[0];
		side[i+1]='\0'; 
		printf("Enter the data ROOT %s\t%d: ",side,count);
		int x;
		scanf("%d",&x);
		if(x == -1){
            *ROOT= NULL;
			side[i]='\0';
            return;
        }
		*ROOT=getnode();
		(*ROOT)->data=x;
		tree_init(&((*ROOT)->lchild),count+1,side,"L");
		side[i+1]='\0';
		tree_init(&((*ROOT)->rchild),count+1,side,"R");
	}
	return;
}
int insertnode(NODE* ROOT,int count,char side[],char* sub,int num){
	int i,status=0;
	for(i=0;side[i]!='\0';i++);
	side[i]=sub[0];
	side[i+1]='\0';
	if(*ROOT == NULL){
		printf("In ROOT %s\t%d: ",side,count);
		printf("\n Want to insert element here(-1/0)?\n");
		int ch;
		scanf("%d",&ch);
		if(ch==0){
			(*ROOT)->data=num;
			return 1;
		}
		else
		{
			return 0;
        }	
	}
	if(!status)
		status=insertnode(&((*ROOT)->lchild),count+1,side,"L",num);
	if(!status)
		status=insertnode(&((*ROOT)->rchild),count+1,side,"R",num);
	return status;
}
void displaytreepreorder(NODE *p){
	if(*p==NULL)
		return;
	
	printf("%d ",(*p)->data);
	displaytreepreorder(&((*p)->lchild));
	displaytreepreorder(&((*p)->rchild));
	return;
}
void displaytreeinorder(NODE *p){
	if(*p==NULL)
		return;
	displaytreeinorder(&((*p)->lchild));
	printf("%d ",(*p)->data);
	displaytreeinorder(&((*p)->rchild));
	return;
}
void displaytreepostorder(NODE *p){
	if(*p==NULL)
		return;
	displaytreepreorder(&((*p)->lchild));
	displaytreepreorder(&((*p)->rchild));
	printf("%d ",(*p)->data);
	return;
}

void push(struct stack *s,NODE ele){
    if(s->top==100-1){
        printf("STACK OVERFLOW\n");
        return;
    }
    s->loc[++(s->top)]=ele;
    return;
}
NODE pop(struct stack *s){
    if(s->top==-1){
        return NULL;
    }
    return s->loc[(s->top)--];
}
void displaytreepreorder1(NODE *ROOT){
	if(*ROOT==NULL){
		printf("Empty Tree\n");
		return;
	}
	struct stack s;
	s.top=-1;
	NODE p = *ROOT;
	while(p!=NULL){
		printf("%d ", p->data);
		if(p->lchild != NULL){
			if(p->rchild!=NULL)
				push(&s,p->rchild);
			p=p->lchild;
		}
		else if(p->rchild!=NULL){
			p=p->rchild;
		}
		else{
			p=pop(&s);
		}
	}
	return;
}
	
void tree_display(NODE *ROOT,int choice){

	if(*ROOT == NULL){
		printf("Empty Tree\n");
		return;
	}

	if(choice==1){
		printf("\nElements of the tree printed in pre order are: ");
		displaytreepreorder(ROOT);
	}
	else if(choice==2){
		printf("\nElements of the tree printed in inorder are: ");
		displaytreeinorder(ROOT);
	} 
	else if(choice==3){
		printf("\nElements of the tree printed in post order are: ");
		displaytreepostorder(ROOT);
	}
	else
		printf("WRONG CHOICE...\n");
	printf("\n");
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
	printf("\nCREATING A BINARY TREE...\n\n");
	NODE ROOT=NULL;
	printf("ENTER DATA \n");
	char s[100];
    while( ROOT == NULL ){
	    tree_init(&ROOT,0,s," ");
        if( ROOT == NULL )
            printf("\nERROR : ROOT not initialised\n\n");
    }
	//tree_display(&ROOT,1);
	//insertnode(&ROOT,0,s," ",100);
	printf("\nThe number of nodes = %d\n", countnode(&ROOT) );
    printf("\nThe number of leaf nodes = %d\n", countleafnode(&ROOT) );
    //tree_display(&ROOT,1);
	//tree_display(&ROOT,2);
	//tree_display(&ROOT,3);
	displaytreepreorder1(&ROOT);
    printf("\n\n");
}