import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/01_matrix/solution.dart';

void main() {
  final Solution solution = Solution();

  test('first', () {
    final result = solution.updateMatrix([
      [0, 0, 0],
      [0, 1, 0],
      [0, 0, 0]
    ]);

    expect(result, [
      [0, 0, 0],
      [0, 1, 0],
      [0, 0, 0]
    ]);
  });

  test('second', () {
    final result = solution.updateMatrix([
      [0, 0, 0],
      [0, 1, 0],
      [1, 1, 1]
    ]);

    expect(result, [
      [0, 0, 0],
      [0, 1, 0],
      [1, 2, 1]
    ]);
  });

  test('third', () {
    final result = solution.updateMatrix([
      [0],
      [0],
      [0],
      [0],
      [0]
    ]);

    expect(result, [
      [0],
      [0],
      [0],
      [0],
      [0]
    ]);
  });
}
