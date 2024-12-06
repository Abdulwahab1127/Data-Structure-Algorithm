#include<stdio.h>
#include<stdlib.h>
#define Size 5

int top = -1;
int Stack[Size];

void push(){

    int x;
    if(top==Size-1){
        printf("\nStack Overflow!\n");
    }else{
        printf("\nEnter The Value : ");
        scanf("%d", &x);
        top++;
        Stack[top] = x;

    }


}

void pop(){
    int vari;

    if(top==-1){

        printf("\nStack Underflow!!");

    }else{

        Stack[top]=vari;

        top--;

        printf("\nThe Popped Value is: %d",vari);
    }

}

void peek(){

        int vari;

        Stack[top]=vari;

        printf("\nThe Top Value is: %d",vari);

}
void display(){
    int vari;
     printf("\nValues in Stack: ");
    for(int i=0;i<Size;i++){

        printf("%d ",Stack[i]);

    }

}
int main(){

for(int i=0;i<Size;i++){
    push();
}
    pop();

    peek();

    display();




}
