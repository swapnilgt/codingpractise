#include<iostream>
#include<utils.h>
#include<string>

using namespace std;


// Input array with number of rows and columns ...
int getNumDecodes(string s, int arr[], int size) {
  for(int i = 2; i <= size; i++) {
    arr[i] += arr[i-1]; // Adding the just previous one ..
    int doubleNumber = Utils::getIntFromChar(s.at(i-2)) * 10 + Utils::getIntFromChar(s.at(i-1)) ;
    cout << "The double number is " << doubleNumber << endl;
    if(doubleNumber <= 26) {
      arr[i] += arr[i - 2];
    }
  }

  return arr[size];
}

int main() {

  int arr[6] = {1,1,0,0,0,0};
  string input = "11111";

  cout << "The number of combinations are " << getNumDecodes(input, arr, 5) << endl;


  return 0;
}
