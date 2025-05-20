import 'dart:math';

// import 'package:flutter/material.dart';

class Solution {
  List<List<int>> kClosest(List<List<int>> points, int k) {
    if (k == points.length) {
      return points;
    }

    debugPrint("!!! Distance pre sort: !!!");
    _printPoints(points);

    // Getting the last non-left node.
    for (int i = (points.length / 2).floor() - 1; i >= 0; i--) {
      _heapify(points, points.length, i);
      // Printing post first iteration.
      debugPrint("Post i = $i");
      _printPoints(points);
    }

    debugPrint("### Distance post sort: ###");
    _printPoints(points);

    // Return value.
    final List<List<int>> retVal = [];

    //debugPrint("## heap: $points");

    // Taking the top k smallest items.
    for (int i = 1; i <= k; i++) {
      retVal.add(points[0]);
      points[0] = points[points.length - i];
      _heapify(points, points.length - i, 0);
    }
    return retVal;
  }

  void _printPoints(List<List<int>> points) {
    final List<double> distance = [];
    for (int i = 0; i < points.length; i++) {
      distance.add(_getDistance(points[i]));
    }
    debugPrint("$distance");
  }

  void _heapify(List<List<int>> points, int n, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int smallest = i;

    // Check with the left node.
    if (left < n &&
        _getDistance(points[left]) < _getDistance(points[smallest])) {
      smallest = left;
    }

    // Check with the right.
    if (right < n &&
        _getDistance(points[right]) < _getDistance(points[smallest])) {
      smallest = right;
    }

    // Swapping if needed.
    if (smallest != i) {
      final List<int> temp = points[smallest];
      points[smallest] = points[i];
      points[i] = temp;
      _heapify(points, n, smallest);
    }
  }

  double _getDistance(List<int> point) {
    return sqrt(point[0] * point[0] + point[1] * point[1]);
  }
}
