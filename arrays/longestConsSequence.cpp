#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int longestConsecutive(std::vector<int> &nums) {
  if (nums.size() == 0)
    return 0;

  std::unordered_set<int> exists{nums.begin(), nums.end()};

  int maxSize{0};
  for (int num : exists) {
    if (exists.find(num - 1) == exists.end()) {
      int size = 0;
      while (exists.find(num) != exists.end()) {
        size++;
        num++;
      }
      maxSize = std::max(size, maxSize);
    }
  }

  return maxSize;
}

int main() {
  std::vector<int> nums1 = {100, 4, 200, 1, 3, 2};
  std::vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::vector<int> nums3 = {1, 0, 1, 2};
  std::vector<int> nums4 = {0, -1};

  std::cout << longestConsecutive(nums1) << "is the longest.\n";
  std::cout << longestConsecutive(nums2) << "is the longest.\n";
  std::cout << longestConsecutive(nums3) << "is the longest.\n";
  std::cout << longestConsecutive(nums4) << "is the longest.\n";

  return 0;
}
