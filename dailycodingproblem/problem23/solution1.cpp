#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct NodeElem {
  NodeElem(pair<int, int> pointInp, int distInp): point(pointInp), dist(-1) {}
  pair<int, int> point;
  int dist;
};

void processNewPoint(pair<int, int> newPoint, int currCost, queue< pair<int, int> >& myQueue, vector< vector<int> >& dist,
  const vector< vector<char> >& map, const pair<int, int>& endPoint, int &minDistance) {

    dist[newPoint.first][newPoint.second] = currCost + 1;
    // Checking if we have reached the end ....
    if(newPoint == endPoint) {
      if(dist[newPoint.first][newPoint.second] < minDistance) {
        minDistance = dist[newPoint.first][newPoint.second];
      }
    } else {// Else we push it to the queue ....
      myQueue.push(newPoint);
    }
}

int getMinDistance(vector< vector<char> > map, pair<int, int> startPoint, pair<int, int> endPoint) {

  int numRows = map.size();
  int numCols = map[0].size();

  // Pushin all -1 in the distance matrices ...
  vector < vector<int> > dist(numRows);
  for(int i = 0; i < numRows; i++) {
    for(int j = 0; j < numCols; j++) {
      if(map[i][j] == 't') { // This is the wall ..
        dist[i].push_back(INT_MAX);
      } else { // Else marking with a -1 saying that we have not visited this yet ...
        dist[i].push_back(-1);
      }
    }
  }

  // Special case when the points are just next to each other ....
  if((startPoint.first == endPoint.first && abs(startPoint.second - endPoint.second) == 1) ||
      (startPoint.second == endPoint.second && abs(startPoint.first - endPoint.first) == 1)) {
        return 1;
      }

    // Queue for pushing vertices for the purpose of BFS ...
    queue< pair<int, int> > myQueue;

    // Initializing the minimum distance we have found so far ...
    int minDistance = INT_MAX;
    myQueue.push(startPoint);
    dist[startPoint.first][startPoint.second] = 0; // Initializing the distance as 0.

    while(!myQueue.empty()) {
      pair<int, int> nextPoint = myQueue.front();
      myQueue.pop(); // Getting the first element in the queue ...
      int currCost = dist[nextPoint.first][nextPoint.second];
      if(currCost < minDistance) { // Nothing to do from here now ...
        // Checking for the point up ...
        // Checking a) We have not reached the top and b) We have not already visited this node.
        if(nextPoint.second < numRows - 1 && dist[nextPoint.first][nextPoint.second + 1] == -1) {
          pair<int, int> newPoint(nextPoint.first, nextPoint.second + 1);
          processNewPoint(newPoint, currCost, myQueue, dist, map, endPoint, minDistance);
        }
        // Checking for the point to the down ...
        if(nextPoint.second > 0 && dist[nextPoint.first][nextPoint.second - 1] == -1) {
          pair<int, int> newPoint(nextPoint.first, nextPoint.second - 1);
          processNewPoint(newPoint, currCost, myQueue, dist, map, endPoint, minDistance);
        }

        // Checking for the point to the left ...
        if(nextPoint.first > 0 && dist[nextPoint.first - 1][nextPoint.second] == -1) {
          pair<int, int> newPoint(nextPoint.first - 1, nextPoint.second);
          processNewPoint(newPoint, currCost, myQueue, dist, map, endPoint, minDistance);
        }

        // Checking for the point to the right ...
        if(nextPoint.first != numCols-1 && dist[nextPoint.first + 1][nextPoint.second] == -1) {
          pair<int, int> newPoint(nextPoint.first - 1, nextPoint.second);
          processNewPoint(newPoint, currCost, myQueue, dist, map, endPoint, minDistance);
        }
      }
  }

  if(minDistance == INT_MAX) {
    return -1;
  } else {
    return minDistance;
  }
}

int main() {

  vector< vector<char> > map(4);
  for(int i = 0; i < map.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(i == 1 && (j == 0 || j ==1 || j == 2 || j == 3)) {
        map[i].push_back('t');
      } else {
        map[i].push_back('f');
      }
    }
  }

  pair<int,int> start(3,0);
  pair<int,int> end(0,0);

  int minDist = getMinDistance(map, start, end);

  cout << "The minimum distance is: " << minDist << endl;

}
