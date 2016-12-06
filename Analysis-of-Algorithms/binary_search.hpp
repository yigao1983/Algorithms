#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <stdexcept>

template<class T>
int binary_search(int n, const T a[], T key)
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

// Ascending order binary search
template<class T>
int binary_search_acs(int lo, int hi, const T a[], T key)
{
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

// Descending order binary search
template<class T>
int binary_search_decs(int lo, int hi, const T a[], T key)
{
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (key < a[mid]) {
      lo = mid + 1;
    } else if (key > a[mid]) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  
  throw std::invalid_argument("Invalid key\n");
}

#endif
