#include <iostream>
#include <vector>

using namespace std;

int getLongestSubs(string s, int k) {

  int len = s.length();

  if(len == 0) {
    return 0;
  }

  int retVal = 0;

  int left = 0, right = 0, unique = 0;
  vector <int> found(26, -1);

  // initializing the values ...
  found[s.at(left) - 97] = left;
  unique++;

  while(right < len) {

    while(right < len && unique < k) {
      if(found[s.at(right) - 97] == -1) {
        unique++;
      }
      found[s.at(right) - 97] = right;

      cout << "Working for index " << right << " wtih val " << s.at(right) << endl;

      right++;
    }

    cout << "Iterating till we find all the elements in the founds list" << endl;
    // Now ... the new value that we have found .. going till index till where we have a number that is already considered..
    while(right < len && found[s.at(right) - 97] != -1) {
      cout << "@@ Working for index " << right << " wtih val " << s.at(right) << endl;
      found[s.at(right) - 97] = right;
      right++;
    }

    cout << "right is " << right << " and left is " << left << endl;

    // Checking if we have found a unique equal to k
    if(unique == k && right - left > retVal) {
      retVal = right - left;
    }

    // Now, mobing the left index ....
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
    cout << "Starting from the left " << left << endl;
    char cLeft = s.at(left);
    // Removing the elements now ...
    while(left < right && cLeft == s.at(left)) {
      left++;
    }

    cout << "Moved till the left index of " << left << endl;
    cout << "cLeft is " << cLeft << " and found value is " << found[cLeft - 97] << endl;

    // If cLeft char has the last position as left - 1, then we remove the number of unique ...
    if(left - 1 == found[cLeft - 97]) {
      found[cLeft - 97] = -1;
      unique--;
    }

    cout << "############################ with uniques as " << unique << endl;
  }

  return retVal;

}


int main() {

  string input = "abcba";
  int k = 2;

  int result = getLongestSubs(input, k);

  cout << "The maximum length of substring is " << result << endl;

  return 0;

}
