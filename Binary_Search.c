#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int search) {
  if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (search == arr[mid]) {
        return mid;
    }
    else if (search < arr[mid]) {
        return BinarySearch(arr, low,  mid - 1, search);
    }
    else {
        return BinarySearch(arr, mid + 1,  high, search);
    }
}

int main() {
  int c, first, last, middle, n, search, array[100];

  printf("Enter number of elements : ");
  scanf("%d", &n);

  printf("Enter %d integers in sorted order : ", n);

  for (c = 0; c < n; c++) { scanf("%d", &array[c]); }

  printf("Enter value to find : ");
  scanf("%d", &search);

  int location = BinarySearch(array, 0, n, search);
  location == -1? 
    printf("Not found! %d isn't present in the list.\n", search):
    printf("%d found at location %d.\n", search, location);
}