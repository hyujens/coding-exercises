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

void dfs(TreeNode *node, int level, std::vector<std::vector<int>> &result) {
  if (!node) {
    return;
  }

  // 確保當前層級的 vector 已建立
  if (result.size() <= level) {
    result.push_back({});
  }

  result[level].push_back(node->val);

  dfs(node->left, level + 1, result);
  dfs(node->right, level + 1, result);
}

/**
 * DFS 版本實作 (使用遞迴)
 *
 * 為什麼 DFS 在 C++ LeetCode 環境中通常比 BFS 快?
 *
 * 1. 記憶體配置 (Memory Allocation):
 *    - BFS 使用 std::queue，底層通常是 std::deque。這需要多次在 Heap (堆積)
 * 上分配記憶體區塊。 記憶體分配 (malloc/new) 與釋放 (free/delete)
 * 是昂貴的系統操作。
 *    - DFS 使用 System Call Stack
 * (系統堆疊)。這是在已分配好的連續記憶體上移動指標， 成本極低 (Zero-overhead)。
 *
 * 2. 快取親和性 (Cache Locality):
 *    - DFS 存取 Stack 是連續的，對 CPU L1/L2 Cache 非常友善，Cache Hit率高。
 *    - BFS 的 Queue Node 散落在 Heap 各處，存取時容易造成 Cache Miss。
 */
std::vector<std::vector<int>> levelOrderWithDFS(TreeNode *root) {
  std::vector<std::vector<int>> result;
  dfs(root, 0, result);
  return result;
}