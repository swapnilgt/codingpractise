class Solution {
  int numIslands(List<List<String>> grid) {
    final int m = grid.length; // rows
    final int n = grid[0].length; //cols

    int numIslands = 0;
    List<List<int>> seen = List.filled(m, List.filled(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // Check if an index is already seen.
        if (seen[i][j] == 1) {
          continue;
        }
        if (grid[i][j] == "1") {
          numIslands++; // marking as seen and running dfs.
          _dfs(grid, seen, i, j);
        }
      }
    }

    return numIslands;
  }

  void _dfs(
    List<List<String>> grid,
    List<List<int>> seen,
    int row,
    int col,
  ) {
    final int m = grid.length; // rows
    final int n = grid[0].length; //cols

    List<List<int>> queue = [];
    // Adding the row and col to the queue.
    queue.add([row, col]);

    while (queue.isNotEmpty) {
      List<int> index = queue.removeAt(0);
      seen[index[0]][index[1]] = 1;

      int down = index[0] - 1;
      int up = index[0] + 1;
      int left = index[1] - 1;
      int right = index[1] + 1;

      // Checking if node on the down is not already
      // visited and it part of land.
      if (down >= 0 &&
          seen[down][index[1]] != 1 &&
          grid[down][index[1]] == "1") {
        queue.add([down, index[1]]);
      }

      // Checking if node on the up is not already
      // visited and it part of land.
      if (up < m && seen[up][index[1]] != 1 && grid[up][index[1]] == "1") {
        queue.add([up, index[1]]);
      }

      // Checking if node on the left is not already
      // visited and it part of land.
      if (left >= 0 &&
          seen[index[0]][left] != 1 &&
          grid[index[0]][left] == "1") {
        queue.add([index[0], left]);
      }

      // Checking if node on the right is not already
      // visited and it part of land.
      if (right < n &&
          seen[index[0]][right] != 1 &&
          grid[index[0]][right] == "1") {
        queue.add([index[0], right]);
      }
    }
  }
}
