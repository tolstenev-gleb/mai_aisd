//27. Написать функцию преобразования инфиксной записи арифметического выражения в постфиксную запись.
// используется алгоритм дейкстры

// функция приоритета
int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack* stack = createStack(strlen(infix));
    int j = 0;
    int i;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (c == ' ') continue;
        
        if (isdigit(c) || isalpha(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(stack, c);
        }
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);   // убираем '('
        }
        else {   // оператор
            while (!isEmpty(stack) && priority(peek(stack)) >= priority(c)) {
                postfix[j++] = pop(stack);
            }
            push(stack, c);
        }
    }
    
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}