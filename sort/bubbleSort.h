#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

#include <algorithm>

using std::swap;

namespace algo {
template <typename T> void bubbleSort(T arr[], int n) {
  bool swapped = false;
  for (int i = 1; i < n; i++) { // n-1 趟扫描交换
    for (int j = 1; j <= n - i; j++) // 每趟扫描将当前最大元素放到正确位置
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
        swapped = true;
      }

    if (swapped == false) // 如果本趟扫描没有发生交换，说明已经有序
      break;
  }
}

template <typename T> void bubbleSort2(T arr[], int n) {
  int newn;
  do {
    newn = 0;
    for (int i = 1; i < n; i++)
      if (arr[i] < arr[i - 1]) {
        swap(arr[i], arr[i - 1]);
        newn = i; // 本趟扫描最后发生交换的位置，下一趟扫描可以跳过此后的元素
      }
    n = newn;
  } while (newn > 0); // newn == 0,说明本趟扫描没有发生交换，已有序
}
} // namespace algo

#endif