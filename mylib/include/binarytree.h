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
  bool _isUnivalTree(Node *parent, int& count);
  bool _checkLockPrecondition(Node* node);
  bool _checkChildrenFree(Node *node);
public:
  BinaryTree();
  BinaryTree(Node *root);
  ~BinaryTree();
  void preOrderTraverse();
  void postOrderTraverse();
  void inOrderTraversal();
  void deserializeFromPreOrderAndInorder(int preOrder[], int inOrder[], int size);
  int countUnivalTrees();
  bool isLocked(Node *node);
  bool lockNode(Node *node);
  bool unlockNode(Node *node);
};

#endif
