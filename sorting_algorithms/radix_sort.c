#include<stdio.h>
#include<stdlib.h>
//linear time sorting algorithm for 3 digit number
int * counting_sort(int *,int *,int);   //array, size of array, range,,,,,,a little different from counting sort
int * radix_sort(int *,int);
int main()       // enter no. of inputs, input array and range
{
int i,j,n,r;
	int *array,*o_array;
	scanf("%d",&n);
	array = (int*) malloc(n * sizeof(int));
	o_array = (int*) malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf(" %d ",&array[i]);
	}
	
	o_array = radix_sort(array,n);
	for(i=0;i<n;i++)
	{
		printf("  %d ", o_array[i]);
	}
	return 0;
}

int * radix_sort(int *arr, int n)
{
	int i;
	int *ones,*tens,*hunds;
	
	ones = (int*) malloc(n * sizeof(int));
	tens = (int*) malloc(n * sizeof(int));
	hunds = (int*) malloc(n * sizeof(int));
	
	for(i=0;i<n;i++)
	{
		ones[i] = arr[i]%10;
	}
	arr = counting_sort(arr,ones,n);
	for(i=0;i<n;i++)                                //update place arrays after every sort
	{
		tens[i] = (arr[i]%100)/10;
	}
	arr = counting_sort(arr,tens,n);
	for(i=0;i<n;i++)
	{
		hunds[i] = (arr[i]%1000)/100;
	}
	arr = counting_sort(arr,hunds,n);
}



int * counting_sort(int *arr,int *place,int n)         //same as counting but sorts corresponding array elements of place elements.
{
	int i;
	int* o_arr, *count_arr,*op_arr;
	o_arr = (int*) calloc(n , sizeof(int));     //output array(main array out)
	
	count_arr = (int*) calloc(10 , sizeof(int));   //counting array
	
	
	for(i=0;i<n;i++)
	{
		count_arr[place[i]]++;     //counting each digit's(in place array) occurence
	}
	for(i=0; i < 9;i++)
	{
		count_arr[i+1] = count_arr[i] + count_arr[i+1];         //determine location of each element(of place array)
	}
	for(i = n-1;i >= 0;i--)
	{
		o_arr[count_arr[place[i]] - 1] = arr[i];             //change position of element from arr into o_arr corresponding to placearray
	
		count_arr[place[i]]--;
	}
	
	return o_arr;
}





