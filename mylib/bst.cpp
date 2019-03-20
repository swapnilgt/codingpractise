#include <iostream>
#include "bst.h"

using namespace std;


BST::BST() {
  cout << "Inside constructor" << endl;
}

BST::~BST() {
  cout << "Inside destructor" << endl;
}

void BST::insert(int k) {
  _insert(_root, k); // calling the private method ..
}

void BST::_insert(Node *parent, int k) {
  if(parent == NULL) {
    cout << "Postion 1" <<  endl;
    parent = new Node(k);
    _root = parent;
  } else if(parent->data < k) {
    cout << "Postion 2" <<  endl;
    if(parent->right == NULL) {
      Node *child = new Node(k);
      child->data = k;
      parent->right = child;
    } else {
      _insert(parent->right, k);
    }
  } else if(parent->data >= k) {
    cout << "Postion 3" <<  endl;
    if(parent->left == NULL) {
      Node *child = new Node(k);
      child->data = k;
      parent->left = child;
    } else {
      _insert(parent->left, k);
    }
  }
}

void BST::_preOrderTraverse(Node *parent) {
  if(parent == NULL) {
    return;
  }
  _preOrderTraverse(parent -> left);
  cout << parent -> data << " ";
  _preOrderTraverse(parent -> right);
}

void BST::preOrderTraverse() {
  _preOrderTraverse(_root);
}
