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
}
