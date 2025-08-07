#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

int intStack[MAX];
int intTop = -1;

void pushChar(char ch) {
    stack[++top] = ch;
}

char popChar() {
    return (top == -1) ? -1 : stack[top--];
}

char peekChar() {
    return (top == -1) ? -1 : stack[top];
}

void pushInt(int val) {
    intStack[++intTop] = val;
}

int popInt() {
    return (intTop == -1) ? -1 : intStack[intTop--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int isAlpha(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch, temp;

    while ((ch = infix[i++]) != '\0') {
        if (isDigit(ch) || isAlpha(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            pushChar(ch);
        }
        else if (ch == ')') {
            while (peekChar() != '(') {
                postfix[k++] = popChar();
            }
            popChar(); 
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peekChar()) >= precedence(ch)) {
                postfix[k++] = popChar();
            }
            pushChar(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = popChar();
    }

    postfix[k] = '\0';
}

int evalPostfix(char postfix[]) {
    int i = 0, op1, op2, res;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isDigit(ch)) {
            pushInt(ch - '0');
        }
        else if (isOperator(ch)) {
            op2 = popInt();
            op1 = popInt();
            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '^': {
                    res = 1;
                    for (int j = 0; j < op2; j++) res *= op1;
                    break;
                }
            }
            pushInt(res);
        }
    }

    return popInt();
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression (single digits/letters only): ");
    gets(infix);  

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Only works for numeric postfix expression
    int result = evalPostfix(postfix);
    printf("Evaluated result: %d\n", result);

    return 0;
}
