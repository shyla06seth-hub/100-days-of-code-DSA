//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

// Display queue
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    scanf("%d", &m);

    // circular rotation
    for (int i = 0; i < m; i++) {
        int x = dequeue();
        enqueue(x);
    }

    display();

    return 0;
}