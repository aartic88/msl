#ifndef SEARCHTREE_HPP_
#define SEARCHTREE_HPP_
#include "./LinkedBinaryTree.hpp"
#include <iostream>
#include <list>
template <typename K, typename V> class Entry {
public:
  typedef K Key;
  typedef V Value;

  Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
  const K &key() const { return _key; }
  const V &value() const { return _value; }
  void setKey(const K &k) { _key = k; }
  void setValue(const V &v) { _value = v; }

private:
  K _key;
  V _value;
};

template <typename E> class SearchTree {
public:
  typedef typename E::Key K;
  typedef typename E::Value V;
  class Iterator;

  SearchTree();

  int size() const { return n; }
  bool empty() const { return size() == 0; }
  Iterator find(const K &k);
  Iterator insert(const K &k, const V &v);
  void erase(const K &k);
  void erase(const Iterator &p);
  Iterator begin();
  Iterator end();

protected:
  typedef LinkedBinaryTree<E> BinaryTree;
  typedef typename BinaryTree::Position TPos;
  TPos finder(const K &k, const TPos &v);

  TPos root() const;
  TPos inserter(const K &k, const V &x);
  TPos eraser(TPos &v);

private:
  BinaryTree T;
  int n;

public:
  //-------class Iterator------
  class Iterator {
  private:
    TPos v;

  public:
    Iterator(const TPos &vv) : v(vv) {}
    const E &operator*() const { return *v; }
    E &operator*() { return *v; }
    bool operator==(const Iterator &p) const { return v == p.v; }
    Iterator &operator++();
    friend class SearchTree;
  };
};
//--------Iterator's Method--------
template <typename E>
SearchTree<E>::Iterator &SearchTree<E>::Iterator::operator++() {
  TPos w = v.right();
  if (w.isInternal()) {
    do {
      v = w;
      w = w.left();
    } while (w.isInternal());
  } else {
    w = v.parent();
    while (v == w.right()) {
      v = w;
      w = w.parent();
    }
    v = w;
  }
  return *this;
}
//---------SearchTree Methods--------
template <typename E> SearchTree<E>::SearchTree() : T(), n(0) {
  T.addRoot();
  T.expandExternal(T.root());
}

template <typename E> SearchTree<E>::TPos SearchTree<E>::root() const {
  return T.root().left();
}

template <typename E> SearchTree<E>::Iterator SearchTree<E>::begin() {
  TPos v = root();
  while (v.isInternal()) {
    v = v.left();
  }
  return Iterator(v.parent());
}

template <typename E> SearchTree<E>::Iterator SearchTree<E>::end() {
  return Iterator(T.root());
}

template <typename E>
SearchTree<E>::TPos SearchTree<E>::finder(const K &k, const TPos &v) {
  if (v.isExternal())
    return v;
  if (k < v->key())
    return finder(k, v.left());
  if (k < v->key())
    return finder(k, v.right());
  else
    return v;
}

template <typename E>
SearchTree<E>::TPos SearchTree<E>::inserter(const K &k, const V &x) {
  TPos v = finder(k, root());
  while (v.isInternal) {
    v = finder(k, v.right());
  }
  T.expandExternal(v);
  v->setKey(k);
  v->setValue(x);
  n++;
  return v;
}

template <typename E>
SearchTree<E>::Iterator SearchTree<E>::insert(const K &k, const V &x) {
  TPos v = inserter(k, x);
  return Iterator(v);
}

template <typename E> SearchTree<E>::Iterator SearchTree<E>::find(const K &k) {
  TPos v = finder(k, root());
  if (v.isInternal()) {
    return Iterator(v);
  } else {
    return end();
  }
}
template <typename E> SearchTree<E>::TPos SearchTree<E>::eraser(TPos &v) {
  TPos w;
  if (v.left().isExternal()) {
    w = v.left();
  } else if (v.right().isExternal()) {
    w = v.right();
  } else {
    w = v.right();
    do {
      w = w.right();
    } while (w.isInternal());
    TPos u = w.parent();
    v->setKEy(u->Key());
    v->setValue(u->Value());
  }
  n--;
  return T.removeAboveExternal();
}

template <typename E> void SearchTree<E>::erase(const K &k) {
  TPos v = finder(k, root());
  if (v.isExternal()) {
    throw "doesnt Exist";
    erase(v);
  }
}

template <typename E> void SearchTree<E>::erase(const Iterator &p) {
  eraser(p.v);
}
#endif