import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/k_closest_points_origin/solution.dart';

void main() {
  final Solution solution = Solution();

  test('first', () {
    expect(
        solution.kClosest([
          [1, 3],
          [-2, 2]
        ], 1),
        [
          [-2, 2]
        ]);
  });

  test('second', () {
    expect(
        solution.kClosest([
          [3, 3],
          [5, -1],
          [-2, 4]
        ], 2),
        [
          [3, 3],
          [-2, 4]
        ]);
  });

  test('third', () {
    expect(
        solution.kClosest([
          [68, 97],
          [34, -84],
          [60, 100],
          [2, 31],
          [-27, -38],
          [-73, -74],
          [-55, -39],
          [62, 91],
          [62, 92],
          [-57, -67]
        ], 5),
        [
          [2, 31],
          [-27, -38],
          [-55, -39],
          [-57, -67],
          [34, -84]
        ]);
  });
}
