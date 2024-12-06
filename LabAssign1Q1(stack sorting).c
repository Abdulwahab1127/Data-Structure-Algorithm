#include<stdio.h>
#include<stdlib.h>
#define Size 50

int top = -1;
int Stack[Size];


//We will be Required a Function to Push Values in Stack

void push(int push_input){

    if(top == Size -1){
        printf("\nWarning! OVERFLOW!!\n");
    }else{

           //After Push we'll Increment top with 1
            top = top+1;

           //Here we are storing Value to the top of Stack array!
            Stack[top]=push_input;

    }

}


void pop()
{
    if(top == -1 ){
        //In-case of Empty Stack
        printf("\nWarning! UNDERFLOW!!\n");

    }else{

       //The Value on top of Stack is Popped!
       printf("\nElement That is Popped = %d \n", Stack[top]);

       //After Popping, we'll Decrement the top with 1
       top = top -1;

    }

}

void StackSorting() {
    int temp_Stack[Size];
    int top1 = -1;

    // While the original stack is not empty
    while (top >= 0) {
        int temporary = Stack[top];
        top = top - 1;
     // Moving elements from temp to original stack
            while (top1 >= 0 && temporary > temp_Stack[top1]) {
            Stack[top + 1] = temp_Stack[top1];
            top = top + 1;
            top1 = top1 - 1;
        }

        temp_Stack[top1 + 1] = temporary;
        top1 = top1 + 1;
    }

    // Moving remaining elements from the temp to the original stack
    while (top1 >= 0) {
        Stack[top + 1] = temp_Stack[top1];
        top = top + 1;
        top1 = top1 - 1;
    }
}

void showStack(){
    int i;
     for(i=0;i<=top;i++){
        printf("%d ,",Stack[i]);
    }
}

int main(){

    int push_input;
    printf("\nWe Will Ask You to Push 6 Elements in the Stack!\n ");
        for (int i=0;i<6;i++){
            printf("\nEnter Element That You want to Add in Stack :");
            scanf("%d",&push_input);
            push(push_input);
        }
    //We Will Display The Un-Sorted Stack First

    printf("\nThe Original Stack: \n");
    showStack();

    StackSorting();

    printf("\nThe Sorted Stack: \n");
    showStack();


    return 0;
}
