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

  if (records.find(node) != records.end())
    return records[node];

  Node *newNode = new (Node);
  newNode->val = node->val;
  records[node] = newNode;

  for (auto item : node->neighbors) {
    newNode->neighbors.push_back(cloneHelper(item, records));
  }

  return newNode;
}

Node *cloneGraph(Node *node) {
  std::unordered_map<Node *, Node *> records;
  Node *result = cloneHelper(node, records);

  return result;
}