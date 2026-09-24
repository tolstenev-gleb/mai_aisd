// 29. Написать функцию подсчёта количества операций в дереве арифметического выражения.

int countOperations(const TreeNode* root) {
    if (root == NULL) return 0;
    
    int count = isOperator(root->data) ? 1 : 0;
    
    return count + countOperations(root->left)
                 + countOperations(root->right);
}