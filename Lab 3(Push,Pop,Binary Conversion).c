#include<stdio.h>
#include<math.h>

//Defining The Max value so wont have to define every time
#define MAX 10

int top = -1, input_array[MAX];


//Function For Binary to Decimal Conversion
void DeciToBinaryConv(){

    int num;

    // Taking Number from user
    printf("\nWrite any Number as Decimal: ");
    scanf("%d", &num);

    //Top Value Already Defined at line 7
    int stack[MAX], rem;

    while (num != 0) {
        rem = num % 2;
        stack[++top] = rem;
        num /= 2;
    }

    printf("\nAfter Converting to Binary = ");

    // Printing the binary by popping elements from the stack
    while (top >= 0) {
        printf("%d", stack[top--]);
    }

    printf("\n");
}

//Function for Binary to Decimal Conversion
void BinaryToDeciConv(){

    int num,deci=0,location=0;
    // Taking Number from user
    printf("\nWrite any Number as Binary: ");
    scanf("%d", &num);

    //Top Already Defined on Top lol
    int stack[MAX], binary;

    //We converting to Decimal from Binary
    //So 2 will be replaced with 10
    while (num != 0) {
        binary = num % 10;
        stack[++top] = binary;
        num /= 10;
    }

    printf("\nAfter Converting to Decimal = ");

    // Printing the Decimal by popping elements from the stack
    while (top >= 0) {

        //Took Help from Internet
        binary = stack[top--];
        deci += binary * pow(2,location);
        location++;

    }
     printf("%d", deci);

    printf("\n");
}

//Function For Push in Stack Array
void push(){

    int push_input;
    if(top == MAX -1){
        printf("\nWarning! OVERFLOW!!\n");
    }else{
        printf("\nEnter Element That You want to Add in Stack :");
        scanf("%d",&push_input);

       //After Push we'll Increment top with 1
        top = top+1;

       //Here we are storing Value to the top of Stack array!
        input_array[top]=push_input;

    }

}

//Function For Pop in Stack Array
void pop()
{
    if(top == -1 ){
        //In-case of Empty Stack
        printf("\nWarning! UNDERFLOW!!\n");

    }else{

       //The Value on top of Stack is Popped!
       printf("\nElement That is Popped = %d \n", input_array[top]);

       //After Popping, we'll Decrement the top with 1
       top = top -1;

    }

}
//Main Function to Call all other functions
int main()
{
    int select=1;
    while(select!=4){

        printf("\nOperations on the stack:");
        printf("\n 1.Push the Element"
                "\n 2.Pop the element"
                "\n 3.Decimal To Binary"
                "\n 4.Binary To Decimal"
                "\n 5.Close");
        printf("\n\nEnter the choice: ");
        scanf("%d", &select);

        //Using Switch For Considering User Choice
        switch(select){

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            DeciToBinaryConv();
            break;

        case 4:
            BinaryToDeciConv();
            break;

        case 5:
            select =4;
            printf("\nThank You for Using The Code!!");
            break;

        }

    }



    return 0;

}
