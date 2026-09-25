/*
14. Написать функцию вычисления ширины двоичного дерева.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;
// --------------- основные функции ---------------


int tree_height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int left_h = tree_height(root->left);
    int right_h = tree_height(root->right);
    return 1 + ((left_h > right_h) ? left_h : right_h);  // переписать через max
}

// тернарный оператор 
// (условие истинно) ? (если да) : (если нет)

int count_level(Node* root, int level) {
    if (root == NULL) {
        return 0;
    }
    if (level == 0) {
        return 1;
    }
    return count_level(root->left, level - 1) +
           count_level(root->right, level - 1);
}

int tree_width(Node* root) {
    int h = tree_height(root);
    int max_width = 0;

    for (int level = 0; level < h; level++) {
        int cur = count_level(root, level);
        if (cur > max_width) {
            max_width = cur;
        }
    }

    return max_width;
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
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Ширина дерева: %d\n", tree_width(root));
    return 0;
}
