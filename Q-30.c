//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, i;
    struct Node *head = NULL, *tail = NULL, *newNode;

    // Read number of terms
    scanf("%d", &n);

    // Read polynomial terms
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print polynomial
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}