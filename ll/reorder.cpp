#include "linkedlist.h"
#include <iostream>
#include <vector>

void reorderList(ListNode *head) {
  if (head == nullptr)
    return;

  std::vector<ListNode *> nodes;

  ListNode *tmp = head;

  while (tmp != nullptr) {
    nodes.push_back(tmp);
    tmp = tmp->next;
  }

  int front = 0;
  int back = nodes.size() - 1;

  while (front < back) {
    nodes.at(front)->next = front == back ? nullptr : nodes.at(back);
    ++front;

    nodes.at(back)->next = front == back ? nullptr : nodes.at(front);
    --back;
  }

  nodes.at(front)->next = nullptr;
}

int main(int argc, char *argv[]) {
  ListNode node5(5, nullptr);
  ListNode node4(4, &node5);
  ListNode node3(3, &node4);
  ListNode node2(2, &node3);
  ListNode node1(1, &node2);

  ListNode *head = &node1;

  ListNode *tmp = head;
  while (tmp != nullptr) {
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << "\n";

  reorderList(head);
  // std::cout << "This is a test\n";

  tmp = head;
  while (tmp != nullptr) {
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << "\n";

  return 0;
}
