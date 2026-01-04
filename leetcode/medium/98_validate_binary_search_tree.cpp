/*
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST). A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys strictly less than
 * the node's key.
 * - The right subtree of a node contains only nodes with keys strictly greater
 * than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 */
/*
 * Constraints:
 * 1) The number of nodes in the tree is in the range [1, 10^4].
 * 2) -2^31 <= Node.val <= 2^31 - 1
 */

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct Record {
  int *max;
  int *min;
  bool broken;
};

Record validationHelper(TreeNode *root) {
  if (root == nullptr)
    return Record{};

  Record right_record = validationHelper(root->right);
  Record left_record = validationHelper(root->left);

  if (right_record.broken || left_record.broken)
    return Record{nullptr, nullptr, true};

  if (right_record.min != nullptr && *right_record.min <= root->val)
    return Record{nullptr, nullptr, true};

  if (left_record.max != nullptr && *left_record.max >= root->val)
    return Record{nullptr, nullptr, true};

  Record new_record = Record{right_record.max, left_record.min, false};
  if (new_record.min == nullptr)
    new_record.min = &root->val;
  if (new_record.max == nullptr)
    new_record.max = &root->val;

  return new_record;
}

bool isValidBST(TreeNode *root) {
  Record record = validationHelper(root);
  return record.broken == false;
}