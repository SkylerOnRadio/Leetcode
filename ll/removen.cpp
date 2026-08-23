#include "linkedlist.h"
#include <iostream>
#include <vector>

ListNode *remove(ListNode *head, int n) {
  if (head == nullptr)
    return nullptr;

  int size{0};
  ListNode *curr = head;
  while (curr != nullptr) {
    curr = curr->next;
    ++size;
  }

  if (n == size) {
    head = head->next;
    return head;
  }

  curr = head;
  ListNode *prev = nullptr;

  while (curr != nullptr) {
    if (n == size) {
      prev->next = curr->next;
      return head;
    }
    prev = curr;
    curr = curr->next;

    ++n;
  }

  return head;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 2, 3, 4, 5};

  ListNode *head = createList(nums);

  ListNode *tmp = head;

  while (tmp != nullptr) {
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << "\n";

  head = remove(head, 2);

  tmp = head;
  while (tmp != nullptr) {
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << "\n";

  return 0;
}
