#include <iostream>
using namespace std;

/*

Recursive solution

*/

// Data Structure to store a linked list node
struct Node {
    int data;
    Node* next;
};

// Helper function to create a new node with the given data and
// pushes it onto the front of the list
void push(Node*& headRef, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

// Recursive solution to delete a linked list
void deleteList(Node *&headRef)
{
    if (headRef == nullptr)
        return;

    if (headRef->next)
        deleteList(headRef->next);

    cout << "Deleting " << headRef->data << endl;
    delete headRef;

    headRef = nullptr;
}

// main method
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

	// points to the head node of the linked list
	Node* head = nullptr;

	// construct linked list
    for (int i = n - 1; i >= 0; i--)
        push(head, keys[i]);

    deleteList(head);

    if (head == nullptr)
        cout << "List deleted";

    return 0;
}
