// ignore_for_file: public_member_api_docs, sort_constructors_first
class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}
// [1,null,1]

class Solution {
  static int possiblemin = -0x8000000000000000;
  static int possiblemax = 0x7FFFFFFFFFFFFFFF;

  bool isValidBST(TreeNode? root) {
    return _isValidBst(root).valid;
  }

  InternalObj _isValidBst(TreeNode? root) {
    if (root == null) {
      return InternalObj(min: null, max: null, valid: true);
    }
    final leftObj = _isValidBst(root.left);
    final rightObj = _isValidBst(root.right);

    if (leftObj.valid == false ||
        rightObj.valid == false ||
        (leftObj.max != null && leftObj.max! >= root.val) ||
        (rightObj.min != null && rightObj.min! <= root.val)) {
      return InternalObj(min: null, max: null, valid: false);
    }

    return InternalObj(
        min: leftObj.min ?? root.val,
        max: rightObj.max ?? root.val,
        valid: true);
  }
}

class InternalObj {
  int? min;
  int? max;
  bool valid;

  InternalObj({
    required this.min,
    required this.max,
    required this.valid,
  });
}
