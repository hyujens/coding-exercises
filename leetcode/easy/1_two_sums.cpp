/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Constraints:

1) 2 <= nums.length <= 10^4
2) -10^9 <= nums[i] <= 10^9
3) -10^9 <= target <= 10^9
4) Only one valid answer exists.
*/
// Solution 1:
// 選一個element並與其他elements相加，看總和為target是否存在。
// 假設n個elements，那麼最糟是 n x (n - 1), O(n^2)
//
// Solution 2:
// 假設array size是n。
// 1. 先排序array，然後選第i個element。
// 2. 對第i+1到最後一個這段，透過二分法來尋找。
// 這邊要注意的是，當排序完後，原本位置就會打亂。
// 所以需要紀錄element跟位置，以便找到elements時，可回傳正確的位置。
// O(nlogn)
//
// Solution 3:
// 透過hash map的解決。
// 選第i個element，並計算(target - i)，把得到的值，檢查是否存在hash map。
// 如果沒有，計算的值當key，第i個elemnt的i作為value。

#include <vector>
std::vector<int> twoSum(std::vector<int> &nums, int target) {
  return std::vector<int>();
}