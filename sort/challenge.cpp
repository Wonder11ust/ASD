#include<stdio.h>
	
	void tukar(int *a,int *b)
	{
		int sementara = *a;
		*a = *b;
		*b = sementara;
	}
	
	void selection_sort(int array[],int size)
	{
		for(int step =0;step<size-1;step++)
		{
			int min_idx = step;
			for(int i=step+1;i<size;i++)
			{
				if(array[i]<array[min_idx])
				min_idx = i;
			}
				 tukar(&array[min_idx],&array[step]);
		}
	}
	
	void insertion_sort(int array[],int size)
	{
		int temp;
		for(int i=1;i<size;i++){
			temp = array[i];
			int j=i-1;
			while(array[j]>temp && j>=0)
			{
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = temp;
		}
	}
	
	void cetakArray(int array[],int size)
	{
		for(int i=0;i<size;++i)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	
	int main()
	{
		int data[] = {23,67,89,5,45,20,15,27} ;
	
	
	
		int size = sizeof(data)/sizeof(data[0]);
		 selection_sort(data,size);
		printf("Sorting Selection (ascending):\n");
		 cetakArray(data,size);
		 printf("\n");
		 printf("Insertion Sort Ascending:\n");
		 insertion_sort(data,size);
		 cetakArray(data,size);
		 
	}
