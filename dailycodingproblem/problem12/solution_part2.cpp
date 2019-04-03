#include<iostream>
#include "utils.h"

using namespace std;


int getNumWays(int N) {

  long long int numWays = 0;

  int totalPos = N-1;

  int toBeFilled = N-1;

  while(toBeFilled > 0) {
    numWays += Utils::nChoosek(totalPos, toBeFilled);
    toBeFilled--;
  }

  return numWays;
}

int main() {

  int N = 5;

  cout << "The result for " << N << " is " << getNumWays(N) << endl;

  return 0;
}
