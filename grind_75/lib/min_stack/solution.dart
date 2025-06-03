class MinStack {
  final List<int> stack = [];
  final List<int> minStack = [];

  MinStack() {}

  void push(int val) {
    if (stack.isEmpty) {
      minStack.add(val);
    } else {
      if (minStack[0] < val) {
        minStack.insert(0, minStack[0]);
      } else {
        minStack.insert(0, val);
      }
    }
    stack.insert(0, val);
  }

  void pop() {
    stack.removeAt(0);
    minStack.removeAt(0);
  }

  int top() {
    return stack[0];
  }

  int getMin() {
    return minStack[0];
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = MinStack();
 * obj.push(val);
 * obj.pop();
 * int param3 = obj.top();
 * int param4 = obj.getMin();
 */