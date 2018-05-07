#include <stdio.h>
 
/*

The lifetime of these nodes are the scope they are declared in, they no longer exists when the scope ends. We can verify that by placing our code inside block scope and try to access the nodes outside block scope.

If we just remove () it will print the linked list.

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
    int n = sizeof(arr)/sizeof(arr[0]);
    
	struct Node* root = NULL;
    

    { // Entering block scope
	    struct Node node[n];
	    for (int i = 0; i < n; i++) 
	    {
			node[i].data = arr[i];
			node[i].next = NULL;
			if (i > 0) {
				node[i-1].next = &node[i];
			}
	    }
	    root = node;
	} // Exiting block scope	
	
    printList(root);

    return 0;
}