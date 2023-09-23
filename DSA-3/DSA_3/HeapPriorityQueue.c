#include<stdio.h>
#include<stdlib.h>
#define size 100
void heapify(int *a, int n)
 {
	int key, k, heap, j;
	for( k=n/2; k>=1; k--)
	  {
		key = a[k];
		heap = 0;
                        
		while( !heap &&  (2*k)<=n)
		  {       
		       j=2*k ;
                                    
               if(  j < n && a[j+1] > a[j])
                    j= j+1;
               if( key < a[j] )
                {
                    a[k]=a[j];
                    k=j;
                }
               else
                  heap =1;      
 		  }
		 a[k] = key; 
	   }
 } 

int main()
  {
	int i, a[size], n,ele,choice;  	
	printf("Enter n\n");
	scanf("%d", &n);
	printf("Enter Data\n");
	for( i=1; i<=n; i++ )
	scanf("%d", &a[i]);
	heapify(a, n);
        while(1)
        {
          printf("\nEnter the choice \n1 : insert \n2 : delete\n3 : display\n4 : exit\n");
          scanf("%d",&choice);
          switch(choice)
          {
          case 1: if( n <size)
                  {
                    printf("\nEnter the key to be inerted  :");
                    scanf("%d",&ele);
                    n++;
                    a[n] =ele;
                    heapify(a, n);
                  }
                  else
                    printf("PRIORITY QUEUE FULL !!!!!!!!!");
                  break;
          case 2: if( n > 0)
                  {
                     ele=a[1];// maximum element tets to be removed
                     a[1]=a[n];// bring the last element to the first position. ie max element gets deleted 
                      n--;//decrease the size
                     heapify(a, n);
                      printf("\nDeleted element is %d :",ele);
                  }
                  else
                     printf(" PRIORITY QUEUE EMPTY !!!!!!!!");
                  break;
         case 3:  printf(" Heap is :");
                  for( i=1; i<=n; i++ )
	             printf("%d ",a[i]);
                  break;
         default:exit(0);
          }
       }  
	
  }