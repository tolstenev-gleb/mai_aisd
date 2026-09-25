/*
17. Проверить, находятся ли все листья двоичного дерева на одном уровне.
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

int leaves_same_level_rec(Node* root, int level, int* leaf_level) {
    if (root == NULL) {
        return 1;
    }

    if (root->left == NULL && root->right == NULL) {
        if (*leaf_level == -1) {
            *leaf_level = level;
            return 1;
        }
        return 0;
    }

    return leaves_same_level_rec(root->left, level + 1, leaf_level) &&
           leaves_same_level_rec(root->right, level + 1, leaf_level);
}

int leaves_same_level(Node* root) {
    int leaf_level = -1;
    return leaves_same_level_rec(root, 0, &leaf_level);
}

int main(void) {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Все листья на одном уровне: %s\n",
           leaves_same_level(root) ? "да" : "нет");
    return 0;
}
