#ifndef PERCOLATION_HPP
#define PERCOLATION_HPP

#include "WeightedQuickUnionUF.hpp"

class Percolation {
  
public:
  
  Percolation(int n);
  virtual ~Percolation();
  void open(int row, int col);
  bool isOpen(int row, int col);
  bool isFull(int row, int col);
  bool percolates();
  
  bool isConnected(int row_i, int col_i, int row_j, int col_j);
  void display();
  
protected:
  
  const int SIZE, TOP, BOTTOM;
  int *grid;
  WeightedQuickUnionUF uf;
  
  bool inBounds(int row, int col);
  void checkBounds(int row, int col);
  int getGridIndex(int row, int col);
};
  
#endif
