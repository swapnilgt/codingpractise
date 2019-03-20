#include <iostream>
#include "bst.h"

using namespace std;

int main() {
  BST myBst;

  cout << "Starting to insert" << endl;
  myBst.insert(1);
  myBst.insert(2);
  myBst.insert(-3);
  myBst.insert(4);
  cout << "Finish insert" << endl;

  cout << "Traversing preorder" << endl;
  myBst.preOrderTraverse();
}
