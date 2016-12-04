#ifndef PERCOLATIONSTATS_HPP
#define PERCOLATIONSTATS_HPP

#include "Percolation.hpp"

class PercolationStats
{
public:
  
  PercolationStats(int n, int trials);
  virtual ~PercolationStats();
  double mean();
  double stddev();
  double confidenceLo();
  double confidenceHi();
  
protected:
  
  const int SIZE;
  const int NTRIAL;
  double *threshold;
};

#endif
