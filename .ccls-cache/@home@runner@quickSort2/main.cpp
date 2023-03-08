#include <iostream>
#include <vector>
#include <iomanip>

//  for use within partition function
const int min_size = 200;

//  partition the array into two halves
int partition(std::vector<int>& A, int p, int r);
//  perform quicksort recursively
void quickSort(std::vector<int>& A, int p, int r);
//  median of 3 for chosing pivot
void medOf3(std::vector<int>& A, int p, int r);
//  wrapper function
void quickSort(std::vector<int>& A, int size);
//   my implementation of a swap function
void mySwap(int& a, int& b);

int main() {
  std::vector<int> A;
  int in;
  while(std::cin >> in) {
    A.push_back(in);
  }
  quickSort(A, A.size());
  for (int i = 0; i < A.size(); i++) {
    std::cout << std::setw(9) << std::setfill('0') << A[i] << '\n';
  }
}

int partition(std::vector<int>& A, int p, int r) {
  if (A.size() >= min_size) {
    medOf3(A, p, r);
  }
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (A[j] <= x) {
      ++i;
      mySwap(A[i], A[j]);
    }
  }
  mySwap(A[i + 1], A[r]);
  return (i + 1);
}

void quickSort(std::vector<int>& A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void medOf3(std::vector<int>& A, int p, int r) {
  int mid = p + (r -p) / 2;
  int median = 0;
  if ((A[p] < A[mid] && A[mid] < A[r]) || (A[r] < A[mid] && A[mid] < A[p])) {
     median = A[mid];
  } 
  else if ((A[mid] < A[p] && A[p] < A[r]) || (A[r] < A[p] && A[p] < A[mid])) {
      median = A[p];
  } 
  else {
      median = A[r];
  }
  mySwap(A[mid], A[r]);
}

void quickSort(std::vector<int>& A, int size) {
  quickSort(A, 0, size - 1);
}

void mySwap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}