//Construct a binary tree from given preorder and inorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int preIndex = 0;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Build Tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if(start > end)
        return NULL;

    // Pick root from preorder
    int rootVal = preorder[preIndex++];
    struct Node* root = createNode(rootVal);

    // If single node
    if(start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, rootVal);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, end);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}