/*
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 */
/*
 * Constraints:
 *
 * 1. The number of nodes in the tree is in the range [0, 10^4].
 * 2. -100 <= Node.val <= 100
 */

#include <algorithm>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;

  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}