class Solution {
  int evalRPN(List<String> tokens) {
    // In case there is only one element in the tokens.
    if (tokens.length == 1) {
      return int.parse(tokens[0]);
    }

    int pointer = 0;
    List<int> stack = [];

    while (pointer < tokens.length) {
      // Checking if we have an operation to be done.
      if (tokens[pointer] == "+" ||
          tokens[pointer] == "*" ||
          tokens[pointer] == "-" ||
          tokens[pointer] == "/") {
        // Popping the integer from the stack and doing operation.
        int b = stack[0];
        stack.removeAt(0);
        int a = stack[0];
        stack.removeAt(0);
        if (tokens[pointer] == "+") {
          stack.insert(0, a + b);
        } else if (tokens[pointer] == "-") {
          stack.insert(0, a - b);
        } else if (tokens[pointer] == "*") {
          stack.insert(0, a * b);
        } else if (tokens[pointer] == "/") {
          stack.insert(0, a ~/ b);
        }
      } // We have new integer. Pushing it to the stack.
      else {
        stack.insert(0, int.parse(tokens[pointer]));
      }
      // Incrementing the pointer.
      pointer++;
    }

    return stack[0];
  }
}
