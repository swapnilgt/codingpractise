#include <iostream>
#include "binarytree.h"

using namespace std;

BinaryTree::BinaryTree() {
  _root = NULL;
  cout << "Inside binary tree constructor" << endl;
}

BinaryTree::BinaryTree(Node *root) {
  _root = root;
}

BinaryTree::~BinaryTree() {
  cout << "Inside binary tree desctructor" << endl;
}

Node* BinaryTree::_deserializeFromPreOrderAndInorder(int preOrder[], int& preOrderIndex, int inOrder[], int left, int right, int len) {

  cout << "Entered with left as " << left << " and right as " << right << endl;
  // Boundary case ...
  if(preOrderIndex > len-1 || left > right) {
    return NULL;
  }

  // Creating a new node for the current preorder element ...
  Node *newNode = new Node(preOrder[preOrderIndex]);

  cout << "Creating a node with value " << preOrder[preOrderIndex] << endl;

  // Iterating to find the location of the above node in the preorder ...
  int index = left;
  while(index <= right) {
    if(inOrder[index] == preOrder[preOrderIndex]) {
      break;
    }
    index++;
  }

  cout << "The element index is " << index << endl;
  cout << "###############################" << endl;

  // Incrementing the preorder preOrderIndex ..
  preOrderIndex++;

  newNode -> left = _deserializeFromPreOrderAndInorder(preOrder, preOrderIndex, inOrder, left, index - 1, len);
  newNode -> right = _deserializeFromPreOrderAndInorder(preOrder, preOrderIndex, inOrder, index + 1, right, len);

  return newNode;
}

void BinaryTree::deserializeFromPreOrderAndInorder(int preOrder[], int inOrder[], int size) {
  int preOrderIndex = 0;
  _root = _deserializeFromPreOrderAndInorder(preOrder, preOrderIndex, inOrder, 0, size - 1, size);
}

void BinaryTree::_preOrderTraverse(Node *parent) {
  if(parent == NULL) {
    return;
  }

  cout << parent -> data << " ";
  _preOrderTraverse(parent -> left);
  _preOrderTraverse(parent -> right);
}

void BinaryTree::preOrderTraverse() {
  _preOrderTraverse(_root);
}

void BinaryTree::_postOrderTraverse(Node *parent) {
  if(parent == NULL) {
    return;
  }
  _postOrderTraverse(parent -> left);
  _postOrderTraverse(parent -> right);
  cout << parent -> data << " ";
}

void BinaryTree::postOrderTraverse() {
  _postOrderTraverse(_root);
}

void BinaryTree::_inOrderTraversal(Node *parent) {
  if(parent == NULL) {
    return;
  }
  _inOrderTraversal(parent -> left);
  cout << parent -> data << " ";
  _inOrderTraversal(parent -> right);
}

void BinaryTree::inOrderTraversal() {
  _inOrderTraversal(_root);
}

bool BinaryTree::_isUnivalTree(Node *parent, int &count) {

  // Handling case, when root is itself null ...
  if(parent == NULL) {
    cout << "There are no elements in the tree" << endl;
    return 0;
  }

  // If the node is a leaf node ...
  if(parent -> left == NULL && parent -> right == NULL) {
    cout << "Reached the leaf node with val " << parent -> data << endl;
    return 1;
  } else if(parent -> right == NULL) {
    cout << "< We only have left" << endl;
    if(_isUnivalTree(parent -> left, count)) {
      count++;
      cout << "!!Returning from left incremented count is " << count << endl;
      if(parent -> left -> data == parent -> data) {
          return 1;
      } else {
          return 0;
      }
    } else  {
      return 0;
    }
  } else if(parent -> left == NULL) {
    cout << "> We only have the right" << endl;
    if(_isUnivalTree(parent -> right, count)) {
      count++;
      cout << "!!Returning from right incremented count is " << count << endl;
      if(parent -> right -> data == parent -> data) {
          return 1;
      } else {
          return 0;
      }
    } else  {
      return 0;
    }
  } else {
    cout << "< > We have both left and right" << endl;
    bool leftUnival = false;
    bool rightUnival = false;
    if(_isUnivalTree(parent -> left, count)) {
      leftUnival = true;
      count++;
      cout << "@!!Returning from left incremented count is " << count << endl;
    }
    if(_isUnivalTree(parent -> right, count)) {
      rightUnival = true;
      count++;
      cout << "@!!Returning from right incremented count is " << count << endl;
    }
    if(leftUnival && rightUnival && parent -> left -> data == parent -> right -> data && parent -> data) {
      return 1;
    } else {
      return 0;
    }
  }
}

int BinaryTree::countUnivalTrees() {
  int count = 0;
  if(_isUnivalTree(_root, count)) {
    count++;
  }
  return count;
}
