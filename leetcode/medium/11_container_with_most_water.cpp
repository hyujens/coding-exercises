/*
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.

**Notice** that you may not slant the container.

Constraints:

1) n == height.length
2) 2 <= n <= 10^5
3) 0 <= height[i] <= 10^4
*/

/*
思路：
- 要找出最大面積，長(x-axis)跟高(y-axis)要盡可能的大。 (Greedy stratergy)
  所以策略上，從x-axis兩端往中間逼近。
  - 面積計算: min(left_y, right_y) * (right_x - left_x)
- 兩點的高度可能會: 1. 不同高, 2. 同高
    - 不同高的，由最矮的點往中間移動。
      這是因為，如果最高移動，任何比最矮的高，面積計算還是以最矮的高度來看。
      所以不管如何，這樣的方式，無法找到最大。(x-axis縮小，但y-axis不會增加)
    - 如果同高，兩邊同時前進。
      這是因為，不管移哪邊，有比不移的高，不移的還是要移。
      如果都沒有，那之前就是最大。所以兩邊移動沒有影響。
*/

#include <vector>
int maxArea(std::vector<int> &height) { return 0; }