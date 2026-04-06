//Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function to detect cycle
int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u, v, adj, visited))
                return 1;
        }
        else if (u != parent) {
            return 1; // cycle detected
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int u, v;

    // Input edges (undirected)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // v -> u
        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int visited[n];

    // Initialize visited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Check for cycle in all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}