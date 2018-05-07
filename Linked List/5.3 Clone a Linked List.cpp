#include <bits/stdc++.h>
using namespace std;

/*
5. Recursive Solution
Finally, for completeness, here is the recursive version of CopyList(). It has the pleasing shortness that recursive code often has. However, it is probably not good for production code since it uses stack space proportional to the length of its list.

*/

/*

There is no need to worry about push function in this code.

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

// Recursive function that takes a linked list and returns a complete copy of
// that list
struct Node* CopyList(struct Node* head)
{
	if (head == nullptr)
		return nullptr;
	else 
	{
		// Allocate the new node in the heap using malloc() and set its data
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = head->data;

		// recursively set the .next pointer of the new node by recur
		// for the rest nodes
		newNode->next = CopyList(head->next);

		return newNode;
	}
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
