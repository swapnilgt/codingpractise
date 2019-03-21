#include <iostream>
#include "binarytree.h"

using namespace std;

int main() {
  int preOrder[7] = {10, 11, 9, 13, 2, 30, 7};
  int inOrder[7] = {9, 11, 10, 2, 30, 13, 7};

  BinaryTree tree;

  tree.deserializeFromPreOrderAndInorder(preOrder, inOrder, 7);

  cout << "Finished deserializing the tree " << endl;

  tree.preOrderTraverse();
}
