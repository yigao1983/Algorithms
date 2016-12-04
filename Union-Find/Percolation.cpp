#include <iostream>
#include <stdexcept>
#include "Percolation.hpp"

Percolation::Percolation(int n) :
  SIZE(n), TOP(SIZE*SIZE), BOTTOM(SIZE*SIZE+1), grid(NULL), uf(SIZE*SIZE+2)
{
  if (SIZE < 0) {
    throw std::invalid_argument("Invalid n");
  }
  
  grid = new int [SIZE*SIZE];
  
  for (int i = 0; i < SIZE*SIZE; ++i) {
    grid[i] = 0;
  }
}

Percolation::~Percolation()
{ delete [] grid; }

bool Percolation::inBounds(int row, int col)
{
  if (row < 1 || row > SIZE) {
    return false;
  }
  
  if (col < 1 || col > SIZE) {
    return false;
  }
  
  return true;
}

void Percolation::checkBounds(int row, int col)
{
  if (!inBounds(row, col)) {
    throw std::out_of_range("row or col out of bounds");
  }
}

int Percolation::getGridIndex(int row, int col)
{ return (row-1) * SIZE + (col-1); }

void Percolation::open(int row, int col)
{
  checkBounds(row, col);
  
  int idx = getGridIndex(row, col);
  
  grid[idx] = 1;
  // Top row case
  if (row == 1) {
    uf.unify(TOP, idx);
  }
  // Up
  int row_up = row-1;
  int col_up = col;
  if (inBounds(row_up, col_up)) {
    int idx_up = getGridIndex(row_up, col_up);
    if (grid[idx_up] == 1) {
      uf.unify(idx_up, idx);
    }
  }
  // Down
  int row_down = row+1;
  int col_down = col;
  if (inBounds(row_down, col_down)) {
    int idx_down = getGridIndex(row_down, col_down);
    if (grid[idx_down] == 1) {
      uf.unify(idx_down, idx);
    }
  }
  // Left
  int row_left = row;
  int col_left = col-1;
  if (inBounds(row_left, col_left)) {
    int idx_left = getGridIndex(row_left, col_left);
    if (grid[idx_left] == 1) {
      uf.unify(idx_left, idx);
    }
  }
  // Right
  int row_right = row;
  int col_right = col+1;
  if (inBounds(row_right, col_right)) {
    int idx_right = getGridIndex(row_right, col_right);
    if (grid[idx_right] == 1) {
      uf.unify(idx_right, idx);
    }
  }
  // Bottom row case (Note: have to be after union operations between neighboring sites)
  if (row == SIZE && isFull(row, col)) {
    uf.unify(BOTTOM, idx);
  }
}

bool Percolation::isOpen(int row, int col)
{
  checkBounds(row, col);
  
  return grid[getGridIndex(row, col)] == 1;
}

bool Percolation::isFull(int row, int col)
{
  checkBounds(row, col);
  
  return isOpen(row, col) && uf.connected(TOP, getGridIndex(row, col));
}

bool Percolation::percolates()
{ return uf.connected(TOP, BOTTOM); }

bool Percolation::isConnected(int row_i, int col_i, int row_j, int col_j)
{
  checkBounds(row_i, col_i);
  checkBounds(row_j, col_j);
  
  int idx_i = getGridIndex(row_i, col_i);
  int idx_j = getGridIndex(row_j, col_j);
  
  return uf.connected(idx_i, idx_j);
}

void Percolation::display()
{
  for (int row = 1; row <= SIZE; ++row) {
    for (int col = 1; col <= SIZE; ++col) {
      if (isOpen(row, col)) {
        std::cout << 1;
      } else {
        std::cout << 0;
      }
    }
    std::cout << std::endl;
  }
}
