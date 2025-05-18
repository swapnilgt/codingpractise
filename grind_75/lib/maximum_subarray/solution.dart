import 'dart:ffi';

class Solution {
  int maxSubArray(List<int> nums) {
    if (nums.length == 1) return nums[0];

    int maxSum = -9223372036854775808;

    int currentSum = 0;

    for (int i = 0; i < nums.length; i++) {
      currentSum = currentSum + nums[i];

      if (currentSum > maxSum) {
        maxSum = currentSum;
      }

      if (currentSum <= 0) {
        currentSum = 0;
      }
    }

    return maxSum;
  }
}
