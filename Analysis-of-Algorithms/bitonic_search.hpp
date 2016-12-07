#ifndef BITONICSEARCH_HPP
#define BITONICSEARCH_HPP

#include <iostream>
#include "binary_search.hpp"

template<class T>
int bitonic_search(int lo, int hi, const T a[], T key)
{
  while (lo <= hi) {
    
    int mid = (lo + hi) / 2;
    
    std::cout << a[mid] << std::endl;
    
    if (a[mid] < key) {
      if (mid == lo || a[mid] > a[mid-1]) {
        return bitonic_search(mid+1, hi, a, key);
      } else if (a[mid] > a[mid+1]) {
        return bitonic_search(lo, mid-1, a, key);
      }
    } else if (a[mid] > key) {
      int i = binary_search_asc(lo, mid-1, a, key);
      if (i > -1) return i;
      else        return binary_search_desc(mid+1, hi, a, key);
    } else {
      return mid;
    }
  }
  
  return -1;
}

#endif
