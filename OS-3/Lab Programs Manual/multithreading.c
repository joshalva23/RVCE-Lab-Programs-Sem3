#include<pthread.h>
//#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<stdio.h>
int a[4][4],b[4][4];

void *matrixeval(void* val)
{
    int *thno = (int*)val;
    int i,j;
    for(i = 0; i < 4 ; i++)
        b[(*thno)][i] = a[(*thno)][i];
    for(i = 0; i < 4; i++)
        for(j = 0; j < (*thno); j++)
            b[(*thno)][i] *= a[(*thno)][i];
}

int main()
{
    pthread_t tid[4];
    int i, j;
    for( i = 0; i < 4; i++)
    {
        printf("Enter the elements of row %d: ",i);
        for(j = 0; j<4;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\nBefore Processing:\n");
    for( i = 0; i < 4 ;i++){
        for( j = 0; j < 4 ;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }

    for(i = 0; i < 4 ; i++)
    {
        pthread_create(&tid[i], NULL, matrixeval, (void*)&i);
        pthread_join(tid[i],NULL);
        sleep(1);
    }


    printf("\nAfter Processing:\n");
     for( i = 0; i < 4 ;i++){
        for( j = 0; j < 4 ;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }

}