//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Function to create graph
void createGraph(struct Graph* graph, int V) {
    graph->V = V;
    for(int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if(right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&heap->heap[i], &heap->heap[smallest]);
        heapify(heap, smallest);
    }
}

// Extract minimum
struct HeapNode extractMin(struct MinHeap* heap) {
    struct HeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int vertex, int dist) {
    int i = heap->size++;
    heap->heap[i].vertex = vertex;
    heap->heap[i].dist = dist;

    while(i && heap->heap[(i-1)/2].dist > heap->heap[i].dist) {
        swap(&heap->heap[i], &heap->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];

    struct MinHeap heap;
    heap.size = 0;

    for(int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while(heap.size > 0) {
        struct HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];
        while(temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Output
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < graph->V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    struct Graph graph;
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    createGraph(&graph, V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v, w);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(&graph, source);

    return 0;
}