#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int count = 1; count < n; count++) {
        int temp = arr[count];
        int j = count - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minInd = i;
        int minVal = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < minVal) {
                minInd = j;
                minVal = arr[j];
            }
        }
        arr[minInd] = arr[i];
        arr[i] = minVal;
    }
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quick_sort(int arr[], int low, int high) {
    if (low <= high) {
        int down = low;
        int up = high;
        int a = low;

        while (down <= up) {
            while (down <= up && arr[down] <= arr[a]) {
                down++;
            }
            while (down <= up && arr[down] > arr[a]) {
                up--;
            }
            if (down <= up) {
                swap(arr, down, up);
            }
        }
        swap(arr, up, a);
        quick_sort(arr, low, up - 1);
        quick_sort(arr, up + 1, high);
    }
}

void merge(int arr[], int mid, int low, int high) {
    int arr2[100];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            arr2[k] = arr[i];
            i++;
            k++;
        } else {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) {
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for (int count = low; count <= high; count++) {
        arr[count] = arr2[count];
    }
}

void merge_sort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter size: \n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements in array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Insertion sort: \n");
    insertion_sort(arr, n);
    display(arr, n);

    printf("Selection sort: \n");
    selection_sort(arr, n);
    display(arr, n);

    printf("Quick sort: \n");
    quick_sort(arr, 0, n - 1);
    display(arr, n);

    printf("Merge sort: \n");
    merge_sort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}
