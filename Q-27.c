//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

/* Definition of Node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to create a linked list */
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

/* Function to find intersection */
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    struct Node* p2;

    while (p1 != NULL) {
        p2 = head2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("No Intersection");
}

/* Main Function */
int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}