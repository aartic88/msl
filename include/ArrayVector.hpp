#ifndef ARRAYVECTOR_HPP_
#define ARRAYVECTOR_HPP_

#include <cmath>
#include <iostream>
#include <string>
// Array based Vector

class ArrayVector {
public:
  ArrayVector();
  int size() const;
  bool empty() const;
  int &operator[](int i);
  int &at(int i);
  void erase(int i);
  void insert(int i, const int &e);
  void reserve(int N);

private:
  int capacity, n;
  int *arr;
};

ArrayVector::ArrayVector() : capacity(0), n(0), arr(NULL) {}
int ArrayVector::size() const { return n; }
bool ArrayVector::empty() const { return size() == 0; }
int &ArrayVector::operator[](int i) { return arr[i]; }
int &ArrayVector::at(int i) {
  if (i < 0 || i >= n) {
    throw "IndexOutofBound";
  }
  return arr[i];
}
void ArrayVector::erase(int i) {
  for (int j = i + 1; j < n; j++) {
    arr[j - 1] = arr[j];
  }
  n--;
}
void ArrayVector::reserve(int N) {
  if (capacity >= N)
    return;
  int *newArr = new int[N];
  for (int i = 0; i < n; i++) {
    newArr[i] = arr[i];
  }
  if (arr != NULL)
    delete[] arr;
  arr = newArr;
  capacity = N;
}
void ArrayVector::insert(int i, const int &e) {
  if (n >= capacity) {
    reserve(std::max(1, 2 * capacity));
  }
  for (int j = n - 1; j >= i; j--) {
    arr[j + 1] = arr[j];
  }
  arr[i] = e;
  n++;
}
#endif