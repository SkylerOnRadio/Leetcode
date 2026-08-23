#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> result;
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums.at(i) > 0)
      break;
    if (i != 0 && nums.at(i) == nums.at(i - 1))
      continue;

    int front = i + 1;
    int end = nums.size() - 1;

    while (front < end) {
      int sum = nums.at(front) + nums.at(end);
      if (sum > -nums.at(i))
        end--;
      else if (sum < -nums.at(i))
        front++;
      else {
        result.push_back({nums.at(i), nums.at(front), nums.at(end)});
        while (front < end && nums.at(front) == nums.at(front + 1))
          front++;
        while (front < end && nums.at(end) == nums.at(end - 1))
          end--;

        front++;
        end--;
      }
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  std::vector<int> nums1 = {0, 1, 1};
  std::vector<int> nums2 = {0, 0, 0, 0};

  std::vector<std::vector<int>> result;

  result = threeSum(nums2);
  for (auto vect : result) {
    for (auto num : vect)
      std::cout << num << " ";
    std::cout << "\n";
  }
  return 0;
}
