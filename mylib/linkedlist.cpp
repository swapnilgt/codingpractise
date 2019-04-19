#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList() {
  cout << "Inside constructor..." << endl;
  _root = NULL;
}

LinkedList::~LinkedList() {
  cout << "Inside destructor..." << endl;
}

void LinkedList::insert(int val) {
  NodeLL *newNode = new NodeLL(val);
  if(_root == NULL) {
    _root = newNode;
  } else {
    NodeLL * currNode = _root;
    while (currNode -> next != NULL) {
      currNode = currNode -> next;
    }

    currNode -> next = newNode;
  }
}

void LinkedList::traverse() {
  if(_root == NULL) {
    return;
  }
  NodeLL *currNode = _root;

  cout << currNode->data;
  while (currNode -> next != NULL) {
    currNode = currNode -> next;
    cout << "->" << currNode -> data;
  }

  cout << endl;
}

void LinkedList::insert(NodeLL * node) {
  if(_root == NULL) {
    //cout << "The root is null. Assigning it to the root" << endl;
    _root = node;
    return;
  }

  NodeLL * currNode = _root;
  //cout << "Moving over " << currNode -> data << endl;
  while (currNode -> next != NULL) {
    //cout << "Moving over " << currNode -> data << endl;
    currNode = currNode -> next;
  }

  //cout << "##########################" << endl;

  currNode -> next = node;
}

NodeLL * LinkedList::getRoot() {
  return _root;
}
