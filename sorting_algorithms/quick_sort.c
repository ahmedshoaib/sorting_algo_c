#include<stdio.h>
#include<stdlib.h>
//divide and conquer sorting algorithm
void quick_sort(int *, int,int);   //array, start index, end index
int partition(int *, int,int);   //array, start index, end index

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
	
	quick_sort(array,0,n-1);
	
	for(i=0;i<n;i++)
	{
		printf("  %d ",array[i]);
	}
	
	
	
	return 0;
}

void quick_sort(int *arr, int p,int r)
{
	if(p < r)                  //limiting case
	{
		int q;

		q = partition(arr,p,r);     //partiton based on a pivot as left subarray smaller and right larger

		quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}

int partition(int *arr, int p,int r)
{
	int i,j,x,temp;
	i = p;
	
	x = arr[r];
	for(j=p;j<r;j++)
	{
		if(arr[j] < x)
		{
			
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
	}
	
	temp = arr[r];
	arr[r] = arr[i];
	arr[i] = temp;
	return i	;	
}