/*
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 */
/*
 * Constraints:
 * 1. The number of nodes in the tree is in the range [0, 2000].
 * 2. -1000 <= Node.val <= 1000
 */

#include <algorithm>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> result;
  std::queue<TreeNode *> q;
  if (root == nullptr) {
    return result;
  }

  q.push(root);
  while (!q.empty()) {
    int handle_size = q.size();
    std::vector<int> found;
    found.reserve(handle_size);
    for (int i = 0; i < handle_size; i++) {
      TreeNode *v = q.front();
      q.pop();
      found.push_back(v->val);
      if (v->left != nullptr)
        q.push(v->left);
      if (v->right != nullptr)
        q.push(v->right);
    }

    result.push_back(std::move(found));
  }

  return result;
}