#include<stdio.h>
#define size 50

//Creating Array of Size 50 for Queue to store Values
queue[size];

//Initializing The size of front,rear to -1
int front = -1 , rear= -1;

//Functions for Front and Rear
int isFull() {
    return rear == size - 1;
}

int isEmpty() {
    return front == -1;
}

void InsertionInQueue(int element){
        //Checking if Queue if Full

        if(isFull()){

        printf("\nQueue Overflow. Insertion Not Possible!");

        }
        if(front == -1){

            front = 0;
            rear = 0;

        }
        else if(isFull() && front != 0){

            rear = 0;
        }
        else{

            rear++;
        }


        //Adding New Values to Queue(insertion)

        queue[rear] = element ;

        printf("\nValue That is Inserted in Linear Queue : %d " ,element);

}

void DeletionFromQueue(){
     int elementD;

    if(isEmpty()){

        printf("\nQueue is Empty.Deletion Not Possible!");

    }else{
        //Storing Front in Variable to Delete
        elementD = queue[front];

        //Checking if Front & Rear are Same
        if(front == rear){
            front = -1;
            rear = -1;

        }else{
            //Removed The Place of Earlier Front Value by Doing Front++

            front++;

        }

      printf("\nThe Deleted Value is : %d", elementD);

    }

}


int main(){

    int insertValue = 0;
    int select = 0;
     while(select!=4){

        printf("\n\nOperations on the Circular Queue:");
        printf("\n 1.Insert in Queue"
                "\n 2.Delete from Queue"
                "\n 3.Close");
        printf("\n\nEnter the choice: ");
        scanf("%d", &select);

        //Using Switch For Considering User Choice
        switch(select){

        case 1:
            printf("\nEnter The Value to Want to Insert: ");
            scanf("%d",&insertValue);
            InsertionInQueue(insertValue);
            break;

        case 2:
            DeletionFromQueue();
            break;


        case 3:
            select =4;
            printf("\nThank You for Using The Code!!");
            break;

        }

    }


}

