/*
12. Написать функцию текстовой визуализации дерева: каждое значение выводится
на отдельной строке с отступом, пропорциональным глубине узла.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// --------------- основные функции ---------------

void print_tree(Node* root, int depth) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%d\n", root->value);

    print_tree(root->left, depth + 1);
    print_tree(root->right, depth + 1);
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

    print_tree(root, 0);
    return 0;
}
