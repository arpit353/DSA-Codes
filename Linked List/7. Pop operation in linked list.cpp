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

// The opposite of Push(). Takes a non-empty list and removes the front node, 
// and returns the data which was in that node.
int pop(struct Node* &headRef)
{
	// underflow condition
    if (headRef == nullptr)
        return -1;

    struct Node* head = headRef;
    int result = headRef->data; // pull out the data before the node is deleted

    headRef = headRef->next;    // unlink the head node for the caller
                                // Note the * -- uses a reference-pointer
                                // just like Push() and DeleteList().

    free(head);                 // free the head node

    return result;              // don't forget to return the data from the link
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

    cout << "Popped node " << pop(head) << endl;

	// print remaining linked list
    printList(head);

    return 0;
}
