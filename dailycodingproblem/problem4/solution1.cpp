#include<iostream>

using namespace std;



int shortestMissingInt(int arr[], int len) {
  int left = 0;
  int right = len - 1;

  while(left < right) {

    // Searching for the first non-negative element from the right ...
    while(left < right && arr[right] <= 0) {
      right--;
    }

    // Searching for the first positive element from the left ...
    while(left < right && arr[left] > 0) {
      left++;
    }

    // Swapping the elements ....
    if(left != right) {
      arr[left] = arr[left] + arr[right];
      arr[right] = arr[left] - arr[right];
      arr[left] = arr[left] - arr[right];
    }

  }

  // Printing the array ...
  for(int i = 0; i < len; i++) {
    cout << "The element is " << arr[i] << " ";
    cout << endl;
  }

  cout << "The left is " << left << " and the right is " << right << endl;

  // Making the position values negative whenever we get a value for that index ..
  for(int i = 0; i <= right; i++) {

    int beforeConversion = arr[i];
    if(beforeConversion < 0) {
      beforeConversion = beforeConversion * -1;
    }

    if(beforeConversion <= (right+1) && arr[beforeConversion - 1] > 0) {
      arr[beforeConversion - 1] = arr[beforeConversion - 1] * -1;
    }
  }

  // Printing the first missing element ...
  for(int i = 0; i <= right; i++) {
    if(arr[i] > 0) {
      return i + 1;
    }
  }

  return right + 2;
}

int main() {

  int arr[8] = {5, 5, 12, 2, 7, -10, -9, -1};
  cout << "The result is: " << shortestMissingInt(arr, 8) << endl;

}
