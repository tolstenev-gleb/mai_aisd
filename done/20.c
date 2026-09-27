/*
20. Проверить, является ли двоичное дерево Двоичным B-деревом, то есть не
содержит ни одного узла степени 1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

int is_b_tree(Node* root) {
    if (root == NULL) {
        return 1;
    }

    if ((root->left != NULL && root->right == NULL) ||
        (root->left == NULL && root->right != NULL)) {
        return 0;
    }

    int res = 0;
    if (is_b_tree(root->left) && is_b_tree(root->right)) {
        res = 1;
    } 
    return res;
}

int main(void) {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Это B-дерево: %s\n",
           is_b_tree(root) ? "да" : "нет");
    return 0;
}
