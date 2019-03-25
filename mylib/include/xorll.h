//==================================
// include guard
#ifndef __XORLL_H_INCLUDED__
#define __XORLL_H_INCLUDED__

//==================================
// forward declared dependencies

// =================================
// include dependencies

// =================================
// the actual class

struct NodeXOR {
  NodeXOR(int value): data(value), addrXOR(NULL) {}
  int data;
  struct NodeXOR *addrXOR;
};

class XORLL {
private:
  NodeXOR *_root;
  void _add(int val, NodeXOR* elem, NodeXOR* prev);
  void _traverse(NodeXOR *elem, NodeXOR *prev);
  NodeXOR* XOR(NodeXOR *a, NodeXOR *b) {
    return (NodeXOR*) ((uintptr_t) (a) ^ (uintptr_t) (b));
  }
public:
  XORLL();
  ~XORLL();
  void add(int val);
  void traverse();
};

#endif
