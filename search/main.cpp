#include "binarySearch.h"
#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];

  std::sort(arr.begin(), arr.end());

  int k;
  while (std::cin >> k) {
    std::cout << algo::binarySearch(arr, k) << ' ' << algo::lower_bound(arr, k)
              << ' ' << algo::upper_bound(arr, k) << std::endl;

    std::cout << std::lower_bound(arr.begin(), arr.end(), k) - arr.begin()
              << ' '
              << std::upper_bound(arr.begin(), arr.end(), k) - arr.begin()
              << std::endl;
  }

  return 0;
}