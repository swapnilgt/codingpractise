#include<iostream>
#include "utils.h"

using namespace std;


int getNumWays(int N) {

  long long int numWays = 1;

  int twos = N/2;
  while(twos > 0) {
    int totalPos = twos + (N - twos * 2);
    numWays += Utils::nChoosek(totalPos, twos);
    twos = twos/2;
  }

  return numWays;
}

int main() {

  int N = 100;

  cout << "The result for " << N << " is " << getNumWays(N) << endl;

  return 0;
}
