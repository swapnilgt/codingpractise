import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/evaluate_reverse_polish/solution.dart';

void main() {
  final Solution solution = Solution();
  test('test 1', () {
    expect(solution.evalRPN(["2", "1", "+", "3", "*"]), 9);
  });

  test('test 2', () {
    expect(solution.evalRPN(["4", "13", "5", "/", "+"]), 6);
  });

  test('test 3', () {
    expect(
        solution.evalRPN([
          "10",
          "6",
          "9",
          "3",
          "+",
          "-11",
          "*",
          "/",
          "*",
          "17",
          "+",
          "5",
          "+"
        ]),
        22);
  });
}
