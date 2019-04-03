#include <iostream>
#include "trie.h"

using namespace std;

int main() {
  Trie trie;

  trie.insert("swapnil");
  trie.insert("ayushi");
  trie.insert("ayushman");
  trie.insert("ayurveda");
  trie.insert("dipyomoy");

  trie.getSuggestionsFor("ayu");

  return 0;
}
