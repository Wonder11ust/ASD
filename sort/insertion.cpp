#include<stdio.h>
	
	void tukar(int *a,int *b)
	{
		int sementara = *a;
		*a = *b;
		*b = sementara;
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
	int data[30];
		int q;
		printf("Masukkan jumlah angka yang ingin di urutkan:");
		scanf("%d", &q);
		for(int i=0;i<q;i++){
			printf("masukkan angka :");
			scanf("%d", &data[i]);
		}
		
		int size = q;
		 insertion_sort(data,size);
		printf("Data setelah diurutkan dari kecil ke besar (ascending):\n");
		 cetakArray(data,size);
	}
