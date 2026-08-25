#include <iostream>
#include <vector>

int dupli(std::vector<int> &nums) {

  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums.at(i) == nums.at(j))
        return nums.at(i);
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 3, 4, 2, 2};

  int dup = dupli(nums);

  std::cout << dup << "\n";

  return 0;
}
