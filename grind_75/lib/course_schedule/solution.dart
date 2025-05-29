class Solution {
  bool canFinish(int numCourses, List<List<int>> prerequisites) {
    // In case the number of courses are 1.
    if (numCourses == 1) {
      if (prerequisites.isEmpty) {
        return true;
      }
    }

    Map<int, List<int>> adj = {}; // adjacency matrix.
    List<int> visited = List.filled(2000, 0);
    List<int> pathVisited = List.filled(2000, 0);

    // Prepare the adjacency list.
    for (int i = 0; i < prerequisites.length; i++) {
      // If we already have adjacency list created, just adding to it.
      if (adj.containsKey(prerequisites[i][0])) {
        adj[prerequisites[i][0]]!.add(prerequisites[i][1]);
      } else {
        // else adding a new list with the required element.
        adj[prerequisites[i][0]] = [prerequisites[i][1]];
      }
    }

    // Now running, DFS for each element.
    for (int i = 0; i < numCourses; i++) {
      if (visited[i] == 1) {
        // If a node is already visited, then skip.
        continue;
      }
      visited[i] = 1;
      pathVisited[i] = 1;
      bool foundLoop = _runDfsAndFindLoop(i, adj, visited, pathVisited);
      if (foundLoop) {
        return false;
      }
      pathVisited[i] = 0; // Resetting the path visited.
    }

    return true;
  }

  bool _runDfsAndFindLoop(
    int courseNum,
    Map<int, List<int>> adj,
    List<int> visited,
    List<int> pathVisited,
  ) {
    if (adj[courseNum] == null) return false; // There is no adjacency list.
    final currAdjList = adj[courseNum]!;
    for (int i = 0; i < currAdjList.length; i++) {
      final adjVal = currAdjList[i];
      // We have a loop.
      if (pathVisited[adjVal] == 1) {
        return true;
      }
      if (visited[adjVal] == 1) {
        // We have alredy visited this node, so no need to visit again.
        continue;
      }

      visited[adjVal] = 1;
      pathVisited[adjVal] = 1;
      bool foundLoop = _runDfsAndFindLoop(adjVal, adj, visited, pathVisited);
      if (foundLoop) {
        // If found path in the downstream.
        return true;
      }
      pathVisited[adjVal] = 0; // Marking path seen as 0
    }
    return false;
  }
}
