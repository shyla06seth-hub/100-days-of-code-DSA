//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Read key to delete
    scanf("%d", &key);

    // Delete first occurrence of key
    temp = head;

    // If head node itself contains the key
    if (head != NULL && head->data == key) {
        head = head->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key found
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Print the linked list after deletion
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}