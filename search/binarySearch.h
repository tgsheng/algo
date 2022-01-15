#ifndef SEARCH_BINARYSEARCH_H
#define SEARCH_BINARYSEARCH_H

#include <vector>
using std::vector;

namespace algo {
template <typename T> int binarySearch(vector<T> &arr, T target) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == target)
      return m;
    else if (arr[m] > target)
      r = m - 1;
    else
      l = m + 1;
  }
  return -1; // Not Found
}

// 返回第一个大于等于 target 的元素下标，否则返回 n
template<typename T>
int lower_bound(vector<T>& arr, T target) {
    int l = 0, r = arr.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        arr[m] < target ? l = m + 1 : r = m;
    }
    return l;
}

// 返回第一个大于 target 的值，返回返回 n
template <typename T> int upper_bound(vector<T>& arr, T target) {
    int l = 0, r = arr.size();
    while (l < r) {
        int m = l + (r - l) / 2;
        arr[m] > target ? r = m : l = m + 1;
    }
    return l;
}
} // namespace algo



#endif