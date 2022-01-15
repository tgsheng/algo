#ifndef UNIONFIND_QUICKFINDUF_H
#define UNIONFIND_QUICKFINDUF_H

#include <vector>

namespace algo {
class QuickFindUF {
private:
  std::vector<int> id;
  int _size;

public:
  QuickFindUF(int n) : _size(n) {
    id.resize(n);
    for (int i = 0; i < n; i++)
      id[i] = i;
  }

  int find(int p) const {
    /* assume 0 <= p < _size */
    return id[p];
  } // quick find

  bool isConnected(int p, int q) const { return id[p] == id[q]; }

  int size() const { return _size; }

  void connect(int p, int q) { // O(n)
    int pId = id[p], qId = id[q];

    /* assume pId != qId */

    for (int i = 0; i < id.size(); i++)
      if (id[i] == pId)
        id[i] = qId;

    _size--;
  }
};
} // namespace algo

#endif