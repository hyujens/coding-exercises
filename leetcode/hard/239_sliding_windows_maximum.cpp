/*
You are given an array of integers `nums`, there is a sliding window of size `k`
which is moving from the very left of the array to the very right. You can only
see the `k` numbers in the window. Each time the sliding window moves right by
one position.

Return the max sliding window.

Constraints:

1) 1 <= nums.length <= 10^5
2) -10^ <= nums[i] <= 10^4
3) 1 <= k <= nums.length
*/
/*
Solution:
1. 在一開始`k` size的windows，建立最多k個不重複的list，從大到小塞到queue裡面。
2. 每次windows向右移動時，windows最右邊的element會跟queue的最右邊比較。
2-1. 如果queue最右邊比較小，移出queue，並塞到另一個stack結構。
2-2. 如果queue最右邊相等，直接drop。
2-3. 一路往左邊比對，直到比windows最右邊的大。
2-3-1. 接下來把stack的值，一個個塞回去，直到達到長度k。
3. 取出queue的最左邊。如果out of windows，
就drop，並往右找。直到找到，則為該windows最大。

PS. queue裡會紀錄(值, 值的index)
*/

#include <algorithm>
#include <deque>
#include <vector>

struct CandidateInfo {
  int val;
  int pos;
};

std::deque<CandidateInfo> get_candidates(std::vector<int> &nums,
                                         unsigned int k) {
  if (k > nums.size())
    k = nums.size();
  std::vector<CandidateInfo> tmp;
  tmp.reserve(k);

  for (int i = 0; i < k; i++) {
    tmp.push_back({nums[i], i});
  }

  std::sort(tmp.begin(), tmp.end(),
            [](const CandidateInfo &a, const CandidateInfo &b) {
              return a.val > b.val;
            });

  std::deque<CandidateInfo> result;
  for (auto candidate : tmp) {
    if (result.empty()) {
      result.push_back(candidate);
      continue;
    }

    auto item = result.back();
    if (candidate.pos < item.pos)
      continue;
    if (candidate.val < item.val)
      result.push_back(candidate);
    else {
      // since candidate is same as the item, only the item close to right will
      // be in queue.
      result.pop_back();
      result.push_back(candidate);
    }
  }

  return result;
}

std::vector<int> maxSlidingWindow(std::vector<int> &nums, unsigned int k) {
  if (nums.empty())
    return {};
  if (nums.size() <= 1 || k == 1) {
    return nums;
  }

  // prealloac the size since we know the length of the result.
  std::vector<int> result;
  int result_size = nums.size() - k + 1;
  result.reserve(result_size);

  auto candidates = get_candidates(nums, k);

  result.push_back(candidates.front().val);
  for (int i = 1; i < (nums.size() - k + 1); i++) {
    auto candidate = candidates.front();
    if (candidate.pos < i) {
      candidates.pop_front();
      candidate = candidates.front();
    }

    int the_most_right = k + i - 1;
    if (nums[the_most_right] >= candidate.val) {
      candidates.erase(candidates.begin(), candidates.end());
      candidates.push_back({nums[the_most_right], the_most_right});
      result.push_back(nums[the_most_right]);
      continue;
    }

    result.push_back(candidate.val);
    while (!candidates.empty()) {
      auto item = candidates.back();
      if (nums[the_most_right] >= item.val)
        candidates.pop_back();
      else {
        candidates.push_back({nums[the_most_right], the_most_right});
        break;
      }
    }

    if (candidates.empty()) {
      candidates.push_back({nums[the_most_right], the_most_right});
    }
  }

  return result;
}