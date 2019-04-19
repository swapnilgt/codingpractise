#include <iostream>
#include "linkedlist.h"

using namespace std;


int main() {

  LinkedList ll1;
  LinkedList ll2;

  NodeLL *first1 = new NodeLL(3);
  NodeLL *first2 = new NodeLL(7);

  ll1.insert(first1);
  ll1.insert(first2);

  NodeLL *second1 = new NodeLL(11);
  NodeLL *second2 = new NodeLL(99);
  NodeLL *second3 = new NodeLL(1);
  ll2.insert(second1);
  ll2.insert(second2);
  ll2.insert(second3);

  NodeLL *common1 = new NodeLL(8);
  NodeLL *common2 = new NodeLL(10);

  ll1.insert(common1);
  ll1.insert(common2);

  ll2.insert(common1);

  cout << "Insertion done ... " << endl;

  ll1.traverse();
  ll2.traverse();

  // First finding the lengths of both the linked lists ...
  int len1 = 0, len2 = 0;
  NodeLL *root1 = ll1.getRoot();
  NodeLL *root2 = ll2.getRoot();

  while(root1 != NULL) {
    len1++;
    root1 = root1 -> next;
  }

  cout << "Length of l1 is " << len1 << endl;

  while(root2 != NULL) {
    len2++;
    root2 = root2 -> next;
  }

  cout << "Length of l2 is " << len2 << endl;

  root1 = ll1.getRoot();
  root2 = ll2.getRoot();
  if(len1 > len2) {
    while(len1 != len2) {
      root1 = root1 -> next;
      len1--;
    }
  } else if(len1 < len2) {
    while(len1 != len2) {
      root2 = root2 -> next;
      len2--;
    }
  }

  cout << "Finished moving the length of one of the lists .." << endl;

  while(root1 -> next != NULL) {
    if(root1 -> data == root2 -> data) {
      cout << "The intersection is at " << root1-> data << endl;
      break;
    }
    root1 = root1 -> next;
    root2 = root2 -> next;
  }

}
