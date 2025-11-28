/*
Given a string s, find the length of the longest substring without duplicate
characters.

constraints:
1) 0 <= s.length <= 5 * 10^4
2) s consists of English letters, digits, symbols and spaces.
*/

/*
Solution:
透過window sliding的想法，來找出最長的substring。
也就是說，當沒重複的時候，windows會擴大，直到找到重複為止。
而下一個windows的起點，就會從上一個重複點開始，並繼續擴大windows，直到下一個重複。
*/

#include <cstddef>
#include <string>
int lengthOfLongestSubstring(std::string s) {
  if (s.empty()) {
    return 0;
  }
  unsigned max = 0;
  size_t windows_start = 0, windows_end = 0;
  bool record[128] = {false};
  unsigned current = 0;
  while (windows_end < s.length()) {
    if (record[s[windows_end]]) {
      // repetition found and update max if current value is larger than the
      // last max.
      if (current > max)
        max = current;
      // clean up record and update current value for next finding.
      while (windows_start < windows_end) {
        auto char_to_remove = s[windows_start];
        record[char_to_remove] = false;
        windows_start++;
        current--;
        if (char_to_remove == s[windows_end])
          break;
      }
    }

    record[s[windows_end]] = true;
    windows_end++;
    current++;
  }

  if (current > max)
    max = current;

  return max;
}

int improvedLengthOfLongestSubstring(std::string s) {
  if (s.empty()) {
    return 0;
  }

  int max_len = 0;
  int start = 0;
  int last_seen[128];                        // 儲存每個字元最後出現的位置
  std::fill(last_seen, last_seen + 128, -1); // 初始化為 -1

  for (int end = 0; end < s.length(); end++) {
    char curr = s[end];

    // 如果當前字元在視窗內出現過，直接移動 start
    if (last_seen[curr] >= start) {
      start = last_seen[curr] + 1; // 跳到重複字元的下一個位置
    }

    last_seen[curr] = end;                        // 更新字元的最後位置
    max_len = std::max(max_len, end - start + 1); // 更新最大長度
  }

  return max_len;
}