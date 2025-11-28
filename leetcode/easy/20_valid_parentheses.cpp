/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

1) 1 <= s.length <= 10^4
2) s consists of parentheses only '()[]{}'.

Solution:
採用stack。如果'(', '{', '['就加到stack，否則就從stack取出來，看有沒有成對。
*/

#include <stack>
#include <string>

char get_left_parentheses(char right) {
  switch (right) {
  case ')':
    return '(';
  case '}':
    return '{';
  case ']':
    return '[';
  }

  return char(0);
}

bool isValid(const std::string &s) {
  if (s.size() % 2 != 0) {
    return false;
  }
  std::stack<char> container;

  for (char c : s) {
    switch (c) {
    case '(':
    case '{':
    case '[':
      container.push(c);
      break;
    default: {
      if (container.empty())
        return false;

      auto v = container.top();
      container.pop();
      if (v != get_left_parentheses(c))
        return false;
    }
    }
  }

  return container.empty();
}