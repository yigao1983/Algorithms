#ifndef FINDMAX_HPP
#define FINDMAX_HPP

#include <iostream>

using namespace std;

template<class T>
int find_max(int lo, int hi, const T a[])
{
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] < a[mid+1]) {
      lo = mid+1;
    } else if (a[mid] < a[mid-1]) {
      hi = mid-1;
    } else {
      return mid;
    }
    cout << lo << " " << hi << endl;
  }
  
  return hi;
}

#endif
