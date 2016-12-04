#ifndef WEIGHTEDQUICKUNIONUF_HPP
#define WEIGHTEDQUICKUNIONUF_HPP

#include "QuickUnionUF.hpp"

class WeightedQuickUnionUF : public QuickUnionUF
{
public:
  
  WeightedQuickUnionUF(int N) : QuickUnionUF(N), sz(new int [SIZE])
  {
    for (int i = 0; i < SIZE; ++i) {
      sz[i] = 1;
    }
  }
  
  virtual ~WeightedQuickUnionUF()
  { delete [] sz; }
  
  void unify(int p, int q)
  {
    int i = root(p);
    int j = root(q);
    
    if (i == j) return;
    
    if (sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    } else {
      id[j] = i;
      sz[i] += sz[j];
    }
  }
  
protected:
  
  int *sz;
};

#endif
