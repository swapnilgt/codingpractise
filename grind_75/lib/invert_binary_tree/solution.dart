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
  TreeNode([this.val = 0, this.left, this.right]);
}

class Solution {
  TreeNode? invertTree(TreeNode? root) {
    if (root == null) {
      return null;
    }

    final TreeNode? left = root.left;
    final TreeNode? right = root.right;

    invertTree(left);
    invertTree(right);

    root.right = left;
    root.left = right;

    return root;
  }
}
