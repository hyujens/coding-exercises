/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Constraints:
1) nums1.length == m
2) nums2.length == n
3) 0 <= m <= 1000
4) 0 <= n <= 1000
5) 1 <= m + n <= 2000
6) -10^6 <= nums1[i], nums2[i] <= 10^6

核心概念：Binary Search on Partition Points (在分割點上做二分搜尋)
=================================================================

中位數的本質：
  - 將所有元素分成「左半部」和「右半部」
  - 左半部的所有元素 ≤ 右半部的所有元素
  - 兩半的數量平衡（相等或差1）

關鍵洞察：
  1. 我們不需要真的合併陣列
  2. 只需要找到正確的「分割點」
  3. 在較短的陣列上做二分搜尋 → O(log(min(m,n)))

分割示意圖：
  nums1: [1, 3, 8, 9]      分割在 i=2
         [1, 3] | [8, 9]

  nums2: [7, 11, 18, 19]   分割在 j=2
         [7, 11] | [18, 19]

  左半部: {1, 3, 7, 11}  (4個元素)
  右半部: {8, 9, 18, 19} (4個元素)

  檢查條件：
    - max(左半部) ≤ min(右半部)
    - 具體來說：nums1[i-1] ≤ nums2[j] && nums2[j-1] ≤ nums1[i]

時間複雜度：O(log(min(m, n)))
空間複雜度：O(1)

相關題型：
  - LeetCode #4: Median of Two Sorted Arrays (本題)
  - LeetCode #378: Kth Smallest Element in a Sorted Matrix
  - LeetCode #719: Find K-th Smallest Pair Distance
  - LeetCode #786: K-th Smallest Prime Fraction
  - 一般化：Find Kth Element in Two Sorted Arrays
*/

#include <algorithm> // for std::max, std::min
#include <climits>   // for INT_MIN, INT_MAX
#include <vector>

double findMedianSortedArrays(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
  // 優化：確保 nums1 是較短的陣列
  // 這樣可以減少搜尋空間，時間複雜度從 O(log(max)) 變成 O(log(min))
  if (nums1.size() > nums2.size()) {
    return findMedianSortedArrays(nums2, nums1);
  }

  int m = nums1.size();
  int n = nums2.size();

  int left = 0;
  int right = m;

  // 二分搜尋主迴圈
  while (left <= right) {
    // i: nums1 的分割點（左邊有 i 個元素）
    int i = (left + right) / 2;

    // j: nums2 的分割點（由 i 計算出來，確保左右平衡）
    // 平衡機制：無論 i 如何變化，i + j 恆等於 (m+n+1)/2
    //   - 初始: i = m/2, j = (m+n+1)/2 - m/2 ≈ n/2 (兩邊都從中間開始)
    //   - i 增加 → j 減少 (nums1左邊多拿，nums2左邊少拿)
    //   - i 減少 → j 增加 (nums1左邊少拿，nums2左邊多拿)
    //   - 總和不變，確保左半部總元素數 = (m+n+1)/2 (右半部也約等於此數)
    // (+1 是為了奇數長度時，多的元素放左邊)
    int j = (m + n + 1) / 2 - i;

    // 取得分割點左右的元素值
    // 邊界處理：用 INT_MIN/INT_MAX 處理陣列邊界

    // maxLeft1: nums1 左半部的最大值
    int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];

    // minRight1: nums1 右半部的最小值
    int minRight1 = (i == m) ? INT_MAX : nums1[i];

    // maxLeft2: nums2 左半部的最大值
    int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];

    // minRight2: nums2 右半部的最小值
    int minRight2 = (j == n) ? INT_MAX : nums2[j];

    // 檢查是否找到正確的分割點
    // 條件：左半部的最大值 ≤ 右半部的最小值
    if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
      // 找到正確分割！計算中位數

      // 總長度為偶數：中位數是左邊最大值和右邊最小值的平均
      if ((m + n) % 2 == 0) {
        return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) /
               2.0;
      }
      // 總長度為奇數：中位數是左邊的最大值
      else {
        return std::max(maxLeft1, maxLeft2);
      }
    }
    // nums1 的左邊太大了，需要往左搜尋（減小 i）
    else if (maxLeft1 > minRight2) {
      right = i - 1;
    }
    // nums1 的左邊太小了，需要往右搜尋（增大 i）
    else {
      left = i + 1;
    }
  }

  // 理論上不會執行到這裡（輸入保證有解）
  return 0.0;
}

/*
測試案例：
----------
1. nums1 = [1,3], nums2 = [2]
   輸出: 2.0

2. nums1 = [1,2], nums2 = [3,4]
   輸出: 2.5

3. nums1 = [], nums2 = [1]
   輸出: 1.0

4. nums1 = [1,3,8,9,15], nums2 = [7,11,18,19,21,25]
   輸出: 11.0

執行流程範例（案例4）：
---------------------
初始: m=5, n=6, 總長度=11（奇數）
左半部應有 (11+1)/2 = 6 個元素

迭代1: i=2, j=4
  nums1: [1,3] | [8,9,15]
  nums2: [7,11,18,19] | [21,25]
  maxLeft1=3, minRight2=21 ✓
  maxLeft2=19, minRight1=8 ✗ (19 > 8)
  → i 太小，left = i + 1 = 3

迭代2: i=4, j=2
  nums1: [1,3,8,9] | [15]
  nums2: [7,11] | [18,19,21,25]
  maxLeft1=9, minRight2=18 ✓
  maxLeft2=11, minRight1=15 ✓
  → 找到！中位數 = max(9,11) = 11

核心技巧總結：
============
1. 二分搜尋在「分割點」上，不是在「元素值」上
2. j 由 i 計算，確保左右平衡
3. 用 INT_MIN/INT_MAX 簡化邊界處理
4. 在較短陣列上搜尋，優化時間複雜度
*/