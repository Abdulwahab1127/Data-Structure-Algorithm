#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int arr[100];
int top = -1;

void push(int x)
{
    if(top == 99)
    {
        printf("Stack Overflow!\n");
    }
    else{
        top++;
        arr[top] = x;
    }
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else{
        int value = arr[top];
        top--;
        return value;
    }
}

void show()
{
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    char postfix[100];
    printf("Enter a postfix expression :");
    fgets(postfix, sizeof(postfix), stdin);

    int length = strlen(postfix);

    for(int i = 0; i < length; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        if(postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '+' || postfix[i] == '-')
        {
            if(top >= 1)
            {
                int a = pop();
                int b = pop();
                switch(postfix[i])
                {
                    case '*': push(b * a); break;
                    case '/': push(b / a); break;
                    case '%': push(b % a); break;
                    case '+': push(b + a); break;
                    case '-': push(b - a); break;
                }
            }
            else
            {
                printf("Invalid Expression!\n");
            }
        }
    }

    if(top == 0)
    {
        printf("Result : %d\n", arr[top]);
    }
    else
    {
        printf("Invalid Expression!\n");
    }

    return 0;
}
