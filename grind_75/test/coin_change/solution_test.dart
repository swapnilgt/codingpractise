import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/coin_change/solution.dart';

void main() {
  final Solution solution = Solution();
  test('first', () {
    expect(solution.coinChange([1, 2, 5], 11), 3);
  });

  test('second', () {
    expect(solution.coinChange([2], 3), -1);
  });

  test('third', () {
    expect(solution.coinChange([1], 0), 0);
  });

  test('fourth', () {
    expect(solution.coinChange([1, 2], 4), 2);
  });

  test('fifth', () {
    expect(solution.coinChange([1, 2], 3), 2);
  });

  test('sixth', () {
    expect(solution.coinChange([1, 2], 5), 3);
  });

  test('seventh', () {
    expect(solution.coinChange([1, 2], 6), 3);
  });

  test('eigth', () {
    expect(solution.coinChange([2, 5, 10, 1], 27), 4);
  });
}
