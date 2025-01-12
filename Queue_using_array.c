 #include<stdio.h>
		#include<stdlib.h>
		#define max 5	
		int queue[max];
		int front=-1,rear=-1;


		void enqueue(int item)
		{
			if(rear==max-1)
			{
				printf("\n queue is full\n");
			}
			else
			{
				if(front==-1)
				{
					front=0;
				}
				rear=rear+1;
				queue[rear]=item;
				printf("inserted item is %d",item);
			}
		}
		void dequeue()
		{

			if(front==-1 ||front>rear)
			{
				printf("\n queue is empty\n");
				//return -1;
			}
			else
			{
				int dequeue_item=queue[front];
				front=front+1;
				printf("dequeue item is %d",dequeue_item);
				if(front>rear)
				{
					front=rear=-1;
				}
				
			}
		}

		void traversal()
		{

			if(front==-1 || front>rear)
			{
				printf("\n queue is empty\n");
			}
			else
			{
				
				for(int i=front;i<=rear;i++)
				{
					printf("%d",queue[i]);
				}
			}
		}

		int main()
		{
			
			
			int choice;
			int item;
		   
			printf("enter your choice");
			
			do	
			{	printf("\n1.enqueue\n2.dequeue\n3.traversal\n4.exit\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
					    printf("enter the item:");
					    scanf("%d",&item);
					    enqueue(item);
					    break;
					case 2:
					    dequeue();
					    break;
					case  3:
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
