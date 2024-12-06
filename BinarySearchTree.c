#include<stdio.h>

struct Node{

    int Data;
    struct Node *left,*right;
};

struct Node *Create(){
    
    int user;
    struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));

    printf("\nEnter Value:");
    scanf("%d",&user);
    if(user==0){
        return 0;
    }
    newNode->Data = user;

    printf("\nEnter Left Child of %d",user);
    newNode->left = Create();


    printf("\nEnter Right Child of %d",user);
    newNode->right = Create();

    return newNode;
};

void PreOrder(struct Node *Root){

    if(Root == 0){
        return;
    }
    else{
        //if Root not 0 then Continue printing
        printf(" %d,",Root->Data);
        PreOrder(Root->left);
        PreOrder(Root->right);

    }



}

void InOrder(struct Node *Root){

    if(Root == 0){
        return;
    }
    else{
        //if Root not 0 then Continue printing

        InOrder(Root->left);
        printf(" %d,",Root->Data);
        InOrder(Root->right);

    }



}

void PostOrder(struct Node *Root){

    if(Root == 0){
        return;
    }
    else{
        //if Root not 0 then Continue printing

        PostOrder(Root->left);
        PostOrder(Root->right);
        printf(" %d,",Root->Data);
    }



}

void Search(struct Node* Root,int key){

    if(Root == 0 && Root->Data == key){
        printf("Element Found %d ",Root->Data);
    }
    if(Root->Data < key )
    {
        Search(Root->right,key);

    }

    Search(Root->right,key);




}



int main(){

    struct Node *Root;
    Root = NULL;
    Root = Create();
    int key;

    //For Pre-Order
    printf("\n\nPre Order is : ");
    PreOrder(Root);

    printf("\n\nIn Order is : ");
    InOrder(Root);

     printf("\n\nPost Order is : ");
    PostOrder(Root);

    printf("\n\nEnter Value to Search : ");
    scanf("%d",&key);

    Search(Root,key);

}
