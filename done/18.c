/*
18. Проверить, является ли двоичное дерево симметричным, то есть равным
своему отражению.
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

int are_mirrors(Node* left, Node* right) {
    if (left == NULL && right == NULL) {
        return 1;
    }
    if (left == NULL || right == NULL) {
        return 0;
    }
    return left->value == right->value &&
           are_mirrors(left->left, right->right) &&
           are_mirrors(left->right, right->left);
}

int is_symmetric(Node* root) {
    if (root == NULL) {
        return 1;
    }
    return are_mirrors(root->left, root->right);
}

int main(void) {
    Node* root = NULL;
    int values[] = {50, 30, 30, 20, 40, 40, 20};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Дерево симметрично: %s\n",
           is_symmetric(root) ? "да" : "нет");
    return 0;
}
