#ifndef QUICKUNIONUF_HPP
#define QUICKUNIONUF_HPP

class QuickUnionUF : public UF
{
public:
  
  QuickUnionUF(int N) : UF(N) {}
  
  virtual ~QuickUnionUF() {}
  
  void unify(int p, int q)
  {
    id[root(p)] = root(q);
  }
  
  bool connected(int p, int q)
  {
    return root(p) == root(q);
  }
  
protected:
  
  int root(int i)
  {
    while (i != id[i]) {
      i = id[i];
    }
    
    return i;
  }
};

#endif
