import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/product_array_except_self/solution.dart';

void main() {
  final solution = Solution();

  test('first', () {
    expect(solution.productExceptSelf([1, 2, 3, 4]), [24, 12, 8, 6]);
  });

  test('second', () {
    expect(solution.productExceptSelf([-1, 1, 0, -3, 3]), [0, 0, 9, 0, 0]);
  });

  test('third', () {
    expect(solution.productExceptSelf([1, 0]), [0, 1]);
  });
}
