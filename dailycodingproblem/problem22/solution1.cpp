#include <iostream>
#include <vector>
#include "trie.h"

using namespace std;

vector<string> getSentenceWords(const vector<string> dictionary, string sentence) {
  Trie myTrie;

  // Inserting all the elements in the the trie ...
  for(int i = 0; i < dictionary.size(); i++) {
    myTrie.insert(dictionary[i]);
  }

  // Now iterating over the given sentence ...
  int i = 0;

  string newWord = "";
  while(i < sentence.length()) {
    newWord = 
  }
}

int main() {

}
