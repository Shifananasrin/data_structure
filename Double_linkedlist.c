#include<stdio.h>
#include<stdlib.h>

//CREATE A NODE STRUCTURE

struct Node
{
	int data;
	struct Node *Llink;
	struct Node *Rlink;
};

// CREATE A NODE
//L for left
//R for right

struct Node *header = NULL;
struct Node *CreateNode(int data)
{
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->Llink = NULL;
	newnode->Rlink = NULL;
	return newnode;
}

//INSERTION  AT FRONT

void insertatFRONT(int data)
{
	struct Node *newnode;
	newnode=CreateNode(data);
	if (header == NULL)
	{
	
		header = newnode;
	}
	else
	{
		
		newnode->Rlink=header;
		header->Llink=newnode;
		header=newnode;
	}
}

//INSERT AT END

void insertatEND(int data)
{
	struct Node *ptr;
	struct Node *newnode;
	newnode= CreateNode(data);
	ptr=header->Rlink;
	while(ptr->Rlink!=NULL)
	{
		ptr=ptr->Rlink;
		
		
	}
	ptr->Rlink=newnode;
	header->Llink=ptr;
}

// INSERT AT ANY
		
//void insertAtAny(int key, int data)
//{
	//struct Node *ptr ;
	//ptr= header;
	//struct Node *newnode;
	//while ((ptr != NULL) && (ptr->data != data))
	//{
		//ptr = ptr->Rlink;
	//}
	//if (ptr == NULL)
	//{
		//printf("Key not found, insertion not possible\n");
		//return;
	//}
	//newnode = CreateNode(data);
	//newnode->Rlink = ptr->Llink;
	//newnode->Llink = ptr->Rlink;
	//ptr->Rlink = newnode;
	//ptr->Llink = newnode;
	//newnode->data=data;
//}

//DELETE AT FRONT

 void deleteatFRONT()
{
	struct Node *ptr;
	if (header == NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr = header;
	header = ptr->Rlink;
	free(ptr);
}


// DELETE AT END
void deleteAtEnd()
{
	if (header == NULL)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		struct Node *ptr ;
		struct Node *ptr1;
		ptr= header;
		ptr1 = ptr;
		while (ptr->Rlink != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->Rlink;
		}
		ptr1->Rlink = NULL;
		free(ptr);
	}
}

// traversal

void traversal()
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->Rlink;
	}
	printf("\n");
}
int main()
		{
		    insertatFRONT(10);
		    insertatFRONT(20);
		    insertatEND(30);
		    insertatEND(40);
		    //insertAtLast(80);
		    //traverseList();
		    //insertAtAny(10, 55);
		    traversal();

		   // searchNode(55);
		    //searchNode(70);

		    deleteatFRONT();
		   traversal();

		    deleteAtEnd();
		    traversal();

		    //deleteAtAny(55);  // Delete the node 25
		    //traverseList();

		   // deleteAtAny(80);  // delete a non-existent node
		    //traverseList();

		    return 0;
		}

