#ifndef SORT_SHELL_H
#define SORT_SHELL_H

#include <algorithm>

using std::swap;

namespace algo {
template <typename T> void shellSort(T arr[], int n) {
  int h = 1;
  while (h < n)
    h = 3 * h + 1;

  /*
      插入排序可以理解为 h=1 的希尔排序
  */
  while (h >= 1) {
    // 对 arr[i], arr[i-h], arr[i-2*h], ... 使用插入排序
    for (int i = h; i < n; i++) {
      T cur = arr[i];
      int j;
      for (j = i; j >= h && cur < arr[j - h]; j -= h)
        arr[j] = arr[j - h];
      arr[j] = cur;
    }
    h /= 3;
  }
}
} // namespace algo

#endif