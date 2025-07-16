class Solution {
  int numIslands(List<List<String>> grid) {
    final int m = grid.length; // rows
    final int n = grid[0].length; //cols

    int numIslands = 0;
    List<List<int>> seen = List.generate(m, (_) => List.filled(n, 0));
    // print("## Seen initialized: $seen");

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // Check if an index is already seen.
        if (seen[i][j] == 1) {
          // print(
          //     "For i: $i, j: $j, seen: ${seen[i][j]}, hence skipping. !!! This should never happend with this.!!!}");
          continue;
        }
        if (grid[i][j] == "1") {
          // print(
          //     "For i: $i, j: $j, grid value is 1 and not seen yet, hence running dfs.");
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
    final List<int> indexToAdd = [row, col];
    queue.add(indexToAdd);
    seen[row][col] = 1;

    while (queue.isNotEmpty) {
      List<int> index = queue.removeAt(0);
      //print("Setting seen for index: $index");

      int down = index[0] - 1;
      int up = index[0] + 1;
      int left = index[1] - 1;
      int right = index[1] + 1;
      // print("m: $m, n: $n");
      // print(
      //     "@@@@ Checking for index: $index, down: $down, up: $up, left: $left, right: $right");

      // Checking if node on the down is not already
      // visited and it part of land.
      if (down >= 0 &&
          seen[down][index[1]] != 1 &&
          grid[down][index[1]] == "1") {
        //print("Adding down: ${down}, ${index[1]} to queue.");
        queue.add([down, index[1]]);
        seen[down][index[1]] = 1; // Marking as seen.
      }

      // Checking if node on the up is not already
      // visited and it part of land.
      if (up < m && seen[up][index[1]] != 1 && grid[up][index[1]] == "1") {
        //print("Adding up: ${up}, ${index[1]} to queue.");
        queue.add([up, index[1]]);
        seen[up][index[1]] = 1; // Marking as seen.
      }

      // Checking if node on the left is not already
      // visited and it part of land.
      if (left >= 0 &&
          seen[index[0]][left] != 1 &&
          grid[index[0]][left] == "1") {
        //print("Adding left: ${index[0]}, ${left} to queue.");
        queue.add([index[0], left]);
        seen[index[0]][left] = 1; // Marking as seen.
      }

      // Checking if node on the right is not already
      // visited and it part of land.
      if (right < n &&
          seen[index[0]][right] != 1 &&
          grid[index[0]][right] == "1") {
        //print("Adding right: ${index[0]}, ${right} to queue.");
        queue.add([index[0], right]);
        seen[index[0]][right] = 1; // Marking as seen.
      }

      //print("Queue: $queue, seen: $seen, for index: $index");
    }
  }
}
