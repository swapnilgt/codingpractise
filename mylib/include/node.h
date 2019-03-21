//==================================
// include guard
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

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

#endif
