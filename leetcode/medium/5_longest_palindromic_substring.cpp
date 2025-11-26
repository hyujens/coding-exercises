/*
Given a string s, return the longest palindromic substring in s.

Constraints:
1) 1 <= s.length <= 1000
2) s consist of only digits and English letters.
*/

#include <cassert> // For assert
#include <string>
#include <vector> // For std::vector

// Solving with Dynamic Programming
/*
==================== DP 解法思維過程 ====================

動態規劃四步驟：

1. 定義狀態 (State Definition)
   dp[i][j] = s[i...j] 是否為回文
   - true:  s[i...j] 是回文
   - false: s[i...j] 不是回文

2. 狀態轉移方程 (State Transition)
   dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]

   解釋：s[i...j] 是回文，需要滿足兩個條件：
   - s[i] == s[j]  (首尾字符相同)
   - dp[i+1][j-1] == true (去掉首尾後仍是回文)

   特殊情況：
   - 長度 1: dp[i][i] = true (單字必為回文)
   - 長度 2: dp[i][i+1] = (s[i] == s[i+1])
   - 長度 3+: 用上述轉移方程

3. 初始化 (Initialization)
   - 所有長度為 1 的子串都是回文
   - 檢查所有長度為 2 的子串

4. 填表順序 (Filling Order)
   - 必須按照子串長度從小到大填表
   - 因為 dp[i][j] 依賴 dp[i+1][j-1] (更短的子串)

時間複雜度：O(n²) - 雙層迴圈
空間複雜度：O(n²) - 需要 n×n 的 2D 陣列
*/

std::string longestPalindromeWithDP(std::string s) {
  int n = s.length();
  if (n < 2)
    return s; // 長度 0 或 1 直接返回

  // 步驟 1: 創建 DP 表格
  // dp[i][j] 表示 s[i...j] 是否為回文
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

  // 記錄最長回文的起始位置和長度
  int maxLen = 1; // 至少有長度 1 的回文
  int start = 0;

  // 步驟 2: 初始化 - 所有長度為 1 的子串都是回文
  for (int i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  // 步驟 3: 按照長度填表 (從長度 2 開始)
  for (int len = 2; len <= n; len++) {
    // 枚舉起始位置 i
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1; // 結束位置

      // 狀態轉移
      if (s[i] == s[j]) {
        // 首尾字符相同
        if (len == 2) {
          // 長度為 2，直接判斷為回文
          dp[i][j] = true;
        } else {
          // 長度 >= 3，依賴 dp[i+1][j-1]
          dp[i][j] = dp[i + 1][j - 1];
        }

        // 更新最長回文
        if (dp[i][j] && len > maxLen) {
          maxLen = len;
          start = i;
        }
      }
      // 如果 s[i] != s[j]，dp[i][j] 保持 false
    }
  }

  return s.substr(start, maxLen);
}