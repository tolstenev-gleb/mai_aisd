// 25 Написать функцию печати арифметического выражения, заданного деревом, в инфиксной форме со скобками.
void printInfix(TreeNode* root) {
    if (root == NULL) return;
    
    if (isOperator(root->data)) printf("(");
    
    printInfix(root->left);
    printf("%c", root->data);
    printInfix(root->right);
    
    if (isOperator(root->data)) printf(")");
}