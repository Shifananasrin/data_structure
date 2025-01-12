#include<stdio.h>
		int main()
		{
			int sum=0;
			int ary[10];
			int size;
			printf("enter the size:");
			scanf( "%d",&size);
			printf("enter the number\n");
			for(int i=0;i<size;i++)
			{
				scanf("%d",&ary[i]);
				
			}
			for(int i=0;i<size;i++)
			{
				sum=sum+ary[i];
			}
			printf("sum is %d",sum);
			return(0);
    }
