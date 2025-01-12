#include<stdio.h>
		#include<stdlib.h>
		#define max 5	
		int stack[max];
		int top=-1;
		void push(int item)
		{
			if(top==max-1)
			{
				printf("\n stack is full\n");
			}
			else
			{
				top=top+1;
				stack[top]=item;
				printf("pushed item is %d",item);
			}
		}
		void pop()
		{

			if(top==-1)
			{
				printf("\n stack is empty\n");
				//return -1;
			}
			else
			{
				int pop_item=stack[top];
				top--;
				printf("pop item is %d",pop_item);
				
			}
		}

		void traversal()
		{

			if(top==-1)
			{
				printf("\n stack is empty\n");
			}
			else
			{
				
				for(int i=top;i>=0;i--)
				{
					
					
					
					printf("%d",stack[i]);
				}
			}
		}

		int main()
		{
			
			
			int choice;
			int item;
		   
			printf("enter your choice");
			
			do	
			{	printf("\n1.push\n2.pop\n3.traversal\n4.exit\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
					    printf("enter the item:");
					    scanf("%d",&item);
					    push(item);
					    break;
					case 2:
					    pop();
					    break;
					case 3:
					    traversal();
					    break;
					case 4:
					    break;
					default:
					    printf("\ninvalid");
					    break;
				}
			}
			while(choice!=4);
			return(0);
		}
