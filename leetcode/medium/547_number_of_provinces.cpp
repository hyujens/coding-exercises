/*
 * There are n cities. Some of them are connected, while some are not. If city a
 * is connected directly with city b, and city b is connected directly with city
 * then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no other
 * cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * ith city and the jth city are directly connected, and isConnected[i][j] = 0
 * otherwise.
 *
 * Return the total number of provinces.
 */

#include <queue>
#include <unordered_set>
#include <vector>

int findCircleNum(std::vector<std::vector<int>> &isConnected) {
  std::unordered_set<int> processing;
  processing.reserve(isConnected.size());
  for (int i = 0; i < isConnected.size(); i++)
    processing.insert(i);

  int provinces = 0;
  while (!processing.empty()) {
    // record a new province
    provinces++;
    std::queue<int> queue;
    queue.push(*processing.begin());

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop();
      processing.erase(v);

      for (int i = 0; i < isConnected[v].size(); i++) {
        // if the connected node can not be found in processing set,
        // it means the node has been processed (visited).
        if (isConnected[v][i] == 1 && processing.find(i) != processing.end()) {
          queue.push(i);
        }
      }
    }
  }

  return provinces;
}

int improvedFindCircleNum(std::vector<std::vector<int>> &isConnected) {
  std::vector<bool> visited(isConnected.size(), false);

  int provinces = 0;
  for (int i = 0; i < visited.size(); i++) {
    if (visited[i])
      continue;

    std::queue<int> queue;
    queue.push(i);
    visited[i] = true;
    provinces++;

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop();

      for (int j = 0; j < isConnected[v].size(); j++) {
        if (isConnected[v][j] == 1 && visited[j] == false) {
          queue.push(j);
          visited[j] = true;
        }
      }
    }
  }

  return provinces;
}