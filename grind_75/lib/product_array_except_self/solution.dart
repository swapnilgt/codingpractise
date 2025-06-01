class Solution {
  List<int> productExceptSelf(List<int> nums) {
    final List<int> leftProd = List.filled(nums.length, 1);
    leftProd[0] = nums[0];

    final List<int> rightProd = List.filled(nums.length, 1);
    rightProd[nums.length - 1] = nums[nums.length - 1];

    final List<int> retVal = List.filled(nums.length, 1);

    for (int i = 1; i < nums.length; i++) {
      leftProd[i] = leftProd[i - 1] * nums[i];
      rightProd[nums.length - i - 1] =
          rightProd[nums.length - i] * nums[nums.length - i - 1];
    }

    for (int i = 0; i < nums.length; i++) {
      if (i == 0) {
        retVal[i] = rightProd[i + 1];
      } else if (i == nums.length - 1) {
        retVal[i] = leftProd[i - 1];
      } else {
        retVal[i] = rightProd[i + 1] * leftProd[i - 1];
      }
    }

    return retVal;
  }
}
