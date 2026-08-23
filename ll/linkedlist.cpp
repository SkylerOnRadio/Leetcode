#include "linkedlist.h"
#include <vector>

ListNode::ListNode() : val(0), next(nullptr) {}

ListNode::ListNode(int val) : val(val), next(nullptr) {}

ListNode::ListNode(int val, ListNode *nextNode) : val(val), next(nextNode) {}

ListNode *recusrse(int i, std::vector<int> &nums) {
  if (i >= nums.size())
    return nullptr;

  return new ListNode(nums.at(i), recusrse(i + 1, nums));
}

ListNode *createList(std::vector<int> nums) {
  int i = 0;
  return recusrse(0, nums);
}

Node::Node(int val) : val(val), next(nullptr), random(nullptr) {}
