import 'package:flutter_test/flutter_test.dart';
import 'package:grind_75/btree_level_order_traversal/solution.dart';

main() {
  final Solution solution = Solution();
  test('empty tree', () {
    expect(solution.levelOrder(null), []);
  });

  test('tree with one node', () {
    final TreeNode root = TreeNode(1, null, null);

    expect(solution.levelOrder(root), [
      [1]
    ]);
  });

  test('tree with two nodes - left', () {
    final TreeNode nodeToLeft = TreeNode(2, null, null);
    final TreeNode root = TreeNode(1, nodeToLeft, null);

    expect(solution.levelOrder(root), [
      [1],
      [2]
    ]);
  });

  test('tree with two nodes - right', () {
    final TreeNode nodeToRight = TreeNode(2, null, null);
    final TreeNode root = TreeNode(1, null, nodeToRight);

    expect(solution.levelOrder(root), [
      [1],
      [2]
    ]);
  });

  test('tree with 3 levels with complete on right side', () {
    final TreeNode nodeSeven = TreeNode(7, null, null);
    final TreeNode nodeFifteen = TreeNode(15, null, null);

    final TreeNode nodeTwenyy = TreeNode(20, nodeFifteen, nodeSeven);
    final TreeNode nodeNine = TreeNode(9, null, null);

    final TreeNode root = TreeNode(3, nodeNine, nodeTwenyy);

    expect(solution.levelOrder(root), [
      [3],
      [9, 20],
      [15, 7]
    ]);
  });

  test('tree with 3 levels with complete on right side', () {
    final TreeNode nodeSeven = TreeNode(7, null, null);
    final TreeNode nodeFifteen = TreeNode(15, null, null);

    final TreeNode nodeTwenyy = TreeNode(20, nodeFifteen, null);
    final TreeNode nodeNine = TreeNode(9, nodeSeven, null);

    final TreeNode root = TreeNode(3, nodeNine, nodeTwenyy);

    expect(solution.levelOrder(root), [
      [3],
      [9, 20],
      [7, 15]
    ]);
  });
}
