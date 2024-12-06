#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int Array[], int LowerB, int UpperB) {
    int pivot = Array[LowerB];
    int Start = LowerB;
    int End = UpperB;

    while (Start < End) {
        while (Array[Start] <= pivot) {
            Start++;
        }
        while (Array[End] > pivot) {
            End--;
        }
        if (Start < End) {
            swap(&Array[Start], &Array[End]);
        }
    }
    swap(&Array[LowerB], &Array[End]);
    return End;
}

void QuickSort(int Array[], int LowerB, int UpperB) {
    if (LowerB < UpperB) {
        int middle = Partition(Array, LowerB, UpperB);
        QuickSort(Array, LowerB, middle - 1);
        QuickSort(Array, middle + 1, UpperB);
    }
}

int main() {
    int n;
    printf("Enter size of the array: \n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int Array[n];

    printf("Enter elements into the array: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &Array[i]);
    }

    QuickSort(Array, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", Array[i]);
    }

    return 0;
}
