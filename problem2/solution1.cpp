#include <iostream>

using namespace std;

void runCode(int arr[], int size) {
  int totalMul = 1;

  for(int i = 0; i < size; i++) {
    totalMul *= arr[i];
  }

  cout << "The total multiplication is " << totalMul << endl;

  for(int i = 0; i < size; i++) {
    if(arr[i] != 0) {
      arr[i] = totalMul/arr[i];
    }
  }
}

int main() {
  int arr[5] = {43, 34, 67, 23, 45};
  runCode(arr, 5);
  for(int i = 0; i < 5; i++) {
    cout << "Elem at position " << i << " is " << arr[i] << endl;
  }
}
