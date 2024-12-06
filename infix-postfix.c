#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>

#define Max 50
//Created a Stack to Push Values on top
char stack[Max];
//As the Stack is Empty so index top is -1
int top = -1;




int isEmpty() {
    return (top == -1);
}
int isFull() {
    return (top == Max -1);
}

void push(char elements) {
    if (top == Max -1) {
        printf("\nWarning! OVERFLOW!!\n");
    } else {
        top++;
        stack[top] = elements;
    }
}
char pop() {
    if (top == -1) {
        printf("\nWarning! UNDERFLOW!!\n");
        return '\0';
    } else {
        char elements = stack[top];
        top--;
        return elements;
    }
}

//Created a Function to Check For Precedence
 int precedence(char x){
    if(x == '^')
        return 3;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else
    //Lower Precedence for Non Operators
        return 0;

 }

 //Took Help from Internet here for this!
int checkforOper( char a){

return (a == '+' || a == '-' || a == '^' || a == '*' ||a == '/');

}



 void infixToPostfix(char *infix , char *postfix){

     int i,s = 0;
     //Using Loop to Print Value one by One
     for(i=0;i<infix[i]!= '\0';i++){

        char value = infix[i];

        //In-case of any space,remove it
        if(value == ' '){
            continue;
        }
        else if(isdigit(value) || isalpha(value)){
                postfix[s++] = value;

        }
        else if( value == '('){

           stack[++top] = value;

        }else if(value == ')'){

            while (!isEmpty() && stack[top] != '(') {
                //it will push the values till it find (
                postfix[s++] = pop();
            }
            //When it reaches the opening Bracket
            // Simple Pop the '('
             if (!isEmpty() && stack[top] == '(') {
                pop();
            }
        //Checking For Pre Here
        }else if(checkforOper(value)){
             while (!isEmpty() && precedence(stack[top]) >= precedence(value)) {
                postfix[s++] = pop();
            }
            push(value);

        }

     }
 //Push Remaining Values to Stack
    while (!isEmpty()) {
        postfix[s++] = pop();
    }

    postfix[s] = '\0';

 }

int main(){

    char infixExp[50];
    char postfixExp[50];

    printf("Enter The Infix Expression : ");
    gets(infixExp);

    infixToPostfix(infixExp,postfixExp);

    printf("\nPostFix Expression : %s ", postfixExp);

return 0;
}
