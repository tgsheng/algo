#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#include <algorithm>

using std::swap;

namespace algo {
// 将 arr[l...r] 分为两部分 arr[l...p) <= arr[p] <= arr(p...r]，返回 p
template <typename T> int partition(T arr[], int l, int r) {
  // 随机选取分界点，否则，原数组有序，以第一个元素为分界点，算法复杂度为 O(n^2)
  swap(arr[l], arr[rand() % (r - l + 1) + l]);
  T v = arr[l];
  int i = l + 1, j = r;
  while (true) {
    while (i <= j && arr[i] < v)
      i++;
    while (i <= j && v < arr[j])
      j--;
    if (i > j)
      break;
    swap(arr[i++], arr[j--]);
  }
  swap(arr[l], arr[j]);
  return j;
}

template <typename T> void quickSort(T arr[], int l, int r) {
  if (l >= r)
    return;
  int p = partition(arr, l, r);
  quickSort(arr, l, p - 1);
  quickSort(arr, p + 1, r);
}

template <typename T> void quickSort(T arr[], int n) {
  quickSort(arr, 0, n - 1);
}

// 将 arr[l...r] 分为三部分 arr[l...lt) < [lt...gt] == v < (gt...r]
template <typename T> void quickSort3Way(T arr[], int l, int r) {
  if (l >= r)
    return;
    
  swap(arr[l], arr[rand() % (r - l + 1) + l]);
  T v = arr[l];
  int lt = l, gt = r; // arr[lt...gt] == v，一开始假设arr[l...r]都是 v
  int i = l + 1; // 待检查元素下标
  while (i <= gt) {
    if (arr[i] < v)
      swap(arr[lt++], arr[i++]);
    else if (v < arr[i])
      swap(arr[gt--], arr[i]);
    else
      i++;
  }

  quickSort3Way(arr, l, lt - 1);
  quickSort3Way(arr, gt + 1, r);
}

template <typename T> void quickSort2(T arr[], int n) {
  quickSort3Way(arr, 0, n - 1);
}

} // namespace algo

#endif