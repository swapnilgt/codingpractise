#include <iostream>
#include "binarytree.h"

using namespace std;

int main() {

  Node *node1 = new Node(1);

  // Initializing the binary tree with the root ...
  BinaryTree bt(node1);

  Node *node2 = new Node(3);
  Node *node3 = new Node(2);
  node1 -> left = node2;
  node1 -> right = node3;
  /////////////////////////////

  Node *node4 = new Node(2);
  Node *node5 = new Node(2);
  node3 -> left = node4;
  node3 -> right = node5;
  /////////////////////////////
  Node *node6 = new Node(2);
  node5 -> right = node6;

  int count = bt.countUnivalTrees();

  cout << "The total count is " << count << endl;

}
