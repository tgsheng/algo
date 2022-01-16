#include "binarySearchTree.h"
#include <algorithm>
#include <ctime>

void shuffle(int arr[], int n) {
  srand(time(nullptr));
  for (int i = n - 1; i >= 0; i--)
    std::swap(arr[i], arr[rand() % (i + 1)]);
}

template <typename T> bool isSorted(const std::vector<T> &arr) {
  for (int i = 1; i < arr.size(); i++)
    if (arr[i] < arr[i - 1])
      return false;
  return true;
}

int main() {
  srand(time(nullptr));
  algo::BST<int, int> bst;

  int n = 10000;
  for (int i = 0; i < n; i++) {
    int key = rand() % n;
    int value = key;
    bst.insert(key, value);
  }

  std::cout << "size = " << bst.size() << std::endl;

  std::vector<int> keys = bst.print();
  if (isSorted(keys))
    std::cout << "Yes\n";
  else
    std::cout << "No\n";

  int order[n];
  for (int i = 0; i < n; i++)
    order[i] = i;
  shuffle(order, n);

  for (int i = 0; i < n; i++) {
    if (bst.contain(order[i])) {
      bst.remove(order[i]);
      std::cout << "After remove " << order[i] << ", size = " << bst.size()
                << std::endl;
    }
  }

  return 0;
}