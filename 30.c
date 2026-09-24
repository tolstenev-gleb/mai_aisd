//30. Написать функцию подсчёта высоты дерева арифметического выражения.

int treeHeight(const TreeNode* root) {
    if (root == NULL) return 0;
    
    int left  = treeHeight(root->left);
    int right = treeHeight(root->right);
    
    return 1 + (left > right ? left : right);
}