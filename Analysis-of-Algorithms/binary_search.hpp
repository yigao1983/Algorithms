#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <stdexcept>

template<class T>
int binary_search(int n, T a[], T key)
{
  int lo = 0, hi = n - 1;
  
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (key < a[mid]) {
      hi = mid - 1;
    } else if (key > a[mid]) {
      lo = mid + 1;
    } else {
      return mid;
    }
  }
  
  throw std::invalid_argument("Invalid key\n");
}

#endif
