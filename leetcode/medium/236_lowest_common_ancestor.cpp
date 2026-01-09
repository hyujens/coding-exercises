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
#include <unordered_set>
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

// ======= optimization 1
// 1. Early stop: 只要找到 p 和 q 就可以停止
// 2. 先從 p 往上走，將路徑上的節點存入一個 HashSet。接著從 q
// 往上走，遇到的第一個存在於 Set 中的節點即為 LCA。
void buildRecordEarlyStop(TreeNode *root, TreeNode *p, TreeNode *q,
                          std::unordered_map<TreeNode *, TreeNode *> &record) {
  record[root] = nullptr;
  std::stack<TreeNode *> stk;
  stk.push(root);
  while (!stk.empty()) {
    TreeNode *current = stk.top();
    stk.pop();
    if (current->left != nullptr) {
      record[current->left] = current;
      stk.push(current->left);
    }
    if (current->right != nullptr) {
      record[current->right] = current;
      stk.push(current->right);
    }

    // 只有都找到才停止。如果停止其一節點，會導致這節點以下都不會去探索。
    if (record.find(p) != record.end() && record.find(q) != record.end())
      return;
  }
}

TreeNode *lowestCommonAncestorV1(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (p == nullptr || q == nullptr)
    return nullptr;
  std::unordered_map<TreeNode *, TreeNode *> record;
  buildRecordEarlyStop(root, p, q, record);
  TreeNode *result = nullptr;
  std::unordered_set<TreeNode *> traversed;

  while (p != nullptr) {
    traversed.insert(p);
    p = record[p];
  }

  while (q != nullptr) {
    if (traversed.count(q) != 0) {
      result = q;
      break;
    }

    q = record[q];
  }

  return result;
}

// ======= optimization 2
// 這個解法比較巧思。需要透過遞回來解。
// 如果找到p就回傳p，找q就回傳q。
// 因此，在遞回呼叫function。一定會在某一level得到p跟q個出現在左右。
// 根據題目，p跟q都是有效的情況，最糟情況就是在root找到。
TreeNode *lowestCommonAncestorV2(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr)
    return nullptr;
  if (root == p)
    return p;
  if (root == q)
    return q;

  TreeNode *left = lowestCommonAncestorV2(root->left, p, q);
  TreeNode *right = lowestCommonAncestorV2(root->right, p, q);
  // 如果左右非null，表示一定有找到p & q。
  if (left && right)
    return root;

  if (left != nullptr)
    return left;
  return right;
}