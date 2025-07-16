import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/rotting_oranges/solution.dart';

void main() {
  final Solution solution = Solution();

  test("test 1", () {
    expect(
        solution.orangesRotting([
          [2, 1, 1],
          [1, 1, 0],
          [0, 1, 1]
        ]),
        4);
  });

  test("test 2", () {
    expect(
        solution.orangesRotting([
          [2, 1, 1],
          [0, 1, 1],
          [1, 0, 1]
        ]),
        -1);
  });

  test("test 3", () {
    expect(
        solution.orangesRotting([
          [0, 2]
        ]),
        0);
  });
}
