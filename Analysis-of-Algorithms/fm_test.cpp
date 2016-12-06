#include <iostream>
#include "find_max.hpp"

using namespace std;

int main(int argc, char **argv)
{
  //int arr[10] = {1,3,4,5,6,4,3,2,1};
  int arr[5] = {0, 1, 2, 3, 4};
  
  cout << find_max(0, 4, arr) << endl;
  
  return 0;
}
