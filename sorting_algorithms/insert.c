#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int *,int );
int main()
{
	int i,n;
	int *array;
	printf("Number of elements : ");
	scanf("%d",&n);
	array = (int*) malloc(n * sizeof(int));
	printf("\ninput array: ");
	for(i=0;i<n;i++)
	{
		scanf(" %d ",&array[i]);
	}
	
	printf("\ninput array: ");
	for(i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
	insertion_sort(array,n);
	printf("\noutput array : ");
	for(i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
	
}

void insertion_sort(int * arr,int n)
{
	int i,j,k,temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j] > arr[i])
			{
				
				temp = arr[i];
				
				for(k=i;k > j; k--)
				{
					arr[k] = arr[k-1];
					
				}
				arr[j] = temp;
				break;
			}
		}
	}

}