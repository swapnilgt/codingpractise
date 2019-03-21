#include <iostream>

using namespace std;

int compare(const void* a, const void* b) {
  const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

bool twoNumbersAddToK(int arr[], int size, int k) {

  // Sorting the array ...
  qsort(arr, size, sizeof(int), compare);

  for(int i = 0 ;i < size; i++) {
    cout << "Element at position " << i << " is " << arr[i] << endl;
  }

  int left = 0, right = size - 1;

  while(left < right) {
    if(arr[left] + arr[right] < k) {
      cout << "Incrementing left: Left is " << arr[left] << " right is " << arr[right] << endl;
      left++;
    } else if(arr[left] + arr[right] > k) {
      cout << "Incrementing right: Left is " << arr[left] << " right is " << arr[right] << endl;
      right--;
    } else {
      cout << "We have found a match!" << endl;
      return 1;
    }
  }
  cout << "We could not find the match!" << endl;
  return 0;
}

int main() {
  int arr[5] = {45, 34, 67, 23, 45};
  cout << twoNumbersAddToK(arr, 5, 56);
}
