//Perform BFS from a given source using queue.

#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Queue implementation
int queue[100];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void bfs(int s, struct Node* adj[], int visited[]) {
    enqueue(s);
    visited[s] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input adjacency list
    // Format: number of neighbors followed by neighbors
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);

            struct Node* newNode = createNode(v);
            newNode->next = adj[i];
            adj[i] = newNode;
        }
    }

    int s;
    scanf("%d", &s);  // source vertex

    int visited[n];

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform BFS
    bfs(s, adj, visited);

    return 0;
}