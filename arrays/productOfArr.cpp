#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  int prefix[nums.size()];
  int postfix[nums.size()];
  std::vector<int> result;

  for (int i = 0; i < nums.size(); ++i) {
    if (i == 0)
      prefix[i] = 1 * nums.at(i);
    else
      prefix[i] = prefix[i - 1] * nums.at(i);
  }

  for (int i = nums.size() - 1; i >= 0; --i) {
    if (i == nums.size() - 1)
      postfix[i] = 1 * nums.at(i);
    else
      postfix[i] = (nums.at(i) * postfix[i + 1]);
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (i == 0)
      result.push_back(postfix[i + 1] * 1);
    else if (i == nums.size() - 1)
      result.push_back(prefix[i - 1] * 1);
    else
      result.push_back(prefix[i - 1] * postfix[i + 1]);
  }

  return result;
}

std::vector<int> optimalProductExceptSelf(std::vector<int> &nums) {
  int prefix{1};
  int postfix{1};
  std::vector<int> result;

  for (int i = 0; i < nums.size(); ++i) {
    result.push_back(prefix);
    prefix *= nums.at(i);
  }

  for (int i = nums.size() - 1; i >= 0; --i) {
    result.at(i) *= postfix;
    postfix *= nums.at(i);
  }

  return result;
}

int main() {
  std::vector<int> nums = {-1, 1, 0, -3, 3};
  std::vector<int> result = productExceptSelf(nums);
  std::vector<int> result1 = optimalProductExceptSelf(nums);
  for (int n : result)
    std::cout << n << "\n";

  std::cout << "\n";

  for (int n : result1)
    std::cout << n << "\n";
  return 0;
}
