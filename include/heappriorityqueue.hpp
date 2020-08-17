#ifndef HEAPPRIORITYQUEUE_HPP_
#define HEAPPRIORITYQUEUE_HPP_

#include <iostream>
#include <vector>

template <typename E> class isLess {
public:
  bool operator()(const E &e, const E &p) const { return e < p; }
};

template <typename E> class VectorCompleteTree {
private:
  std::vector<E> V;

public:
  typedef typename std::vector<E>::iterator Position;

protected:
  Position pos(int i) { return V.begin() + i; }
  int idx(const Position &p) const { return p - V.begin(); }

public:
  VectorCompleteTree() : V(1) {}
  int size() const { return V.size() - 1; }

  Position left(const Position &p) { return pos(2 * idx(p)); }
  Position right(const Position &p) { return pos(2 * idx(p) + 1); }
  Position parent(const Position &p) { return pos(idx(p) / 2); }

  bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }
  bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }
  bool isRoot(const Position &p) const { return idx(p) == 1; }

  Position root() { return pos(1); }
  Position last() { return pos(size()); }

  void addLast(const E &e) { V.push_back(e); }
  void remove() { V.pop_back(); }
  void swap(const Position &p, const Position &q) {
    E e = *q;
    *q = *p;
    *p = e;
  }
};

template <typename E, typename C> class HeapPriorityQueue {
public:
  int size() const;
  bool empty() const;
  void insert(const E &e);
  const E &min();
  void removeMin();

private:
  VectorCompleteTree<E> T;
  C isLess;
};

template <typename E, typename C> int HeapPriorityQueue<E, C>::size() const {
  return T.size();
}
template <typename E, typename C> bool HeapPriorityQueue<E, C>::empty() const {
  return size() == 0;
}
template <typename E, typename C> const E &HeapPriorityQueue<E, C>::min() {
  return *(T.root());
}
template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e) {
  T.addLast(e);
  typename VectorCompleteTree<E>::Position v =
      T.last(); // position v=T.last()  err position nont defined int thisscope
  while (!T.isRoot(v)) {
    typename VectorCompleteTree<E>::Position u = T.parent(v);
    if ((!isLess(*v, *u)))
      break;
    T.swap(v, u);
    v = u;
  }
}

template <typename E, typename C> void HeapPriorityQueue<E, C>::removeMin() {
  if (size() == 1)
    T.removeMin();
  else {
    typename VectorCompleteTree<E>::Position u = T.root();
    T.swap(u, T.last());
    T.removeLast();
    while (T.hasLeft(u)) {
      typename VectorCompleteTree<E>::Position v = T.Left(u);
      if (T.hasRight(u) && isLess(*(T.right(u)), *v)) {
        v = T.right(u);
      }
      if (isLess(*v, *u)) {
        T.swap(u, v);
        u = v;
      } else
        break;
    }
  }
}
#endif