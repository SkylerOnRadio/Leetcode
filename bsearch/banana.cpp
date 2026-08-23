#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

int minEat(std::vector<int> &piles, int h) {
  std::sort(piles.begin(), piles.end());

  int minRate{piles.back()};

  int high = minRate;
  int low = 1;
  while (high >= low) {
    int mid = (high + low) / 2;
    int64_t timeTaken{0};
    for (int pile : piles) {
      if (pile > mid)
        timeTaken += std::ceil(static_cast<double>(pile) / mid);
      else if (pile <= mid)
        ++timeTaken;
    }
    if (timeTaken > h)
      low = mid + 1;
    else
      high = mid - 1;

    if (timeTaken <= h)
      if (minRate > mid)
        minRate = mid;
  }

  return minRate;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {3, 6, 7, 11};
  std::vector<int> nums1 = {30, 11, 23, 4, 20};
  std::vector<int> nums2 = {312884470};

  std::cout << minEat(nums, 8) << "\n";

  return 0;
}
