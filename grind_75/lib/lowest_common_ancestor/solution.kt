/**
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int = 0) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

data class ResultObj(var foundP: Boolean, var foundQ: Boolean)

class Solution {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {

      return _lca(root, p, q, ResultObj(false, false)).second;
        
    }

    fun _lca(root: TreeNode?, p: TreeNode?, q: TreeNode?, resultObj: ResultObj): Pair<ResultObj, TreeNode?> {
      if(root == null) {
        return Pair(resultObj, null);
      }

      // Check for the found left and found right first.
      val leftResult = _lca(root?.left, p, q, resultObj.copy());
      val rightResult = _lca(root?.right, p, q, resultObj.copy());

      if(leftResult.second != null) {
        return Pair(ResultObj(true, true), leftResult.second);
      } else if(rightResult.second != null) {
        return Pair(ResultObj(true, true), rightResult.second);
      } else if((leftResult.first.foundP || rightResult.first.foundP || p?.`val` == root.`val`)
       && (leftResult.first.foundQ || rightResult.first.foundQ || q?.`val` == root.`val`)) { // Current node is the answer
        return Pair(ResultObj(true, true), root);
      }

      var currFoundP = false;
      var currFoundQ = false;

      if(p?.`val` == root.`val`) {
        currFoundP = true;
      } else if(q?.`val` == root.`val`) {
        currFoundQ = true;
      }

      return Pair(ResultObj(
        currFoundP || leftResult.first.foundP || rightResult.first.foundP,
        currFoundQ || leftResult.first.foundQ || rightResult.first.foundQ,
      ), null);

    }
}