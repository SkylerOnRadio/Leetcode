#include <algorithm>
#include <iostream>
#include <vector>

int median(std::vector<int> &nums1, std::vector<int> &nums2) {
  int m{0};

  int totalSize = nums1.size() + nums2.size();
  int low = 0;
  int high = nums1.size() - 1;
  int mid;
  int mid2;

  while (high >= low) {
    mid = (high + low) / 2;
    mid2 = (totalSize / 2) - (mid + 1) - 1;

    if (mid2 + 1 < nums2.size() && nums1.at(mid) <= nums2.at(mid2 + 1)) {
      if (mid + 1 < nums1.size() && nums2.at(mid2) <= nums1.at(mid + 1))
        break;
      else
        high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  std::cout << mid << "\t" << mid2 << "\n";
  if (totalSize & 1)
    return std::min(nums1.at(mid), nums2.at(mid2));
  else
    return std::min(nums1.at(mid), nums2.at(mid2)) +
           std::max(nums1.at(mid + 1), nums2.at(mid2 + 1));

  return m;
}

int main() {
  std::vector<int> nums1 = {1, 2};
  std::vector<int> nums2 = {3, 4};
  std::cout << median(nums1, nums2);
  return 0;
}
