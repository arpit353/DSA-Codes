#include <bits/stdc++.h>
using namespace std;

/*

Given a linked list, write a function to rearrange its nodes so they are sorted in increasing order. In other words, sort linked list.

We can use SortedInsert() function to sort linked list. We start with an empty result list. Iterate through the source list and SortedInsert() each of its nodes into the result list. Be careful to note the .next field in each node before moving it into the result list.

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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert given node into the correct sorted position in the given
// list sorted in increasing order using dummy node strategy for the head end
void SortedInsert(struct Node** headRef, struct Node* newNode)
{
    struct Node dummy;
    struct Node* current = &dummy;
    dummy.next = *headRef;

    while (current->next != nullptr && current->next->data < newNode->data)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
    *headRef = dummy.next;
}

// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort(struct Node** headRef)
{
    struct Node* result = nullptr;		// build the answer here
    struct Node* current = *headRef;	// iterate over the original list
    struct Node* next;

    while (current != nullptr)
    {
    	// tricky - note the next pointer before we change it
        next = current->next;

        SortedInsert(&result, current); // As we are using address, orignal will change.
        current = next;
    }

    *headRef = result;
}

// main method
int main()
{
    // input keys
	int keys[] = {6, 3, 4, 8, 2, 9};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

    InsertSort(&head);

	// print remaining linked list
    printList(head);

    return 0;
}
