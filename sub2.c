#include <stdio.h>
#include <stdlib.h>

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
    
    // If the tree is empty, set the new node as root
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Create a queue for level order traversal
    struct Node** queue = (struct Node*)malloc(100 * sizeof(struct Node)); // Arbitrary size for simplicity
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* current = queue[front++];

        // If left child is empty, insert here
        if (current->left == NULL) {
            current->left = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->left; // Enqueue left child
        }

        // If right child is empty, insert here
        if (current->right == NULL) {
            current->right = newNode;
            free(queue);
            return;
        } else {
            queue[rear++] = current->right; // Enqueue right child
        }
    }

    free(queue);
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // Visit left subtree
        printf("%d ", root->data);      // Visit node
        inorderTraversal(root->right);  // Visit right subtree
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      // Visit node
        preorderTraversal(root->left);   // Visit left subtree
        preorderTraversal(root->right);  // Visit right subtree
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Visit left subtree
        postorderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Visit node
    }
}

// Function to print the tree in level order (for verification)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node** queue = (struct Node*)malloc(100 * sizeof(struct Node)); // Arbitrary size for simplicity
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left; // Enqueue left child
        if (current->right != NULL)
            queue[rear++] = current->right; // Enqueue right child
    }

    free(queue);
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

    printf("\nLevel Order Traversal of the Binary Tree:\n");
    levelOrderTraversal(root);

    printf("\nInorder Traversal of the Binary Tree:\n");
    inorderTraversal(root);

    printf("\nPreorder Traversal of the Binary Tree:\n");
    preorderTraversal(root);

    printf("\nPostorder Traversal of the Binary Tree:\n");
    postorderTraversal(root);
    
    return 0;
}