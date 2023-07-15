#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* BST node */

struct node
{
int data;
struct node *left_child;
struct node *right_child;
};

typedef struct node* NODE;

/* Function to create a newnode */
NODE getnode()
{
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if(p== NULL)
    {
        printf("Insufficient Memory");
        exit(0);
    }
    p->left_child= NULL;
    p->right_child = NULL;
    return p;
}
//InOrder Succucessor of a node p
int InOrderSucc(NODE p)
{
    NODE q;
    if(p == NULL)
    {
        printf("ERROR!!!!!!!!!!!!");
        exit(0);
    }
    q= p->right_child; // one step right
    // travrse left
    while(q->left_child != NULL) 
         q=q->left_child;
    return q->data;
}      

NODE  BSTInsert(NODE root, int x)
{
    NODE p,q,parent ;

    q= getnode();
    q->data =x;

    if(root == NULL)
        return q;
    p = root;
    while(p !=NULL)
    {
        parent = p;
        if(x == p->data )
        {
            printf("Duplicate Entry");
            free(q);
            return root;
        } 
        if( x < p->data)
            p=p->left_child;
        else
            p=p->right_child;
    }

    if(x < parent->data)
        parent->left_child = q;
    else
        parent->right_child = q;
    return root;
}
NODE BSTDelete(NODE tp, int x)
{
    int y;
    NODE r; 
    if (tp == NULL)
    {
        printf(" Element %d Not Presenst",x);
        return NULL;   //tp
    } 
    if(x == tp->data  )
    {
        //Case 1
        if( tp->left_child == NULL &&  tp->right_child==NULL)
        {   
            free(tp);
            return NULL;
        }
        //Case 2 : left subtree  is NULL
        if(tp->left_child == NULL)
        {
            r= tp->right_child;
            free(tp);
            return r;
        }
        //Case 2 : right subtree  is NULL
        if(tp->right_child == NULL)
        {
            r= tp->left_child;
            free(tp);
            return r;
        }
        // Case 3: both left && right NOT NULL
        y = InOrderSucc(tp);
        tp->data= y;
        tp->right_child= BSTDelete(tp->right_child,y);
        return tp; 
    }
    if( x < tp->data)
        tp->left_child = BSTDelete(tp->left_child,x);
    else
        tp->right_child = BSTDelete(tp->right_child,x);
    return tp;
}
void InOrder( NODE p)
{
    if( p )    // p != NULL
    {
        InOrder(p->left_child);
        printf("%d ",p->data);
        InOrder(p->right_child);
    }
}
void PreOrder( NODE p)
{
    if( p != NULL)
    {
        printf("%d ",p->data);
        PreOrder(p->left_child);
        
        PreOrder(p->right_child);
    }
}
void PostOrder( NODE p)
{
    if( p)
    {
        PostOrder(p->left_child);
        PostOrder(p->right_child);
        printf("%d ",p->data);
    }
}

int main()
{
   
    int choice,x;
    NODE root=NULL;
  
    printf("Demonstration of BST Insert ,Delete, Display");
    while(1)
    {
     
        printf("\n1:Insert\n2:Delete\n3:Inorder Display\n4:Preorder Display\n5:Postorder Display\n6:exit ");
        printf("\nEnter the Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element to be Inserted ");
                    scanf("%d",&x);
                    root=BSTInsert(root,x);
                    break;
            case 2: printf("\nEnter the element to be Deleted ");
                    scanf("%d",&x);
                    root=BSTDelete(root,x);
                    break;
            case 3: printf("\nTraversal of BST : Inorder ");
                    InOrder(root);
                    break;
            case 4: printf("\nTraversal of BST : Preorder ");
                    PreOrder(root);
                    break;
            case 5: printf("\nTraversal of BST : Postorder ");
                    PostOrder(root);
                    break;       
          
            case 6: exit(0);
       
        } //switch
    
    }//while
    return 0;
}//main