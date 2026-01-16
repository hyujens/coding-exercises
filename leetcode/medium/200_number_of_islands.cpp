/*
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 */
#include <queue>
#include <utility>
#include <vector>
int numIslands(std::vector<std::vector<char>> &grid) {
  int islands = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] != '1')
        continue;

      islands++;
      std::queue<std::pair<int, int>> queue;
      grid[i][j] = '2';
      queue.push(std::pair<int, int>(i, j));
      while (!queue.empty()) {
        auto v = queue.front();
        queue.pop();
        // 1. check left
        if (v.second - 1 >= 0 && grid[v.first][v.second - 1] == '1') {
          grid[v.first][v.second - 1] = '2';
          queue.push(std::pair<int, int>(v.first, v.second - 1));
        }
        // 2. check right
        if (v.second + 1 < grid[v.first].size() &&
            grid[v.first][v.second + 1] == '1') {
          grid[v.first][v.second + 1] = '2';
          queue.push(std::pair<int, int>(v.first, v.second + 1));
        }
        // 3. check top
        if (v.first - 1 >= 0 && grid[v.first - 1][v.second] == '1') {
          grid[v.first - 1][v.second] = '2';
          queue.push(std::pair<int, int>(v.first - 1, v.second));
        }
        // 4. check buttom
        if (v.first + 1 < grid.size() && grid[v.first + 1][v.second] == '1') {
          grid[v.first + 1][v.second] = '2';
          queue.push(std::pair<int, int>(v.first + 1, v.second));
        }
      }
    }
  }

  return islands;
}