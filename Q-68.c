//Implement topological sorting using in-degree array and queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX];
    int i, j, u, v, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) where u -> v:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add all vertices with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Kahn's Algorithm
    while (front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("Graph has a cycle! Topological sorting not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}