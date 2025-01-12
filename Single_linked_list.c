	 #include<stdio.h>
		#include<stdlib.h>
		
		// Node structure

		struct Node
		{
		    int data;
		    struct Node *link;
		};
		struct Node *header = NULL;
		
		//Create Node

		struct Node *CreateNode(int data)
		{
		    struct Node *newnode;
		    newnode = malloc(sizeof(struct Node));
		    newnode->data = data;
		    newnode->link = NULL;
		    return newnode;
		}

		// insert at front

		void insertAtFront(int data)
		{
		    struct Node *newnode = CreateNode(data);
		    if (header == NULL)
		    {
			header = newnode;
		    }
		    else
		    {
			newnode->link = header;
			header = newnode;
		    }
		}

		// insert at last

		void insertAtLast(int data)
		{
		    struct Node *ptr;
		    struct Node *newnode = CreateNode(data);

		    if (header == NULL)
		    {
			header = newnode;
			return;
		    }

		    ptr = header;
		    while (ptr->link != NULL)
		    {
			ptr = ptr->link;
		    }
		    ptr->link = newnode;
		}

		// insert at any

		void insertAtAny(int key, int data)
		{
		    struct Node *ptr = header;
		    struct Node *newnode;

		    while (ptr != NULL && ptr->data != key)
		    {
			ptr = ptr->link;
		    }

		    if (ptr == NULL)
		    {
			printf("Key not found, insertion not possible\n");
			return;
		    }

		    newnode = CreateNode(data);
		    newnode->link = ptr->link;
		    ptr->link = newnode;
		}

		// traversal

		void traverseList()
		{
		    struct Node *ptr = header;
		    while (ptr != NULL)
		    {
			printf("%d -> ", ptr->data);
			ptr = ptr->link;
		    }
		    printf("NULL\n");
		}

		// delete at front


		void deleteAtFront()
		{
		    struct Node *ptr;

		    if (header == NULL)
		    {
			printf("List is empty\n");
			return;
		    }

		    ptr = header;
		    header = header->link;
		    free(ptr);
		}

		// delete at end

		void deleteAtEnd()
		{
		    if (header == NULL)
		    {
			printf("List is empty\n");
			return;
		    }

		    if (header->link == NULL)
		    {
			free(header);
			header = NULL;
			return;
		    }

		    struct Node *ptr = header;
		    struct Node *ptr1 = NULL;

		    while (ptr->link != NULL)
		    {
			ptr1 = ptr;
			ptr = ptr->link;
		    }
		    ptr1->link = NULL;
		    free(ptr);
		}

		// delete at any

		void deleteAtAny(int key)
		{
		    if (header == NULL)
		    {
			printf("List is empty\n");
			return;
		    }

		    struct Node *ptr = header;
		    struct Node *prev = NULL;

		    // Search for the node with the given key
		    while (ptr != NULL && ptr->data != key)
		    {
			prev = ptr;
			ptr = ptr->link;
		    }

		    // Key not found
		    if (ptr == NULL)
		    {
			printf("Key not found, deletion not possible\n");
			return;
		    }

		    // Key found
		    if (prev == NULL)  // If the node to delete is the first node
		    {
			header = ptr->link;
		    }
		    else
		    {
			prev->link = ptr->link;
		    }

		    free(ptr);
		    printf("Node with key %d deleted\n", key);
		}

		// searching an node

		void searchNode(int key)
		{
			struct Node *ptr=header;
			while(ptr!=NULL)
			{
				if(ptr->data==key)
				{	
					printf("key %d found in the list\n",key);
					return;
				}
				ptr=ptr->link;
			}
			printf("key %d not found in the list\n",key);

		}

		int main()
		{
		    insertAtFront(10);
		    insertAtFront(20);
		    insertAtLast(30);
		    insertAtLast(40);
		    insertAtLast(80);
		    traverseList();
		    insertAtAny(10, 55);
		    traverseList();

		    searchNode(55);
		    searchNode(70);

		    deleteAtFront();
		    traverseList();

		    deleteAtEnd();
		    traverseList();

		    deleteAtAny(55);  // Delete the node 25
		    traverseList();

		    deleteAtAny(80);  // delete a non-existent node
		    traverseList();

		    return 0;
		}
