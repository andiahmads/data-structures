#include <algorithm>
#include <iostream>
using namespace std;

int maximum_subarray_sum(int arr[], int n) {
  int base = 0;
  for (int a = 0; a < n; a++) {
    int sum = 0;

    for (int b = a; b < n; b++) {
      sum += arr[b];
      base = max(base, sum);
    }
  }
  return base;
}

int main() {
  int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
  int lenght = sizeof(arr) / sizeof(arr[0]);

  int result = maximum_subarray_sum(arr, lenght);

  cout << "result from c++: " << result << endl;

  return 0;
}
