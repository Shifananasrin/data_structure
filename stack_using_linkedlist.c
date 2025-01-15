
	#include <stdio.h>
	#include <stdlib.h>

	#define MAX_SIZE 5  

	// Define Node structure
	struct Node 
	{
		int data;
		struct Node *link;
	};


	struct Node *top = NULL;  

	// Initialize size of the stack
	int size = 0;  

	//  create a new Node
	struct Node *createNode(int data) 
	{
		struct Node *newnode = malloc(sizeof(struct Node));
		newnode->data = data;
		newnode->link = NULL;
		return newnode;
	}

	//  push  onto the stack
	void push(int data) 
	{
		if (size == MAX_SIZE) 
		{  
			printf("Stack overflow! Cannot push more elements.\n");
			return;
		}
		struct Node *newnode = createNode(data); 
		if (top == NULL) 
		{
			top = newnode;  
		} 
		else 
		{
			newnode->link = top; 
			top = newnode;  
		}
		// Increment the stack size
		size++;  
		printf("Inserted value: %d\n", data);
	}

	//  pop  from the stack
	void pop() 
	{
		if (top == NULL) 
		{
			printf("Stack is empty\n");
		} 
		else 
		{
			struct Node *ptr = top;  
			top = top->link;        
			printf("Deleted value: %d\n", ptr->data); 
			free(ptr);             
			size--;  
		}
	}



	// Traverse 
	void Traverse() 
	{
		struct Node *ptr = top;
		if (ptr == NULL) 
		{
			printf("Stack is empty\n");
	    	} 
	    	else 
	    	{
			printf("Stack elements: ");
			while (ptr != NULL) 
			{
			    	printf("%d ", ptr->data);  
			    	ptr = ptr->link; 
			}
			printf("\n");  
	    	}
	}

	int main() 
	{
		int choice, data;
		do 
		{       
			printf("1.PUSH\n");
			printf("2.POP\n");
			printf("3.TRAVERSAL\n");
			printf("4.EXIT\n");
			printf("enter your choice ");
			scanf("%d", &choice);
			switch (choice) 
			{
				case 1:
					printf("\nEnter value to push: ");
					scanf("%d", &data);
					push(data);
					break;
				case 2:
		        		pop();
		        		break;
		    		case 3:
					Traverse();
					break;
		    		case 4:
					printf("Exiting...\n");
					exit(0);
		    		default:
		        		printf("\nInvalid option! Try again...\n");
			}
	 	} 
	 	while (1);
		return 0;
	}
