#include <iostream>

using namespace std;


int getMinCost(int arr[][], int n, int k) {


  int preMin = 0;
  int preSecondMin = 0;
  int preMinIndex = -1;

  for(int i = 0; i < n; i++) {
    int currMin = INT_MAX;
    int currSecondMin = INT_MAX;
    int currMinIndex;
    for(int j = 0; j < k; j++) {
      if(j == preMinIndex) {
        arr[i][j] += preSecondMin;
      } else {
        arr[i][j] += preMin;
      }

      // Updating the minimum ...
      if(arr[i][j] < currMin) {
        currSecondMin = currMin;
        currMin = arr[i][j];
        currMinIndex = j;
      } else if(arr[i][j] < preSecondMin) {
        currSecondMin = arr[i][j];
      }
    }

    preMin = currMin;
    preSecondMin = currSecondMin;
    preMinIndex = currMinIndex;
  }

  return preMin;
}

int main() {

}
