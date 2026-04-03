//Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

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

int main() {
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);

    // Array of adjacency lists
    struct Node* adj[n];

    // Initialize all lists as NULL
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph, uncomment below:
        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}