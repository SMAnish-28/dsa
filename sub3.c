#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in level order
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node** queue = (struct Node*)malloc(100 * sizeof(struct Node));
    int front = 0, rear = 0;

    queue[rear++] = *root;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue);
}

// Function to count the number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if the binary tree is strictly binary (Full Binary Tree)
bool isStrictlyBinary(struct Node* root) {
    if (root == NULL)
        return true;

    // If both children are present or both are absent
    if ((root->left == NULL && root->right == NULL) ||
        (root->left != NULL && root->right != NULL))
        return isStrictlyBinary(root->left) && isStrictlyBinary(root->right);

    return false; // One child is missing
}

// Check if the binary tree is complete
bool isCompleteBinaryTree(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    // If index exceeds total nodes, it's not complete
    if (index >= totalNodes)
        return false;

    return isCompleteBinaryTree(root->left, 2 * index + 1, totalNodes) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, totalNodes);
}

// Check if the binary tree is almost complete
bool isAlmostCompleteBinaryTree(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    // If index exceeds total nodes, it's not almost complete
    if (index >= totalNodes)
        return false;

    // For almost complete binary trees:
    // - The last level can have missing nodes but only on the right side.
    // - All other levels must be completely filled.
    
    bool leftComplete = isAlmostCompleteBinaryTree(root->left, 2 * index + 1, totalNodes);
    bool rightComplete = isAlmostCompleteBinaryTree(root->right, 2 * index + 2, totalNodes);

    return leftComplete && rightComplete && 
           ((root->right == NULL && root->left != NULL) || root->right != NULL);
}

int main() {
    struct Node* root = NULL;

    int n, data;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }

    int totalNodes = countNodes(root);

    printf("\nChecking properties of the Binary Tree:\n");

    // Strictly Binary Tree Check
    if (isStrictlyBinary(root))
        printf("The tree is a Strictly Binary Tree.\n");
    else
        printf("The tree is NOT a Strictly Binary Tree.\n");

    // Complete Binary Tree Check
    if (isCompleteBinaryTree(root, 0, totalNodes))
        printf("The tree is a Complete Binary Tree.\n");
    else
        printf("The tree is NOT a Complete Binary Tree.\n");

    // Almost Complete Binary Tree Check
    if (isAlmostCompleteBinaryTree(root, 0, totalNodes))
        printf("The tree is an Almost Complete Binary Tree.\n");
    else
        printf("The tree is NOT an Almost Complete Binary Tree.\n");

    return 0;
}