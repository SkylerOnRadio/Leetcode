#include <iostream>
#include <vector>

int bsear(std::vector<int> &nums, int target) {
  int low{0};
  int high = nums.size() - 1;
  while (high >= low) {
    int mid = (high + low) / 2;
    if (nums.at(mid) == target)
      return mid;
    else if (nums.at(mid) > target)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
  std::cout << bsear(nums, 9) << "\n";
  return 0;
}
