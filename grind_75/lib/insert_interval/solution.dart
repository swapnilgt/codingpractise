import 'dart:math';

class Solution {
  List<List<int>> insert(List<List<int>> intervals, List<int> newInterval) {
    List<List<int>> retVal = [];
    // Condition when there are no existing values.
    if (intervals.isEmpty) {
      retVal.add(newInterval);
      return retVal;
    }

    // Case when the newInterval is before the existing list.
    if (newInterval[1] < intervals[0][0]) {
      retVal.insert(0, newInterval);
      retVal.addAll(intervals);
      return retVal;
    }

    // Case when the newInterval is after the existing list.
    if (newInterval[0] > intervals[intervals.length - 1][1]) {
      retVal.addAll(intervals);
      retVal.add(newInterval);
      return retVal;
    }

    int leftMost = newInterval[0];
    int rightMost = newInterval[1];

    int currItem = 0;
    // Searching for the first end index in intervals that is greater than start index of the newInterval.
    // And we dont reach the end of the intervals.
    while (intervals[currItem][1] < newInterval[0]) {
      retVal.add(intervals[currItem]);
      currItem++;
    }

    leftMost = min(newInterval[0], intervals[currItem][0]);

    // This is to re-evaluate the last item that we had evaludated.
    // currItem--;

    // Now searching for the first start index intervals that is smaller than the end index of the newInterval.
    while (currItem < intervals.length &&
        intervals[currItem][0] <= newInterval[1]) {
      currItem++;
    }

    // In case we have not reached the end, then we set the rightmost.
    rightMost = max(newInterval[1], intervals[currItem - 1][1]);

    // Adding the item.
    retVal.add([leftMost, rightMost]);

    // Adding the rest of the items to the list.
    while (currItem < intervals.length) {
      retVal.add(intervals[currItem]);
      currItem++;
    }

    // Here, we might have the following different situations.
    /// Cases where start interval is smaller than the first element.
    /// a) intervals - (3, 6), (8, 9); newInterval (1, 2);
    /// a) intervals - (3, 6), (8, 9); newInterval (1, 3);
    /// b) intervals - (3, 6), (8, 9); newInterval (1, 4);
    /// c) intervals - (3, 6), (8, 9); newInterval (1, 7);
    /// d) intervals - (3, 6), (8, 9); newInterval (1, 9);
    /// e) intervals - (3, 6), (8, 9); newInterval (1, 10);
    ///
    /// Cases when start interval is same as the first element.
    /// a) intervals - (3, 6), (8, 9); newInterval (3, 3);
    /// b) intervals - (3, 6), (8, 9); newInterval (3, 4);
    /// c) intervals - (3, 6), (8, 9); newInterval (1, 7);
    /// d) intervals - (3, 6), (8, 9); newInterval (1, 9);
    /// e) intervals - (3, 6), (8, 9); newInterval (1, 10);

    ///
    return retVal;
  }
}

/// (3,6), (7, 9)
/// newInterval (1, 4)
/// newInterval (1, 3)
