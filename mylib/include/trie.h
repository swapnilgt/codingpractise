#include <string>

using namespace std;

#ifndef _TRIE_H_INCLUDED_
#define _TRIE_H_INCLUDED_

#define ALPHABET_SIZE 26

struct TrieNode {
  TrieNode(): isEndOfWord(false) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
      children[i] = NULL;
    }
  }
  struct TrieNode *children[ALPHABET_SIZE];
  bool isEndOfWord;
};


class Trie {
private:
  TrieNode *_root;
  void _insert(string s, int i, TrieNode *parent);
  void _getSuggestionsFor(string s, TrieNode *parent, vector<string> & retVal);

public:
  Trie(); //  intialize the values inside the structure ....
  ~Trie();
  void insert(string s);
  void getSuggestionsFor(string s);
};


#endif
