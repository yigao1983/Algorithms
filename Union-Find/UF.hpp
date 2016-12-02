#ifndef UF
#define UF

class UF
{
public:
  
  UF(int N) : arr(new int[N]) {}
  
  virtual ~UF()
  { delete [] arr; }
  
protected:
  
  int *arr;
}

#endif
