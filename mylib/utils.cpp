#include <iostream>
#include <cmath>
#include "utils.h"

using namespace std;

int Utils::getIntFromChar(char input) {
  return input - 48;
}

long long int Utils::nChoosek(int n, int r) {
    if(r > n) {
        return 0;
    }

    if(n/2 < r) {
        r = n - r;
    }

    double res = 1.0;

    //cout << " n and c after possible changes are " << n << " " << r << endl;

    while(r >= 1) {

        //cout << " n and c for the iteration are " << n << " " << r << endl;

        res = res * (n * 1.0)/r;
        n--;
        r--;
    }

    //cout << "Combination of " << n << " and " << r << " is " << res << endl;

    return (long long int) round(res);
}
