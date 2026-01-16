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

  if (grid.size() == 0 || grid[0].size() == 0)
    return islands;

  const int dirs[4][2] = {
      {-1, 0}, // top
      {1, 0},  // buttom
      {0, -1}, // left
      {0, 1},  // right
  };

  // since passed value is a m x n matrix, it means we won't get various length
  // for each row or each column.
  int totalSizeInRow = grid.size();
  int totalSizeInColumn = grid[0].size();

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] != '1')
        continue;

      islands++;
      std::queue<std::pair<int, int>> queue;
      grid[i][j] = '2';
      queue.push({i, j});
      while (!queue.empty()) {
        auto v = queue.front();
        queue.pop();
        for (const auto &d : dirs) {
          int ni = v.first + d[0];
          int nj = v.second + d[1];
          if (ni >= 0 && ni < totalSizeInRow && nj >= 0 &&
              nj < totalSizeInColumn && grid[ni][nj] == '1') {
            grid[ni][nj] = '2';
            queue.push({ni, nj});
          }
        }
      }
    }
  }

  return islands;
}