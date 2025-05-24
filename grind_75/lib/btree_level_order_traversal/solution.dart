// ignore_for_file: public_member_api_docs, sort_constructors_first
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;

  TreeNode(this.val, this.left, this.right);
}

class Solution {
  List<List<int>> levelOrder(TreeNode? root) {
    final List<List<int>> retVal = [];

    // If the root is not present.
    if (root == null) {
      return retVal;
    }

    _levelOrderInternal(root, 0, retVal);

    return retVal;
  }

  void _levelOrderInternal(
      TreeNode currNode, int level, List<List<int>> retVal) {
    // Checking the size of the retVal list and adding the item if the item at
    // that level already exists.
    if (retVal.length >= level + 1) {
      // We alredy have the element at this level.
      retVal.elementAt(level).add(currNode.val);
    } else {
      // First element to be inserted at the current level.
      retVal.add([currNode.val]);
    }

    // Not.. getting the next set of elements and pushing to the queue.
    // And then recursing over it.

    // First iterating over the left.
    if (currNode.left != null) {
      _levelOrderInternal(currNode.left!, level + 1, retVal);
    }
    // Second iteration over the right.
    if (currNode.right != null) {
      _levelOrderInternal(currNode.right!, level + 1, retVal);
    }
  }
}
