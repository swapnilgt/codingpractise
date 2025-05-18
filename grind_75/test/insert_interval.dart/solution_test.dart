import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/insert_interval/solution.dart';

void main() {
  final solution = Solution();

  test('one', () {
    final result = solution.insert([
      [1, 3],
      [6, 9]
    ], [
      2,
      5
    ]);

    expect(result, [
      [1, 5],
      [6, 9]
    ]);
  });

  test('two', () {
    final result = solution.insert([
      [1, 2],
      [3, 5],
      [6, 7],
      [8, 10],
      [12, 16]
    ], [
      4,
      8
    ]);

    expect(result, [
      [1, 2],
      [3, 10],
      [12, 16]
    ]);
  });

  test('three', () {
    final result = solution.insert([
      [1, 2]
    ], [
      1,
      3
    ]);

    expect(result, [
      [1, 3]
    ]);
  });

  test('four', () {
    final result = solution.insert([
      [1, 2]
    ], [
      2,
      3
    ]);

    expect(result, [
      [1, 3]
    ]);
  });

  test('five', () {
    final result = solution.insert([
      [1, 2]
    ], [
      0,
      1
    ]);

    expect(result, [
      [0, 2]
    ]);
  });

  test('six', () {
    final result = solution.insert([
      [1, 2]
    ], [
      2,
      5
    ]);

    expect(result, [
      [1, 5]
    ]);
  });

  test('seven', () {
    final result = solution.insert([
      [2, 3],
      [4, 6],
      [7, 10]
    ], [
      1,
      10
    ]);

    expect(result, [
      [1, 10]
    ]);
  });

  test('eight', () {
    final result = solution.insert([
      [2, 3],
      [4, 6],
      [7, 10]
    ], [
      2,
      11
    ]);

    expect(result, [
      [2, 11]
    ]);
  });

  test('eight', () {
    final result = solution.insert([
      [2, 3],
      [4, 6],
      [7, 10]
    ], [
      2,
      10
    ]);

    expect(result, [
      [2, 10]
    ]);
  });
}
