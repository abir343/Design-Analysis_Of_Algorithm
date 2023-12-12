#include <stdio.h>

void MergeSort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;
    
    MergeSort(i, mid, a, aux);
    MergeSort(mid + 1, j, a, aux);
    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}

int main() {
  int a[100], aux[100], n, i, d, swap;
  printf("Enter number of elements in the array : ");
  scanf("%d", &n);
  printf("Enter %d integers : ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  MergeSort(0, n - 1, a, aux);
  printf("Printing the sorted array : ");
  for (i = 0; i < n; i++)
     printf("%d ", a[i]);
  return 0;
}