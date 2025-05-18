class Solution {
  bool isValid(String s) {
    if(s.trim().isEmpty || s.trim().length) return false;
    String characters = s.trim();
    for(var i = 0; i < characters.length; i++) {
      if(characters[i] == '(' || characters[i] == '{' || characters[i] == '[') {
        stack.add(characters[i]);
      } else if(characters[i] == ')' || characters[i] == '}' || characters[i] == ']') {
        if(stack.isEmpty) return false;
        String last = stack.removeLast();
        if(!isMatchingPair(last, characters[i])) return false;
      }
    }

    final stack = <String>[];
  }

  bool 
}