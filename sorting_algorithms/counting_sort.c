#include<stdio.h>
#include<stdlib.h>
//linear time sorting algorithm
int * counting_sort(int *,int,int);   //array, size of array, range

int main()       // enter no. of inputs, input array and range
{
int i,j,n,r;
	int *array, *o_array;
	scanf("%d",&n);
	array = (int*) malloc(n * sizeof(int));
	o_array = (int*) malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf(" %d ",&array[i]);
	}
	
	scanf("%d",&r);
	if(r <= 9 && r > 0 )
	{
	
	o_array = counting_sort(array,n,r);
	
	for(i=0;i<n;i++)
	{
		printf("  %d ", o_array[i]);
	}
	}
	else{
		printf("enter valid range (1-9 ) ");
	}
	
	
	return 0;
}
int * counting_sort(int *arr,int n, int r)
{
	int i;
	int* o_arr, *count_arr;
	o_arr = (int*) calloc(n , sizeof(int));
	count_arr = (int*) calloc((r+1) , sizeof(int));
	for(i=0;i<n;i++)
	{
		count_arr[arr[i]]++;
	}
	for(i=0;i<r;i++)
	{
		count_arr[i+1] = count_arr[i] + count_arr[i+1];
	}
	for(i = n-1;i >= 0;i--)
	{
		o_arr[count_arr[arr[i]] - 1] = arr[i];
		count_arr[arr[i]]--;
	}
	return o_arr;
}





