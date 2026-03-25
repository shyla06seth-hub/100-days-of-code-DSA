//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure (for BFS with HD)
struct QNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1, r=2*i+2;
            if(l<n) nodes[i]->left = nodes[l];
            if(r<n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {

    if(root == NULL) return;

    struct QNode queue[MAX];
    int front = 0, rear = -1;

    // store result using HD index shift
    int result[200][MAX];   // columns
    int count[200] = {0};   // number of elements in each column

    int offset = 100; // to handle negative HD

    queue[++rear] = (struct QNode){root, 0};

    while(front <= rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        result[hd][count[hd]++] = curr->data;

        if(curr->left)
            queue[++rear] = (struct QNode){curr->left, temp.hd - 1};

        if(curr->right)
            queue[++rear] = (struct QNode){curr->right, temp.hd + 1};
    }

    // print from leftmost to rightmost
    for(int i=0;i<200;i++){
        if(count[i] > 0){
            for(int j=0;j<count[i];j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}