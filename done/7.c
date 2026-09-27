/*
7. Написать функцию удаления из двоичного дерева всех листьев, числовое значение
которых отличается от значения родителя более чем на заданное значение d.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// --------------- основные функции ---------------

Node* remove_leaf_by_gap_rec(Node* root, int parent_value, int d) {
    if (root == NULL) {
        return NULL;
    }

    root->left = remove_leaf_by_gap_rec(root->left, root->value, d);
    root->right = remove_leaf_by_gap_rec(root->right, root->value, d);

    if (root->left == NULL && root->right == NULL) {
        if (abs(root->value - parent_value) > d) {
            free(root);
            return NULL;
        }
    }

    return root;
}

Node* remove_leaves_by_gap(Node* root, int d) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    return remove_leaf_by_gap_rec(root, root->value, d);
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

// --------------- main для проверки ---------------

int main(void) {
    Node* root = NULL;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 25, 35, 10};
    int n = 10;

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("До удаления листьев:\n");
    print_tree(root, 0);

    root = remove_leaves_by_gap(root, 5);

    printf("\nПосле удаления листьев:\n");
    print_tree(root, 0);

    return 0;
}
