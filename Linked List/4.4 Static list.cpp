#include <stdio.h>
#define N 5
 
/*

As discussed, Linked List nodes declared in automatic storage won’t hang around after you’ve left the scope they were defined in. The solution is to make it global.

*/

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

struct Node node[N];
 
// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("nullptr");
}

struct Node* createStaticList(int arr[])
{
    for (int i = 0; i < N; i++) 
    {
        node[i].data = arr[i];
        node[i].next = NULL;

        if (i > 0)
            node[i - 1].next = &node[i];
    }
    return node;
}

int main()
{
    int arr[N] = { 1, 2, 3, 4, 5 };
    struct Node* root = createStaticList(arr);

    printList(root);

    return 0;
}