#include<iostream>
#include <string>
#include <vector>
#include "trie.h"

using namespace std;

Trie::Trie() {
  cout << "Inside the trie constructor " << endl;
  _root = new TrieNode();
}

Trie::~Trie() {
  cout << "Inside the trie destructor " << endl;
}

void Trie::_insert(string s, int i, TrieNode *parent) {

  if(s.length() == i) {
    parent -> isEndOfWord = true;
    return;
  }

  char c = s.at(i);
  int charIndex = (int) (c - 97);

  // If we have reached the end of the string ....
  if(parent -> children[charIndex] == NULL) {
    parent -> children[charIndex] = new TrieNode();
  }

  _insert(s, i + 1, parent -> children[charIndex]);

}

void Trie::insert(string s) {
  _insert(s, 0, _root);
}


void Trie::_getSuggestionsFor(string s, TrieNode *node, vector<string> &retVal) {

  // If this node is end of the word ...
  if(node -> isEndOfWord) {
    retVal.push_back(s);
  }

  // Now iterating over each item and it's possibility ...
  for(int i = 0; i < ALPHABET_SIZE; i++) {
    if(node -> children[i] == NULL) { // If the trie ends for this alphabet ...
      continue;
    }
    char nextChar = (char)(i + 97);
    _getSuggestionsFor(s + nextChar, node -> children[i], retVal);
  }
}

void Trie::getSuggestionsFor(string s) {
  vector<string> retVal;

  TrieNode *startNodeForSearch = _root;
  int i = 0;
  while(i < s.length()) {
    int charIndex = (int)(s.at(i) - 97);
    if(startNodeForSearch -> children[charIndex] == NULL) {
      break;
    }
    i++;
    startNodeForSearch = startNodeForSearch -> children[charIndex];
  }

  cout << "We have already found string in the tree: " << (i == s.length()) << endl;
  cout << "Value of i is " << i << endl;

  // We have found a node for the end of the string ....
  if(i == s.length()) {
    // populating the results ....slack
    _getSuggestionsFor(s.substr(i), startNodeForSearch, retVal);
  }

cout << "The suggestions are: ";
  for(int i = 0; i < retVal.size(); i++) {
    cout << retVal[i] << ",";
  }
cout << endl;
}
