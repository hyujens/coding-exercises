/*
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i] =
 * [a_i, b_i] indicates that you must take course b_i first if you want to take
 * course a_i.
 *
 * - For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 * Return true if you can finish all courses. Otherwise, return false.
 */
/*
 * Constraints:
 * 1) 1 <= numCourses <= 2000
 * 2) 0 <= prerequisites.length <= 5000
 * 3) prerequisites[i].length == 2
 * 4) 0 <= a_i, b_i < numCourses
 * 5) All the pairs prerequisites[i] are unique.
 */

#include <unordered_set>
#include <vector>

// when cycle happens, it means it is not possible to finish courses.
// @startPoint specifies the search point
// @graph specifies the built graph of course relation
// @path specifies the current path we explore
// @visited records courses have been explored and we can skip to explore when
// the course has been visited.
bool isCycle(int startPoint, std::vector<std::vector<int>> &graph,
             std::unordered_set<int> &path, std::vector<bool> &visited) {
  path.insert(startPoint);
  visited[startPoint] = true;
  bool cycleFound = false;

  for (int i = 0; i < graph[startPoint].size(); i++) {
    if (graph[startPoint][i] == 0)
      continue;
    if (path.find(i) != path.end()) {
      cycleFound = true;
      break;
    }

    // 既然course不在path上，但曾經處理過。這表示在這course之後都處理過。
    // 因此，這必然不會有cycle，所以略過，並從鄰居開始找。
    if (visited[i])
      continue;

    cycleFound = isCycle(i, graph, path, visited);
    if (cycleFound)
      break;
  }

  path.erase(startPoint);
  return cycleFound;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  // build graph
  std::vector<std::vector<int>> graph(numCourses,
                                      std::vector<int>(numCourses, 0));
  for (auto courses : prerequisites) {
    // illegal course design
    if (courses.size() != 2)
      return false;
    graph[courses[0]][courses[1]] = 1;
  }

  std::vector<bool> visited(numCourses, false);
  std::unordered_set<int> path;

  for (int i = 0; i < visited.size(); i++) {
    if (visited[i])
      continue;

    bool cycleFound = isCycle(i, graph, path, visited);
    if (cycleFound)
      return false;
  }

  return true;
}