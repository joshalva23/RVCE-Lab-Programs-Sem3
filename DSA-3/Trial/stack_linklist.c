#include "sll.c"
int main(){
    NODE START=NULL;
    InsertLast(&START,30);
    InsertFirst(&START,60);
    InsertBefore(&START,60,50);
    InsertAfter(&START,30,40);
    display(&START);
    
    printf("%d",DeleteLast(&START));
}