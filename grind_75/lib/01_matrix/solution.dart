import 'package:flutter/material.dart';

class Pair {
  final int i;
  final int j;

  Pair({required this.i, required this.j});
}

class Solution {
  List<List<int>> _initIntegerMatrix(int numRows, int numCols, int defaultVal) {
    return List.generate(numRows, (_) => List.filled(numCols, defaultVal));
  }

  List<List<int>> updateMatrix(List<List<int>> mat) {
    // num rows.
    final int m = mat.length;
    // num columns.
    final int n = mat[0].length;
    // Edge case of one row and one column.
    if (m == 1 && n == 1) {
      return mat;
    }

    // Initialise everything to -1.
    final retVal = _initIntegerMatrix(m, n, -1);

    // Iterate over all the indices and start finding the smallest distance.
    final List<Pair> bfsQueue = [];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          retVal[i][j] = 0; // initialise the starting value with 0.
          bfsQueue.add(Pair(i: i, j: j)); // Adding the first set to the queue.
        }
      }
    }

    // Now running the bfs and assigning all the values.
    while (bfsQueue.isNotEmpty) {
      final frontElem = bfsQueue[0];
      // Removing the element at the front.
      bfsQueue.removeAt(0);

      // Noting the current distance.
      final currDist = retVal[frontElem.i][frontElem.j];

      debugPrint('Checking for node: at (${frontElem.i}, ${frontElem.j})');

      // Checking for element to the top.
      if (frontElem.i - 1 >= 0 && retVal[frontElem.i - 1][frontElem.j] == -1) {
        debugPrint(
            'Updating for element at the top: (${frontElem.i - 1}, ${frontElem.j})');
        retVal[frontElem.i - 1][frontElem.j] = currDist + 1;
        bfsQueue.add(Pair(i: frontElem.i - 1, j: frontElem.j));
      }
      // Checking for element to the bottom.
      if (frontElem.i + 1 < m && retVal[frontElem.i + 1][frontElem.j] == -1) {
        debugPrint(
            'Updating for element at the bottom: (${frontElem.i + 1}, ${frontElem.j})');
        retVal[frontElem.i + 1][frontElem.j] = currDist + 1;
        bfsQueue.add(Pair(i: frontElem.i + 1, j: frontElem.j));
      }
      // Checking for element to the left.
      if (frontElem.j - 1 >= 0 && retVal[frontElem.i][frontElem.j - 1] == -1) {
        debugPrint(
            'Updating for element at the left: (${frontElem.i}, ${frontElem.j - 1})');
        retVal[frontElem.i][frontElem.j - 1] = currDist + 1;
        bfsQueue.add(Pair(i: frontElem.i, j: frontElem.j - 1));
      }
      // Checking for element to the right.
      if (frontElem.j + 1 < n && retVal[frontElem.i][frontElem.j + 1] == -1) {
        debugPrint(
            'Updating for element at the right: (${frontElem.i}, ${frontElem.j + 1})');
        retVal[frontElem.i][frontElem.j + 1] = currDist + 1;
        bfsQueue.add(Pair(i: frontElem.i, j: frontElem.j + 1));
      }

      debugPrint("#######################################################");
    }

    // Iterating to get the list of indices for
    return retVal;
  }
}
