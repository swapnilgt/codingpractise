#include<iostream>
#include<deque>

using namespace std;


void getWindowMax(int arr[], int len, int k) {

  deque<int> maxStack;
  deque<int> indexStack;

  int index = 0;

  while (index < len) {
    while(!maxStack.empty() && maxStack.back() <= arr[index]) {
      cout << "!Popping " << maxStack.back() << " from the back " << endl;
      maxStack.pop_back();
      indexStack.pop_back();
    }

    // Removing the irrelevant elements ...
    while(!maxStack.empty() && index - indexStack.front() >= k) {
      cout << "#Popping " << maxStack.front() << " from the front " << endl;
      maxStack.pop_front();
      indexStack.pop_front();
    }

    cout << "Pushing " << arr[index] << endl;

    maxStack.push_back(arr[index]);
    indexStack.push_back(index);

    if(index >= k - 1) {
      cout << maxStack.front() << endl;
    }

    index++;

    cout << "########################" << endl;
  }

  cout << endl;
}


int main() {

  int arr[6] = {10, 5, 2, 7, 8, 7};

  getWindowMax(arr, 6, 3);

  return 0;

}
