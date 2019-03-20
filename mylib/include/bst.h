//==================================
// include guard
#ifndef __BST_H_INCLUDED__
#define __BST_H_INCLUDED__

//==================================
// forward declared dependencies

// =================================
// include dependencies

// =================================
// the actual class

struct Node {
  Node(int value): data(value), left(NULL), right(NULL) {}
  int data;
  struct Node *left;
  struct Node *right;
};

class BST {
private:
  Node *_root;
  void _insert(Node *parent, int k);
  void _preOrderTraverse(Node *parent);
public:
  BST();
  ~BST();
	void insert(int k);
  void preOrderTraverse();
};

#endif
