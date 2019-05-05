#include <iostream>

using namespace std;

bool isMatched(string regex, string target) {

  int regexLen = regex.length();
  int targetLen = target.length();

  if(regexLen == 0 || targetLen == 0) {
    return regexLen == targetLen;
    cout << "Returning false" << endl;
    cout << "############" << endl;
  }

  cout << "Entering with regex " << regex << " and target " << target << endl;

  // If we have reached the last and we are left with the
  if(regexLen == 1) {
    if(targetLen != 1) {
      cout << "Returning false" << endl;
      cout << "############" << endl;
      return false;
    } else if(regex.at(0) == '.' || regex.at(0) == target.at(0)) {
      cout << "Returning true" << endl;
      cout << "############" << endl;
      return true;
    }
    cout << "Returning false" << endl;
    cout << "############" << endl;
    return false;
  } else if(regexLen == 2 && regex.compare(".*") == 0) {
    cout << "Returning true" << endl;
    cout << "############" << endl;
    return true;
  } else {
    if(regex.at(1) == '*') {
      if(regex.at(0) == '.' || regex.at(0) == target.at(0)) {
        return isMatched(regex.substr(2, regexLen), target.substr(1, targetLen)) || isMatched(regex, target.substr(1, targetLen));
      } else {
        cout << "Returning false" << endl;
        cout << "############" << endl;
        return false;
      }
    } else if (regex.at(0) == '.' || regex.at(0) == target.at(0)) {
      return isMatched(regex.substr(1, regexLen), target.substr(1, targetLen));
    } else {
      cout << "Returning false" << endl;
      cout << "############" << endl;
      return false;
    }
  }
}

int main() {

  string regex = "swap";
  string target = "swapnil";

  bool matches = isMatched(regex, target);

  cout << "We have found the match? " << matches << endl;

}
