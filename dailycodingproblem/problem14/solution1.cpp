#include <iostream>
#include <cstdlib>

using namespace std;

float getPiValue() {
  int numIterations = 10000;
  int granularity = 1000;

  int insideSquares = 0;
  int insideCircle = 0;

  cout << "Num iterations are " << numIterations << endl;

  for (int i = 0; i < numIterations; i++) {
    float x = (((rand() * granularity) % granularity) * 1.0)/granularity;
    float y = (((rand() * granularity) % granularity) * 1.0)/granularity;

    float sumSquares = x * x + y * y;

    if(sumSquares <= 1) {
      insideCircle++;
    }
    insideSquares++;
  }

  return (4.0 * insideCircle)/insideSquares;
}

int main() {
  cout << "The pi value is " << getPiValue() << endl;
}
