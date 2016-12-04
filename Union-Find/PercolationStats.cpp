#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cmath>
#include "PercolationStats.hpp"

PercolationStats::PercolationStats(int n, int trials) :
  SIZE(n), NTRIAL(trials), threshold(NULL)
{
  if (SIZE < 0) {
    throw std::invalid_argument("Invalid n");
  }
  
  threshold = new double [NTRIAL];
  
  srand(time(NULL));
  for (int i = 0; i < NTRIAL; ++i) {
    Percolation perc(SIZE);
    while (!perc.percolates()) {
      int row = rand() % n + 1;
      int col = rand() % n + 1;
      perc.open(row, col);
    }
    //perc.display();
    threshold[i] = static_cast<double>(perc.countOpen()) / (n*n);
    //std::cout << threshold[i] << std::endl;
  }
}

PercolationStats::~PercolationStats()
{ delete [] threshold; }

double PercolationStats::mean()
{
  double thr_sum = 0.0;
  
  for (int i = 0; i < NTRIAL; ++i) {
    thr_sum += threshold[i];
  }
  
  return thr_sum / NTRIAL;
}

double PercolationStats::stddev()
{
  double thr_mean = mean();
  double thr_sum2 = 0.0;
  
  for (int i = 0; i < NTRIAL; ++i) {
    double diff = threshold[i] - thr_mean;
    thr_sum2 += diff*diff;
  }
  
  return sqrt( thr_sum2 / (NTRIAL-1) );
}

double PercolationStats::confidenceLo()
{ return mean() - 1.96 * stddev() / sqrt(NTRIAL); }

double PercolationStats::confidenceHi()
{ return mean() + 1.96 * stddev() / sqrt(NTRIAL); }
