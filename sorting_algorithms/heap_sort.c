 #include<stdio.h>
#include<stdlib.h>

void heap_sort(int *, int);   //array,size
void max_heapify(int *, int, int);  //array, index, size of array
void build_max_heap(int *, int);     //array, heap size,arr size


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
	
	heap_sort(array,n);
	
	for(i=0;i<n;i++)
	{
		printf("  %d ",array[i]);
	}
	
	
	
	return 0;
}

void heap_sort(int *arr, int n)
{
	int i,j;
	int heap_size = n;
	
	for(i=(n-1);i>0;i--)                       // for all array elements
	{

		build_max_heap(arr,heap_size);            //build max-heap
		
		arr[i] = arr[i]+arr[0];                      //swap max element with last index
		arr[0] = arr[i] - arr[0];
		arr[i] = arr[i] - arr[0];
		heap_size-- ;                             //decrease heap size
		
	}
}




void build_max_heap(int *arr,int heap_size)
{
	int i;
	for(i=(heap_size/2);i>=0;i--)          //from centre of array upto first element
	{
		max_heapify(arr,i,heap_size);      //keep building max-heaps bottom-up
		
	}
	
}

void max_heapify(int *arr,int i, int n)      //  ****************** careful about indexing of children **************************
{
	int j;
	if((arr[i] < arr[(2*i)+2]) || (arr[i] < arr[(2*i)+1]))
	{
		if((arr[(2*i)+1] > arr[(2*i)+2]) && (((2*i)+1) < n))   //left chld is lagest, also check for buffer overflow
		{

			arr[i] = arr[(2*i)+1] + arr[i];
			arr[(2*i)+1] = arr[i] - arr[(2*i)+1];
			arr[i] = arr[i] - arr[(2*i)+1];
			max_heapify(arr,(2*i)+1,n);
			
		}
		else if((arr[(2*i)+2] > arr[(2*i)+1]) && (((2*i)+2) < n) )    //right chld is lagest
		{

			arr[i] = arr[(2*i)+2] + arr[i];
			arr[(2*i)+2] = arr[i] - arr[(2*i)+2];
			arr[i] = arr[i] - arr[(2*i)+2];
			max_heapify(arr,(2*i)+2,n);
		}
	}
}


