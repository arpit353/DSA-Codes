#include <bits/stdc++.h>
using namespace std;

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

// Return the number of nodes in a list
int Length(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
    while (current != nullptr)
    {
        count++;
        current=current->next;
    }
    return count;
}

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
void FrontBackSplit(struct Node* source, struct Node** frontRef, 
					struct Node** backRef)
{
    int len = Length(source);
    if (len < 2)
    {
        *frontRef = source;
        *backRef = nullptr;
		return;
    }

	struct Node* current = source;

    int hopCount = (len - 1) / 2; // (figured these with a few drawings)
    for (int i = 0; i < hopCount; i++)
        current = current->next;

    // Now cut at current
    *frontRef = source;
    *backRef = current->next;
    current->next = nullptr;
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

	struct Node *a = nullptr, *b = nullptr;
    FrontBackSplit(head, &a, &b);

	// print linked list
    cout << "Front List - ";
    printList(a);
	
    cout << "\nBack List  - ";
	printList(b);

    return 0;
}
