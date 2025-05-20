import 'dart:math';

class Solution {
  List<List<int>> kClosest(List<List<int>> points, int k) {
    if (k == points.length) {
      return points;
    }

    // Getting the last non-left node.
    for (int i = (points.length / 2).floor() - 1; i >= 0; i--) {
      _heapify(points, points.length, i);
    }
    final List<List<int>> retVal = [];
    for (int i = k - 1; i >= 0; i--) {
      retVal.add(points[i]);
    }
    return retVal;
  }

  void _heapify(List<List<int>> points, int n, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    // Check with the left node.
    if (left < n &&
        _getDistance(points[left]) > _getDistance(points[largest])) {
      largest = left;
    }

    // Check with the right.
    if (right < n &&
        _getDistance(points[right]) > _getDistance(points[largest])) {
      largest = right;
    }

    // Swapping if needed.
    if (largest != i) {
      final List<int> temp = points[largest];
      points[largest] = points[i];
      points[i] = temp;
      _heapify(points, n, i);
    }
  }

  double _getDistance(List<int> point) {
    return sqrt(point[0] * point[0] + point[1] * point[1]);
  }
}
