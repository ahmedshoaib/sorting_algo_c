 #include<stdio.h>
#include<stdlib.h>

void selection_sort(int *, int);
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
	
	selection_sort(array,n);
	for(i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
	
	
	
	return 0;
}

void selection_sort(int *arr, int n)
{
	int i,j,min,temp,k;
	
	for(i=0;i<n;i++)      //iterate rest of array
	{
		min = i;
		for(j=i;j<n;j++)         //find minium element
		{
			if(arr[min] >= arr[j])
				min = j;
		}
		temp = arr[min];             //bring it to the first index
		arr[min] = arr[i];
		arr[i] = temp;
				
	}
	
}