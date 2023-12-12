// Date : 13/10/2020
#include<stdio.h>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int n, int i) {
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    // Check if left child exists and is larger than its parent
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Check if right child exists and larger than its parent
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not the largest
    if (largest != i) {
        Swap(&arr[i], &arr[largest]); //make root the largest
        Heapify(arr, n, largest); // Apply heapify to the largest node
    }
}

void HeapSort(int arr[], int n) {
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]); //Move the largest element at root to the end
        Heapify(arr, i, 0); //Apply heapify to reduced heap
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter %d integers : ", n);
    for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

    printf("Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    HeapSort(arr, n);

    printf("\nAfter performing Heap Sort : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}