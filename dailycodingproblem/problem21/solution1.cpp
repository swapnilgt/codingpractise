#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool myCompare(const pair<int, int> &a, const pair <int, int> &b) {
  if(a.first < b.first) {
    return true;
  } else if(a.first > b.first) {
    return false;
  } else if(b.second < b.second) {
    return true;
  } else {
    return false;
  }
}

int calculateMinRooms(vector< pair<int, int> > slots) {

  // first sorting the slots based on the start time and end time ....
  sort(slots.begin(), slots.end(), myCompare);

  for(int i=0; i < slots.size(); i++) {
    cout << "Element is: " << slots[i].first << "," << slots[i].second << endl;
  }

  int retVal = 0;

  while(!slots.empty()) {

      pair<int, int> currCompSlot = slots[0];
      slots.erase(slots.begin()); // Removing the first element ...

      //cout << "Picking the first slot as: " <<

      int i = 0; // Now .. iterating over the left elements ...
      while(!slots.empty() && i < slots.size()) {
        if(slots[i].first > currCompSlot.second) {
          currCompSlot = slots[i];
          slots.erase(slots.begin() + i);
        } else {
          i++;
        }
      }

      retVal++; // WE have found one non - overlap grouping ..
  }

  return retVal;
}

int main() {

  vector< pair<int, int> > myVector;

  pair<int, int> first(0, 10);
  pair<int, int> second(20, 80);
  pair<int, int> third(30, 40);
  pair<int, int> fourth(50, 60);

  myVector.push_back(first);
  myVector.push_back(second);
  myVector.push_back(third);
  myVector.push_back(fourth);

  int result = calculateMinRooms(myVector);

  cout << "Result is " << result << endl;

}
