class Solution {
  bool isValid(String s) {
    if (s.trim().isEmpty || s.trim().length <= 1) return false;
    String characters = s.trim();
    final stack = <String>[];
    for (var i = 0; i < characters.length; i++) {
      if (characters[i] == '(' ||
          characters[i] == '{' ||
          characters[i] == '[') {
        stack.add(characters[i]);
      } else if (characters[i] == ')' ||
          characters[i] == '}' ||
          characters[i] == ']') {
        if (stack.isEmpty) return false;
        String last = stack.removeLast();
        if (!isMatchingPair(last, characters[i])) return false;
      }
    }
    if (stack.isNotEmpty) return false;
    return true;
  }

  bool isMatchingPair(String opening, String closing) {
    return (opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']');
  }
}
