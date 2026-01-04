/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
 * in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 */
/*
 * Constraints:
 * 1) The number of nodes in the tree is in the range [2, 10^5].
 * 2) -10^9 <= Node.val <= 10^9
 * 3) All Node.val are unique.
 * 4) p != q
 * 5) p and q will exist in the tree.
 */

#include <cstddef>
#include <stack>
#include <unordered_map>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct Record {
  int level;
  TreeNode *parent;
};

void buildRecord(TreeNode *root, TreeNode *parent, int level,
                 std::unordered_map<TreeNode *, Record> &record) {
  if (root == nullptr)
    return;
  record[root] = Record{level, parent};
  buildRecord(root->right, root, level + 1, record);
  buildRecord(root->left, root, level + 1, record);
}

// 在這例子中，當10^5
// nodes在最糟情況是行程一直線。那麼會造成過深的recursion (超過c++預設的stack
// size)，這可能導致stack overflow。 因此這個function採用stack data
// structure來取代function recursion。
struct State {
  TreeNode *node;
  TreeNode *parent;
  int level;
};
void buildRecordWithStack(TreeNode *root, TreeNode *parent, int level,
                          std::unordered_map<TreeNode *, Record> &record) {
  std::stack<State> stk;
  stk.push({root, parent, level});

  // DFS
  while (!stk.empty()) {
    State current = stk.top();
    stk.pop();

    if (current.node == nullptr)
      continue;
    record[current.node] = Record{current.level, current.parent};
    if (current.node->right)
      stk.push({current.node->right, current.node, current.level + 1});
    if (current.node->left)
      stk.push({current.node->left, current.node, current.level + 1});
  }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  std::unordered_map<TreeNode *, Record> record;
  // buildRecord(root, nullptr, 0, record);
  buildRecordWithStack(root, nullptr, 0, record);
  while (true) {
    if (p == q)
      return p;
    auto p_record = record[p];
    auto q_record = record[q];

    if (p_record.parent == q_record.parent)
      return p_record.parent;

    if (p_record.level < q_record.level) {
      q = q_record.parent;
      continue;
    }
    if (p_record.level > q_record.level) {
      p = p_record.parent;
      continue;
    }

    p = p_record.parent;
    q = q_record.parent;
  }
}