#include<stdio.h>
 		int a[10], b[10], d[20];
		int size1, size2;
		int i, j;
		void sort(int c[], int size) 
		{
			int temp;
			for(i = 0; i < size - 1; i++) 
			{
				for(j = i + 1; j < size; j++)
		 		{
					if(c[i] > c[j]) 
					{
						temp = c[i];
						c[i] = c[j];
						c[j] = temp;
	   				}
				}
			}
		}
 		void merge(int a[],int b[],int size1,int size2)
		{
			for(i = 0; i < size1; i++) 
			{
				d[i] = a[i];
			}
			for(i = 0; i < size2; i++)
			{
				d[size1 + i] = b[i];
			}
		}
		void display(int c[], int size)
		{
			for(i = 0; i < size; i++) 
			{
				printf("%d\t", c[i]);
			}
		}
		int main() 
		{
			printf("Enter the size of first array:\n");
			scanf("%d", &size1);
			printf("Enter the elements of  first array :\n");
			for(i = 0; i < size1; i++)
			{
				scanf("%d", &a[i]);
			}
			printf("Enter the size of second array :\n");
			scanf("%d", &size2);
			printf("Enter the elements of secon array:\n");
			for(i = 0; i < size2; i++)
 			{
				scanf("%d", &b[i]);
			}
			printf("the entered unsorted array1\t");
			display(a,size1);
			printf("\nthe entered unsorted array2\t");
			display(b,size2);
			sort(a, size1);
			sort(b, size2);
		 	printf("\nSorted array 1:\n");
			display(a, size1);
			printf("\nSorted array 2:\n");
			display(b, size1);
			int merged_size = size1 + size2;
			printf("\nthe merged array");
			merge(a,b,size1,size2);
			display(d, merged_size);
			sort(d, merged_size);
			printf("\nMerged and sorted array:\n");
			display(d, merged_size);

			return 0;
		}
