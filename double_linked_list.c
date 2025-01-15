#include<stdio.h>
	#include<stdlib.h>

	// Node structure
	
	struct Node
	{
	    int data;
	    struct Node *Llink;
	    struct Node *Rlink;
	};

	struct Node *header = NULL;

	// Create a new node
	struct Node *CreateNode(int data)
	{
	    struct Node *newnode;
	    newnode = (struct Node*)malloc(sizeof(struct Node));
	    newnode->data = data;
	    newnode->Llink = NULL;
	    newnode->Rlink = NULL;
	    return newnode;
	}

	// Insert at the front
	void insertatFRONT(int data)
	{
	    struct Node *newnode;
	    newnode = CreateNode(data);

	    if (header == NULL)
	    {
		header = newnode;
	    }
	    else
	    {    
		newnode->Rlink = header;
		header->Llink = newnode;
		header = newnode;
	    }
	}

	// Insert at the end
	void insertatEND(int data)
	{
	    struct Node *ptr;
	    struct Node *newnode;
	    newnode = CreateNode(data);
	    
	    if (header == NULL)  
	    {
		header = newnode; 
	    }
	    else
	    {
		ptr = header;
		while (ptr->Rlink != NULL) 
		{
		    ptr = ptr->Rlink;
		}
		ptr->Rlink = newnode; 
		newnode->Llink = ptr;  
	    }
	}

	// Insert at any position
	void insertatANY(int key, int data)
	{
	    struct Node *ptr = header;
	    struct Node *newnode;
	    
	    while (ptr != NULL && ptr->data != key)
	    {
		ptr = ptr->Rlink;
	    }

	    if (ptr == NULL)
	    {
		printf("Key not found, insertion not possible\n");
		return;
	    }

	    newnode = CreateNode(data);
	    newnode->Rlink = ptr->Rlink;
	    if (ptr->Rlink != NULL)  // Update the Llink of the next node if it exists
	    {
		ptr->Rlink->Llink = newnode;
	    }
	    ptr->Rlink = newnode;
	    newnode->Llink = ptr;
	}

	// Delete from the front
	void deleteatFRONT()
	{
	    struct Node *ptr;
	    if (header == NULL)
	    {
		printf("List is empty\n");
	    }
	    else
	    {
		ptr = header;
		header = header->Rlink;
		if (header != NULL)  // Set the Llink of the new head to NULL
		{
		    header->Llink = NULL;
		}
		free(ptr);
		printf("Node deleted from the front\n");
	    }
	}

	// Delete from the end
	void deleteatEND()
	{
	    if (header == NULL)
	    {
		printf("List is empty\n");
	    }
	    else
	    {
		struct Node *ptr;
		struct Node *ptr1;
		ptr = header;
		while (ptr->Rlink != NULL)
		{
		    ptr1 = ptr;
		    ptr = ptr->Rlink;
		}
		ptr1->Rlink = NULL;
		free(ptr);
		printf("Node deleted from the end\n");
	    }
	}

	// Delete at any position
	void deleteAtANY(int key)
	{
	    if (header == NULL)
	    {
		printf("List is empty\n");
		return;
	    }

	    struct Node *ptr = header;
	    struct Node *prev = NULL;

	    while (ptr != NULL && ptr->data != key)
	    {
		prev = ptr;
		ptr = ptr->Rlink;
	    }

	    if (ptr == NULL)
	    {
		printf("Key not found, deletion not possible\n");
		return;
	    }

	    if (prev == NULL)  // If the node to delete is the first node
	    {
		header = ptr->Rlink;
	    }
	    else
	    {
		prev->Rlink = ptr->Rlink;
	    }

	    if (ptr->Rlink != NULL)
	    {
		ptr->Rlink->Llink = prev;  // Update the Llink of the next node
	    }

	    free(ptr);
	    printf("Node with key %d deleted\n", key);
	}

	// Traversal of the list
	void traversal()
	{
	    struct Node *ptr = header;
	    if (ptr == NULL)
	    {
		printf("List is empty\n");
		return;
	    }
	    
	    while (ptr != NULL)
	    {
		printf("%d ", ptr->data);
		ptr = ptr->Rlink;
	    }
	    printf("\n");
	}

	// Search for a node by key
	void searchNode(int key)
	{
	    struct Node *ptr = header;
	    while (ptr != NULL)
	    {
		if (ptr->data == key)
		{    
		    printf("Key %d found in the list\n", key);
		    return;
		}
		ptr = ptr->Rlink;
	    }
	    printf("Key %d not found in the list\n", key);
	}

	// Main function with menu-driven options
	int main()
	{
	    int choice, data, key;

	    do
	    {
	  
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert at any \n");
		printf("4. Delete from front\n");
		printf("5. Delete from end\n");
		printf("6. Delete at any\n");
		printf("7. Traverse the list\n");
		printf("8. Search a node\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
		    case 1:
		        printf("Enter data to insert at front: ");
		        scanf("%d", &data);
		        insertatFRONT(data);
		        break;
		    case 2:
		        printf("Enter data to insert at end: ");
		        scanf("%d", &data);
		        insertatEND(data);
		        break;
		    case 3:
		        printf("Enter key to insert after: ");
		        scanf("%d", &key);
		        printf("Enter data to insert: ");
		        scanf("%d", &data);
		        insertatANY(key, data);
		        break;
		    case 4:
		        deleteatFRONT();
		        break;
		    case 5:
		        deleteatEND();
		        break;
		    case 6:
		        printf("Enter key to delete: ");
		        scanf("%d", &key);
		        deleteAtANY(key);
		        break;
		    case 7:
		        traversal();
		        break;
		    case 8:
		        printf("Enter key to search: ");
		        scanf("%d", &key);
		        searchNode(key);
		        break;
		    case 9:
		        printf("Exiting...\n");
		        break;
		    default:
		        printf("Invalid choice. Please try again.\n");
		}

	    } 
	    while (choice != 9);  
	    return 0;
	}
	
