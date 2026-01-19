# Introduction
這repo主要記錄programming的相關問題。主要目的是學習各種演算法與解題的技巧與思維。

# Roadmap
下面是各種問題類型跟各種技巧的相關leetcode題目。這些題目來自Claude Sonnet 4.5跟Gemini 3.

由於這list是由claude先提供，然後再由Gemini做增減，所以標示新增部分，是由Gemini建議加入。

1. 基礎資料結構 (8題)
此區重點：熟練掌握指針操作與基本容器特性

* [v] Array - Two Sum (1) - Hash table 基本應用
* [v] Sliding Window - Longest Substring Without Repeating (3) - 滑動窗口基礎
* [v] Two Pointers - Container With Most Water (11) - 雙指針思維
* [v] Linked List - Reverse Linked List (206) - 鏈表反轉基礎
* [v] Linked List - Linked List Cycle II (142) (新增) - 快慢指針與環的檢測
* [v] Stack - Valid Parentheses (20) - Stack 經典應用
* [v] Queue/Monotonic - Sliding Window Maximum (239) - 單調隊列
* [ ] Complex - Trapping Rain Water (42) (新增) - 雙指針/單調棧的綜合應用（魔王題）

2. 樹相關 (9題)
此區重點：遞迴思維與樹的遍歷順序

* [v] Traversal - Binary Tree Inorder (94) - 遍歷基礎
* [v] BFS - Binary Tree Level Order (102) - 層序遍歷
* [v] DFS - Maximum Depth of Binary Tree (104) - 深度優先
* [v] Reconstruct - Construct Binary Tree from Preorder and Inorder (105) (新增) - 遞迴重建樹
* [v] BST - Validate BST (98) - BST 性質驗證
* [v] LCA - Lowest Common Ancestor (236) - 最近公共祖先思維
* [ ] Serialize - Serialize and Deserialize Binary Tree (297) - 序列化技巧
* [v] Trie - Implement Trie (208) - 字典樹實作
* [ ] Segment Tree - Range Sum Query Mutable (307) - 線段樹（進階，時間不夠可跳過）

3. 圖論 (7題)
此區重點：圖的建立、遍歷與最短路徑

* [v] DFS/BFS - Number of Islands (200) - 網格圖遍歷
* [v] Graph Copy - Clone Graph (133) (新增) - 圖的深拷貝與映射
* [v] Union Find - Number of Provinces (547) - 並查集應用
* [v] Topological - Course Schedule (207) - 拓撲排序（檢測環）
* [ ] Dijkstra - Network Delay Time (743) - 單源最短路徑
* [ ] MST - Min Cost to Connect All Points (1584) - 最小生成樹 (Prim/Kruskal)
* [ ] Bipartite - Is Graph Bipartite (785) - 二分圖染色

4. 動態規劃 (13題)
此區重點：定義狀態 (State) 與 轉移方程 (Transition)

* [ ] 1D DP - Climbing Stairs (70) - DP 入門
* [ ] 1D DP - House Robber (198) - 非連續選擇
* [ ] Subarray - Maximum Product Subarray (152) (新增) - 雙狀態維護 (Min/Max)
* [ ] LIS - Longest Increasing Subsequence (300) - LIS 經典 O(NlogN)
* [ ] Knapsack 0/1 - Partition Equal Subset Sum (416) - 背包問題變體
* [ ] Knapsack Unbounded - Coin Change (322) - 完全背包/找零錢
* [ ] 2D DP - Unique Paths (62) - 網格路徑計數
* [ ] 2D DP - Edit Distance (72) - 兩個字串的編輯距離
* [ ] LCS - Longest Common Subsequence (1143) - 最長公共子序列
* [ ] Palindrome - Longest Palindromic Substring (5) - 中心擴展法或 DP
* [ ] Stock - Best Time to Buy and Sell Stock (121) - 買賣股票基礎
* [ ] Interval DP - Burst Balloons (312) - 區間 DP（高難度，重點在思維）
* [ ] Bitmask DP - Shortest Path Visiting All Nodes (847) - 狀態壓縮與 BFS 結合

5. 搜索與回溯 (8題)
此區重點：剪枝技巧與二分法的邊界控制

* [ ] Binary Search - Binary Search (704) - 二分搜索基礎
* [ ] Rotated BS - Search in Rotated Sorted Array (33) (新增) - 局部有序的二分搜索
* [ ] BS on Answer - Koko Eating Bananas (875) - 對答案進行二分
* [ ] Backtracking - Permutations (46) - 全排列
* [ ] Backtracking - Combinations (77) - 組合
* [ ] Backtracking - Subsets (78) - 子集
* [ ] Backtracking - N-Queens (51) - 棋盤類回溯
* [ ] Word Search - Word Search (79) - 網格內的 DFS 回溯

6. 貪心算法 (5題)
此區重點：局部最佳解如何導致全局最佳解

