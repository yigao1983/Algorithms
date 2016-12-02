#ifndef UF_HPP
#define UF_HPP

class UF
{
public:
  
  UF(int N) : SIZE(N), id(new int [N])
  {
    for (int i = 0; i < N; ++i) {
      id[i] = i;
    }
  }
  
  virtual void unify(int p, int q) = 0;
  
  virtual bool connected(int p, int q) = 0;
  
  virtual ~UF()
  { delete [] id; }
  
protected:
  
  const int SIZE;
  int *id;
};

#endif
