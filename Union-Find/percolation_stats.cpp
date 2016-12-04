#include <iostream>
#include <iomanip>
#include <sstream>
#include "PercolationStats.hpp"

using namespace std;

int main(int argc, char **argv)
{
  int n, trials;
  
  if (argc < 3) {
    cout << "Not enough input" << endl;
    return 1;
  }
  
  istringstream(argv[1]) >> n;
  istringstream(argv[2]) >> trials;
  
  PercolationStats perc_stats(n, trials);
  
  cout << "mean = " << perc_stats.mean() << endl;
  cout << "stddev = " << perc_stats.stddev() << endl;
  cout << "95\% conficence interval = "
       << perc_stats.confidenceLo() << " "
       << perc_stats.confidenceHi() << endl;
  
  return 0;
}
