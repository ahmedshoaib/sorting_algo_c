#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *, int);
int main()
{
int i,j,n;
	int* array;
	scanf("%d",&n);
	array = (int*) malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf(" %d ",&array[i]);
	}
	
	bubble_sort(array,n);
	for(i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
	
	
	
	return 0;
}

void bubble_sort(int *arr, int n)
{
	int i=0,temp=0,flag;
	do{                              //until no new interchanges take place(max. of n times)
		flag = 0;
		
		for(i=1;i<n;i++)              
		{
			if(arr[i]<arr[i-1])     // swap adjacent elements
			{
				flag = 1;
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;
			}
		}
		
	}while(flag == 1 );
	
}