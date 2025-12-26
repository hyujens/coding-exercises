/*
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 */

#include <vector>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return std::vector<int>();

  auto result = inorderTraversal(root->left);
  result.push_back(root->val);
  auto right_result = inorderTraversal(root->right);
  result.insert(result.end(), right_result.begin(), right_result.end());
  return result;
}