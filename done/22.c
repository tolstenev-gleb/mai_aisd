/*
22. Найти значение нетерминальной вершины двоичного дерева, имеющей
максимальную глубину.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void find_deepest_non_terminal(Node* root, int depth, int* max_depth, int *ptr_best_val) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL || root->right != NULL) {
        if (depth > *max_depth) {
            *max_depth = depth;
            *ptr_best_val = root->value;
        }
    }

    find_deepest_non_terminal(root->left, depth + 1, max_depth, ptr_best_val);
    find_deepest_non_terminal(root->right, depth + 1, max_depth, ptr_best_val);
}

int find_deepest_non_terminal_node(Node* root, int *ptr_status) {
    int max_depth = -1;
    int best_val = 0;
    if (root->left == NULL && root->right == NULL) {
        *ptr_status = 0;
    } else {
        find_deepest_non_terminal(root, 0, &max_depth, &best_val);
        *ptr_status = 1;
    }
    return best_val;
}

int main(void) {
    Node* root = NULL;
    int values[] = {50};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int status = 0;
    int deepest = find_deepest_non_terminal_node(root, &status);
    if (status == 1) {
        printf("Нетерминальная вершина максимальной глубины: %d\n", deepest);
    } else {
        printf("Нетерминальная вершина не найдена\n");
    }

    return 0;
}
