#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::vector<int> result;
  std::unordered_map<int, int> freqMap;
  for (int num : nums) {
    if (freqMap.find(num) == freqMap.end()) {
      freqMap.insert({num, 1});
      continue;
    }
    freqMap[num]++;
  }
  std::unordered_map<int, std::vector<int>> map;
  int highestFreq{0};
  for (auto i : freqMap) {
    if (highestFreq < i.second)
      highestFreq = i.second;
    if (map.find(i.second) == map.end()) {
      map.insert({i.second, {i.first}});
      continue;
    }
    map.find(i.second)->second.push_back(i.first);
  }
  for (int i = highestFreq; k > 0; --i) {
    if (map.find(i) == map.end())
      continue;

    std::vector<int> numbersOfFreqI = map.find(i)->second;
    for (int n : numbersOfFreqI) {
      result.push_back(n);
      k--;
    }
  }
  return result;
}

std::vector<int> L_topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> count;
  std::vector<std::vector<int>> frequency(nums.size() + 1);
  std::vector<int> result;
  for (int n : nums) {
    auto freq = (count.find(n) == count.end()) ? 1 : count.find(n)->second + 1;
    count[n]++;
  }
  for (auto keyValue : count) {
    frequency.at(keyValue.second).push_back(keyValue.first);
  }
  for (int i = nums.size(); result.size() < k && i >= 0; i--) {
    for (int n : frequency.at(i)) {
      result.push_back(n);
      if (result.size() >= k)
        break;
    }
  }
  return result;
}

int main() {
  std::vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  std::vector<int> result = topKFrequent(nums, 2);
  for (int n : result)
    std::cout << n << "\n";
  return 0;
}
