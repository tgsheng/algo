#include "bubbleSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "selectionSort.h"
#include "shellSort.h"
#include <ctime>
#include <iostream>

using std::cin;
using std::cout;

template <typename T> bool isSorted(T arr[], int n) {
  for (int i = 1; i < n; i++)
    if (arr[i] < arr[i - 1])
      return false;
  return true;
}

int main() {
  int n;
  cin >> n;

  int *arr = new int[n];
  srand(time(nullptr));
  for (int i = 0; i < n; i++)
    arr[i] = rand() % n;

  // algo::bubbleSort(arr, n);
  // algo::bubbleSort2(arr, n);
  // algo::selectionSort(arr, n);
  // algo::selectionSort2(arr, n);
  // algo::insertionSort(arr, n);
  // algo::insertionSort2(arr, n);
  // algo::shellSort(arr, n);
  // algo::quickSort(arr, n);
  // algo::quickSort2(arr, n);
  // algo::mergeSort(arr, n);
  // algo::mergeSort2(arr, n);
  // algo::heapSort(arr, n);
  // algo::heapSort2(arr, n);
  algo::heapSort3(arr, n);

  if (isSorted(arr, n))
    cout << "Yes\n";
  else
    cout << "No\n";

  delete[] arr;

  return 0;
}