#include <iostream>
#include <vector>

using namespace std;

string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
int n = 13;
//vector<string> dictionary{"mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","like","ice","cream"};

bool isWordInDict(const string word) {
  for(int i = 0; i < n; i++) {
    if(dictionary[i].compare(word) == 0) {
      return true;
    }
  }
  return false;
}


void isPossible(string targetString, vector<string> &retVal, string currVal) {

  //cout << "Entering with string " << targetString << endl;

  for(int i = 1; i <= targetString.length(); i++) {
    string prefix = targetString.substr(0, i);
    //cout << "If  " << prefix << " is in the dict? " << isWordInDict(prefix) << endl;
    if(isWordInDict(prefix)) {
      string newCurrVal = currVal + " " + prefix;
      if(i == targetString.length()) {
        retVal.push_back(newCurrVal);
        return;
      }
      isPossible(targetString.substr(i, targetString.length()), retVal, newCurrVal);
    }
  }
}

vector<string> getPossibleWordBreaks(string inputStr) {
  vector<string> retVal;

  isPossible(inputStr, retVal, "");

  return retVal;
}

int main() {

    //string dictionary[] = {"mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","like","ice","cream"};
    string inputStr = "ilovesamsungmobile";

    vector<string> possible = getPossibleWordBreaks(inputStr);

    for(int i = 0 ; i < possible.size(); i++) {
      cout << possible[i] << endl;
    }

}
