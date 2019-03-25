#include<iostream>
#include<xorll.h>

using namespace std;


int main() {
  XORLL ll;

  ll.add(1);
  ll.add(2);
  ll.add(3);
  ll.add(4);
  ll.add(5);

  ll.traverse();
}
