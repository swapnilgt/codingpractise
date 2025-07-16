import 'package:flutter_test/flutter_test.dart';

void main() {
  test("test", () {
    List<List<int>> seen = List.generate(3, (_) => List.filled(3, 0));

    seen[0][1] = 1;

    expect(seen, [
      [0, 1, 0],
      [0, 0, 0],
      [0, 0, 0]
    ]);
  });
}
