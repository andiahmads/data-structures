#include "stdio.h"

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  int arr[] = {1, 3, 8, 2, 9, 2, 5, 6};
  int length = sizeof(arr) / sizeof(arr[0]);
  bubleSort(arr, length);
}
