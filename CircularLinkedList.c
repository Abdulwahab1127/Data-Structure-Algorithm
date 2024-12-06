#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
    struct node *head;


};

void implim(){

    struct node *p,*temp;
    struct node *head;
    int c = 1;
    while(c==1){
        p = (struct node *)malloc(sizeof(struct node));

        p->next = NULL;
        printf("\nEnter The Data You want to Store in New Node :");
        scanf("%d",&p->info);

        if(head == NULL){

            head = temp = p;
        }else{

            temp->next = p;
            temp = p;

        }
            temp->next = head;
        printf("\nPress '1' to Continue and Any '0' to Exit: ");
        scanf("%d",&c);

    }


}
void displayList(){

    struct node *temp;
    struct node *head;

    if(head==0){
        printf("\n\nList is Empty!\n\n");
    }else{
        temp = head;
        while(temp->next != head){

            printf("\n %d ",temp->info);

            temp = temp->next;

        }
            printf("\n %d ",temp->info);

    }





}


int main(){
    implim();

    displayList();


}
