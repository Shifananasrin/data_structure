#include<stdio.h>
#include<stdlib.h>

//Node structure

struct Node
{
	int data;
	struct Node *link;
};

struct Node *header=NULL;

//Create a Node

 struct Node *createNode(int data)
{
	struct Node *newnode;
	newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->link=NULL;
	return(newnode);
}
//insertion at front
void insertAtFront(int data)
{
	//call create node function
	struct Node *newnode;
	newnode=createNode(data);

	//check node is first node
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}
//insertatend
void insertAtEnd(int data)
{
	struct Node *newnode;
	struct Node *ptr;
	newnode=createNode(data);
	ptr=header->link;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
		newnode=createNode(data);
		newnode->data=data;
		newnode->link=NULL;
		ptr->link=newnode;
		
}
//insertionatany
void insertionAtAny(int data)
{
	struct Node *newnode;
	struct Node *ptr;
	ptr=header;
	while((ptr!=NULL) && (ptr->data!=data))
	{
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("key is node found, insertion is not possible");
	}
	newnode=createNode(data);
	newnode->link=ptr->link;
	ptr->link=newnode;
	newnode->data=data;
}
//traversal function for checking the insertion are correct
void traversallist()
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}

//deletion at front
void deletionAtFront()
{
	struct Node *ptr;
	if(header==NULL)
	{
		printf("list is empty");
	}
	else
	{
		
	        ptr=header;
	        header=header->link;
	        free(ptr);
	}
		
}
// deletion at end
void deletionAtEnd()
{
	struct Node *ptr;
	struct Node *ptr1;
	if(header==NULL)
	{
		printf("list is empty");
	}
	while(ptr->link!=NULL)
	{
		ptr1=prt;
		ptr=ptr->link;
	}
	ptr->link=NULL;
	free(ptr);	
}
	
int main()
{
	//struct Node *Node;
	insertAtFront(10);
	insertAtFront(20);
	insertAtEnd(30);
	insertionAtAny(10);
	traversallist();
	deletionAtFront();
	traversallist();
	deletionAtEnd()
	traversallist();
	return(0);
}






























