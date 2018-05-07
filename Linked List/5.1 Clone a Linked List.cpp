#include <bits/stdc++.h>
using namespace std;

/*

Write a function that takes a singly linked list and returns a complete copy of that list.

1. Naive Approach
The idea is to iterate over the original list in the usual way and maintain two pointers to keep track of the new list: one head pointer, and one tail pointer which always points to the last node in the new list. The first node is done as a special case, and then the tail pointer is used in the standard way for the others.


*/

/*

There is no need to worry about push function in this code. If you want to understand just take pen paper draw the example for understanding.

Example :- 

first 1->NULL  :- newlist at 1 and tail  at 1

Second 1->2-> NULL  :- newlist at 1 and tail at 2

struct Node* current = head;    // used to iterate over the original list
struct Node* newList = nullptr; // head of the new list
struct Node* tail = nullptr;    // kept pointing to last node in new list


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
struct Node* CopyList(struct Node* head)
{
	struct Node* current = head;    // used to iterate over the original list
	struct Node* newList = nullptr; // head of the new list
	struct Node* tail = nullptr;    // kept pointing to last node in new list

	while (current != nullptr)
	{
		// special case for the first new node
		if (newList == nullptr)
		{
			newList = (struct Node*)malloc(sizeof(struct Node));
			newList->data = current->data;
			newList->next = nullptr;
			tail = newList;
		}
		else
		{
			tail->next = (struct Node*)malloc(sizeof(struct Node));
			tail = tail->next;
			tail->data = current->data;
			tail->next = nullptr;
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
