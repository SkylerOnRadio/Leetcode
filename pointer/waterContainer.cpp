#include <algorithm>
#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
  int low = 0;
  int high = height.size() - 1;
  int highestArea{0};

  while (high > low) {
    int area = (high - low) * std::min(height.at(low), height.at(high));
    if (area > highestArea)
      highestArea = area;

    height.at(low) > height.at(high) ? high-- : low++;
  }

  return highestArea;
}

int main() {
  std::vector<int> nums1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::vector<int> nums2 = {1, 1};

  std::cout << maxArea(nums1) << "\n";
  std::cout << maxArea(nums2) << "\n";

  return 0;
}
