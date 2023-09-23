//Heapsort
#include<stdio.h>
#define MAX 20
int h[MAX];
void heapify(int n){
    int k, v, heap, j,i;
    for(i=n/2; k>=1; k--){
        k=i;
        v = h[k];
        heap = 0;
        while(!heap && 2*k<=n){
            j = 2*k;
            if(j<n){
                //then two children
                if(h[j] < h[j+1])
                    j = j+1;
            }
            if(v >= h[j])
                heap = 1;
            else {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}
void display(int n){
    int i;
    for(i=1;i<=n;i++)
        printf("%d  ", h[i]);
}
void heapsort(int n){
    heapify(n);
    int i;
    for( i=1;i<=n;i++)
        printf("%d ",h[i]);
    for( i=n; i>=1; i--){
        int temp = h[i];
        h[i] = h[1];
        h[1] = temp;
        heapify(i-1);
    }   
}
int main(){
    int n,i;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for( i=1; i<=n; i++)
        scanf("%d", &h[i]);
    printf("unsorted list: ");
    display(n);
    heapsort(n);
    printf("\nsorted list: ");
    display(n);
    return 0;
}