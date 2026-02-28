//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make the list circular
    if (temp != NULL)
        temp->next = head;

    // Traverse and print circular linked list
    temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}