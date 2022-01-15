#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include <algorithm>

using std::copy;
using std::min;

namespace algo {
template <typename T> void merge(T arr[], int l, int m, int r) {
  T *aux = new T[r - l + 1]; // 若使用栈，大数组可能溢出
  copy(arr + l, arr + r + 1, aux);

  int i = l, j = m + 1, k = l;
  while (i <= m && j <= r)
    arr[k++] = (aux[i - l] < aux[j - l]) ? aux[i++ - l] : aux[j++ - l];

  while (i <= m)
    arr[k++] = aux[i++ - l];
  while (j <= r)
    arr[k++] = aux[j++ - l];

  delete[] aux;
}

// 自顶向下
template <typename T> void mergeSort(T arr[], int l, int r) {
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  if (arr[m + 1] < arr[m])
    merge(arr, l, m, r);
}

template <typename T> void mergeSort(T arr[], int n) {
  mergeSort(arr, 0, n - 1);
}

// 自底向上
template <typename T> void mergeSort2(T arr[], int n) {
  for (int sz = 1; sz < n; sz += sz)
    for (int l = 0; l + sz < n; l += sz + sz)
      // l+sz<n 保证有两段可以归并，arr[l...l+sz-1], arr[l+sz...r]
      merge(arr, l, l + sz - 1, min(l + sz + sz - 1, n - 1));
}
} // namespace algo

#endif