* [ ] Greedy - Jump Game (55) - 跳躍遊戲（覆蓋範圍）
* [ ] Interval - Merge Intervals (56) - 區間合併
* [ ] Interval - Meeting Rooms II (253) - 區間調度 / 掃描線
* [ ] Greedy - Gas Station (134) - 環形貪心 / 歸零思考
* [ ] Construct - Reorganize String (767) - 堆與貪心構造

7. 進階技巧 (11題)
此區重點：特定演算法優化與數學技巧

* [ ] Heap - Kth Largest Element (215) - Quick Select 或 Heap
* [ ] Heap - Merge K Sorted Lists (23) - 多路歸併
* [ ] Prefix Sum - Subarray Sum Equals K (560) - 前綴和 + Hash Map
* [ ] Prefix Sum (Mod) - Subarray Sums Divisible by K (974) (新增) - 前綴和 + 同餘定理
* [ ] Bit Manipulation - Single Number (136) - 異或 (XOR) 特性
* [ ] Math - Pow(x, n) (50) - 快速冪
* [ ] Sampling - Linked List Random Node (382) - 蓄水池抽樣
* [ ] String - Implement strStr (28) - KMP 或 Rabin-Karp (了解概念即可)
* [ ] Monotonic Stack - Largest Rectangle in Histogram (84) - 單調棧經典
* [ ] Design - LRU Cache (146) - Hash Map + Double Linked List
* [ ] Design - Min Stack (155) (新增) - 輔助堆疊設計

8. 特殊類型 (3題)
此區重點：矩陣操作與機率模擬

* [ ] Matrix - Rotate Image (48) - 原地旋轉矩陣
* [ ] Simulation - Spiral Matrix (54) - 螺旋矩陣模擬
* [ ] Probability - Random Pick with Weight (528) - 前綴和 + 二分搜索 (帶權隨機)

## AI建議
### Gemini
為了提高複習效率，建議將以下投資報酬率較低或過於冷門的題目移除或標註為選讀。
* String / DP
   * 刪除： Manacher Algorithm (in LC 5) - 面試中過於冷門且難以現場推導，建議僅保留中心擴展法。
* Game Theory
   * 刪除： Nim Game (292) - 屬於腦筋急轉彎，缺乏演算法通用性。
* Tree / Data Structure
   * 降低優先級： Range Sum Query Mutable (307) (Segment Tree) - 除非面試特定領域（如高頻交易），否則線段樹非必備，可用 Fenwick Tree 或其他方式替代。
* String
   * 調整： Implement strStr (28) (KMP) - 建議將重點放在 Rolling Hash (Rabin-Karp) 概念，KMP 完整實作在現代面試中出現率較低。

### Claude
這是claude根據Gemini的建議提供他的看法。

**完全同意的部分 ✅**
1. Manacher Algorithm - 同意移除

    面試中幾乎不會要求現場推導 Manacher。LC 5 用中心擴展法 O(n²) 或 DP 就夠了。
    如果真要 O(n)，面試官通常會接受「知道有 Manacher 但記不住細節」。

2. Nim Game (292) - 同意移除

3. Segment Tree (307) - 同意降低優先級

    清單已標註「時間不夠可跳過」，這很合理。建議至少理解概念，因為它代表「區間查詢」這類問題的思維。
    如果時間真的不夠，可以跳過實作細節。

**部分同意但有補充 ⚠️**
1. KMP / strStr (28)
    Gemini 建議改用 Rolling Hash，但我認為: 
    * 保留 KMP，理由:
        * Google/Meta仍會考KMP,尤其是高級職位。
        * KMP 的核心是「利用已匹配信息避免重複比對」，這個思維很重要。
        * Rolling Hash有hash collision風險，不是完美替代。
    * 實際建議:
        * 第一輪: 理解 KMP 的 `next` 陣列(或稱 `lps`)概念即可，不用背實作。
        * 如果這題標記為❌: 第二輪再深入練習，搭配 LC 214(Shortest Palindrome) 強化理解。
        * Rolling Hash可以額外了解，但不用取代KMP。

**我的額外補充建議**

優先級調整:

可以降低優先級的題目(如果時間真的很緊):

1. Reservoir Sampling (382) - 機率題,面試較少出現
2. Bitmask DP (847) - 狀態壓縮 DP 偏難,除非是競賽向公司

建議提高優先級(Gemini清單已經很好，但這兩個可以特別注意):

1. Trapping Rain Water (42) - 標註為魔王題是對的,這題綜合性很高
2. Clone Graph (133) - 圖的深拷貝在系統設計中很常見

**最終定案建議**

**必做 (不可跳過):**

* 基礎資料結構 (8題) - 全部
* 樹相關前 7 題 (跳過 Segment Tree)
* 圖論全部 (7題)
* DP 至少做 10 題 (Bitmask DP 可放最後)
* 搜索與回溯全部 (8題)
* 貪心全部 (5題)

**時間不夠可選做:**

* Segment Tree (307)
* Reservoir Sampling (382)
* Bitmask DP (847)

**關於 KMP:**

* 第一輪理解概念
* 如果你已經會 KMP,那就保留;如果完全不會,可以先跳過,第二輪再決定