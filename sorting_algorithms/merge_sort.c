#include<stdio.h>
#include<stdlib.h>
void merge_sort(int *,int,int);
void merge(int *, int , int , int );



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
	for(i=0;i<n;i++)
	{
		printf(" %d \n",array[i]);
	}
	merge_sort(array,0,n-1);
	for(i=0;i<n;i++)
	{
		printf(" %d ",array[i]);
	}
	
	
	
	return 0;
}


void merge_sort(int *arr, int p,int q)
{
	int r;
	if(p!=q)
	{
		r = (p+q)/2;
//		printf("mid : %d , p,q = %d,%d\n",r,p,q);
		merge_sort(arr,p,r);        //run algo on first half
		merge_sort(arr,r+1,q);      //sort second half
		merge(arr,p,r,q);    //merge the two
		
	}
}

/*
void merge(int *arr, int p, int r, int q)
{
	int i,j,k;
	int left[r-p+1],right[q-r];
	printf("merging arrays from %d to %d and %d to %d\n",p,r,r+1,q);
	for(i=0;i<=(r-p);i++)
	{
		left[i] = arr[p+i];
	}
	for(j=1;j<=(q-r);j++)
	{
		right[j-1] = arr[r+j];
	}
	i=0;j=0;
	for(k=0;k<(q-p+1);k++)
	{
		if(left[i]<right[j])
		{
			arr[k+p] = left[i];
			i++;
			
			if(i = r-p+1 )
			{
				k++;
				while(k!=(q-p+1))
				{
					arr[k+p] = right[j];
					j++;
					k++;
				}
			}
			
		}
		
		else if(left[i] >= right[j])
		{
			arr[k+p] = right[j];
			j++;
			
			if(j = q-r )
			{
				k++;
				printf("\nfor p,q = %d,%d left[i] starts copying from = %d\n",p,q,left[i]);
				while(k!=(q-p+1))
				{
					arr[k+p] = left[i];
					printf("\narr[%d] = %d\n",k+p,arr[k+p]);
					i++;
					k++;
				}
			}
			
		}
		
		
		
	}
	for(k=p;k<=q;k++)
	{
		printf(" %d ",arr[k]);
		printf("\n");
	}
}
*/

 void merge(int *A , int start, int mid, int end) {
 //stores the starting position of both parts in temporary variables.
int p = start ,q = mid+1;

int Arr[end-start+1] , k=0;

for(int i = start ;i <= end ;i++) {
    if(p > mid)      //checks if first part comes to an end or not .
       Arr[ k++ ] = A[ q++] ;

   else if ( q > end)   //checks if second part comes to an end or not
       Arr[ k++ ] = A[ p++ ];

   else if( A[ p ] < A[ q ])     //checks which part has smaller element.
      Arr[ k++ ] = A[ p++ ];

   else
      Arr[ k++ ] = A[ q++];
 }
  for (int p=0 ; p< k ;p ++) {
   /* Now the real array has elements in sorted manner including both 
        parts.*/
     A[ start++ ] = Arr[ p ] ;                          
  }
}