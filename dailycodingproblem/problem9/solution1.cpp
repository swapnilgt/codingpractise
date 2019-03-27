#include<iostream>

using namespace std;

int getLargestNonAdjacentSum(int arr[], int size) {
  // If the array length is 1
  if(size == 1) {
    return arr[0];
  }
  int dp[size];
  // Populating intial data ...
  dp[0] = arr[0];
  dp[1] = max(dp[0], arr[1]);

  // Now.. iterating over the rest of the elements ...
  for(int i = 2; i < size; i++) {
    dp[i] = max(dp[i - 1], max(dp[i-2], dp[i-2] + arr[i]));
  }

  return dp[size - 1];
}

int main() {
  int arr[5] = {2, 4, 6, 2, 5};

  cout << "The maxium non adjacent sum is " << getLargestNonAdjacentSum(arr, 5) << endl;
}
