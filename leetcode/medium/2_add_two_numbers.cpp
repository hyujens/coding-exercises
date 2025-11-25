/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Constraints:

1) The number of nodes in each linked list is in the range [1, 100].
2) 0 <= Node.val <= 9
3) It is guaranteed that the list represents a number that does not have leading
zeros.
*/

// Solution:
// 定義p1 & p2分別指向l1 & l2, 跟leading, 用來判別是否已進位。
// 從p1 & p2一開始指的node做計算，如果大於9, 則leading = true。
// 再往下一個node處理時，leading = true，先加一，再計算。

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { return nullptr; }