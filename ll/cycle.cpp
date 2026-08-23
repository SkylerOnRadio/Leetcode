#include "linkedlist.h"
#include <ios>
#include <iostream>

bool hasCycle(ListNode *head) {
  if (head == nullptr)
    return false;

  ListNode *tmp1 = head;
  ListNode *tmp2 = head;

  int i = 0;

  while (tmp1->next != nullptr && tmp2->next != nullptr) {
    tmp2 = tmp2->next;
    if (i & 1)
      tmp1 = tmp1->next;
    ++i;

    if (tmp2 == tmp1)
      return true;
  }

  return false;
}

int main(int argc, char *argv[]) {
  ListNode node4(-4);
  ListNode node3(0, &node4);
  ListNode node2(2, &node3);
  ListNode node1(3, &node2);
  ListNode *head = &node1;
  // node4.next = &node2;

  std::boolalpha(std::cout);

  std::cout << hasCycle(head) << "\n";

  return 0;
}
