#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
    int height;
} Node;

int height(Node* node) {
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int get_balance(Node* node) {
    if (node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

Node* insert(Node* node, int value) {
    if (node == NULL)
        return create_node(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Valor já existe na árvore
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = get_balance(node);
    if (balance > 1 && value < node->left->value) // Left Left case
        return right_rotate(node);
    if (balance < -1 && value > node->right->value) // Right Right case
        return left_rotate(node);
    if (balance > 1 && value > node->left->value) { // Left Right case
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && value < node->right->value) { // Right Left case
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void inorder_traversal(Node* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->value);
        inorder_traversal(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 27);
    printf("Árvore AVL em ordem crescente:\n");
    inorder_traversal(root);
    return 0;
}
