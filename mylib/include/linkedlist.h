//==================================
// include guard
#ifndef _LINKEDLIST_H_INCLUDED__
#define _LINKEDLIST_H_INCLUDED__

//==================================
// forward declared dependencies

// =================================
// include dependencies

// =================================
// the actual class

struct NodeLL {
  NodeLL(int value): data(value), next(NULL) {}
  int data;
  struct NodeLL *next;
};

class LinkedList {
private:
  NodeLL *_root;
public:
  LinkedList();
  ~LinkedList();
  void insert(int val);
  void insert(NodeLL *node);
  void traverse();
  NodeLL* getRoot();
};

#endif
