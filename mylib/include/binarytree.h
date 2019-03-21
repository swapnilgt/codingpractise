#include "node.h"
//==================================
// include guard
#ifndef __BT_H_INCLUDED__
#define __BT_H_INCLUDED__

//==================================
// forward declared dependencies

// =================================
// include dependencies

// =================================
// the actual class


class BinaryTree {
protected:
  Node *_root;
  Node* _deserializeFromPreOrderAndInorder(int preOrder[], int& preOrderIndex, int inOrder[], int left, int right, int len);
  void _preOrderTraverse(Node *parent);
  void _postOrderTraverse(Node *parent);
  void _inOrderTraversal(Node *parent);
public:
  BinaryTree();
  ~BinaryTree();
  void preOrderTraverse();
  void postOrderTraverse();
  void inOrderTraversal();
  void deserializeFromPreOrderAndInorder(int preOrder[], int inOrder[], int size);
};

#endif