#include "linkedlist.h"
#include <iostream>
#include <vector>

int getNum(ListNode *head) {
  int num = 0;
  int i = 1;

  while (head != nullptr) {
    num += (head->val * i);
    i *= 10;
    head = head->next;
  }

  return num;
}

ListNode *add(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr && l2 == nullptr)
    return nullptr;

  if ((l1 == nullptr) ^ (l2 == nullptr))
    return l1 == nullptr ? l2 : l1;

  ListNode *dummy = new ListNode(0);

  ListNode *tmp1 = l1;
  ListNode *tmp2 = l2;
  ListNode *res = dummy;

  int carry{0};

  while (tmp1 != nullptr || tmp2 != nullptr) {
    int num1{0};
    int num2{0};

    if (tmp1 != nullptr) {
      num1 = tmp1->val;
      tmp1 = tmp1->next;
    }
    if (tmp2 != nullptr) {
      num2 = tmp2->val;
      tmp2 = tmp2->next;
    }

    int sum = num1 + num2 + carry;

    carry = sum / 10;

    res->next = new ListNode(sum % 10);
    res = res->next;
  }

  if (carry != 0)
    res->next = new ListNode(carry);

  return dummy->next;
}

int main(int argc, char *argv[]) {
  std::vector<int> num1 = {4, 0, 2, 1};
  std::vector<int> num2 = {2, 1, 5};

  ListNode *a = createList(num1);
  ListNode *b = createList(num2);

  ListNode *res = add(a, b);

  std::cout << getNum(a) << " + " << getNum(b) << " = " << getNum(res) << "\n";

  return 0;
}
