//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large value (INF)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int key[MAX];      // minimum weight to include node
    int visited[MAX];  // MST set

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1
    int totalWeight = 0;

    // Prim's Algorithm
    for (int count = 1; count <= n; count++) {
        int u = -1;

        // Find minimum key vertex not yet included
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}