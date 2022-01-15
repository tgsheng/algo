#ifndef UNIONFIND_QUICKUNIONUF_H
#define UNIONFIND_QUICKUNIONUF_H

#include <vector>

namespace algo {
class QuickUnionUF {
public:
  QuickUnionUF(int n) : _size(n) {
    root.resize(n);
    for (int i = 0; i < n; i++)
      root[i] = i;
  }

  int find(int p) {
    while (p != root[p])
      p = root[p];
    return p;
  }

  bool isConnected(int p, int q) { return find(p) == find(q); }

  void connect(int p, int q) { // quick union
    int pRoot = find(p), qRoot = find(q);
    
    /* assume pRoot != qRoot */
    /* if (pRoot == qRoot) return; */

    root[pRoot] = qRoot;
    _size--;
  }

  int size() const { return _size; }

private:
  std::vector<int> root;
  int _size;
};
} // namespace algo

#endif