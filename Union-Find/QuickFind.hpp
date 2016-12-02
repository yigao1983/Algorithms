#ifndef QUICKFIND_HPP
#define QUICKFIND_HPP

#include "UF.hpp"

class QuickFind : public UF
{
public:
  
  QuickFind(int N) : UF(N) {}
  
  virtual ~QuickFind() {}
  
  void unify(int p, int q)
  {
    int pid = id[p];
    int qid = id[q];
    
    for (int i = 0; i < SIZE; ++i) {
      if (id[i] == pid) {
        id[i] = qid;
      }
    }
  }
  
  bool connected(int p, int q)
  {
    return id[p] == id[q];
  }
};

#endif
