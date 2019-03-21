#include<iostream>

using namespace std;

void runCode(int arr[], const int n) {

  if(n <= 1) {
    cout << "There are less than 1 elements in the array" << endl;
    return;
  }

  int leftMult[n];
  int rightMult[n];

  int mult = 1;
  for(int i = 0; i < n; i++) {
    leftMult[i] = arr[i] * mult;
    mult = leftMult[i];
    cout << "The value of mult is: " << mult << endl;
  }

  mult = 1;
  for(int i = n-1; i >= 0; i--) {
    rightMult[i] = arr[i] * mult;
    mult = rightMult[i];
    cout << "The value of mult is: " << mult << endl;
  }

  for(int i = 0; i < n; i++) {
    if(i == 0) {
      arr[i] = rightMult[i+1];
    } else if(i == n-1) {
      arr[i] = leftMult[i-1];
    } else {
      arr[i] = leftMult[i-1] * rightMult[i+1];
    }
  }
}

int main() {
  int arr[5] = {0, 34, 67, 23, 45};
  runCode(arr, 5);
  for(int i = 0; i < 5; i++) {
    cout << "Elem at position " << i << " is " << arr[i] << endl;
  }
}
