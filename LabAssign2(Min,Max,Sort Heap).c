#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int array[], int number, int i) {
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //Finding Greater element from values
    if (left < number && array[left] > array[parent])
        parent = left;

    if (right < number && array[right] > array[parent])
        parent = right;

    //if greater value not parent then swap
    if (parent != i) {
        swap(&array[i], &array[parent]);
        //Recursion
        maxHeapify(array, number, parent);
    }
}

//creating max heap using function
void MaxHeap_Builder(int array[], int number) {
    for (int i = number / 2 - 1; i >= 0; i--)
        maxHeapify(array, number, i);
}

//creating min heap using function
void minHeapify(int array[], int number, int i) {
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < number && array[left] < array[parent])
        parent = left;

    if (right <number && array[right] < array[parent])
        parent = right;
//if smaller value not parent then swap
    if (parent != i) {
        swap(&array[i], &array[parent]);
        minHeapify(array, number, parent);
    }
}

void MinHeap_Builder(int array[], int number) {

    for (int i = number / 2 - 1; i >= 0; i--)
        minHeapify(array, number, i);

}


void MaxHeap_Sorting(int array[], int number) {

    MaxHeap_Builder(array, number);

    //Move top to Leaf and Store in Stack for Ascending Order
    for (int i = number - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        maxHeapify(array, i, 0);
    }
}

int main() {
    int choice, array[5];

    printf("\nWelcome to the Heap Program\n");
    printf("Enter 5 values to perform the function:\n");

    for (int i = 0; i < 5; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int number = sizeof(array) / sizeof(array[0]);


    printf("\nOriginal array: ");

    for (int i = 0; i < number; i++)
        printf("%d ", array[i]);
    printf("\n");

do{
    printf("\nPress '1' for Min Heap\n"
           "Press '2' for Max Heap\n"
           "Press '3' for Heap Sorting\n"
           "Press '4' for Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        MinHeap_Builder(array, number);
        printf("Min heap: ");

        for (int i = 0; i < number; i++)
            printf("%d ", array[i]);
            printf("\n");

    } else if (choice == 2) {
        MaxHeap_Builder(array, number);
        printf("Max heap: ");

        for (int i = 0; i < number; i++)
            printf("%d ", array[i]);
            printf("\n");

    } else if (choice == 3) {
        MaxHeap_Sorting(array, number);
        printf("Sorted max heap: ");

        for (int i = 0; i < number; i++)
            printf("%d ", array[i]);
            printf("\n");

    }

    } while (choice != 4);

    return 0;
}
