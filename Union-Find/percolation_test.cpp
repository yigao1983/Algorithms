#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Percolation.hpp"

using namespace std;

int main(int argc, char **argv)
{
  Percolation perc(5);
  
  while (!perc.percolates()) {
    int row = rand() % 5 + 1;
    int col = rand() % 5 + 1;
    perc.open(row, col);
    perc.display();
    cout << perc.percolates() << endl;
  }
  
  cout << perc.countOpen() << endl;
  
  return 0;
}
