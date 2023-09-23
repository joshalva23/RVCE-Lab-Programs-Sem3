#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node *next;
};
typedef struct node* Node;
Node getnode(){
	Node p=(Node)malloc(sizeof(struct node));
	if(p==NULL){
		printf("Insufficient Memory\n");
		exit(0);
	}
	p->next=NULL;
	return p;
}
Node insert_last(int coeff, int exp , Node list){
	Node temp,cur;
	
	temp=getnode();
	temp->coeff = coeff;
	temp->exp = exp;
	if(list==NULL)
		return temp;
	cur=list;
	while(cur->next !=NULL)
		cur= cur->next;
	cur->next = temp;
	return list;
}


Node insert_update(int coeff, int exp,Node list){
	Node temp,cur, prev;
	int linked=0;

	temp=getnode();
	temp->coeff = coeff;
	temp->exp = exp;

	if(list == NULL)
		return temp;

	prev=NULL;
	cur =list;
	while(cur != NULL){
		if(cur->exp ==exp){
			cur->coeff=cur->coeff+coeff;
			linked=1;
			free(temp);
			break;
		}
		if(cur->exp > exp)
			break;
		prev=cur;
		cur= cur->next;
	}
	if(!linked){
		if(prev==NULL){
			temp->next=list;
			list=temp;
		}
		else{
			temp->next=prev->next;
			prev->next=temp;
		}
	}
	return list;
}
Node mul(Node poly1, Node poly2){
	Node p,q;
	Node result=NULL;
	int c,e;
	 
	if(poly1==NULL||poly2==NULL){
		printf("Multiplied polynomial is 0 degree\n");
		exit(0);
	}
	p=poly1;
	while(p!=NULL){
		q=poly2;
		while(q !=NULL){
			c=p->coeff*q->coeff;
			e=p->exp + q->exp;
			result=insert_update(c,e,result);
			q=q->next;
		}
		p=p->next;
	}
	return result;
}
void display(Node first){
	Node p;
	if(first == NULL){
		printf("Polynomial doesn't exist\n");
	}
	p=first;
	while(p!=NULL){
		if(p->coeff>=0)
		printf("%+dx^%d",p->coeff,p->exp);
		p=p->next;
	}
	printf("\n");
}
Node readpoly(Node list){
	int i,n;
	int coeff;
	int exp;
	printf("Enter no. of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter term %d: \n",i);
		printf("Coefficient :");
		scanf("%d",&coeff);
		printf("Exponent :");
		scanf("%d",&exp);
		list=insert_last(coeff,exp,list);
	}
	return list;
}

int main(){
	Node poly1=NULL,poly2=NULL, poly3=NULL;
	printf("Enter 1st polynomial:\n");
	poly1=readpoly(poly1);
	printf("\nEnter 2nd polynomial:\n");
	poly2= readpoly(poly2);
	poly3= mul(poly1,poly2);	
	printf("Polynomial 1:\n ");
	display(poly1);
	printf("Polynomial 2:\n ");
	display(poly2);
	printf("\n--------------------------\n");
	display(poly3);
	return 0;
}
