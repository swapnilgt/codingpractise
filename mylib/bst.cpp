#include <iostream>
#include "bst.h"

using namespace std;


BST::BST() {
  _root = NULL;
  cout << "Inside constructor" << endl;
}

BST::~BST() {
  cout << "Inside destructor" << endl;
}

void BST::insert(int k) {
  // cout << "@@ Calling the private insert" << endl;
  _insert(_root, k); // calling the private method ..
}

void BST::_insert(Node *parent, int k) {
  // cout << "Parent is " << parent << endl;
  // cout << "Inserting: " << k <<  endl;
  if(parent == NULL) {
    cout << "Postion 1" <<  endl;
    parent = new Node(k);
    _root = parent;
  } else if(parent->data < k) {
    if(parent->right == NULL) {
      cout << "Postion 2" <<  endl;
      Node *child = new Node(k);
      child->data = k;
      parent->right = child;
    } else {
      cout << "Postion 2.1" <<  endl;
      _insert(parent->right, k);
    }
  } else if(parent->data >= k) {
    if(parent->left == NULL) {
      cout << "Postion 3" <<  endl;
      Node *child = new Node(k);
      child->data = k;
      parent->left = child;
    } else {
      cout << "Postion 3.1" <<  endl;
      _insert(parent->left, k);
    }
  }
}

void BST::_preOrderTraverse(Node *parent) {
  if(parent == NULL) {
    return;
  }

  cout << parent -> data << " ";
  _preOrderTraverse(parent -> left);
  _preOrderTraverse(parent -> right);
}

void BST::preOrderTraverse() {
  _preOrderTraverse(_root);
}

void BST::_postOrderTraverse(Node *parent) {
  if(parent == NULL) {
    return;
  }
  _postOrderTraverse(parent -> left);
  _postOrderTraverse(parent -> right);
  cout << parent -> data << " ";
}

void BST::postOrderTraverse() {
  _postOrderTraverse(_root);
}

void BST::_inOrderTraversal(Node *parent) {
  if(parent == NULL) {
    return;
  }
  _inOrderTraversal(parent -> left);
  cout << parent -> data << " ";
  _inOrderTraversal(parent -> right);
}

void BST::inOrderTraversal() {
  _inOrderTraversal(_root);
}
