#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "QuickFindUF.hpp"
#include "QuickUnionUF.hpp"
#include "WeightedQuickUnionUF.hpp"

using namespace std;

int main(int argc, char **argv)
{
  fstream uf_file;
  string line;
  int N;
  
  if (argc < 2) {
    cout << "No input file" << endl;
    return 1;
  }
  
  uf_file.open(argv[1]);
  
  getline(uf_file, line);
  
  istringstream(line) >> N;
  
  QuickUnionUF uf(N);
  
  while (getline(uf_file, line)) {
    int p, q;
    istringstream(line) >> p >> q;
    if (!uf.connected(p, q)) {
      uf.unify(p, q);
    }
  }
  
  for (int i = 0; i < N; ++i) {
    cout << uf.connected(i, 9) << endl;
  }
  
  uf_file.close();
  
  return 0;
}
