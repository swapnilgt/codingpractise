class Solution {
  int search(List<int> nums, int target) {
    int left = 0;
    int right = nums.length - 1;

    while (left <= right) {
      final int mid = ((left + right) / 2).floor();
      //print("##### Iteration ########");

      if (nums[mid] == target) {
        return mid;
      }
      //print("Mid is: $mid");

      // If the mid is smaller than the target.
      if (nums[mid] < target) {
        // print(
        //     "& Mid is smaller than the target. Ideally we should look into the right ....");
        if (nums[right] >= target || nums[mid] > nums[right]) {
          //print("&& Right part is sorted, else looking into right ...");
          left = mid + 1;
        } else {
          // print(
          //     "&& Element can be found only in the left.. so going towards the left ....");
          right = mid - 1;
        }
      } else {
        // print(
        //     "@ Mid is larger than the target. Ideally we should look into the left ....");
        if (nums[left] <= target || nums[mid] < nums[left]) {
          //print("@@ Left part is sorted .... hence looking into left");
          right = mid - 1;
        } else {
          // print(
          //     "@@ Element can only be found in the right, hence looking into the right ...");
          left = mid + 1;
        }
      }
    }

    return -1;
  }
}
