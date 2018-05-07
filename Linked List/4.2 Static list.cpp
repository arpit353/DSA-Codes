#include <stdio.h>

/*

Above method would become a pain if number of nodes required is very large in the linked list. We can construct a linked list easily using iteration if the keys are given in the form of an array or any other data structure (using its iterator). Below is the implementation of the idea.

Similar think as previous code we just added the for look for automatci addition.

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
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node node[n];
    for (int i = 0; i < n; i++) 
    {
        node[i].data = arr[i];
        node[i].next = NULL;

        if (i > 0)
            node[i-1].next = &node[i];
    }

    struct Node* head = node;

    printList(head);

    return 0;
}