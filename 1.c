#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int min(int x, int y) { return (x<y)? x :y; } 
 void merge(int arr[],int l,int m, int r){
	int i,j,k;
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}k++;
		}
	
	while(i<n1){
		arr[k]=L[i];
		i++;k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;k++;
	}
}
void mergesort_recur(int arr[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergesort_recur(arr,l,m);
		mergesort_recur(arr,m+1,r);
		merge(arr,l,m,r);
	}
	
}
void mergesort_iter(int arr[], int n) 
{ 
   int c,l,r,m;  
  
   for (c=1; c<=n-1; c = 2*c) 
   { 
       
       for (l=0; l<n-1; l+= 2*c) 
       { 
            m = l+ c - 1; 
  
           r = min(l + 2*c - 1, n-1); 
  
           merge(arr, l, m, r); 
       } 
   } 
} 
int main(int argc, char *argv[]){
	FILE *fptr;
	int n,j,x;
	clock_t t;
	srand(time(0));
	printf("\nEnter no. of element ");
	scanf("%d",&n);
	int array1[n],array2[n];
	fptr=fopen(argv[1],"w");
	if(fptr == NULL)
   	{
      		printf("\nError!");   
      		exit(1);             
  	 }

	for (j=0;j<n;j++){
		x=rand();
		fprintf(fptr,"%d\n",x);
		array1[j]=x;
		array2[j]=x;
	}
	fclose(fptr);
	int size= sizeof(array1)/sizeof(int);
	t=clock();
	mergesort_recur(array1,0,size-1);
	t=clock()-t;
	printf("\nTime taken for recurrsive unsorted  array is :%ld",t);
	t=clock();
	mergesort_recur(array1,0,size-1);
	t=clock()-t;
	printf("\nTime taken for recurrsive sorted array is :%ld",t);
	fptr=fopen(argv[2],"w");
	for (j=0;j<n;j++){
		x=array1[j];
		fprintf(fptr,"%d\n",x);
		
	}
	t=clock();
	mergesort_iter(array2,size-1);
	t=clock()-t;
	printf("\nTime taken for iterative unsorted  array is :%ld",t);
	t=clock();
	mergesort_iter(array2,size-1);
	t=clock()-t;
	printf("\nTime taken for iterative sorted array is :%ld",t);
	}
	/*	data:	20000
	Time taken for unsorted array is :3221
	Time taken for sorted array is :1624
	*/
	
	
	
	
	
	
	
	
	
	
