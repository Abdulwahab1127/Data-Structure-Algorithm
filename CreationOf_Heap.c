#include<stdio.h>
#include <stdlib.h>

int a;
int array[10];

void Swapping(int i,int j){

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

}

void Max_Heap(int i){
    //We will Declare Nodes Here of Heap
    int left,right,parent;
    int max = 1;

    left = 2 * array[i] + 1;
    right = 2 * array[i] + 2;
    parent = ( i - 1 ) / 2;

    for(int i = a /2;i>=0;i--){

        Max_Heap(i);
    }

    if(left<=a && array[left]>=array[max]){

        max = left;
    }

    if(right<=a && array[right]>=array[max]){

        max = right;
    }

    if(max != i){

        Swapping(i , max);
        Max_Heap(max);

    }




}

//Testing above functions
int main(){

      // Initialize your array with values (for example)
    int array[] = {4, 10, 3, 5, 1, 7, 9, 11, 6, 2};

    // Display the initial array
    printf("Initial Array: ");
    for (int i = 0; i < a; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Perform Max Heap operations
    for (int i = a / 2; i >= 0; i--) {
        Max_Heap(i);
    }

    // Display the array after max heap operations
    printf("Array after Max Heap: ");
    for (int i = 0; i < a; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;
}
