#include <bits/stdc++.h>
using namespace std;

/*
2. Using push()
The above implementation is a little unsatisfying because the 3-step-link-in is repeated — once for the first node and once for all the other nodes. Below function uses Push() to take care of allocating and inserting the new nodes, and so avoids repeating that code.


we are just using the first case of push meaning it add list element when null condition. We are pushing at the next pointer which is null.

*/


// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
    	cout << ptr->data << " -> ";
    	ptr = ptr->next;
    }

    cout << "nullptr";
}

// Helper function to insert a new node in the beginning of the linked list
void push(struct Node** headRef, int data)
{
    // Allocate the new node in the heap and set its data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

	// Set the .next pointer of the new node to point to the current
	// first node of the list.
    newNode->next = *headRef;

    // Change the head pointer to point to the new node, so it is
	// now the first node in the list.
    *headRef = newNode;
}

// Function that takes a linked list and returns a complete copy of that list
// using dummy node using push() function
struct Node* CopyList(struct Node* head)
{
	struct Node* current = head; 	// used to iterate over the original list
	struct Node* newList = nullptr; // head of the new list
	struct Node* tail = nullptr; 	// kept pointing to last node in new list

	while (current != nullptr)
	{
		// special case for the first new node
		if (newList == nullptr)
		{
			push(&newList, current->data);
			tail = newList;
		}
		else
		{
			push(&(tail->next), current->data); // add each node at the tail
			tail = tail->next; 		// advance the tail to the new last node
		}
		current = current->next;
	}

	return newList;
}

// main method
int main()
{
    // input keys
	int keys[] = {1, 2, 3, 4};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

	// copy linked list
	struct Node* dup = CopyList(head);

	// print duplicate linked list
    printList(dup);

    return 0;
}
