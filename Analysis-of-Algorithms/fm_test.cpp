#include <iostream>
#include "find_max.hpp"

using namespace std;

int main(int argc, char **argv)
{
  //int arr[10] = {1,3,4,5,6,4,3,2,1};
  int arr[1] = {5};
  
  cout << find_max(2, 0, arr) << endl;
  
  return 0;
}
