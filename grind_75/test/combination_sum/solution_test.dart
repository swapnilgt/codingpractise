import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/combination_sum/solution.dart';

void main() {
  final Solution solution = Solution();

  test(
    'test 1',
    () {
      expect(
        solution.combinationSum([2, 3, 6, 7], 7),
        [
          [2, 2, 3],
          [7]
        ],
      );
    },
  );
}
