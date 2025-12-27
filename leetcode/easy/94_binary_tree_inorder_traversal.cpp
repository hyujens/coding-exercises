/*
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 */

#include <stack>
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

// 上面每一次都需要建立跟銷毀vector物件，會有performance問題。
// 所以這版本建立把vector傳進去的版本
void inorderTraversal(TreeNode *root, std::vector<int> &result) {
  if (root == nullptr)
    return;
  inorderTraversal(root->left, result);
  result.push_back(root->val);
  inorderTraversal(root->right, result);
}

std::vector<int> improvedInorderTraversal(TreeNode *root) {
  std::vector<int> result;
  inorderTraversal(root, result);
  return result;
}

std::vector<int> InorderTraversalIterativeVersion(TreeNode *root) {
  std::vector<int> result;
  std::stack<TreeNode *> st;
  TreeNode *curr = root;

  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    result.push_back(curr->val);
    curr = curr->right;
  }
  return result;
}