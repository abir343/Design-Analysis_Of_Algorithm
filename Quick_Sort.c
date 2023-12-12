#include <stdio.h>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int q = Partition(arr, low, high);

        QuickSort(arr, low, q - 1);
        QuickSort(arr, q + 1, high);
    }
}

int main() {
    int arr[100], n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers : ", n);
    for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

    QuickSort(arr, 0, n - 1);

    printf("After performing quick sort : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}