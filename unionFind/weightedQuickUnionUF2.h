#ifndef UINONFIND_WEIGHTEDQUICKUNIONUF2_H
#define UINONFIND_WEIGHTEDQUICKUNIONUF2_H

#include <vector>

namespace algo {
class WeightedQuickUnionUF2 {
public:
  WeightedQuickUnionUF2(int n) : _size(n) {
    root.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++)
      root[i] = i, rank[i] = 1;
  }

  int find(int p) {
    while (p != root[p])
      p = root[p];
    return p;
  }

  bool isConnected(int p, int q) { return find(p) == find(q); }

  void connect(int p, int q) {
    int pRoot = find(p), qRoot = find(q);

    /* assume pRoot != qRoot */
    /* if (pRoot == qRoot) return; */

    if (rank[pRoot] < rank[qRoot])
      root[pRoot] = qRoot;
    else {
      root[qRoot] = pRoot;
      if (rank[pRoot] == rank[qRoot])
        rank[pRoot]++;
    }

    _size--;
  }

  int size() const { return _size; }

private:
  std::vector<int> root;
  std::vector<int> rank; // height of every component
  int _size;
};
} // namespace algo

#endif