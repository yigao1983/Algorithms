#include <iostream>
#include <stdexcept>
#include <chrono>
#include "binary_search.hpp"

using namespace std;

int main(int argc, char **argv)
{
  using namespace chrono;
  
  const int N = 2000;
  int arr[N];
  
  for (int i = 0; i < N; ++i) {
    arr[i] = 2*i;
  }
  
  steady_clock::time_point t_beg = steady_clock::now();
  
  try {
    cout << binary_search(N, arr, 0) << endl;
  } catch (std::exception &e) {
    cerr << e.what();
  }
  
  steady_clock::time_point t_end = steady_clock::now();
  
  cout << duration_cast<nanoseconds>(t_end-t_beg).count() << endl;
  
  return 0;
}
