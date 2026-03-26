//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

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

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if(root == NULL) return;

    struct Node* queue[MAX];
    int front = 0, rear = -1;

    queue[++rear] = root;

    int leftToRight = 1;

    while(front <= rear) {
        int size = rear - front + 1;

        int level[size];

        for(int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            // store normally
            if(leftToRight)
                level[i] = curr->data;
            else
                level[size - i - 1] = curr->data;

            if(curr->left)
                queue[++rear] = curr->left;

            if(curr->right)
                queue[++rear] = curr->right;
        }

        // print level
        for(int i = 0; i < size; i++)
            printf("%d ", level[i]);
    }

    leftToRight = !leftToRight; // alternate direction
    }


int main() {
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}