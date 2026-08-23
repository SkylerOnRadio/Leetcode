#include <iostream>
#include <vector>

// check every point in the array
// sorting is nlogn so that is not applicable
// have to do binary search instantly.
// if the number of rotations can be found then the answer is in O(1)
int brute(std::vector<int> &nums) {
  int min{nums.front()};
  for (int i = 0; i < nums.size(); ++i) {
    if (min > nums.at(i))
      min = nums.at(i);
  }

  return min;
}

int optimal(std::vector<int> &nums) {
  int low = 0;
  int high = nums.size() - 1;
  int min{nums.front()};

  while (high >= low) {
    int mid = (high + low) / 2;

    if (nums.at(low) < nums.at(high)) {
      if (min > nums.at(low))
        min = nums.at(low);
      break;
    }

    if (nums.at(mid) < min)
      min = nums.at(mid);

    if (nums.at(mid) >= nums.at(low))
      low = mid + 1;
    else
      high = mid - 1;
  }

  return min;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {3, 4, 5, 1, 2};
  std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
  std::vector<int> nums2 = {17, 11, 13, 15};
  std::vector<int> nums3 = {2, 1};
  std::cout << optimal(nums3) << "\n";
  return 0;
}
