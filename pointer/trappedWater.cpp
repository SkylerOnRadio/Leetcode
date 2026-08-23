#include <iostream>
#include <vector>

int trap(std::vector<int> &height) {
  int area{0};
  int i{0};
  int j{0};
  int lb{0};
  int rb = height.at(0);
  int indexJ{0};

  while (i < height.size()) {
    if (i == j && i < height.size() - 1) {

      if (j < height.size() - 1) {
        rb = height.at(++j);
        indexJ = j;
      }

      while (j <= height.size() - 1) {
        if (height.at(j) >= rb) {
          rb = height.at(j);
          indexJ = j;
        }
        ++j;
      }
      j = indexJ;

    } else {
      int waterTrapped = (rb > lb ? lb : rb) - height.at(i);
      if (waterTrapped > 0)
        area += waterTrapped;

      if (height.at(i) > lb)
        lb = height.at(i);

      ++i;
    }
  }

  return area;
}

int optimal(std::vector<int> &height) {
  if (height.empty())
    return 0;

  int area = 0;
  int left = 0;
  int right = height.size() - 1;
  int leftMax = height.at(left);
  int rightMax = height.at(right);

  while (left < right) {
    if (height.at(left) < height.at(right)) {
      int res = leftMax - height.at(left);
      if (res >= 0)
        area += res;
      if (leftMax < height.at(left))
        leftMax = height.at(left);

      left++;
    } else {
      int res = rightMax - height.at(right);
      if (res >= 0)
        area += res;
      if (rightMax < height.at(right))
        rightMax = height.at(right);
      right--;
    }
  }

  return area;
}

int main() {
  std::vector<int> nums = {4, 2, 0, 3, 2, 5};
  std::vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << trap(nums) << "\n";
  std::cout << trap(nums1) << "\n";
  std::cout << optimal(nums) << "\n";
  std::cout << optimal(nums1) << "\n";
  return 0;
}
