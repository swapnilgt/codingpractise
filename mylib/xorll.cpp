#include<iostream>
#include<xorll.h>

using namespace std;

XORLL::XORLL() {
  _root = NULL;
  cout << "Inside xor ll constructor" << endl;
}

XORLL::~XORLL() {
  cout << "Inside xor ll destructor" << endl;
}

void XORLL::_add(int val, NodeXOR* elem, NodeXOR* prev) {

  // Case for first element ...
  if(_root == NULL) {
    _root = new NodeXOR(val);
    _root -> addrXOR = NULL;
    cout << "Inserting the root element " << val << endl;
    return;
  }

  // Case for last element ...
  if(elem -> addrXOR == NULL) {
    NodeXOR *newElem = new NodeXOR(val);
    newElem -> addrXOR = NULL;
    elem -> addrXOR = XOR(newElem, prev);
    cout << "Inserting the element " << val << endl;
    cout << "###############################" << endl;
  } else {
    cout << "Moving to next element for insertion " << endl;
    _add(val, XOR(elem -> addrXOR, prev), elem);
  }

}

void XORLL::_traverse(NodeXOR *elem, NodeXOR *prev) {
  if(elem == NULL) {
    return;
  }

  cout << elem -> data << "->";

  // Recursing on the next one ...
  if(elem -> addrXOR != NULL) {
    _traverse(XOR(elem -> addrXOR, prev), elem);
  }
}

void XORLL::add(int val) {
  _add(val, _root, NULL);
}

void XORLL::traverse() {
  _traverse(_root, NULL);
}
