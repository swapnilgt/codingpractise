import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/3sum/solution.dart';

void main() {
  final Solution solution = Solution();

  test('3 elems - sum 0', () {
    expect(solution.threeSum([0, 0, 0]), [
      [0, 0, 0]
    ]);
  });

  test('3 elems - sum non zero', () {
    expect(solution.threeSum([-1, -1, 0]), []);
  });

  test('third', () {
    expect(Set.from(solution.threeSum([-1, 0, 1, 2, -1, -4])), {
      [-1, -1, 2],
      [-1, 0, 1]
    });
  });

  test('fourth', () {
    expect(Set.from(solution.threeSum([-1, 0, 1, 2, -1, -4])), {
      [-1, -1, 2],
      [-1, 0, 1]
    });
  });
}
