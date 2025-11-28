/*
Given the `head` of a linked list, return the node where the cycle begins. If
there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the `next` pointer. Internally, `pos` is
used to denote the index of the node that tail's next pointer is connected to
(0-indexed). It is `-1` if there is no cycle. **Note that** `pos` is not passed
as a parameter.

**Do not modify** the linked list.
*/
/*
Solution 1.
    利用set，把經過的node的memory address存下來。
可以利用Node存不存在來確認是否有cycle發生。 Time Complexity: O(n) Space
Complexity: O(n)

Solution 2. Floyd's cycle detection
    這是利用指針的移動速度來偵測是否有cycle。基本想法在於有cycle發生時，兩指針必然會相遇，
因為速度快的會追上。這是由於cycle的特性。
    那麼速度要怎麼選擇呢?
就數學上的意義，兩者速度都可以任意選擇，但一般會是，一個前進一步，一個前進兩步。
這樣的選擇來自於實作上的簡單跟好計算。 所以接下來要怎麼回傳cycle的起點呢?
下面會用推導方式來說明。

[-----------------------][----|----]
           a             ^  b    c |
                         |         |
                         |_________|

假設 a 是 head到
cycle起點，b是cycle起點到相遇點，c則是相遇點往前走回到cycle起點。 假設fast
pointer選擇一次走兩步，slow pointer一次一步。那麼:
- slow pointer到相遇點就走了 a + b
- fast pointer跟slow pointer在相遇點碰到，要走 a + b + n(c + b)。
  也就是說，fast pointer 走的總距離等於 Slow pointer 走的距離 (a + b) 加上 n
  圈的 cycle 長度 (c + b)。

既然fast pointer是slow pointer的兩倍快，那麼fast pointer走的距離就是slow
pointer的兩倍，因此fast pointer走的步數:
2 * (a + b) = a + b + n * (c + b)
=> 2a + 2b = a + b + n * (b + c)
=> a + b = n * (b + c)
=> a = n * (b + c) - b
=> a = n * (b + c) - b - c + c = n * (b + c) - (b + c) + c
=> a = (n - 1) * (b + c) + c

從這算式可以發現，走了a步相當於，相遇點往前走c步，之後再走(n - 1)圈。
因此我們就可以知道，需要有一個pointer走a步，由於不知道a不多長，所以需要另一個pointer在相遇點同時跑，
直到兩個pointers指向同一個。

最後，當找到cycle時，就可以把fast pointer移到最前面，然後改成跟slow
pointer一樣快。 這樣就能找到cycle起始點了。
*/

#include <cstddef>
#include <unordered_set>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycleWithSet(ListNode *head) {
  std::unordered_set<ListNode *> visited;
  ListNode *cur = head;
  while (cur) {
    if (visited.count(cur)) {
      return cur;
    }

    visited.insert(cur);
    cur = cur->next;
  }

  return nullptr;
}

ListNode *detectCycleWithFloydAlg(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  // slow_ptr takes one step to move, and fast_ptr takes two steps to move
  auto slow_ptr = head;
  auto fast_ptr = head;
  while (fast_ptr != nullptr) {
    slow_ptr = slow_ptr->next;

    // Take one step first to avoid null pointer
    fast_ptr = fast_ptr->next;
    if (fast_ptr != nullptr) {
      fast_ptr = fast_ptr->next;
    }

    if (slow_ptr == fast_ptr)
      break;
  }

  if (fast_ptr == nullptr) {
    return nullptr;
  }

  fast_ptr = head;
  while (fast_ptr != slow_ptr) {
    fast_ptr = fast_ptr->next;
    slow_ptr = slow_ptr->next;
  }

  return slow_ptr;
}