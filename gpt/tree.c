#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;


/*
    Создание нового узла
*/
Node *create_node(int value)
{
    Node *node;

    node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}


/*
    Вставка значения в бинарное дерево поиска

              50
             /  \
           30    70
          /  \  /  \
        20  40 60  80
*/
Node *insert(Node *root, int value)
{
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}


/*
    Поиск значения
*/
Node *find(Node *root, int value)
{
    if (root == NULL) {
        return NULL;
    }

    if (value == root->value) {
        return root;
    }

    if (value < root->value) {
        return find(root->left, value);
    }

    return find(root->right, value);
}


/*
    Прямой обход:
    root -> left -> right

             50
            /  \
          30    70
         /  \
       20   40

    Результат:
    50 30 20 40 70
*/
void preorder(Node *root)
{
    if (root == NULL) {
        return;
    }

    printf("%d ", root->value);

    preorder(root->left);
    preorder(root->right);
}


/*
    Симметричный обход:
    left -> root -> right

    Для BST значения выводятся
    в отсортированном порядке.
*/
void inorder(Node *root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->value);

    inorder(root->right);
}


/*
    Обратный обход:
    left -> right -> root
*/
void postorder(Node *root)
{
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->value);
}


/*
    Поиск минимального элемента
*/
Node *find_min(Node *root)
{
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}


/*
    Поиск максимального элемента
*/
Node *find_max(Node *root)
{
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}


/*
    Удаление узла

    Возможны три случая:

    1. У узла нет потомков
    2. Есть один потомок
    3. Есть два потомка
*/
Node *remove_node(Node *root, int value)
{
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = remove_node(root->left, value);
    }
    else if (value > root->value) {
        root->right = remove_node(root->right, value);
    }
    else {

        /*
            Случай 1:
            нет левого потомка
        */
        if (root->left == NULL) {
            Node *temp = root->right;

            free(root);

            return temp;
        }

        /*
            Случай 2:
            нет правого потомка
        */
        if (root->right == NULL) {
            Node *temp = root->left;

            free(root);

            return temp;
        }

        /*
            Случай 3:
            есть оба потомка

            Находим минимальный элемент
            в правом поддереве.
        */
        Node *temp = find_min(root->right);

        root->value = temp->value;

        root->right = remove_node(root->right, temp->value);
    }

    return root;
}


/*
    Подсчёт количества узлов
*/
int count_nodes(Node *root)
{
    if (root == NULL) {
        return 0;
    }

    return 1
        + count_nodes(root->left)
        + count_nodes(root->right);
}


/*
    Высота дерева

    Пустое дерево имеет высоту 0.
*/
int height(Node *root)
{
    if (root == NULL) {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height) {
        return left_height + 1;
    }

    return right_height + 1;
}


/*
    Освобождение всей памяти дерева
*/
void free_tree(Node *root)
{
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}


int main(void)
{
    /*
        ========================================
        1. СОЗДАНИЕ ОТДЕЛЬНЫХ УЗЛОВ ВРУЧНУЮ
        ========================================

                    50
                   /  \
                 30    70
                /  \
              20   40
    */

    Node *node1 = create_node(50);
    Node *node2 = create_node(30);
    Node *node3 = create_node(70);
    Node *node4 = create_node(20);
    Node *node5 = create_node(40);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    Node *root = node1;

    printf("Дерево, созданное вручную:\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");


    /*
        ========================================
        2. СОЗДАНИЕ ДЕРЕВА ЧЕРЕЗ INSERT
        ========================================
    */

    Node *tree = NULL;

    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 70);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 60);
    tree = insert(tree, 80);

    /*
                    50
                   /  \
                 30    70
                /  \  /  \
              20   40 60  80
    */

    printf("\nДерево после insert:\n");

    printf("Preorder:  ");
    preorder(tree);
    printf("\n");

    printf("Inorder:   ");
    inorder(tree);
    printf("\n");

    printf("Postorder: ");
    postorder(tree);
    printf("\n");


    /*
        ========================================
        3. ПОИСК
        ========================================
    */

    Node *found = find(tree, 40);

    if (found != NULL) {
        printf("\nЭлемент 40 найден\n");
    }
    else {
        printf("\nЭлемент 40 не найден\n");
    }


    /*
        ========================================
        4. MIN / MAX
        ========================================
    */

    Node *min = find_min(tree);
    Node *max = find_max(tree);

    printf("\nМинимум: %d\n", min->value);
    printf("Максимум: %d\n", max->value);


    /*
        ========================================
        5. КОЛИЧЕСТВО УЗЛОВ
        ========================================
    */

    printf("\nКоличество узлов: %d\n", count_nodes(tree));


    /*
        ========================================
        6. ВЫСОТА
        ========================================
    */

    printf("Высота дерева: %d\n", height(tree));


    /*
        ========================================
        7. УДАЛЕНИЕ
        ========================================
    */

    tree = remove_node(tree, 20);

    printf("\nПосле удаления 20:\n");
    inorder(tree);
    printf("\n");

    tree = remove_node(tree, 30);

    printf("\nПосле удаления 30:\n");
    inorder(tree);
    printf("\n");

    tree = remove_node(tree, 50);

    printf("\nПосле удаления 50:\n");
    inorder(tree);
    printf("\n");


    /*
        ========================================
        8. ОСВОБОЖДЕНИЕ ВСЕГО ДЕРЕВА
        ========================================
    */

    free_tree(tree);

    tree = NULL;

    return 0;
}