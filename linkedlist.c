# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>


typedef struct node 
{
	int val;
	struct node* next;
}
node;
 
void create (int);
void insert (int);  // keep the list sorted
void display (void);
void delete (int);
void search (int);

node* head = NULL;

int main()
{
	int to_create;

	printf ("Enter a value to create a linked list: ");
	scanf ("%d", &to_create);		

	create(to_create);
	
	int ans = 0;
	int value;
	
	do
	{
		printf("Avaliable commands\n\n"
		"\t\t1 - Insert\n"
		"\t\t2 - Delete\n"
		"\t\t3 - Search\n"
		"\t\t0 - Quit\n\n");

		printf("Your command: ");

		scanf("%d", &ans);
	
		value = 0;

		switch (ans) {
			case 1:
				printf ("Enter value to insert: ");
				scanf ("%d", &value);
	
				insert(value);   		  
				break;
			case 2:
				printf ("Enter value to delete: ");
				scanf ("%d", &value);

				delete(value); 
				break;
			case 3:
				printf ("Enter value to search: ");
 				scanf ("%d", &value);

				search(value); 
				break;
		}

		display();	
	}
	while (ans != 0);

	// free the list
	node* cursor = head;
	while (cursor != NULL) 
	{
		node* tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
		
	return 0;
}

void create(int to_create)
{
	node* start_list = malloc (sizeof(node));
	if (start_list == NULL)
	{
		printf ("Run out of memory\n");
		return;
	}

	start_list -> val = to_create;
	start_list -> next = NULL;
	
	head = start_list;
}

void display (void)
{
	node* crawler = head;

	if(crawler == NULL)
        	printf("List is empty\n");

	// make it beautiful
	for(int i=0; i<80; i++, printf("-"));
		printf("\n");	

	// go through and print value of each node
	while (crawler != NULL)
	{
		printf ("%d   ", crawler -> val);
		crawler = crawler -> next;
	}
	
	// make it beautiful again
	printf("\n");
	for(int i=0; i<80; i++, printf("-"));
		printf("\n");

}

void insert(int n)
{
	node* new_node = malloc (sizeof(node));
	if (new_node == NULL)
		return;

	new_node -> val = n;
	new_node -> next = NULL;

	node* previous = head;
	node* cursor = head;

	while (cursor != NULL) {
		if (cursor->val >= new_node->val) 
		{
			// Insert in the beginning
			if (cursor == head) 
			{
				new_node->next = cursor;
				head = new_node;
			} 
			// Insert in the middle
			else 
			{
				new_node->next = cursor;
				previous->next = new_node;
			}
			return;
		} 

		previous = cursor;
		cursor = cursor->next;
	}

	// Insert at the end
	previous->next = new_node;
}

void search (int n)
{
	node* crawler = head;
	
	while (crawler != NULL)
	{
		if (crawler->val == n)
		{
			printf("%d was found in the list!\n", n);
			return;
		}
		crawler = crawler->next;
	}	

	printf("%d was not found in the list!\n", n);
	return;
}

void delete (int n)
{
	//if search(n);
	node *previous = NULL, *ptr = head;

	while (ptr != NULL) 
	{
		if (ptr->val == n) 
		{
			if (ptr == head) 
			{
				head = ptr->next;
			} 
			else 
			{
				previous->next = ptr->next;				
			}
			free(ptr);
			return;
		}

		previous = ptr;
		ptr = ptr->next;
	}

	printf("Value not found!\n");
	
}
