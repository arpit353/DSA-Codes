#include <bits/stdc++.h>
using namespace std;

/*

Fast/Slow pointer strategy –
 
There is a trick technique that uses two pointers to traverse the list. A “slow” pointer advances one nodes at a time, while the “fast” pointer goes two nodes at a time. When the fast pointer reaches the end, the slow pointer will be about half way. For either strategy, care is required to split the list at the right poin

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

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
It uses the fast/slow pointer strategy
*/
void FrontBackSplit(struct Node* source, struct Node** frontRef, 
					struct Node** backRef)
{
	// if length is less than 2, handle seperately
    if (source == nullptr || source->next == nullptr)
    {
        *frontRef = source;
        *backRef = nullptr;
		return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
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
