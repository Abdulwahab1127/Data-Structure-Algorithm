#include <stdio.h>
#include <stdlib.h>
#define Size 50

int Stack1[Size], Stack2[Size];
int top1 = -1, top2 = -1;


void Enqueue(int value) {
    if (top1 == Size - 1) {
        printf("\nQueue Overflow! Cannot Add More Values.\n");
    } else {

        // Move elements from Stack2 to Stack1 to maintain order

        while (top2 >= 0) {
            Stack1[++top1] = Stack2[top2--];
        }

        Stack1[++top1] = value;
    }
}

int Dequeue() {
    if (top1 == -1 && top2 == -1) {

        printf("\nQueue is Empty. Cannot Delete More Values.\n");

        return -1;

    } else {

        // Move elements from Stack1 to Stack2 to maintain order

        while (top1 >= 0) {

            Stack2[++top2] = Stack1[top1--];
        }

        int DQElement = Stack2[top2--];

        return DQElement;
    }
}

int main() {

    Enqueue(5);
    Enqueue(7);
    Enqueue(35);
    Enqueue(18);
    Enqueue(12);
    Enqueue(19);

    printf("\n\n");
    printf(" %d ", Dequeue());
    printf(" %d ", Dequeue());

    Enqueue(15);

    printf(" %d ", Dequeue());
    printf(" %d ", Dequeue());
    printf("\n\n");

    return 0;
}
