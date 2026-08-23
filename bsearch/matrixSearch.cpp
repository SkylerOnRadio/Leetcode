#include <ios>
#include <iostream>
#include <vector>

bool search(std::vector<std::vector<int>> &matrix, int target) {
  int lowRow{0};
  int highRow = matrix.size() - 1;
  int searchRow{-1};

  if (matrix.size() != 1) {
    while (highRow >= lowRow) {
      int mid = (lowRow + highRow) / 2;
      std::cout << lowRow << "\t" << mid << "\t" << highRow << "\n";
      if (matrix.at(mid).at(0) == target)
        return true;
      else if (matrix.at(mid).at(0) > target)
        highRow = mid - 1;
      else if (matrix.at(mid).at(0) < target) {
        if (mid + 1 < matrix.size()) {
          if (matrix.at(mid + 1).at(0) > target) {
            searchRow = mid;
            break;
          } else if (matrix.at(mid + 1).at(0) == target)
            return true;
          else
            lowRow = mid + 1;
        } else {
          searchRow = mid;
          break;
        }
      }
    }
  } else
    searchRow = 0;

  if (searchRow == -1)
    return false;

  int high = matrix.at(searchRow).size() - 1;
  int low = 0;

  while (high >= low) {
    int mid = (high + low) / 2;
    if (matrix.at(searchRow).at(mid) == target)
      return true;
    else if (matrix.at(searchRow).at(mid) > target)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return false;
}

bool optimal(std::vector<std::vector<int>> &matrix, int target) {
  int lowRow{0};
  int highRow = matrix.size() - 1;
  int searchRow{-1};

  while (highRow >= lowRow) {
    int mid = (lowRow + highRow) / 2;
    std::cout << lowRow << "\t" << mid << "\t" << highRow << "\n";
    if (matrix.at(mid).at(0) == target)
      return true;
    else if (matrix.at(mid).at(0) > target)
      highRow = mid - 1;
    else if (matrix.at(mid).at(0) < target) {
      int end = matrix.at(mid).size() - 1;
      if (matrix.at(mid).at(end) > target) {
        searchRow = mid;
        break;
      } else if (matrix.at(mid).at(end) == target)
        return true;
      else
        lowRow = mid + 1;
    }
  }

  if (searchRow == -1)
    return false;

  int high = matrix.at(searchRow).size() - 1;
  int low = 0;

  while (high >= low) {
    int mid = (high + low) / 2;
    if (matrix.at(searchRow).at(mid) == target)
      return true;
    else if (matrix.at(searchRow).at(mid) > target)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::boolalpha(std::cout);

  std::vector<std::vector<int>> nums = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60},
  };

  std::vector<std::vector<int>> nums1 = {
      {1},
      {3},
      {5},
  };

  std::vector<std::vector<int>> nums2 = {
      {1, 3},
  };

  std::cout << optimal(nums1, 3) << "\n";

  return 0;
}
