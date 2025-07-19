import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/search_rotated_array/solution.dart';

void main() {
  final Solution solution = Solution();

  test('test 1', () {
    expect(
      solution.search([4, 5, 6, 7, 0, 1, 2], 0),
      4,
    );
  });

  test('test 2', () {
    expect(
      solution.search([4, 5, 6, 7, 0, 1, 2], 3),
      -1,
    );
  });

  test('test 3', () {
    expect(
      solution.search([1], 0),
      -1,
    );
  });

  test('test 4', () {
    expect(
      solution.search([1], 1),
      0,
    );
  });

  test('test 5', () {
    expect(
      solution.search([1, 2, 3, 4, 5, 6], 4),
      3,
    );
  });

  test('test 6', () {
    expect(
      solution.search([1, 2, 3, 4, 5, 6], 7),
      -1,
    );
  });
}
