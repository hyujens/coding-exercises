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

// version by Gemini 3 pro
// 加上 const 確保不修改輸入
int modernFindCircleNum(const std::vector<std::vector<int>> &isConnected) {
  if (isConnected.empty())
    return 0;

  const int n = isConnected.size();
  std::vector<bool> visited(n, false);
  int provinces = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i])
      continue;
    // 發現新省份
    provinces++;
    std::queue<int> q; // 改名 queue -> q
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      // 在這裡使用 const reference 避免複製 inner vector (雖 int vector
      // 複製不貴，但若是大物件就有差)
      const auto &neighbors = isConnected[v];

      for (int j = 0; j < n; ++j) {
        // 使用 !visited[j] 語法較直覺
        if (neighbors[j] == 1 && !visited[j]) {
          q.push(j);
          visited[j] = true;
        }
      }
    }
  }
  return provinces;
}