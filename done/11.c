/*
11. Написать функцию освобождения памяти всего двоичного дерева.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;


// --------------- основные функции ---------------

void free_tree(Node* root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

// --------------- main для проверки ---------------

int main(void) {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Дерево: ");
    inorder(root);
    printf("\n");

    free_tree(root);
    root = NULL;

    printf("Память освобождена.\n");


    // проверка через valgrind
    return 0;
}
