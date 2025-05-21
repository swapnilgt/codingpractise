import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/longest_substring/solution.dart';

void main() {
  final Solution solution = Solution();

  test('first', () {
    expect(solution.lengthOfLongestSubstring(''), 0);
  });

  test('second', () {
    expect(solution.lengthOfLongestSubstring('a'), 1);
  });

  test('third', () {
    expect(solution.lengthOfLongestSubstring('bbbbb'), 1);
  });

  test('fourth', () {
    expect(solution.lengthOfLongestSubstring('abcabcbb'), 3);
  });

  test('fifth', () {
    expect(solution.lengthOfLongestSubstring('pwwkew'), 3);
  });

  test('sixth', () {
    expect(solution.lengthOfLongestSubstring('abcdefghij klmn o p'), 15);
  });

  test('seventh', () {
    expect(solution.lengthOfLongestSubstring('abcdefghij'), 10);
  });

  test('eight', () {
    expect(solution.lengthOfLongestSubstring('aabcdefghij'), 10);
  });

  test('ninth', () {
    expect(solution.lengthOfLongestSubstring('abcdefghijj'), 10);
  });

  test('ninth', () {
    expect(solution.lengthOfLongestSubstring('aaabcdefghijjj'), 10);
  });

  test('tenth', () {
    expect(solution.lengthOfLongestSubstring('dvdf'), 3);
  });
}
