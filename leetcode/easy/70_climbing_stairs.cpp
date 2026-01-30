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

int climbStairsHelp(int n, std::vector<int> &records) {
  if (records[n] != 0)
    return records[n];

  int val = climbStairsHelp(n - 1, records);
  val += records[n - 2];
  records[n] = val;

  return val;
}

int climbStairs(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  std::vector<int> records;
  records.reserve(n + 1);
  for (int i = 0; i <= n; i++)
    records.emplace_back(0);

  records[1] = 1;
  records[2] = 2;

  return climbStairsHelp(n, records);
}

int climbStairsV2(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  std::vector<int> records;
  records.reserve(n + 1);
  records.push_back(0);
  records.push_back(1);
  records.push_back(2);

  for (int i = 3; i <= n; i++) {
    records.push_back(records[i - 1] + records[i - 2]);
  }

  return records[n];
}

int climbStairsV3(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  // val_n_1 means (n - 1)th from nth elements
  int val_n_1 = 2;
  // val_n_2 means (n - 2)th from nth elements
  int val_n_2 = 1;
  int val = 0;
  for (int i = 3; i <= n; i++) {
    val = val_n_1 + val_n_2;
    val_n_2 = val_n_1;
    val_n_1 = val;
  }

  return val;
}