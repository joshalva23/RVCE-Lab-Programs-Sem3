//Implementation of sparse matrix multiplication.
//Each node in the list can have the row and column index of the matrix element and the value of the element. 
//Print the complete matrix as the output.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int row;
    int col;
    int info;
    struct node *next;
};
typedef struct node* NODEPTR;

NODEPTR getnode(int r, int c, int ele){
    NODEPTR p; 
    p = (NODEPTR)malloc(sizeof(struct node));
    p->row = r;
    p->col = c;
    p->info = ele;
    p->next = NULL;
    return p;
}

void insertend(NODEPTR *head, int r, int c, int ele){
    NODEPTR temp;
    temp = getnode(r, c, ele);
    
    if(*head == NULL)
        *head = temp;
    else {
        NODEPTR p = *head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

NODEPTR createList(NODEPTR *head){
    int n, r, c, ele;
    printf("enter the number of rows: ");
    scanf("%d", &r);
    printf("enter the number of columns: ");
    scanf("%d", &c);
    printf("enter the number of non-zero elements: ");
    scanf("%d", &n);
    
    *head = getnode(r, c, n);
    
    printf("enter non-zero entries of the matrix: (row col ele) :\n");
    int i;
    for(i=0; i<n; i++){
        scanf("%d%d%d", &r, &c, &ele);
        insertend(head, r, c, ele);
    }
}

void display(NODEPTR head){
    if(head == NULL)
        printf("\nempty list");
    else {
        NODEPTR p;
        printf("\nNo. of rows = %d", head->row);
        printf("\nNo. of columns = %d",head->col);
        printf("\nTotal non-zero entries = %d", head->info);
        printf("\nList contents: row - col - ele\n");
        for(p=head->next; p!=NULL; p=p->next){
            printf("%d  %d  %d\n", p->row, p->col, p->info);
        }
    }
}

void displaymatrix(NODEPTR head){
    if(head == NULL)
        printf("empty matrix");
    else {
        NODEPTR q;
        int r, c;
        r = head->row;
        c = head->col;
        
        q = head->next;
        printf("\nsparse matrix:\n");
        int i,j;
        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                if(q!=NULL && q->row==i && q->col==j){
                    printf("%d  ", q->info);
                    q = q->next;
                }
                else {
                    printf("0  ");
                }
            }
            printf("\n");
        }
    }
}

int main(){
    NODEPTR head = NULL;
    createList(&head);
    display(head);
    displaymatrix(head);
    return 0;
}