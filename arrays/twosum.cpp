#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); ++i) {
    int diff = target - nums.at(i);
    if (map.find(diff) != map.end()) {
      int index = map.find(diff)->second;
      return {i, index};
    }
    map.insert({nums.at(i), i});
  }
  return {};
}

std::vector<int> twoSum2(std::vector<int> &numbers, int target) {
  int i = 0;
  int j = numbers.size() - 1;

  while (i < j) {
    if (numbers.at(i) + numbers.at(j) > target)
      j--;
    else if (numbers.at(i) + numbers.at(j) < target)
      i++;
    else
      return {++i, ++j};
  }

  return {};
}

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  std::vector<int> nums1 = {
      2,
      3,
      4,
  };
  std::vector<int> nums2 = {-1, 0};
  std::vector<int> indices = twoSum(nums, 9);

  return 0;
}
