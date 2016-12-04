#include <iostream>
#include <iomanip>
#include "Percolation.hpp"

using namespace std;

int main(int argc, char **argv)
{
  const int N = 5;
  Percolation perc(N);
  
  perc.open(1, 1);
  perc.open(1, 3);
  perc.open(2, 3);
  perc.open(3, 3);
  perc.open(3, 4);
  perc.open(4, 4);
  perc.open(5, 4);
  perc.open(5, 1);
  
  perc.display();
  /*
  cout << boolalpha << perc.isFull(1, 1) << endl;
  cout << boolalpha << perc.isConnected(2, 3, 3, 3) << endl;
  cout << boolalpha << perc.isFull(2, 3) << endl;
  cout << boolalpha << perc.isFull(3, 3) << endl;
  cout << boolalpha << perc.isFull(5, 1) << endl;
  */
  cout << boolalpha << perc.percolates() << endl;
  cout << boolalpha << perc.isOpen(5, 1) << endl;
  cout << boolalpha << perc.isFull(5, 1) << endl;
  cout << boolalpha << perc.isFull(1, 1) << endl;
  
  return 0;
}
