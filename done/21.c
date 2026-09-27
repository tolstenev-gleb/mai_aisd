/*
21. Найти значение листа двоичного дерева, имеющего минимальную глубину.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void find_shallowest_leaf(Node *t, int depth, int *min_depth, int *best_val) {
    if (t == NULL) {
        return;
    }

    /* Если дошли до листа */
    if (t->left == NULL && t->right == NULL) {
        if (depth < *min_depth) {
            *min_depth = depth;
            *best_val = t->value;
        }
        return;
    }

    /* Спуск к потомкам с увеличением глубины */
    find_shallowest_leaf(t->left, depth + 1, min_depth, best_val);
    find_shallowest_leaf(t->right, depth + 1, min_depth, best_val);
}

/* Основная функция: корень дерева находится на глубине 0 */
int min_depth_leaf_value(Node *root) {
    int min_depth;
    int best_val;

    if (root == NULL) {
        return 0;
    }

    min_depth = INT_MAX;
    best_val = 0;

    /* Старт с глубины 0 для корня */
    find_shallowest_leaf(root, 0, &min_depth, &best_val);

    return best_val;
}