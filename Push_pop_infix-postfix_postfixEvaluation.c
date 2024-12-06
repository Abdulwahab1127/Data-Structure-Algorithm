#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

#define Max 50

// Stack for infix to postfix conversion
char stack[Max];
int top = -1;

int stack_top = -1;

// Stack for postfix evaluation
int arr[100];
int postfix_top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == Max - 1);
}

void push_char(char elements) {
    if (isFull()) {
        cout << "\nWarning! OVERFLOW!!" << endl;
    } else {
        top++;
        stack[top] = elements;
    }
}

char pop_char() {
    if (isEmpty()) {
        cout << "\nWarning! UNDERFLOW!!" << endl;
        return '\0';
    } else {
        char elements = stack[top];
        top--;
        return elements;
    }
}

int isStackEmpty() {
    return (postfix_top == -1);
}

int isStackFull() {
    return (postfix_top == 99);
}

void push_int(int x) {
    if (isStackFull()) {
        cout << "Stack Overflow!" << endl;
    } else {
        postfix_top++;
        arr[postfix_top] = x;
    }
}

int pop_int() {
    if (isStackEmpty()) {
        cout << "Stack Underflow!" << endl;
        return 0;
    } else {
        int value = arr[postfix_top];
        postfix_top--;
        return value;
    }
}

int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int checkforOper(char a) {
    return (a == '+' || a == '-' || a == '^' || a == '*' || a == '/');
}

void infixToPostfix(char *infix, char *postfix) {
    int i, s = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char value = infix[i];
        if (value == ' ') {
            continue;
        } else if (isdigit(value) || isalpha(value)) {
            postfix[s++] = value;
        } else if (value == '(') {
            stack[++top] = value;
        } else if (value == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[s++] = pop_char();
            }
            if (!isEmpty() && stack[top] == '(') {
                pop_char();
            }
        } else if (checkforOper(value)) {
            while (!isEmpty() && precedence(stack[top]) >= precedence(value)) {
                postfix[s++] = pop_char();
            }
            push_char(value);
        }
    }
    while (!isEmpty()) {
        postfix[s++] = pop_char();
    }
    postfix[s] = '\0';
}

void push() {
    int push_input;
    if (top == Max - 1) {
        cout << "\nWarning! OVERFLOW!!" << endl;
    } else {
        cout << "\nEnter Element That You want to Add in Stack :";
        cin >> push_input;
        top = top + 1;
        stack[top] = push_input;
    }
}

void pop() {
    if (top == -1) {
        cout << "\nWarning! UNDERFLOW!!" << endl;
    } else {
        cout << "\nElement That is Popped = " << stack[top] << endl;
        top = top - 1;
    }
}

int evaluatePostfix(char *postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push_int(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int operand2 = pop_int();
            int operand1 = pop_int();
            switch (ch) {
                case '+':
                    push_int(operand1 + operand2);
                    break;
                case '-':
                    push_int(operand1 - operand2);
                    break;
                case '*':
                    push_int(operand1 * operand2);
                    break;
                case '/':
                    push_int(operand1 / operand2);
                    break;
                case '^':
                    push_int(static_cast<int>(pow(operand1, operand2)));
                    break;
            }
        }
    }
    return pop_int();
}

void show() {
    for (int i = stack_top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {
    int select = 1;
    char infixExp[50];
    char postfixExp[50];
    char expression[100];

    while (select != 6) {
        cout << "\nOperations:";
        cout << "\n1. Push to Stack";
        cout << "\n2. Pop from Stack";
        cout << "\n3. Infix to Postfix Conversion";
        cout << "\n4. Evaluate Postfix Expression";
        cout << "\n5. Show Stack";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> select;

        switch (select) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Enter the Infix Expression : ";
                cin >> infixExp;
                infixToPostfix(infixExp, postfixExp);
                cout << "Postfix Expression : " << postfixExp << endl;
                break;
            case 4:
                cout << "Enter the Postfix Expression : ";
                cin >> expression;
                int result = evaluatePostfix(expression);
                cout << "Result : " << result << endl;
                break;
            case 5:
                show();
                break;
            case 6:
                select = 6;
                cout << "Thank You for Using The Code!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
