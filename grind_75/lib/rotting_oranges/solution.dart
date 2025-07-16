class Solution {
  int orangesRotting(List<List<int>> grid) {
    final int rows = grid.length;
    final int cols = grid[0].length;

    // Need to run DFS starting with each
    List<List<int>> minDepth =
        List.generate(rows, (index) => List.filled(cols, 0));

    // * We need to run the depth thing starting with each rotten orange.
    // * We need to keep track of the highest depth reached so far.
    // * We need to keep track of the minimum depth possible for each node.
    // * We need to check if we can reach all the oranges.
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        // Check if we have a rotten orange at the given index.
        if (grid[row][col] == 2) {
          // Running DFS for each of these.
          _runDfs(grid, rows, cols, row, col, minDepth);
        }
      }
    }

    // a) Post running DFS, we need to get the maximum depth in the minDepth grid.
    // b) Check if none of the elements that is marked as fresh has a non-zero depth.
    int retVal = 0;
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        if (grid[row][col] == 1 && minDepth[row][col] == 0) {
          return -1; // We have found atleast one fresh orange that is not
          // reachable by rotten orance.
        }
        if (minDepth[row][col] > retVal) {
          retVal = minDepth[row][col];
        }
      }
    }

    return retVal;
  }

  void _runDfs(List<List<int>> grid, int rows, int cols, int i, int j,
      List<List<int>> minDepth) {
    List<List<int>> seen = List.generate(rows, (index) => List.filled(cols, 0));
    seen[i][j] = 1;

    final List<List<int>> queue = [];
    queue.add([i, j, 0]);

    while (queue.isNotEmpty) {
      final index = queue.removeAt(0);

      final left = index[1] - 1;
      final right = index[1] + 1;
      final up = index[0] + 1;
      final down = index[0] - 1;
      final currentDepth = index[2];

      // For the element at the left.
      if (left >= 0 && seen[index[0]][left] != 1 && grid[index[0]][left] == 1) {
        queue.add([index[0], left, currentDepth + 1]);
        seen[index[0]][left] = 1;
        if (minDepth[index[0]][left] == 0 ||
            minDepth[index[0]][left] > currentDepth + 1) {
          minDepth[index[0]][left] = currentDepth + 1;
        }
      }

      // For the element at the right.
      if (right < cols &&
          seen[index[0]][right] != 1 &&
          grid[index[0]][right] == 1) {
        queue.add([index[0], right, currentDepth + 1]);
        seen[index[0]][right] = 1;
        if (minDepth[index[0]][right] == 0 ||
            minDepth[index[0]][right] > currentDepth + 1) {
          minDepth[index[0]][right] = currentDepth + 1;
        }
      }

      // For the element at the down.
      if (down >= 0 && seen[down][index[1]] != 1 && grid[down][index[1]] == 1) {
        queue.add([down, index[1], currentDepth + 1]);
        seen[down][index[1]] = 1;
        if (minDepth[down][index[1]] == 0 ||
            minDepth[down][index[1]] > currentDepth + 1) {
          minDepth[down][index[1]] = currentDepth + 1;
        }
      }

      // For the element at the up.
      if (up < rows && seen[up][index[1]] != 1 && grid[up][index[1]] == 1) {
        queue.add([up, index[1], currentDepth + 1]);
        seen[up][index[1]] = 1;
        if (minDepth[up][index[1]] == 0 ||
            minDepth[up][index[1]] > currentDepth + 1) {
          minDepth[up][index[1]] = currentDepth + 1;
        }
      }
    }
  }
}
