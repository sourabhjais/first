#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
int  main()
{   int i,j,r1,r2,c1,c2,k;
    clock_t t;
    printf("Enter number of rows and columns of first matrix (MAX 10)\n");
    scanf("%d%d",&r1,&c1);
    printf("Enter number of rows and columns of second matrix MAX 10)\n");
    scanf("%d%d",&r2,&c2);
    if(r2==c1)
    {
        int **arr1 = (int **)malloc(r1 * sizeof(int *)); 
        int **arr2 = (int **)malloc(r2 * sizeof(int *)); 
        int **arr3 = (int **)malloc(r1 * sizeof(int *)); 
        for (i=0; i<r1; i++){
       		arr1[i] = (int *)malloc(c1 * sizeof(int)); 
       		arr3[i] = (int *)malloc(c2 * sizeof(int)); 
       		}
	 for (i=0; i<r2; i++) 
       		arr2[i] = (int *)malloc(c2 * sizeof(int)); 
        printf("\n Enter First Matrix:");
 	srand(time(0));
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            	arr1[i][j]=rand()%1000;	    
        }
 
        printf("\n Enter Second Matrix: ");
        srand(time(0));
        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            	arr2[i][j]=rand()%1000;    
        }
 
        printf("\nMultiplication of the Matrices:\n");
        t=clock();
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                arr3[i][j]=0;
                for(k=0; k<r1; k++)
                    arr3[i][j]+=arr1[i][k]*arr2[k][j];
                printf("%d  ",arr3[i][j]);
            }
            printf("\n");
        }
 	t=clock()-t;
    	printf("The time taken is %ld\t",t);
    }
   
    else
    {
        printf("Matrix Multiplication is Not Possible");
    }
    
}
