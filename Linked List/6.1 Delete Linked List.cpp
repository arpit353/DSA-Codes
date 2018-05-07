#include <iostream>
using namespace std;

/*
Write a function that takes a linked list, deallocates all of its memory and sets its head pointer to nullptr (the empty list).

The idea is to iterate through the list and delete each node encountered. There is a slight complication inside the loop, since we need extract the .next pointer before we delete the node, since after the delete it will be technically unavailable.

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

// Iterative solution to delete a linked list
void deleteList(Node* &headRef)
{
   Node* prev = headRef;

   while (headRef)
   {
       headRef = headRef->next;

       cout << "Deleting " << prev->data << endl;
       delete prev;
       prev = headRef;
   }
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
