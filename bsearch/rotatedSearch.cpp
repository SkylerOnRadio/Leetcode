#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (high >= low) {
    int mid = (high + low) / 2;

    if (nums.at(low) <= nums.at(high)) {
      if (target == nums.at(mid))
        return mid;
      else if (target > nums.at(mid))
        low = mid + 1;
      else
        high = mid - 1;
    }

    else if (nums.at(low) <= nums.at(mid)) {
      if (target == nums.at(mid))
        return mid;
      else if (target >= nums.at(low) && target < nums.at(mid)) {
        high = mid - 1;
      } else // if (target < nums.at(low))
        low = mid + 1;
    } else {
      if (target == nums.at(mid))
        return mid;
      else if (target > nums.at(mid) && target <= nums.at(high))
        low = mid + 1;
      else // if (target > nums.at(high))
        high = mid - 1;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  // 4  5 6 1
  std::vector<int> nums = {5, 1, 3};
  std::cout << search(nums, 3) << "\n";
  return 0;
}
