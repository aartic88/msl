#ifndef LINKEDBINARYTREE_HPP_
#define LINKEDBINARYTREE_HPP_
#include <iostream>
#include <list>
#include <string>
class LinkedBinaryTree {
protected:
  //-------NODE declaration---------
  struct Node {
    int data;
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
    int &operator*() { return v->data; }
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

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {}
int LinkedBinaryTree::size() const { return n; }
bool LinkedBinaryTree::empty() const { return size() == 0; }
LinkedBinaryTree::Position LinkedBinaryTree::root() const {
  return LinkedBinaryTree::Position(_root);
}
void LinkedBinaryTree::addRoot() {
  _root = new Node;
  n = 1;
}
void LinkedBinaryTree::expandExternal(const LinkedBinaryTree::Position &p) {
  Node *v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}
LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const LinkedBinaryTree::Position &p) {
  Node *w = p.v;
  Node *v = w->par;
  Node *sib = (w == v->left ? v->right : v->left);
  if (v == _root) {
    _root = sib;
    sib->par = NULL;
  } else {
    Node *gpar = v->par;
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
  return LinkedBinaryTree::Position(sib);
}
std::list<LinkedBinaryTree::Position> LinkedBinaryTree::positions() const {
  std::list<LinkedBinaryTree::Position> pl;
  preorder(_root, pl);
  return pl;
}
void LinkedBinaryTree::preorder(
    LinkedBinaryTree::Node *v,
    std::list<LinkedBinaryTree::Position> &pl) const {
  pl.push_back(LinkedBinaryTree::Position(v));
  if (v->left != NULL) {
    preorder(v->left, pl);
  }
  if (v->right != NULL) {
    preorder(v->right, pl);
  }
}
#endif