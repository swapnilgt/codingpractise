class Trie {
  Node root = Node();

  Trie() {
    root.initNodes();
  }

  void insert(String word) {
    Node currNode = root;
    for (final rune in word.runes) {
      // Check if the node at the current character already exists.
      // Else initiatlising the node
      if (currNode.map![rune - 97].map == null) {
        currNode.map![rune - 97] = Node();
        currNode.map![rune - 97].initNodes();
      }
      currNode = currNode.map![rune - 97];
    }
    // Marking the node as existing.
    currNode.exists = true;
  }

  bool search(String word) {
    Node currNode = root;
    for (final rune in word.runes) {
      if (currNode.map![rune - 97].map == null) {
        return false;
      }
      currNode = currNode.map![rune - 97];
    }
    return currNode.exists;
  }

  bool startsWith(String prefix) {
    Node currNode = root;
    for (final rune in prefix.runes) {
      if (currNode.map![rune - 97].map == null) {
        return false;
      }
      currNode = currNode.map![rune - 97];
    }
    return true;
  }
}

class Node {
  List<Node>? map;
  bool exists = false;

  void initNodes() {
    // Initialising the nodes.
    map = List.filled(26, Node());
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = Trie();
 * obj.insert(word);
 * bool param2 = obj.search(word);
 * bool param3 = obj.startsWith(prefix);
 */
