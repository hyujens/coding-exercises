/*
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Constraints:
 *
 * 1) 1 <= n <= 45
 */

#include <vector>
std::vector<int> records;

int climbStairs(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  if (records.empty()) {
    // no initialization and let's make it.
    records.reserve(n + 1);
    for (int i = 0; i <= n; i++)
      records.emplace_back(0);

    records[1] = 1;
    records[2] = 2;
  }

  int val = climbStairs(n - 1);
  val += records[n - 2];
  records[n] = val;

  return val;
}