#include <bits/stdc++.h>
using namespace std;

/*

Given a list that is sorted in increasing order, and a single node, insert the node into the correct sorted position in the given list. The function should take an existing node, and just rearranges pointers to insert it into the list.

There are many possible solutions to this problem. The basic strategy is to iterate down the list looking for the place to insert the new node. That could be the end of the list, or a point just before a node which is larger than the new node. The three solutions presented handle the “head end” case in different ways…

*/

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to return new linked list node from heap
struct Node* newNode(int key)
{
	// Allocate the new node in the heap using malloc() and set its data
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = key;

	// Set the .next pointer of the new node to point to null
	node->next = nullptr;

	return node;
}

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

// Function to insert the given node into the correct sorted position in the 
// given list sorted in increasing order
void SortedInsert(struct Node** headRef, struct Node* newNode)
{
    // Special case for the head end
    if (*headRef == nullptr || (*headRef)->data >= newNode->data)
	{
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    // Locate the node before the point of insertion
    struct Node* current = *headRef;
    while (current->next != nullptr && current->next->data < newNode->data)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

// main method
int main()
{
    // input keys
	int keys[] = { 2, 4, 6, 8};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	struct Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

    SortedInsert(&head, newNode(5));
	SortedInsert(&head, newNode(9));
	SortedInsert(&head, newNode(1));

	// print remaining linked list
    printList(head);

    return 0;
}
