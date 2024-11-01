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
	
	
int main()
{
	struct Node *Node;
	insertAtfront(10);
	insertAtfrot(20);
	return(0);
}


