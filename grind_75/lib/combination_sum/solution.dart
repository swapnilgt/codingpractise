class MyListClass {
  final List<int> myList;

  MyListClass({required this.myList});

  @override
  bool operator ==(Object other) {
    other is MyListClass && this.myList.length == other.myList.length;
  }
}

class Solution {
  List<List<int>> combinationSum(List<int> candidates, int target) {
    final Set<List<int>> retVal = {};

    // Take the current element and still be open to take the current in the next loop.
    _combinationSum(
        candidates, target - candidates[0], retVal, [candidates[0]], 0);
    // Take the current element and not taking the current in the next loop.
    _combinationSum(
        candidates, target - candidates[0], retVal, [candidates[0]], 1);
    // Dont take the current and don't include in the next loop.
    _combinationSum(candidates, target, retVal, [], 1);

    return retVal.toList();
  }

  void _combinationSum(List<int> candidates, int currTarget,
      Set<List<int>> retVal, List<int> candidateList, int start) {
    if (currTarget == 0) {
      // We have found a candidate.
      retVal.add(candidateList);
      return;
    } else if (currTarget < 0) {
      // We have breached the total sum, hence returning.
      return; // Nothing to be done.
    }
    // CHeck if we have reached the end of the list.
    if (start == candidates.length) {
      return;
    }

    final List<int> newList1 = [];
    final List<int> newList2 = [];
    final List<int> newList3 = [];
    for (int j = 0; j < candidateList.length; j++) {
      newList1.add(candidateList[j]);

      newList2.add(candidateList[j]);

      newList3.add(candidateList[j]);
    }
    newList1.add(candidates[start]);
    newList2.add(candidates[start]);

    // Take the current element and still be open to take the current in the next loop.
    _combinationSum(
        candidates, currTarget - candidates[start], retVal, newList1, start);
    // Take the current element and not taking the current in the next loop.
    _combinationSum(candidates, currTarget - candidates[start], retVal,
        newList2, start + 1);
    // Dont take the current and don't include in the next loop.
    _combinationSum(candidates, currTarget, retVal, newList3, start + 1);
  }
}
