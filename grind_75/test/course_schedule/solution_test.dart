import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/course_schedule/solution.dart';

void main() {
  final Solution solution = Solution();
  test("first", () {
    expect(
        solution.canFinish(2, [
          [1, 0]
        ]),
        true);
  });

  test("second", () {
    expect(
        solution.canFinish(2, [
          [1, 0],
          [0, 1]
        ]),
        false);
  });

  test("third", () {
    expect(
        solution.canFinish(2, [
          [0, 0],
          [1, 1]
        ]),
        false);
  });

  test("third", () {
    expect(
        solution.canFinish(2, [
          [0, 0],
          [1, 1]
        ]),
        false);
  });

  test("fourth", () {
    expect(
        solution.canFinish(1, [
          [0, 0]
        ]),
        false);
  });

  test("fifth", () {
    expect(solution.canFinish(1, []), true);
  });

  test("sixth", () {
    expect(
        solution.canFinish(7, [
          [1, 2],
          [2, 3],
          [3, 4],
          [4, 5],
          [5, 6],
          [3, 7],
          [7, 5]
        ]),
        true);
  });

  test("seventh", () {
    expect(
        solution.canFinish(10, [
          [1, 2],
          [2, 3],
          [3, 4],
          [4, 5],
          [5, 6],
          [3, 7],
          [7, 5],
          [8, 1],
          [8, 9],
          [9, 10],
          [10, 8]
        ]),
        false);
  });
}
