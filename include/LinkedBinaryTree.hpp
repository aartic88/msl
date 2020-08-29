#ifndef LINKEDBINARYTREE_HPP_
#define LINKEDBINARYTREE_HPP_
#include <iostream>
#include <list>
#include <string>
template <typename E> class LinkedBinaryTree {
protected:
  //-------NODE declaration---------
  struct Node {
    E data;
    Node *par;          // parent
    Node *left, *right; // left and right child
    Node() : data(), par(NULL), left(NULL), right(NULL) {} // constructor
  };

public:
  //------POSITION CLASS-------
  
  class Position {
  private:
    Node *v;

  public:
    Position(Node *_v = NULL) : v(_v) {} // Constructor
    E &operator*() { return v->data; }
    Position left() const { return Position(v->left); }
    Position right() const { return Position(v->right); }
    Position parent() const { return Position(v->par); }
    bool isRoot() const { return v->par == NULL; }
    bool isExternal() const { return v->left == NULL && v->right == NULL; }
    friend class LinkedBinaryTree;
  };
  //-------BINARYTREE methods------
  LinkedBinaryTree();
  int size() const;
  bool empty() const;
  Position root() const;
  std::list<Position> positions() const; // return List of Positions
  void addRoot();
  void expandExternal(const Position &p);
  Position removeAboveExternal(const Position &p);

protected:
  void preorder(Node *v, std::list<Position> &) const;

private:
  Node *_root;
  int n;
};

template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree() : _root(NULL), n(0) {}

template <typename E>
int LinkedBinaryTree<E>::size() const { return n; }

template <typename E>
bool LinkedBinaryTree<E>::empty() const { return size() == 0; }

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const {   ///////what is this typename????????
  return LinkedBinaryTree<E>::Position(_root);
}

template <typename E>
void LinkedBinaryTree<E>::addRoot() {
  _root = new Node;
  n = 1;
}

template <typename E>
void LinkedBinaryTree<E>::expandExternal(const LinkedBinaryTree<E>::Position &p) {
  Node *v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}
/*
template <typename E>
LinkedBinaryTree<E>::Position<E>
LinkedBinaryTree<E>::removeAboveExternal(const LinkedBinaryTree<E>::Position<E> &p) {
  Node<E> *w = p.v;
  Node<E> *v = w->par;
  Node<E> *sib = (w == v->left ? v->right : v->left);
  if (v == _root) {
    _root = sib;
    sib->par = NULL;
  } else {
    Node<E> *gpar = v->par;
    if (v == gpar->left) {
      gpar->left = sib;
    } else {
      gpar->right = sib;
    }
    sib->par = gpar;
  }
  delete w;
  delete v;
  n -= 2;
  return LinkedBinaryTree<E>::Position<E>(sib);
}
*/
template <typename E>
 std::list<typename LinkedBinaryTree<E>::Position> LinkedBinaryTree<E>::positions() const {  ///again adding type?????
  std::list<LinkedBinaryTree<E>::Position> pl;
  preorder(_root, pl);
  return pl;
}
template <typename E>
void LinkedBinaryTree<E>::preorder(LinkedBinaryTree<E>::Node *v,std::list<LinkedBinaryTree<E>::Position> &pl) const{
  pl.push_back(LinkedBinaryTree<E>::Position(v));
  if (v->left != NULL) {
    preorder(v->left, pl);
  }
  if (v->right != NULL) {
    preorder(v->right, pl);
  }
}

#endif