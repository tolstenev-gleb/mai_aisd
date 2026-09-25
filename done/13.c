/*
13. Написать функцию вычисления высоты двоичного дерева.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// --------------- основные функции ---------------

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int tree_height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(tree_height(root->left), tree_height(root->right));
}

// --------------- доп. функции для проверки ---------------

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

// --------------- main для проверки ---------------

int main(void) {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Высота дерева: %d\n", tree_height(root));
    return 0;
}
