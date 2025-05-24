class Solution {
  List<List<int>> threeSum(List<int> nums) {
    // CHecking for the edge case.
    if (nums.length == 3) {
      if (nums[0] + nums[1] + nums[2] == 0) {
        return [nums];
      }
      return [];
    }

    // Sorting the list.
    nums.sort();
    // Map to check if an existing combination already exists.
    final Set<String> seen = {};

    // Initialising the final result that needs to be returned.
    final List<List<int>> retVal = [];

    for (int pos = 0; pos < nums.length - 2; pos++) {
      _find0Sums(nums, nums[pos], pos + 1, nums.length - 1, seen, retVal);
    }

    // Returning the ffinal value/
    return retVal;
  }

  void _find0Sums(List<int> nums, int currVal, int start, int end,
      Set<String> seen, List<List<int>> retVal) {
    while (start < end) {
      // Checking if the sum is a 0.
      if (nums[start] + nums[end] + currVal == 0) {
        final String key = "$currVal;${nums[start]};${nums[end]}";
        // CHecking if this combination is alredy seen.
        if (!seen.contains(key)) {
          retVal.add([currVal, nums[start], nums[end]]);
          seen.add(key);
        }
        start++;
        end--;
      } else if (nums[start] + nums[end] + currVal < 0) {
        start++;
      } else {
        end--;
      }
    }
  }
}
