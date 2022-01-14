#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

#include <algorithm>

using std::swap;

namespace algo {
/*
    插入排序经过几趟扫描交换后，有序部分并不是全局的
    而选择排序和冒泡排序经过几趟扫描交换之后，有序部分是全局的
*/
template <typename T> void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
      swap(arr[j], arr[j - 1]); // 频繁的交换
  }
}

template <typename T> void insertionSort2(T arr[], int n) {
  for (int i = 1; i < n; i++) {
    T cur = arr[i];
    int j;
    for (j = i; j > 0 && cur < arr[j - 1]; j--)
      arr[j] = arr[j - 1]; // 减少了交换的次数
    arr[j] = cur; 
  }
}
} // namespace algo

#endif