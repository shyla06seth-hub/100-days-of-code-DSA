//Print the nodes visible when the binary tree is viewed from the right side

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

// Right View
void rightView(struct Node* root) {
    if(root == NULL) return;

    struct Node* queue[MAX];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while(front <= rear) {
        int size = rear - front + 1;

        for(int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            // print last node of level
            if(i == size - 1)
                printf("%d ", curr->data);

            if(curr->left)
                queue[++rear] = curr->left;

            if(curr->right)
                queue[++rear] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}