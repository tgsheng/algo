#ifndef SORT_HEAP_H
#define SORT_HEAP_H

#include <algorithm>

using std::copy;
using std::swap;

template <typename T> class MaxHeap {
public:
  MaxHeap(int capacity) : _capacity(capacity), _size(0) {
    _data = new T[capacity];
  }

  MaxHeap(T arr[], int n) {
    _data = new T[n];
    _capacity = _size = n;
    copy(arr, arr + n, _data);

    // 从第一个非叶子节点开始调整建堆
    for (int i = _size / 2 - 1; i >= 0; i--)
      shiftDown(i); // 向下调整建堆
  }

  ~MaxHeap() { delete[] _data; }

  void pop() {
    swap(_data[0], _data[--_size]);
    shiftDown(0);
  }

  void insert(const T &val) {
    _data[_size++] = val;
    shiftUp(_size - 1); // 向上调整建堆
  }

  bool isEmpty() const { return _size == 0; }

  int size() const { return _size; }

  T top() const { return _data[0]; }

private:
  void shiftDown(int i) { // O(logn)
    int l, r, largest;
    while (true) {
      l = 2 * i + 1, r = l + 1;

      // largest 记录节点i及其左右孩子节点中最大者
      largest = (l < _size && _data[i] < _data[l]) ? l : i;
      if (r < _size && _data[largest] < _data[r])
        largest = r;

      if (largest == i)
        break;

      swap(_data[i], _data[largest]);

      i = largest;
    }
  }

  void shiftUp(int i) {
    int up = (i - 1) / 2;
    while (i > 0 && _data[up] < _data[i]) {
      swap(_data[i], _data[up]);
      i = up;
      up = (i - 1) / 2;
    }
  }

private:
  T *_data;
  int _size;
  int _capacity;
};

#endif