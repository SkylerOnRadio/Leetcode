#include "linkedlist.h"
#include <iostream>
#include <ostream>

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr && list2 == nullptr)
    return nullptr;

  ListNode *dummy = new ListNode(0);
  ListNode *atmp = dummy;

  while (list1 != nullptr || list2 != nullptr) {
    // list1 is null, so the other can't be null
    if (list1 == nullptr) {
      atmp->next = list2;
      break;
    }

    // list2 is null, so the other can't be null
    else if (list2 == nullptr) {
      atmp->next = list1;
      break;
    }

    // both aren't null
    else {
      int val;
      if (list1->val > list2->val) {
        val = list2->val;
        list2 = list2->next;
      } else {
        val = list1->val;
        list1 = list1->next;
      }

      atmp->next = new ListNode(val);
      atmp = atmp->next;
    }
  }

  return dummy->next;
}

int main(int argc, char *argv[]) {
  ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));

  ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  ListNode *tmp = list1;
  std::cout << "The first list: \n";
  while (tmp != nullptr) {
    std::cout << tmp->val << "->";
    tmp = tmp->next;
  }
  std::cout << std::endl;

  tmp = list2;
  std::cout << "The second list: \n";
  while (tmp != nullptr) {
    std::cout << tmp->val << "->";
    tmp = tmp->next;
  }
  std::cout << std::endl;

  ListNode *ans = mergeTwoLists(list1, list2);
  tmp = ans;

  while (tmp != nullptr) {
    std::cout << tmp->val << "->";
    tmp = tmp->next;
  }
  std::cout << std::endl;

  return 0;
}
