/*
10. Написать функцию удаления узла из двоичного дерева поиска с сохранением
порядка. Рассмотреть случаи: узел не найден, лист, один потомок, два потомка.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// --------------- основные функции ---------------

Node* find_min(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* remove_node(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = remove_node(root->left, value);
    } else if (value > root->value) {
        root->right = remove_node(root->right, value);
    } else {
        // Удаление листа
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* min_right = find_min(root->right);
        root->value = min_right->value;
        root->right = remove_node(root->right, min_right->value);
    }

    return root;
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
    int values[] = {50, 30, 70, 20, 40, 60, 80, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("До удаления:\n");
    print_tree(root, 0);
    printf("\n");

    root = remove_node(root, 777);
    printf("Удаление 777 (узел не существует):\n");
    print_tree(root, 0);
    printf("\n");

    root = remove_node(root, 60);
    printf("Удаление 60 (лист):\n");
    print_tree(root, 0);
    printf("\n");

    root = remove_node(root, 70);
    printf("Удаление 70 (один потомок):\n");
    print_tree(root, 0);
    printf("\n");

    root = remove_node(root, 30);
    printf("Удаление 30 (два потомка):\n");
    print_tree(root, 0);
    printf("\n");

    return 0;
}
