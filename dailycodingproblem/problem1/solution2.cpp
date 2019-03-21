#include <iostream>
#include <set>
#include <iterator>

using namespace std;

bool twoNumbersAddToK(int arr[], int size, int k) {
  set<int> numberSet;
  for(int i = 0; i < size; i++) {
    numberSet.insert(arr[i]);
  }

  for(int i = 0; i < size; i++) {
    if(numberSet.find(k - arr[i]) != numberSet.end()) {
      cout << "Found a combo" << endl;
      return 1;
    }
  }

  cout << "Could not find a combo" << endl;
  return 0;
}

int main() {
  int arr[5] = {45, 34, 67, 23, 45};
  cout << twoNumbersAddToK(arr, 5, 57);
}
