#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

#include <algorithm>

using std::swap;

namespace algo {
template <typename T> void selectionSort(T arr[], int n) {
  for (int i = 0; i < n - 1; i++) { // n-1 趟扫描
    int minIdx = i;
    for (int j = i + 1; j < n; j++) // 每趟扫描，找出未归位的最小元素所在位置
      if (arr[j] < arr[minIdx])
        minIdx = j;
    swap(arr[i], arr[minIdx]);
  }
}

template <typename T> void selectionSort2(T arr[], int n) {
  int l = 0, r = n - 1;
  while (l < r) {
    int minIdx = l, maxIdx = r;

    if (arr[maxIdx] < arr[minIdx])
      swap(arr[minIdx], arr[maxIdx]);

    for (int i = l + 1; i < r; i++)
      if (arr[i] < arr[minIdx])
        minIdx = i;
      else if (arr[i] > arr[maxIdx])
        maxIdx = i;

    swap(arr[l++], arr[minIdx]);
    swap(arr[r--], arr[maxIdx]);
  }
}
}; // namespace algo

#endif