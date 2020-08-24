#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include <iostream>
#include <list>
#include <vector>
template <typename K, typename V> class Entry {
public:
  Entry(const K &k = K(), const V &v = V()) : _key(k), _value(v) {}
  const K &key() const { return _key; }
  const V &value() const { return _value; }
  void setKey(const K &k) { _key = k; }
  void setValue(const V &v) { _value = v; }

private:
  K _key;
  V _value;
};

template <typename K, typename V> class HashMap {
public:
  typedef Entry<const K, V> EEntry; //  (key,value) pair
  class Iterator;

  HashMap(int capacity = 100) : n(0), B(capacity){};
  int size() const { return n; }
  bool empty() const { return size() == 0; }
  Iterator find(const K &k);
  Iterator put(const K &k, const V &v);
  void erase(const K &k);
  void erase(const Iterator &p);
  Iterator begin();
  Iterator end();

protected:
  typedef std::list<EEntry> Bucket; // bucket of entries(same key)
  typedef typename Bucket::iterator EItor;
  typedef std::vector<Bucket> BktArray; // bucket array
  typedef typename BktArray::iterator BItor;
  //---utilities----
  Iterator finder(const K &k);
  Iterator inserter(const Iterator &p, const EEntry &e);
  void eraser(const Iterator &p);
  static void nextEntry(Iterator &p) { ++p.ent; }
  static bool endOfBkt(const Iterator &p) { return p.ent == p.bkt->end(); }

private:
  int n; // number of entries
  BktArray B;

public:
  class Iterator {
  private:
    EItor ent;
    BItor bkt;
    const BktArray *ba;

  public:
    Iterator(const BktArray &a, const BItor &b, const EItor &q = EItor())
        : ent(q), bkt(b), ba(&a) {}
    EEntry &operator*() const { return *ent; }
    bool operator==(const Iterator &p) const;
    Iterator &operator++();
    friend class HashMap;
  };
};
//-----Iterator Methods------
template <typename K, typename V>
 bool HashMap<K, V>::Iterator::operator==(const Iterator &p) const {
  if (ba != p.ba || bkt != p.bkt)
    return false;
  else if (bkt == ba->end())
    return true;
  else
    return (ent == p.ent);
}
template <typename K, typename V>
typename HashMap<K, V>::Iterator &HashMap<K, V>::Iterator::operator++() {
  ++ent;
  if (endOfBkt(*this)) {
    ++bkt;
    while (bkt != ba->end() && bkt->empty())
      ++bkt;
    if (bkt == ba->end())
      return *this;
    ent = bkt->begin();
  }
  return *this;
}
//-----Iterator Methods------

//--------HashMap Methods--------

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::end() {
  return Iterator(B, B.end());
}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::begin() {
  if (empty())
    return end();
  BItor bkt = B.begin();
  while (bkt->empty())
    ++bkt;
  return Iterator(B, bkt, bkt->begin());
}

template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::finder(const K &k) {
  int i = k % B.size();
  BItor bkt = B.begin() + i;
  Iterator p(B, bkt, bkt->begin());
  while (!endOfBkt(p) && (*p).key() != k) {
    nextEntry(p);
  }
  return p;
}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::find(const K &k) {
  Iterator p = finder(k);
  if (endOfBkt(p))
    return end();
  else
    return p;
}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::inserter(const Iterator &p,
                                                         const EEntry &e) {
EItor ins = p.bkt->insert(p.ent, e);
  n++;
  return Iterator(B, p.bkt, ins);
}
template <typename K, typename V>
typename HashMap<K, V>::Iterator HashMap<K, V>::put(const K &k, const V &v) {
  Iterator p = finder(k);
  if (endOfBkt(p)) {
    return inserter(p, EEntry(k, v));
  } else {
    p.ent->setValue(v);
    return p;
  }
}
template <typename K, typename V>
 void HashMap<K, V>::eraser(const Iterator &p) {
  p.bkt->erase(p.ent);
  n--;
}
template <typename K, typename V>
void HashMap<K, V>::erase(const Iterator &p) {
  eraser(p);
}
template <typename K, typename V>
 void HashMap<K, V>::erase(const K &k) {
  Iterator p = finder(k);
  if (endOfBkt(p))
    throw "Erase of nonexistence";
  eraser(p);
}
#endif