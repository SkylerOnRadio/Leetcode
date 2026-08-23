#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int largest(std::vector<int> &heights) {
  std::stack<std::vector<int>> store;
  int res{0};
  int area{0};
  int index{-1};

  for (int i = 0; i < heights.size(); ++i) {
    while (!(store.empty()) && store.top().at(0) > heights.at(i)) {
      area = store.top().at(0) * (i - store.top().at(1));
      index = store.top().at(1);
      store.pop();
      if (area > res)
        res = area;
    }
    if (index != -1) {
      store.push({heights.at(i), index});
      index = -1;
    } else
      store.push({heights.at(i), i});
    std::cout << store.top().at(0) << ", " << store.top().at(1) << "\n";
  }

  while (!store.empty()) {
    area = store.top().at(0) * (heights.size() - store.top().at(1));
    if (area > res)
      res = area;
    store.pop();
  }

  return res;
}

int brute(std::vector<int> &heights) {
  int max{0};

  for (int i = 0; i < heights.size(); ++i) {
    int currArea{0};
    for (int j = i + 1; j < heights.size(); ++j) {
      if (j + 1 < heights.size() && (heights.at(j) > heights.at(j + 1))) {
        currArea = std::min(heights.at(i), heights.at(j)) * (j - i + 1);
        break;
      }
      currArea = std::min(heights.at(i), heights.at(j)) * (j - i + 1);
    }
    if (currArea > max)
      max = currArea;
    currArea = 0;
  }

  return max;
}

int main() {
  std::vector<int> nums = {2, 1, 5, 6, 2, 3};
  std::vector<int> nums1 = {1, 1};
  std::vector<int> nums2 = {3, 6, 5, 7, 4, 8, 1, 0};
  std::cout << largest(nums2) << "\n";
  return 0;
}
