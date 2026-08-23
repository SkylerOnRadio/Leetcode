#include "linkedlist.h"
#include <iostream>
#include <vector>

ListNode *add(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr && l2 == nullptr)
    return nullptr;

  if (l1 == nullptr || l2 == nullptr)
    return l1 == nullptr ? l2 : l1;

  ListNode *prev = nullptr;
  ListNode *curr = l1;
  ListNode *next;

  while (curr != nullptr) {
    next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
  }
  l1 = prev;

  prev = nullptr;
  curr = l2;
  next = nullptr;

  while (curr != nullptr) {
    next = curr->next;

    curr = prev;

    prev = curr;
    curr = next;
  }
  l2 = prev;

  ListNode *tmp1 = l1;
  ListNode *tmp2 = l1;

  ListNode *dummy = new ListNode(0);
  ListNode *res = dummy;

  int carry{0};
  while (tmp1 != nullptr || tmp2 != nullptr) {
    int sum = tmp1->val + tmp2->val + carry;
    carry = sum / 10;
    sum = sum % 10;

    res->next = new ListNode(sum);
    res = res->next;
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }

  if ((tmp1 == nullptr) ^ (tmp2 == nullptr)) {
    ListNode *tmp;
    if (tmp1 == nullptr) {
      tmp = tmp2;
    } else {
      tmp = tmp1;
    }

    while (tmp != nullptr) {
      int sum = tmp->val + carry;
      carry = sum / 10;
      sum = sum % 10;

      res->next = new ListNode(sum);
      res = res->next;
      tmp = tmp->next;
    }
  }

  if (carry != 0) {
    res->next = new ListNode(carry);
  }

  prev = nullptr;
  curr = dummy;
  next = nullptr;

  while (curr != nullptr) {
    next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
  }

  return prev;
}

int main(int argc, char *argv[]) {
  std::vector<int> list1 = {2, 4, 3};
  std::vector<int> list2 = {5, 6, 4};

  ListNode *head1 = createList(list1);
  ListNode *head2 = createList(list2);

  ListNode *res = add(head1, head2);

  ListNode *tmp = res;
  int num{0};
  int i{1};

  while (tmp != nullptr) {
    num += tmp->val * i;
    i *= 10;
    tmp = tmp->next;
  }

  std::cout << num << "\n";

  return 0;
}
