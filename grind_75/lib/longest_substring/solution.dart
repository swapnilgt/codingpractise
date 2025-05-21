class Solution {
  int lengthOfLongestSubstring(String s) {
    if (s.length <= 1) return s.length;

    // Creating hashmap.
    List<int> map = List.filled(128, 0);
    int left = 0;
    int right = 0;
    int maxLength = 1;

    // Initializing the map with the first character.
    map[s.codeUnitAt(left)] = 1;

    while (right < s.length - 1) {
      // moving the right index to right by 1.
      right++;

      // Incrementing the count of the character at right.
      map[s.codeUnitAt(right)]++;

      // checking if this is the first found character in the window.
      if (map[s.codeUnitAt(right)] == 1) {
        // updating the maxLength.
        if (right - left + 1 > maxLength) {
          maxLength = right - left + 1;
        }
      }
      // Now moving the left length.
      else {
        while (left < right) {
          map[s.codeUnitAt(left)]--;
          left++;
          // If we have been able to set the character at the right index as 1
          // we break the loop.
          if (map[s.codeUnitAt(right)] == 1) {
            break;
          }
        }
      }
    }

    return maxLength;
  }
}
