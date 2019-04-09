#include <iostream>
#include <stack>

using namespace std;

int main() {

  string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  int len = s.length();

  stack<char> myStack;
  stack<char> result;

  int index = 0;

  int currLevel = 1;

  bool isFile = false;

  // Reading till end of string 's'....
  while(index < len) {

    isFile = false;

    cout << "Trying to find out till a new line" << endl;
    // First searching for the first '\n'
    while(index < len && s.at(index) != '\n') {
      cout << s.at(index);
      if(s.at(index) == '.') {
        isFile = true;
      }
      // Pushing element onto the stack ...
      myStack.push(s.at(index));
      index++;
    }

    if(index < len) {
        index++; // Crossing the new line character ....
    }

    cout << endl << "Found a file? " << isFile << endl;

    // Checking if we found a file ...
    if(isFile && result.size() < myStack.size()) {
      cout << "$$$$ Found a file greater than the existing path..." << endl;
      // Updating the stack in case we have found a larger size ...
      result = stack<char>(myStack);
    }

    // We have reached the end of the string ...
    if(index == len) {
      break;
    }

    // Now checking if the next element is at the same level or next level ...
    int newLevel = 1;
    cout << "Trying to find the level of the next elem" << endl;
    //cout << "s.at(index) is: |" << s.at(index) << "|" << endl;
    while(index < len && s.at(index) == '\t') {
      newLevel++;
      index++;
      cout << "Here!!!" << endl;
    }
    cout << "The existing level is " << currLevel << endl;
    cout << "The new level is " << newLevel << endl;

    // We have the new element at the current level ...
    // Should be either 0 or 1 (cannot climb more than one directory level)
    if(newLevel - currLevel == 1) {
      myStack.push('/');
      currLevel++;
    } else {
      int levelsPopped = (currLevel - newLevel) + 1;
      cout << "Levels to be popped are " << levelsPopped << endl;
      // Removing till we find levelDiff number of '/'
      while(levelsPopped > 0) {
        if(myStack.top() == '/') {
          levelsPopped--;
          if(levelsPopped == 0) {
            break;
          } else {
            currLevel--;
          }
        }
        cout << "Popping: " << myStack.top() << endl;
        myStack.pop();
      }
    }
    cout << "Post popping: currLevel: " << currLevel << endl;
    cout << "Post popping: newLevel: " << newLevel << endl;
    cout << "#######################" << endl;

  }

  cout << "Final size is " << result.size() << endl;

  string resStr = "";
  while(!result.empty()) {
    resStr = result.top() + resStr;
    result.pop();
  }

  cout << resStr << endl;

  return 0;
}
