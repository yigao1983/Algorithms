#include <iostream>
#include <stdexcept>
#include <chrono>
#include "bitonic_search.hpp"

using namespace std;

int main(int argc, char **argv)
{
  using namespace chrono;
  
  const int N = 5;
  int arr[N] = {1, 3, 5, 4, 2};
  
  steady_clock::time_point t_beg = steady_clock::now();
  
  cout << bitonic_search(0, N-1, arr, 1) << endl;
  
  steady_clock::time_point t_end = steady_clock::now();
  
  cout << duration_cast<nanoseconds>(t_end-t_beg).count() << endl;
  
  return 0;
}
