#include "quickFindUF.h"
#include "quickUnionUF.h"
#include "weightedQuickUnionUF.h"
#include "weightedQuickUnionUF2.h"
#include "weightedQuickUnionWithPathCompressionUF.h"
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  // algo::QuickFindUF uf(n);
  // algo::QuickUnionUF uf(n);
  // algo::WeightedQuickUnionUF uf(n);
  // algo::WeightedQuickUnionUF2 uf(n);
  algo::WeightedQuickUnionWithPathCompressionUF uf(n);
  int p, q;
  while (std::cin >> p >> q) {
    if (uf.isConnected(p, q))
      continue;
    uf.connect(p, q);
    std::cout << p << ' ' << q << '\n';
  }
  std::cout << uf.size() << " components" << std::endl;
  return 0;
}