// 26. Написать функцию печати арифметического выражения, заданного деревом, в постфиксной записи.
void printPostfix(const TreeNode* root) {
    if (root == NULL) return;
    
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c ", root->data);
}