#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *recursive(ListNode *curr, ListNode *prev, ListNode *next) {
  if (next == nullptr) {
    curr->next = prev;
    return curr;
  } else {
    ListNode *start = recursive(curr->next, curr, curr->next->next);
    curr->next = prev;
    return start;
  }
}

ListNode *reverse(ListNode *head) {
  if (head == nullptr)
    return nullptr;

  return recursive(head, nullptr, head->next);
}

ListNode *addToLL(int val) {
  if (val % 5 == 0)
    return new ListNode(val, nullptr);
  else
    return new ListNode(val, addToLL(val + 1));
}

int main(int argc, char *argv[]) {
  ListNode *head = addToLL(1);

  ListNode *tmp = head;
  // while (tmp != nullptr) {
  //   std::cout << tmp->val << std::endl;
  //   tmp = tmp->next;
  // }

  tmp = reverse(head);

  while (tmp != nullptr) {
    std::cout << tmp->val << std::endl;
    tmp = tmp->next;
  }
  return 0;
}
