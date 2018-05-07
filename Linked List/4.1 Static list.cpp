#include <stdio.h>


/*

The fundamental purpose of a pointer-based linked list is to provide dynamic expansion but in cases where your linked list does not need to have dynamic size, you can use static storage for it. The automatic storage has the property that its lifetime ends when execution of the block where it’s declared terminates, so it’s difficult to use it for long-lived data. Also, there’s typically a bound on the amount of such storage you can obtain and past that Memory overflow will happen. And there is no way to detect when you’ve exceeded that bound.

Below code uses automatic storage to allocate nodes of linked list.

In automatic storage we don't need malloc function to store and use pointer. We just make random nodes and the add the next link to point the next node.

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
    struct Node* curr = head;
    while (curr) 
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("nullptr");
}

// main function
int main()
{
    struct Node e = { 5, NULL }; //last node
	struct Node d = { 4, &e };
    struct Node c = { 3, &d };
    struct Node b = { 2, &c };
    struct Node a = { 1, &b };	//first node

    struct Node* head = &a;

    printList(head);

    return 0;
}

