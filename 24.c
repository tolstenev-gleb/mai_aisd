// 24. Написать функцию построения дерева арифметического выражения по постфиксной записи
// думаю достаточно будет именно функции, ничего больше, ведь только ее просят в задаче

TreeNode* buildExpressionTree(const char* postfix) {
    Stack* stack = createStack(strlen(postfix));
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        
        if (c == ' ') continue;
        
        if (isOperator(c)) {
            TreeNode* right = pop(stack);
            TreeNode* left = pop(stack);
            
            TreeNode* node = createNode(c);
            node->left = left;
            node->right = right;
            
            push(stack, node);
        } else {
            push(stack, createNode(c));
        }
    }
    
    TreeNode* root = pop(stack);
    free(stack->items);
    free(stack);
    
    return root;
}
