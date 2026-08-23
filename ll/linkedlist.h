#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode();
  ListNode(int val);
  ListNode(int val, ListNode *nextNode);
};

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int val);
};

ListNode *createList(std::vector<int> nums);

#endif // !LINKEDLIST_H
