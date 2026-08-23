#include "linkedlist.h"
#include <iostream>
#include <map>
#include <vector>

Node *optimal(Node *head) {
  if (head == nullptr)
    return nullptr;

  Node *res = new Node(head->val);
  std::map<Node *, Node *> originalToCopy;

  originalToCopy.insert({head, res});

  Node *tmp = head;
  Node *ans = res;

  while (tmp != nullptr) {
    if (tmp->next == nullptr) {
      ans->next = nullptr;
    } else if (originalToCopy.find(tmp->next) == originalToCopy.end()) {
      ans->next = new Node(tmp->next->val);
      originalToCopy.insert({tmp->next, ans->next});
    } else {
      ans->next = originalToCopy.find(tmp->next)->second;
    }

    if (tmp->random == nullptr) {
      ans->random = nullptr;
    } else if (originalToCopy.find(tmp->random) == originalToCopy.end()) {
      ans->random = new Node(tmp->random->val);
      originalToCopy.insert({tmp->random, ans->random});
    } else {
      ans->random = originalToCopy.find(tmp->random)->second;
    }

    tmp = tmp->next;
    ans = ans->next;
  }

  return res;
}

Node *copyRandomList(Node *head) {

  Node *dummy = new Node(0);
  Node *res = dummy;
  std::vector<std::vector<Node *>> list;
  std::vector<Node *> copy;

  Node *tmp = head;
  // copy the liked list itself and store all the pointers of the node in a
  // vector
  while (tmp != nullptr) {
    res->next = new Node(tmp->val);
    copy.push_back(res->next);
    list.push_back({tmp, tmp->next, tmp->random});
    res = res->next;
    tmp = tmp->next;
  }

  int indexOfCopy = 0;
  int indexOfOrigin = 0;

  res = dummy->next;
  while (res != nullptr) {
    if (list.at(indexOfCopy).at(2) == nullptr) {
      res->random = nullptr;
      res = res->next;
      ++indexOfCopy;
      continue;
    }

    while (list.at(indexOfCopy).at(2) != list.at(indexOfOrigin).at(0)) {
      ++indexOfOrigin;
    }
    res->random = copy.at(indexOfOrigin);
    indexOfOrigin = 0;

    res = res->next;
    ++indexOfCopy;
  }

  return dummy->next;
}

int main(int argc, char *argv[]) {
  Node *node5 = new Node(1);
  Node *node4 = new Node(10);
  Node *node3 = new Node(11);
  Node *node2 = new Node(13);
  Node *node1 = new Node(7);

  node1->next = node2;
  node1->random = nullptr;

  node2->next = node3;
  node2->random = node1;

  node3->next = node4;
  node3->random = node5;

  node4->next = node5;
  node4->random = node3;

  node5->random = node1;

  Node *res = optimal(node1);

  Node *tmp = node1;
  while (tmp != nullptr) {
    int next = tmp->next == nullptr ? -10000 : tmp->next->val;
    int rando = tmp->random == nullptr ? -10000 : tmp->random->val;
    std::cout << rando << "<-" << tmp->val << "->" << next << "\n";
    tmp = tmp->next;
  }

  tmp = res;
  while (tmp != nullptr) {
    int next = tmp->next == nullptr ? -10000 : tmp->next->val;
    int rando = tmp->random == nullptr ? -10000 : tmp->random->val;
    std::cout << rando << "<-" << tmp->val << "->" << next << "\n";
    tmp = tmp->next;
  }

  return 0;
}
