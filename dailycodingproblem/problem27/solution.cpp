#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string s) {
  stack<char> myStack;
  int i = 0;
  while(i < s.length()) {
    char c = s.at(i);
    cout << "Next char is " << c << endl;
    if(c == '}' || c == ')' || c == ']') {
      char openingChar;
      switch(c) {
        case '}':
          openingChar = '{';
          break;
        case ')':
          openingChar = '(';
          break;
        case ']':
          openingChar = '[';
          break;
      }
      cout << "Corresponding opening char is " << openingChar << endl;
      if(!myStack.empty() && myStack.top() == openingChar) {
        myStack.pop();
        cout << "Found the opening char and popping it" << endl;
      } else {
        return false;
      }
    } else {
      cout << "Pushing the new opening char" << endl;
      myStack.push(c);
    }

    i++;
  }
  if(myStack.size() == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string s = "([)]";
  cout << "The string is a balanced? " << isBalanced(s) << endl;
}
