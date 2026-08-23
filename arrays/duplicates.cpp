#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

bool containsDuplicate(std::vector<int> &nums) {
  std::unordered_map<int, int> numExists;
  for (int num : nums) {
    if (numExists.find(num) != numExists.end())
      return true;
    numExists.insert({num, 1});
  }
  return false;
}

int main() {
  std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  bool exists = containsDuplicate(nums);
  std::boolalpha(std::cout);
  std::cout << exists << "\n";
  return 0;
}
