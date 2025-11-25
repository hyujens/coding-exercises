/*
Given a string s, find the length of the longest substring without duplicate
characters.

constraints:
1) 0 <= s.length <= 5 * 10^4
2) s consists of English letters, digits, symbols and spaces.
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