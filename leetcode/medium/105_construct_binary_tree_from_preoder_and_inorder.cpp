/*
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 */
/*
 * Constraints:
 * 1) 1 <= preorder.length <= 3000
 * 2) inorder.length == preorder.length
 * 3) -3000 <= preorder[i], inorder[i] <= 3000
 * 4) preorder and inorder consist of unique values.
 * 5) Each value of inorder also appears in preorder.
 * 6) preorder is guaranteed to be the preorder traversal of the tree.
 * 7) inorder is guaranteed to be the inorder traversal of the tree.
 */

#include <algorithm>
#include <cstddef>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void buildTreeRecursively(std::vector<int> &preorder, int &candidate,
                          std::vector<int> &inoder, int start, int end,
                          TreeNode **built) {
  if (start >= end)
    return;
  if (candidate >= preorder.size())
    return;
  TreeNode *elem = new (TreeNode);
  elem->val = preorder[candidate];
  *built = elem;
  int pos = std::find(inoder.begin(), inoder.end(), preorder[candidate]) -
            inoder.begin();

  candidate += 1;
  if (candidate >= preorder.size())
    return;

  if (pos > start) {
    buildTreeRecursively(preorder, candidate, inoder, start, pos, &elem->left);
  }
  if (pos < end) {
    buildTreeRecursively(preorder, candidate, inoder, pos + 1, end,
                         &elem->right);
  }
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  if (preorder.size() == 0)
    return nullptr;
  TreeNode *result = new (TreeNode);
  result->val = preorder[0];
  int pos =
      std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
  int candidate = 1;
  buildTreeRecursively(preorder, candidate, inorder, 0, pos, &result->left);
  buildTreeRecursively(preorder, candidate, inorder, pos + 1, preorder.size(),
                       &result->right);

  return result;
}