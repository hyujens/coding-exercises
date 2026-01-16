/*
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a value (int) and a list (List[Node]) of its
 * neighbors.
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

Node *cloneHelper(Node *node, std::unordered_map<Node *, Node *> &records) {
  if (node == nullptr)
    return nullptr;

  auto it = records.find(node);
  if (it != records.end())
    return it->second;

  Node *newNode = new Node(node->val);
  // 既然知道有多少elemets，預留空間，以避免觸發重新配置 (reallocation)與搬移。
  newNode->neighbors.reserve(node->neighbors.size());
  records[node] = newNode;

  for (auto item : node->neighbors) {
    newNode->neighbors.push_back(cloneHelper(item, records));
  }

  return newNode;
}

Node *cloneGraph(Node *node) {
  std::unordered_map<Node *, Node *> records;

  return cloneHelper(node, records);
}

void deleteGraph(Node *node) {
  if (node == nullptr)
    return;

  std::unordered_set<Node *> visited;
  // 用vector來追蹤是因為要收集所有要處理的節點
  // 如果用stack或queue，就會讓紀錄變得複雜
  std::vector<Node *> q;

  q.push_back(node);
  visited.insert(node);

  size_t head = 0; // 這是用來追蹤接下來要處理的node
  while (head < q.size()) {
    Node *curr = q[head];
    head += 1; // 下一個要處理的
    for (Node *neighbor : curr->neighbors) {
      if (visited.find(neighbor) == visited.end()) {
        // 第一次出現的node需要被處理
        visited.insert(neighbor);
        q.push_back(neighbor);
      }
    }
  }

  // 確認所有不重複的node
  // 可以安全移除
  for (Node *n : q)
    delete n;
}

void deleteGraphHelper(Node *node, std::unordered_set<Node *> &candidates) {
  if (node == nullptr || candidates.find(node) != candidates.end())
    return;

  candidates.insert(node);
  for (Node *item : node->neighbors) {
    if (candidates.find(item) == candidates.end())
      deleteGraphHelper(item, candidates);
  }
}

void deleteGraphV2(Node *node) {
  std::unordered_set<Node *> candidates;
  deleteGraphHelper(node, candidates);

  for (Node *n : candidates)
    delete n;
}