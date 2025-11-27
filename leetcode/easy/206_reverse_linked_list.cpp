/*
Given the head of a singly linked list, reverse the list, and return the
reversed list.

Constraints:
1) The number of nodes in the list is the range [0, 5000].
2) -5000 <= Node.val <= 5000
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *cur = head;

  while (cur != nullptr) {
    ListNode *temp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = temp;
  }

  return prev;
}