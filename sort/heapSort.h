#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include "heap.h"

namespace algo {
template <typename T> void heapSort(T arr[], int n) {
  MaxHeap<T> maxHeap(arr, n); // O(n)
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = maxHeap.top(); // O(1)
    maxHeap.pop();          // O(logn)
  }                         // O(nlogn)
}

template <typename T> void heapSort2(T arr[], int n) {
  MaxHeap<T> maxHeap(n);
  for (int i = 0; i < n; i++) // O(nlogn)
    maxHeap.insert(arr[i]);   // O(logn)
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = maxHeap.top();
    maxHeap.pop();
  }
}

// 原地堆排序，不需要MaxHeap，不过也需要一个shiftDown
template <typename T> void shiftDown(T arr[], int n, int i) {
  while (2 * i + 1 < n) {
    int j = 2 * i + 1;
    if (j + 1 < n && arr[j] < arr[j + 1])
      j++; // 左右孩子中最大者
    if (arr[j] <= arr[i])
      break;
    swap(arr[i], arr[j]);
    i = j;
  }
}

template <typename T> void heapSort3(T arr[], int n) {
  // 从第一个非叶子节点开始shiftDown向下调整建堆
  for (int i = n / 2 - 1; i >= 0; i--)
    shiftDown(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    shiftDown(arr, i, 0); // 重新建堆
  }
}
} // namespace algo

#endif